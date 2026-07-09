# Atmosic AES hardware driver

This directory contains the Atmosic AES hardware accelerator driver and its
glue into the PSA Crypto dispatch layer used by Mbed TLS 4.x.

- `atm_aes.[ch]` -- low-level HAL for the AES hardware block.
- `psa_aes.c`    -- PSA Crypto integration (linker-wrap of the built-in
  `mbedtls_psa_cipher_encrypt` / `..._decrypt` entry points).
- `Kconfig`      -- `ATM_AES_HW` and `ATM_AES_HW_FALLBACK_ON_EXHAUSTION`.
- `CMakeLists.txt` -- compiles the driver and applies the
  `-Wl,--wrap=mbedtls_psa_cipher_*` flags.

## PSA driver descriptors, and how they apply here

### What a "descriptor" actually is

A PSA driver descriptor is a JSON file that declares to the PSA core what a
driver can do. It is the contract between the driver author and the
auto-generated dispatch layer. The schema lives at
`modules/crypto/tf-psa-crypto/scripts/data_files/driver_jsons/driver_transparent_schema.json`
and the canonical example is `p256_transparent_driver.json`:

```json
{
    "prefix":       "p256",
    "type":         "transparent",
    "mbedtls/h_condition":   "defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED)",
    "headers":      ["../drivers/p256-m/p256-m_driver_entrypoints.h"],
    "capabilities": [
        {
            "entry_points": ["import_key", "export_public_key"],
            "algorithms":   ["PSA_ALG_ECDH", "PSA_ALG_ECDSA(PSA_ALG_ANY_HASH)"],
            "key_types":    ["PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1)"],
            "key_sizes":    [256],
            "fallback":     false
        }
    ]
}
```

The fields, decoded:

| Field | Meaning |
|---|---|
| `prefix` | Symbol prefix the generator expects on entry-point functions (e.g. `p256_transparent_sign_hash`, `atm_transparent_cipher_encrypt`). |
| `type` | `transparent` (cleartext keys, plain accelerator) or `opaque` (keys live behind a boundary, dispatch by key location). AES HW is `transparent`. |
| `mbedtls/h_condition` / `mbedtls/c_condition` | C preprocessor guards wrapped around the generated `#include` line and the call site. This is how the dispatcher gets compiled out when the driver is not enabled. |
| `headers` | Header(s) `#include`d at the top of the generated `psa_crypto_driver_wrappers.h`. |
| `capabilities[]` | The actual matching rules: which `entry_points`, for which `algorithms`, on which `key_types`/`key_sizes`. The dispatcher emits an `if (...)` guard from these. |
| `fallback` | If `true`, a `PSA_ERROR_NOT_SUPPORTED` return drops through to the next driver / built-in. If `false`, the driver is authoritative. |
| `names` | Optional override of the conventional `<prefix>_<type>_<entry_point>` symbol naming. |

### What the descriptor would look like for AES HW

```json
{
    "prefix":              "atm",
    "type":                "transparent",
    "mbedtls/h_condition": "defined(CONFIG_ATM_AES_HW)",
    "headers":             ["psa_atm_aes.h"],
    "capabilities": [
        {
            "mbedtls/c_condition": "defined(CONFIG_ATM_AES_HW)",
            "entry_points": ["cipher_encrypt", "cipher_decrypt"],
            "algorithms":   ["PSA_ALG_ECB_NO_PADDING", "PSA_ALG_CTR"],
            "key_types":    ["PSA_KEY_TYPE_AES"],
            "key_sizes":    [128, 256],
            "fallback":     true
        }
    ]
}
```

…and we would implement `atm_transparent_cipher_encrypt` and
`atm_transparent_cipher_decrypt` with the PSA-shaped signatures.

### How that descriptor would actually become code

1. `modules/crypto/tf-psa-crypto/scripts/data_files/driver_jsons/driverlist.json`
   lists every JSON descriptor that the build is allowed to consume.
2. At build time, `tf-psa-crypto`'s CMake calls
   `scripts/generate_driver_wrappers.py`, which:
   - Validates each descriptor against `driver_transparent_schema.json` /
     `driver_opaque_schema.json`.
   - Renders `data_files/driver_templates/psa_crypto_driver_wrappers.h.jinja`
     (and `..._no_static.c.jinja`) with the descriptor list as the Jinja
     context.
3. The output, `core/psa_crypto_driver_wrappers.h`, contains `static inline`
   functions like `psa_driver_wrapper_cipher_encrypt()` that conditionally
   call the driver's entry point first, then fall back to
   `mbedtls_psa_cipher_encrypt_internal()` (the built-in software).

### Why we did **not** add a descriptor here

Two real-world problems with the descriptor route:

1. **It would require forking `tf-psa-crypto`.** `driverlist.json` lives in the
   upstream module tree. Adding a descriptor means either editing the upstream
   file in place (a fork) or injecting a path during the upstream CMake's run,
   which the existing CMake does not support. Project policy is to avoid
   forking `mbedtls` or `tf-psa-crypto`.
2. **`cipher_*` is not in the auto-generated set today.** The generator only
   fully emits dispatch for `import_key` / `export_public_key`. For everything
   else (including ciphers), the *current* recommended path is **manual edits**
   to the `.jinja` template -- i.e., editing upstream files. Same fork
   problem, worse version-skew problem.

### What linker wrapping replaces in that picture

When no driver matches, the generated `psa_crypto_driver_wrappers.h` calls
`mbedtls_psa_cipher_encrypt` / `..._decrypt` (the built-in software entry
points) as the fallback. Those are external symbols at link time.

`-Wl,--wrap=mbedtls_psa_cipher_encrypt` rewrites every reference to
`mbedtls_psa_cipher_encrypt` to point at `__wrap_mbedtls_psa_cipher_encrypt`,
and exposes the original under `__real_mbedtls_psa_cipher_encrypt`. So the
wrapper:

- Sees the call the dispatcher would have routed to software.
- If the key/algorithm pair is one of {AES-ECB-128, AES-ECB-256, AES-CTR-128},
  runs the Atmosic HW.
- Otherwise calls `__real_*` and the software path runs unmodified.

Net effect: the same observable behavior as a real descriptor with
`algorithms: ["PSA_ALG_ECB_NO_PADDING", "PSA_ALG_CTR"]`,
`key_types: ["PSA_KEY_TYPE_AES"]`, and `fallback: true`, **without touching
`tf-psa-crypto`**.

### Scope: one-shot only

Only `mbedtls_psa_cipher_encrypt` / `..._decrypt` are wrapped. The multi-part
entry points (`cipher_encrypt_setup`, `cipher_decrypt_setup`, `cipher_set_iv`,
`cipher_update`, `cipher_finish`, `cipher_abort`) are intentionally left to
the software implementation: the Atmosic AES block has no save/restore for
its key/IV/counter state, so multi-part operations cannot be paused and
resumed across other HW users (notably the BLE controller, which also takes
`aes_hw_mutex`). Streaming callers therefore continue to work, just on the
software path.

`PSA_ERROR_INSUFFICIENT_MEMORY` is reused as the in-band signal for
"AES HW is busy" (the `aes_hw_mutex` `K_MSEC(100)` lock attempt timed out).
Under `CONFIG_ATM_AES_HW_FALLBACK_ON_EXHAUSTION` (default `y`) the wrapper
transparently retries the call against `__real_*`; with the option disabled
the error is propagated to the caller, which is occasionally useful for
diagnosing contention.

### Trade-offs to be aware of

| Aspect | Descriptor (the "right" way) | `--wrap` (what we did) |
|---|---|---|
| Discoverability | Driver advertised in the build, visible to the generator | Invisible to the PSA dispatcher; only the linker knows |
| Dispatch cost | Inlined `if` in `static inline` | Indirect through wrap (LTO can re-inline on most toolchains) |
| Multi-driver coexistence | Generator orders capabilities and emits `NOT_SUPPORTED` chain | "First wrapper wins"; if another driver also wraps the same symbol, the last `--wrap` flag on the link line wins, which is fragile |
| Upstream coupling | Need to fork `tf-psa-crypto` | None -- only depends on the names of the built-in `mbedtls_psa_cipher_*` symbols |
| Survives Mbed TLS upgrade | Yes (descriptors are stable) | Only as long as the built-in symbol names stay the same |

The last row is the honest cost: if a future Mbed TLS release renames or
inlines `mbedtls_psa_cipher_encrypt` away, the wrap flags become silent
no-ops. That maintenance risk should be re-verified on every Mbed TLS bump.

### Migration path if upstream catches up

If/when `tf-psa-crypto` finishes auto-generating dispatch for cipher entry
points and exposes a way to register out-of-tree descriptors (the
`psa-driver-wrappers-codegen-migration-guide.md` is the in-progress design
for exactly this), the swap is mechanical:

- Drop the `-Wl,--wrap=...` flags from `CMakeLists.txt`.
- Rename `__wrap_mbedtls_psa_cipher_*` to `atm_transparent_cipher_*` to match
  descriptor convention.
- Add the descriptor and a small `psa_atm_aes.h` exposing the entry-point
  prototypes.

The body of `psa_aes.c` -- the algorithm/key-size matching and the
`atm_aes_op()` call -- stays the same.

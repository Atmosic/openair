# Atmosic SHA-2 hardware driver

This directory contains the Atmosic SHA-256 hardware accelerator driver and its
glue into the PSA Crypto dispatch layer used by Mbed TLS 4.x.

- `atm_sha2.[ch]` -- low-level HAL for the SHA-2 hardware block.
- `psa_sha256.c`  -- PSA Crypto integration (linker-wrap of the built-in
  `mbedtls_psa_hash_*` entry points).
- `Kconfig`       -- `ATM_SHA2_HW`, `ATM_SHA2_API_{SINGLE,MULTI}`, and
  `ATM_SHA2_HW_MAX_CONTEXTS`.
- `CMakeLists.txt` -- compiles the driver and applies the
  `-Wl,--wrap=mbedtls_psa_hash_*` flags.

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
| `prefix` | Symbol prefix the generator expects on entry-point functions (e.g. `p256_transparent_sign_hash`, `atm_transparent_hash_setup`). |
| `type` | `transparent` (cleartext keys, plain accelerator) or `opaque` (keys live behind a boundary, dispatch by key location). SHA-256 HW is `transparent`. |
| `mbedtls/h_condition` / `mbedtls/c_condition` | C preprocessor guards wrapped around the generated `#include` line and the call site. This is how the dispatcher gets compiled out when the driver is not enabled. |
| `headers` | Header(s) `#include`d at the top of the generated `psa_crypto_driver_wrappers.h`. |
| `capabilities[]` | The actual matching rules: which `entry_points`, for which `algorithms`, on which `key_types`/`key_sizes`. The dispatcher emits an `if (...)` guard from these. |
| `fallback` | If `true`, a `PSA_ERROR_NOT_SUPPORTED` return drops through to the next driver / built-in. If `false`, the driver is authoritative. |
| `names` | Optional override of the conventional `<prefix>_<type>_<entry_point>` symbol naming. |

### What the descriptor would look like for SHA-256 HW

```json
{
    "prefix":              "atm",
    "type":                "transparent",
    "mbedtls/h_condition": "defined(CONFIG_ATM_SHA2_HW)",
    "headers":             ["psa_atm_sha256.h"],
    "capabilities": [
        {
            "mbedtls/c_condition": "defined(CONFIG_ATM_SHA2_HW)",
            "entry_points": ["hash_setup", "hash_update", "hash_finish",
                             "hash_abort", "hash_clone", "hash_compute"],
            "algorithms":   ["PSA_ALG_SHA_256"],
            "fallback":     true
        }
    ]
}
```

…and we would implement `atm_transparent_hash_setup`, `..._update`,
`..._finish`, `..._abort`, `..._clone`, `..._compute` with the PSA-shaped
signatures.

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
   functions like `psa_driver_wrapper_hash_setup()` that conditionally call the
   driver's entry point first, then fall back to
   `mbedtls_psa_hash_setup_internal()` (the built-in software).

### Why we did **not** add a descriptor here

Two real-world problems with the descriptor route:

1. **It would require forking `tf-psa-crypto`.** `driverlist.json` lives in the
   upstream module tree. Adding a descriptor means either editing the upstream
   file in place (a fork) or injecting a path during the upstream CMake's run,
   which the existing CMake does not support. Project policy is to avoid
   forking `mbedtls` or `tf-psa-crypto`.
2. **`hash_*` is not in the auto-generated set today.** The generator only
   fully emits dispatch for `import_key` / `export_public_key`. For everything
   else (including hashes), the *current* recommended path is **manual edits**
   to the `.jinja` template -- i.e., editing upstream files. Same fork
   problem, worse version-skew problem.

### What linker wrapping replaces in that picture

When no driver matches, the generated `psa_crypto_driver_wrappers.h` calls
`mbedtls_psa_hash_setup` / `..._update` / `..._finish` / `..._abort` /
`..._clone` / `..._compute` (the built-in software entry points) as the
fallback. Those are external symbols at link time.

`-Wl,--wrap=mbedtls_psa_hash_setup` rewrites every reference to
`mbedtls_psa_hash_setup` to point at `__wrap_mbedtls_psa_hash_setup`, and
exposes the original under `__real_mbedtls_psa_hash_setup`. So the wrapper:

- Sees the call the dispatcher would have routed to software.
- If `alg == PSA_ALG_SHA_256`, runs the Atmosic HW.
- Otherwise calls `__real_*` and the software path runs unmodified.

Net effect: the same observable behavior as a real descriptor with
`algorithms: ["PSA_ALG_SHA_256"]` and `fallback: true`, **without touching
`tf-psa-crypto`**.

### Trade-offs to be aware of

| Aspect | Descriptor (the "right" way) | `--wrap` (what we did) |
|---|---|---|
| Discoverability | Driver advertised in the build, visible to the generator | Invisible to the PSA dispatcher; only the linker knows |
| Dispatch cost | Inlined `if` in `static inline` | Indirect through wrap (LTO can re-inline on most toolchains) |
| Multi-driver coexistence | Generator orders capabilities and emits `NOT_SUPPORTED` chain | "First wrapper wins"; if another driver also wraps the same symbol, the last `--wrap` flag on the link line wins, which is fragile |
| Upstream coupling | Need to fork `tf-psa-crypto` | None -- only depends on the names of the built-in `mbedtls_psa_hash_*` symbols |
| Survives Mbed TLS upgrade | Yes (descriptors are stable) | Only as long as the built-in symbol names stay the same |

The last row is the honest cost: if a future Mbed TLS release renames or
inlines `mbedtls_psa_hash_setup` away, the wrap flags become silent no-ops.
That maintenance risk should be re-verified on every Mbed TLS bump.

### Migration path if upstream catches up

If/when `tf-psa-crypto` finishes auto-generating dispatch for hash entry points
and exposes a way to register out-of-tree descriptors (the
`psa-driver-wrappers-codegen-migration-guide.md` is the in-progress design for
exactly this), the swap is mechanical:

- Drop the `-Wl,--wrap=...` flags from `CMakeLists.txt`.
- Rename `__wrap_mbedtls_psa_hash_*` to `atm_transparent_hash_*` to match
  descriptor convention.
- Add the descriptor and a small `psa_atm_sha256.h` exposing the entry-point
  prototypes.

The body of `psa_sha256.c` -- the HW-pool management and the per-entry-point
logic -- stays the same.

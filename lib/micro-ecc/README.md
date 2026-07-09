# Atmosic uECC PSA ECC driver

This directory contains the Atmosic uECC-backed ECC glue into the PSA
Crypto dispatch layer used by Mbed TLS 4.x.

- `psa_ecc.c`      -- PSA Crypto integration (linker-wrap of the built-in
  `mbedtls_psa_ecdsa_sign_hash`, `..._verify_hash` and
  `mbedtls_psa_key_agreement_ecdh` entry points, and -- under
  `ATM_UECC_PSA_NO_FALLBACK` -- of `mbedtls_psa_ecp_import_key` as well;
  see *Why `NO_FALLBACK` also wraps `import_key`* below). The file
  `#include`s the upstream uECC source (`uECC.c`) so that it can install
  a Zephyr-CSPRNG-backed `default_RNG` callback at compile time.

  `mbedtls_psa_ecp_generate_key` is intentionally left unwrapped: PSA
  stores ECC key pairs as the bare scalar and the software keygen path
  only does rejection sampling against the curve order (no point
  arithmetic). `uECC_make_key` always computes the public point in
  addition, so routing keygen through uECC would do an unnecessary
  scalar mult per call.
- `Kconfig`        -- `ATM_UECC_PSA` (and `ATM_UECC_PSA_NO_FALLBACK` for
  the bootloader code-size variant), plus the legacy `ATM_UECC_*` curve and
  feature switches for direct uECC consumers.
- `CMakeLists.txt` -- compiles either `psa_ecc.c` (when `ATM_UECC_PSA=y`) or
  the upstream `uECC.c` directly, and applies the
  `-Wl,--wrap=mbedtls_psa_*` flags in the former case.

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
| `prefix` | Symbol prefix the generator expects on entry-point functions (e.g. `p256_transparent_sign_hash`, `atm_transparent_sign_hash`). |
| `type` | `transparent` (cleartext keys, plain accelerator) or `opaque` (keys live behind a boundary, dispatch by key location). uECC is `transparent`. |
| `mbedtls/h_condition` / `mbedtls/c_condition` | C preprocessor guards wrapped around the generated `#include` line and the call site. This is how the dispatcher gets compiled out when the driver is not enabled. |
| `headers` | Header(s) `#include`d at the top of the generated `psa_crypto_driver_wrappers.h`. |
| `capabilities[]` | The actual matching rules: which `entry_points`, for which `algorithms`, on which `key_types`/`key_sizes`. The dispatcher emits an `if (...)` guard from these. |
| `fallback` | If `true`, a `PSA_ERROR_NOT_SUPPORTED` return drops through to the next driver / built-in. If `false`, the driver is authoritative. |
| `names` | Optional override of the conventional `<prefix>_<type>_<entry_point>` symbol naming. |

### What the descriptor would look like for uECC

```json
{
    "prefix":              "atm",
    "type":                "transparent",
    "mbedtls/h_condition": "defined(CONFIG_ATM_UECC_PSA)",
    "headers":             ["psa_atm_uecc.h"],
    "capabilities": [
        {
            "mbedtls/c_condition": "defined(CONFIG_ATM_UECC_PSA)",
            "entry_points": ["sign_hash", "verify_hash"],
            "algorithms":   ["PSA_ALG_ECDSA(PSA_ALG_ANY_HASH)"],
            "key_types":    ["PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1)",
                             "PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_R1)",
                             "PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_K1)",
                             "PSA_KEY_TYPE_ECC_PUBLIC_KEY(PSA_ECC_FAMILY_SECP_K1)"],
            "key_sizes":    [192, 224, 256],
            "fallback":     true
        }
    ]
}
```

…and we would implement `atm_transparent_sign_hash` and
`atm_transparent_verify_hash` with the PSA-shaped signatures.

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
   functions like `psa_driver_wrapper_sign_hash()` that conditionally call
   the driver's entry point first, then fall back to
   `mbedtls_psa_ecdsa_sign_hash()` (the built-in software).

### Why we did **not** add a descriptor here

Two real-world problems with the descriptor route:

1. **It would require forking `tf-psa-crypto`.** `driverlist.json` lives in the
   upstream module tree. Adding a descriptor means either editing the upstream
   file in place (a fork) or injecting a path during the upstream CMake's run,
   which the existing CMake does not support. Project policy is to avoid
   forking `mbedtls` or `tf-psa-crypto`.
2. **`sign_hash` / `verify_hash` are not in the auto-generated set today.** The
   generator only fully emits dispatch for `import_key` / `export_public_key`.
   For everything else (including ECDSA sign/verify), the *current* recommended
   path is **manual edits** to the `.jinja` template -- i.e., editing upstream
   files. Same fork problem, worse version-skew problem.

### What linker wrapping replaces in that picture

When no driver matches, the generated `psa_crypto_driver_wrappers.h` calls
`mbedtls_psa_ecdsa_sign_hash` / `..._verify_hash` (the built-in software entry
points) as the fallback. Those are external symbols at link time.

`-Wl,--wrap=mbedtls_psa_ecdsa_sign_hash` rewrites every reference to
`mbedtls_psa_ecdsa_sign_hash` to point at
`__wrap_mbedtls_psa_ecdsa_sign_hash`, and exposes the original under
`__real_mbedtls_psa_ecdsa_sign_hash`. So the wrapper:

- Sees the call the dispatcher would have routed to software.
- If the (curve, key bit-size) pair is one uECC implements
  (secp192r1 / secp224r1 / secp256r1 / secp256k1) and the algorithm is
  randomized ECDSA on sign or any ECDSA on verify, runs uECC.
- Otherwise calls `__real_*` and the software path runs unmodified -- which
  is also how RFC 6979 deterministic ECDSA sign and Brainpool/Edwards/etc.
  curves are handled.

### Why `NO_FALLBACK` also wraps `import_key`

Wrapping `mbedtls_psa_ecdsa_{sign,verify}_hash` is necessary but not
sufficient to actually drop the software ECC stack from the binary. The
bootloader (and any PSA caller) reaches the built-in via `psa_import_key()`
for the verifying key:

    psa_import_key
      -> psa_driver_wrapper_import_key
        -> mbedtls_psa_ecp_import_key       (psa_crypto_ecp.c)
          -> mbedtls_psa_ecp_load_representation
            -> mbedtls_ecp_point_read_binary  (ecp.c)
              -> bignum.c, bignum_core.c, ecp_curves.c, ecdsa.c

Even with the sign/verify wraps in place, this import path keeps the entire
software ECP/bignum chain alive: `psa_crypto_ecp.c` transitively references
`mbedtls_ecdsa_sign`, `mbedtls_ecp_group_load`, `mbedtls_mpi_init`, etc.,
each of which drags in its own object file.

Under `ATM_UECC_PSA_NO_FALLBACK` we therefore add a third
`-Wl,--wrap=mbedtls_psa_ecp_import_key` and provide a uECC-shaped
`__wrap_*` that validates the PSA encoding and copies the bytes through
(for short-Weierstrass keys, the import format and the storage format are
identical -- uncompressed SEC1 for public, raw scalar for key pair). With
this wrap in place, `psa_crypto_ecp.c` has no live external caller and the
linker drops the whole chain.

**Caveat.** The lightweight stub does not run
`mbedtls_ecp_point_read_binary`'s on-curve check. A malformed public key is
therefore not rejected at `psa_import_key()` time; it surfaces later as
`PSA_ERROR_INVALID_SIGNATURE` from `psa_verify_hash()`. This is acceptable
for the bootloader (where the public key is built into the image) but is
part of the contract of `NO_FALLBACK` -- do not enable it in images that
import attacker-controlled ECC public keys.

### Trade-offs to be aware of

| Aspect | Descriptor (the "right" way) | `--wrap` (what we did) |
|---|---|---|
| Discoverability | Driver advertised in the build, visible to the generator | Invisible to the PSA dispatcher; only the linker knows |
| Dispatch cost | Inlined `if` in `static inline` | Indirect through wrap (LTO can re-inline on most toolchains) |
| Multi-driver coexistence | Generator orders capabilities and emits `NOT_SUPPORTED` chain | "First wrapper wins"; if another driver also wraps the same symbol, the last `--wrap` flag on the link line wins, which is fragile |
| Upstream coupling | Need to fork `tf-psa-crypto` | None -- only depends on the names of the built-in `mbedtls_psa_ecdsa_*` symbols |
| Survives Mbed TLS upgrade | Yes (descriptors are stable) | Only as long as the built-in symbol names stay the same |

The last row is the honest cost: if a future Mbed TLS release renames or
inlines `mbedtls_psa_ecdsa_sign_hash` away, the wrap flags become silent
no-ops. That maintenance risk should be re-verified on every Mbed TLS bump.

### Migration path if upstream catches up

If/when `tf-psa-crypto` finishes auto-generating dispatch for ECDSA entry
points and exposes a way to register out-of-tree descriptors (the
`psa-driver-wrappers-codegen-migration-guide.md` is the in-progress design
for exactly this), the swap is mechanical:

- Drop the `-Wl,--wrap=...` flags from `CMakeLists.txt` (all three:
  `mbedtls_psa_ecdsa_sign_hash`, `..._verify_hash`, and -- if `NO_FALLBACK`
  was used -- `mbedtls_psa_ecp_import_key`).
- Rename `__wrap_mbedtls_psa_ecdsa_*` to `atm_transparent_{sign,verify}_hash`
  to match descriptor convention.
- Add the descriptor and a small `psa_atm_uecc.h` exposing the entry-point
  prototypes. Descriptor-based dispatch for `import_key` is already
  auto-generated by `tf-psa-crypto` today (the limitation is on
  `sign_hash`/`verify_hash`), so the `import_key` workaround simply
  disappears in that world.

The body of `psa_ecc.c` -- the curve/key-size matching and the `uECC_sign()`
/ `uECC_verify()` calls -- stays the same.

/* Copyright 2014, Kenneth MacKay. Licensed under the BSD 2-clause license. */
/* Copyright 2025, Atmosic */

#include <string.h>
#include "uECC_ll.h"
#include "uECC_vli.h"
#include "uECC_internal.h"

#if uECC_VLI_NATIVE_LITTLE_ENDIAN
#error "BLE requires using uECC with big endian keys"
#endif

#define uECC_WORD_SIZE 4

#if __STDC_VERSION__ >= 199901L
    #define RESTRICT restrict
#else
    #define RESTRICT
#endif

#define SUPPORTS_INT128 0

#define MAX_TRIES 64

#define HIGH_BIT_SET 0x80000000
#define uECC_WORD_BITS 32
#define uECC_WORD_BITS_SHIFT 5
#define uECC_WORD_BITS_MASK 0x01F

#define uECC_secp160r1_WORDS 5
#define uECC_secp192r1_WORDS 6
#define uECC_secp256r1_WORDS 8
#define uECC_secp256k1_WORDS 8
#define uECC_secp224r1_WORDS 7

#define uECC_secp160r1_N_WORDS 6
#define uECC_secp192r1_N_WORDS 6
#define uECC_secp256r1_N_WORDS 8
#define uECC_secp256k1_N_WORDS 8
#define uECC_secp224r1_N_WORDS 7

#define Curve_P_uECC_secp160r1 {0x7FFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}
#define Curve_P_uECC_secp192r1 {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}
#define Curve_P_uECC_secp256r1 {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, \
                                0x00000000, 0x00000000, 0x00000001, 0xFFFFFFFF}
#define Curve_P_uECC_secp256k1 {0xFFFFFC2F, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, \
                                0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}
#define Curve_P_uECC_secp224r1 {0x00000001, 0x00000000, 0x00000000, 0xFFFFFFFF, \
                                0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}

#define Curve_B_uECC_secp160r1 {0xC565FA45, 0x81D4D4AD, 0x65ACF89F, 0x54BD7A8B, 0x1C97BEFC}
#define Curve_B_uECC_secp192r1 {0xC146B9B1, 0xFEB8DEEC, 0x72243049, 0x0FA7E9AB, 0xE59C80E7, 0x64210519}
#define Curve_B_uECC_secp256r1 {0x27D2604B, 0x3BCE3C3E, 0xCC53B0F6, 0x651D06B0, \
                                0x769886BC, 0xB3EBBD55, 0xAA3A93E7, 0x5AC635D8}
#define Curve_B_uECC_secp256k1 {0x00000007, 0x00000000, 0x00000000, 0x00000000, \
                                0x00000000, 0x00000000, 0x00000000, 0x00000000}
#define Curve_B_uECC_secp224r1 {0x2355FFB4, 0x270B3943, 0xD7BFD8BA, 0x5044B0B7, \
                                0xF5413256, 0x0C04B3AB, 0xB4050A85}

#define Curve_G_uECC_secp160r1 { \
    {0x13CBFC82, 0x68C38BB9, 0x46646989, 0x8EF57328, 0x4A96B568}, \
    {0x7AC5FB32, 0x04235137, 0x59DCC912, 0x3168947D, 0x23A62855}}

#define Curve_G_uECC_secp192r1 { \
    {0x82FF1012, 0xF4FF0AFD, 0x43A18800, 0x7CBF20EB, 0xB03090F6, 0x188DA80E}, \
    {0x1E794811, 0x73F977A1, 0x6B24CDD5, 0x631011ED, 0xFFC8DA78, 0x07192B95}}

#define Curve_G_uECC_secp256r1 { \
    {0xD898C296, 0xF4A13945, 0x2DEB33A0, 0x77037D81,  \
     0x63A440F2, 0xF8BCE6E5, 0xE12C4247, 0x6B17D1F2}, \
    {0x37BF51F5, 0xCBB64068, 0x6B315ECE, 0x2BCE3357,  \
     0x7C0F9E16, 0x8EE7EB4A, 0xFE1A7F9B, 0x4FE342E2}}

#define Curve_G_uECC_secp256k1 { \
    {0x16F81798, 0x59F2815B, 0x2DCE28D9, 0x029BFCDB,  \
     0xCE870B07, 0x55A06295, 0xF9DCBBAC, 0x79BE667E}, \
    {0xFB10D4B8, 0x9C47D08F, 0xA6855419, 0xFD17B448,  \
     0x0E1108A8, 0x5DA4FBFC, 0x26A3C465, 0x483ADA77}}

#define Curve_G_uECC_secp224r1 { \
    {0x115C1D21, 0x343280D6, 0x56C21122, 0x4A03C1D3, \
     0x321390B9, 0x6BB4BF7F, 0xB70E0CBD}, \
    {0x85007E34, 0x44D58199, 0x5A074764, 0xCD4375A0, \
     0x4C22DFE6, 0xB5F723FB, 0xBD376388}}

#define Curve_N_uECC_secp160r1 {0xCA752257, 0xF927AED3, 0x0001F4C8, 0x00000000, 0x00000000, 0x00000001}
#define Curve_N_uECC_secp192r1 {0xB4D22831, 0x146BC9B1, 0x99DEF836, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}
#define Curve_N_uECC_secp256r1 {0xFC632551, 0xF3B9CAC2, 0xA7179E84, 0xBCE6FAAD, \
                                0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF}
#define Curve_N_uECC_secp256k1 {0xD0364141, 0xBFD25E8C, 0xAF48A03B, 0xBAAEDCE6, \
                                0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}
#define Curve_N_uECC_secp224r1 {0x5C5C2A3D, 0x13DD2945, 0xE0B8F03E, 0xFFFF16A2, \
                                0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}

#define uECC_WORDS uECC_CONCAT(uECC_CURVE, _WORDS)
#define uECC_N_WORDS uECC_CONCAT(uECC_CURVE, _N_WORDS)

typedef struct EccPoint {
    uECC_word_t x[uECC_WORDS];
    uECC_word_t y[uECC_WORDS];
} EccPoint;

static const uECC_word_t curve_p[uECC_WORDS] = uECC_CONCAT(Curve_P_, uECC_CURVE);
static const uECC_word_t curve_b[uECC_WORDS] = uECC_CONCAT(Curve_B_, uECC_CURVE);
static const EccPoint curve_G = uECC_CONCAT(Curve_G_, uECC_CURVE);
static const uECC_word_t curve_n[uECC_N_WORDS] = uECC_CONCAT(Curve_N_, uECC_CURVE);

static int default_RNG(uint8_t *dest, unsigned size) {
    return 0;
}


static uECC_RNG_Function g_rng_function = &default_RNG;

void uECC_set_rng_ll(uECC_RNG_Function rng_function) {
    g_rng_function = rng_function;
}


/* ------ Point operations ------ */

/* Returns 1 if 'point' is the point at infinity, 0 otherwise. */
static cmpresult_t EccPoint_isZero(const EccPoint *point) {
    return (uECC_vli_isZero(point->x, uECC_WORDS) && uECC_vli_isZero(point->y, uECC_WORDS));
}


/* Point multiplication algorithm using Montgomery's ladder with co-Z coordinates.
From http://eprint.iacr.org/2011/338.pdf
*/

/* Computes result = x^3 + ax + b. result must not overlap x. */
static void curve_x_side(uECC_word_t * RESTRICT result, const uECC_word_t * RESTRICT x) {
#if (uECC_ENUM == uECC_secp256k1_enum)
    uECC_vli_modSquare_fast(result, x, uECC_CURVE()); /* r = x^2 */
    uECC_vli_modMult_fast(result, result, x, uECC_CURVE()); /* r = x^3 */
    uECC_vli_modAdd(result, result, curve_b, curve_p, uECC_WORDS); /* r = x^3 + b */
#else
    uECC_word_t _3[uECC_WORDS] = {3}; /* -a = 3 */

    uECC_vli_modSquare_fast(result, x, uECC_CURVE()); /* r = x^2 */
    uECC_vli_modSub(result, result, _3, curve_p, uECC_WORDS); /* r = x^2 - 3 */
    uECC_vli_modMult_fast(result, result, x, uECC_CURVE()); /* r = x^3 - 3x */
    uECC_vli_modAdd(result, result, curve_b, curve_p, uECC_WORDS); /* r = x^3 - 3x + b */
#endif
}

enum
{
  ECC_POINT_MULT_STATE_INIT,
  ECC_POINT_MULT_STATE_BIT_ADDC,
  ECC_POINT_MULT_STATE_BIT_ADD,
  ECC_POINT_MULT_STATE_EXIT_ADDC,
  ECC_POINT_MULT_STATE_EXIT_ADD,
  ECC_POINT_MULT_STATE_COMPLETE
};

typedef struct
{
  uint8_t     state;
  uECC_word_t Rx[2][uECC_WORDS];
  uECC_word_t Ry[2][uECC_WORDS];
  bitcount_t  i;
} EccPointMultCtx;

static int EccPoint_mult(EccPointMultCtx *pCtx,
                         EccPoint * RESTRICT result,
                         const EccPoint * RESTRICT point,
                         const uECC_word_t * RESTRICT scalar,
                         const uECC_word_t * RESTRICT initialZ,
                         bitcount_t numBits) {
    uECC_word_t nb;
    uECC_word_t z[uECC_WORDS];

    switch (pCtx->state) {
        case ECC_POINT_MULT_STATE_INIT:
            uECC_vli_set(pCtx->Rx[1], point->x, uECC_WORDS);
            uECC_vli_set(pCtx->Ry[1], point->y, uECC_WORDS);

            XYcZ_initial_double(pCtx->Rx[1], pCtx->Ry[1], pCtx->Rx[0], pCtx->Ry[0], initialZ, uECC_CURVE());

            pCtx->i = numBits - 2;
            pCtx->state = ECC_POINT_MULT_STATE_BIT_ADDC;
            return 0;

        case ECC_POINT_MULT_STATE_BIT_ADDC:
            nb = !uECC_vli_testBit(scalar, pCtx->i);
            XYcZ_addC(pCtx->Rx[1 - nb], pCtx->Ry[1 - nb], pCtx->Rx[nb], pCtx->Ry[nb], uECC_CURVE());

            pCtx->state = ECC_POINT_MULT_STATE_BIT_ADD;
            return 0;

        case ECC_POINT_MULT_STATE_BIT_ADD:
            nb = !uECC_vli_testBit(scalar, pCtx->i);
            XYcZ_add(pCtx->Rx[nb], pCtx->Ry[nb], pCtx->Rx[1 - nb], pCtx->Ry[1 - nb], uECC_CURVE());

            pCtx->i--;
            pCtx->state = (pCtx->i > 0) ? ECC_POINT_MULT_STATE_BIT_ADDC : ECC_POINT_MULT_STATE_EXIT_ADDC;
            return 0;

        case ECC_POINT_MULT_STATE_EXIT_ADDC:
            nb = !uECC_vli_testBit(scalar, 0);
            XYcZ_addC(pCtx->Rx[1 - nb], pCtx->Ry[1 - nb], pCtx->Rx[nb], pCtx->Ry[nb], uECC_CURVE());

            pCtx->state = ECC_POINT_MULT_STATE_EXIT_ADD;
            return 0;

        case ECC_POINT_MULT_STATE_EXIT_ADD:
            nb = !uECC_vli_testBit(scalar, 0);

            /* Find final 1/Z value. */
            uECC_vli_modSub(z, pCtx->Rx[1], pCtx->Rx[0], curve_p, uECC_WORDS);   /* X1 - X0 */
            uECC_vli_modMult_fast(z, z, pCtx->Ry[1 - nb], uECC_CURVE());       /* Yb * (X1 - X0) */
            uECC_vli_modMult_fast(z, z, point->x, uECC_CURVE());               /* xP * Yb * (X1 - X0) */
            uECC_vli_modInv(z, z, curve_p, uECC_WORDS);                      /* 1 / (xP * Yb * (X1 - X0)) */
            uECC_vli_modMult_fast(z, z, point->y, uECC_CURVE());               /* yP / (xP * Yb * (X1 - X0)) */
            uECC_vli_modMult_fast(z, z, pCtx->Rx[1 - nb], uECC_CURVE());       /* Xb * yP / (xP * Yb * (X1 - X0)) */
            /* End 1/Z calculation */

            XYcZ_add(pCtx->Rx[nb], pCtx->Ry[nb], pCtx->Rx[1 - nb], pCtx->Ry[1 - nb], uECC_CURVE());
            apply_z(pCtx->Rx[0], pCtx->Ry[0], z, uECC_CURVE());

            uECC_vli_set(result->x, pCtx->Rx[0], uECC_WORDS);
            uECC_vli_set(result->y, pCtx->Ry[0], uECC_WORDS);

            pCtx->state = ECC_POINT_MULT_STATE_COMPLETE;
            return 1;

        case ECC_POINT_MULT_STATE_COMPLETE:
        default:
            return 1;
    }
}

enum
{
  ECC_MAKE_KEY_STATE_INIT,
  ECC_MAKE_KEY_STATE_ECC_POINT_MULT,
  ECC_MAKE_KEY_STATE_EXIT,
  ECC_MAKE_KEY_STATE_COMPLETE
};

typedef struct EccMakeKeyCtx {
  uint8_t         state;
  uECC_word_t     private[uECC_WORDS];
  EccPoint        public;
  uECC_word_t     tmp1[uECC_WORDS];
  uECC_word_t     tmp2[uECC_WORDS];
  uECC_word_t     *p2[2];
  uECC_word_t     carry;

  EccPointMultCtx pointMultCtx;
} EccMakeKeyCtx;

typedef struct EccSharedSecretCtx {
  uECC_word_t     random[uECC_WORDS];
  uECC_word_t     *initial_Z;
  EccPoint        public;
  EccPoint        product;
  uECC_word_t     private[uECC_WORDS];
  uECC_word_t     tmp[uECC_WORDS];
  uECC_word_t     *p2[2];
  uECC_word_t     carry;

  EccPointMultCtx pointMultCtx;
} EccSharedSecretCtx;

typedef union EccCtx {
  EccMakeKeyCtx      makeKey;
  EccSharedSecretCtx sharedSecret;
} EccCtx;

static EccCtx uECC_ctx;

/**************************************************************************************************
  Make Key
**************************************************************************************************/

void uECC_make_key_start(const uint8_t private_key[uECC_BYTES]) {
    memset(&uECC_ctx, 0, sizeof(uECC_ctx));
    uECC_ctx.makeKey.state = ECC_MAKE_KEY_STATE_INIT;
    uECC_vli_bytesToNative(uECC_ctx.makeKey.private, private_key, uECC_BYTES);
}

int uECC_make_key_continue(void) {
    switch (uECC_ctx.makeKey.state) {
        case ECC_MAKE_KEY_STATE_INIT:
            /* Make sure the private key is in the range [1, n-1]. */
            if (uECC_vli_isZero(uECC_ctx.makeKey.private, uECC_WORDS)) {
                return 0;
            }

            if (uECC_vli_cmp(curve_n, uECC_ctx.makeKey.private, uECC_WORDS) != 1) {
                return 0;
            }

            // Regularize the bitcount for the private key so that attackers cannot use a side channel
            // attack to learn the number of leading zeros.
            uECC_ctx.makeKey.p2[0] = uECC_ctx.makeKey.tmp1;
            uECC_ctx.makeKey.p2[1] = uECC_ctx.makeKey.tmp2;
            uECC_ctx.makeKey.carry = uECC_vli_add(uECC_ctx.makeKey.tmp1, uECC_ctx.makeKey.private, curve_n, uECC_WORDS);
            uECC_vli_add(uECC_ctx.makeKey.tmp2, uECC_ctx.makeKey.tmp1, curve_n, uECC_WORDS);

            uECC_ctx.makeKey.pointMultCtx.state = 0;
            uECC_ctx.makeKey.state = ECC_MAKE_KEY_STATE_ECC_POINT_MULT;
            return 0;

        case ECC_MAKE_KEY_STATE_ECC_POINT_MULT:
            if (EccPoint_mult(&uECC_ctx.makeKey.pointMultCtx,
                              &uECC_ctx.makeKey.public,
                              &curve_G,
                              uECC_ctx.makeKey.p2[!uECC_ctx.makeKey.carry],
                              0,
                              (uECC_BYTES * 8) + 1)) {
                uECC_ctx.makeKey.state = ECC_MAKE_KEY_STATE_EXIT;
            }
            return 0;

        case ECC_MAKE_KEY_STATE_EXIT:
            if (EccPoint_isZero(&uECC_ctx.makeKey.public)) {
                uECC_ctx.makeKey.state = ECC_MAKE_KEY_STATE_INIT;
                return 0;
            }

            uECC_ctx.makeKey.state = ECC_MAKE_KEY_STATE_COMPLETE;
            return 1;

        case ECC_MAKE_KEY_STATE_COMPLETE:
        default:
            return 1;
    }
}

void uECC_make_key_complete(uint8_t public_key[uECC_BYTES*2], uint8_t private_key[uECC_BYTES]) {
    uECC_vli_nativeToBytes(private_key, uECC_BYTES, uECC_ctx.makeKey.private);
    uECC_vli_nativeToBytes(public_key, uECC_BYTES, uECC_ctx.makeKey.public.x);
    uECC_vli_nativeToBytes(public_key + uECC_BYTES, uECC_BYTES, uECC_ctx.makeKey.public.y);
}

/**************************************************************************************************
  Validate Key
**************************************************************************************************/

int uECC_valid_public_key_ll(const uint8_t public_key[uECC_BYTES*2]) {
    uECC_word_t tmp1[uECC_WORDS];
    uECC_word_t tmp2[uECC_WORDS];
    EccPoint public;

    uECC_vli_bytesToNative(public.x, public_key, uECC_BYTES);
    uECC_vli_bytesToNative(public.y, public_key + uECC_BYTES, uECC_BYTES);

    // The point at infinity is invalid.
    if (EccPoint_isZero(&public)) {
        return 0;
    }

    // x and y must be smaller than p.
    if (uECC_vli_cmp(curve_p, public.x, uECC_WORDS) != 1 || uECC_vli_cmp(curve_p, public.y, uECC_WORDS) != 1) {
        return 0;
    }

    uECC_vli_modSquare_fast(tmp1, public.y, uECC_CURVE()); /* tmp1 = y^2 */
    curve_x_side(tmp2, public.x); /* tmp2 = x^3 + ax + b */

    /* Make sure that y^2 == x^3 + ax + b */
    return (uECC_vli_cmp(tmp1, tmp2, uECC_WORDS) == 0);
}

/**************************************************************************************************
  Shared Secret
**************************************************************************************************/

void uECC_shared_secret_start(const uint8_t public_key[uECC_BYTES*2],
                              const uint8_t private_key[uECC_BYTES]) {
    uECC_word_t tries;

    memset(&uECC_ctx, 0, sizeof(uECC_ctx));

    // Try to get a random initial Z value to improve protection against side-channel
    // attacks. If the RNG fails every time (eg it was not defined), we continue so that
    // uECC_shared_secret() can still work without an RNG defined.
    uECC_ctx.sharedSecret.initial_Z = NULL;
    for (tries = 0; tries < MAX_TRIES; ++tries) {
        if (g_rng_function((uint8_t *)uECC_ctx.sharedSecret.random, sizeof(uECC_ctx.sharedSecret.random)) && !uECC_vli_isZero(uECC_ctx.sharedSecret.random, uECC_WORDS)) {
            uECC_ctx.sharedSecret.initial_Z = uECC_ctx.sharedSecret.random;
            break;
        }
    }

    uECC_vli_bytesToNative(uECC_ctx.sharedSecret.private, private_key, uECC_BYTES);
    uECC_vli_bytesToNative(uECC_ctx.sharedSecret.public.x, public_key, uECC_BYTES);
    uECC_vli_bytesToNative(uECC_ctx.sharedSecret.public.y, public_key + uECC_BYTES, uECC_BYTES);

    // Regularize the bitcount for the private key so that attackers cannot use a side channel
    // attack to learn the number of leading zeros.
    uECC_ctx.sharedSecret.p2[0] = uECC_ctx.sharedSecret.private;
    uECC_ctx.sharedSecret.p2[1] = uECC_ctx.sharedSecret.tmp;
    uECC_ctx.sharedSecret.carry = uECC_vli_add(uECC_ctx.sharedSecret.private, uECC_ctx.sharedSecret.private, curve_n, uECC_WORDS);
    uECC_vli_add(uECC_ctx.sharedSecret.tmp, uECC_ctx.sharedSecret.private, curve_n, uECC_WORDS);

    uECC_ctx.sharedSecret.pointMultCtx.state = 0;
}

int uECC_shared_secret_continue(void) {
    return EccPoint_mult(&uECC_ctx.sharedSecret.pointMultCtx,
                         &uECC_ctx.sharedSecret.product,
                         &uECC_ctx.sharedSecret.public,
                         uECC_ctx.sharedSecret.p2[!uECC_ctx.sharedSecret.carry],
                         uECC_ctx.sharedSecret.initial_Z,
                         (uECC_BYTES * 8) + 1);
}

void uECC_shared_secret_complete(uint8_t secret[uECC_BYTES]) {
    uECC_vli_nativeToBytes(secret, uECC_BYTES, uECC_ctx.sharedSecret.product.x);
}

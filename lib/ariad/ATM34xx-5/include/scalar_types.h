/*
 * Copyright (c) 2026 Atmosic
 *
 * SPDX-License-Identifier: LicenseRef-Atmosic
 */

/* Pipeline scalar precision policy.
 *
 * The entire estimator pipeline computes in a single scalar type, `ereal`,
 * and a matching complex type, `ecplx`. The default build selects `float`:
 * this is the embedded / Cortex-M33 deployment shape, whose image carries
 * zero f64 soft-float and only single-precision libm.
 *
 * Define USE_F64_VALIDATION to select `double`. That build is the host
 * reference the Python ctypes harness (c_unitary_loader.py) binds against
 * and the 63-dataset compare_c_vs_python.py regression validates; it is
 * bit-for-bit identical to the original all-double port (see ER() below).
 *
 * <tgmath.h> is pulled in here so every call site keeps writing the plain
 * names -- sqrt, cos, sin, atan2, exp, log, hypot, floor, ceil, fabs,
 * llrint, cexp, cabs, csqrt, conj, creal, cimag -- and the type-generic
 * macros dispatch to the float variant (sqrtf, cosf, ...) when the
 * argument is `ereal == float`, or the double variant under
 * USE_F64_VALIDATION. No f-suffixed call names are needed in the pipeline.
 *
 * Caveat (see complex override below): glibc's <tgmath.h> on the current
 * toolchain mis-dispatches the libm-calling *complex* macros (cexp, cabs,
 * csqrt) to the double routine even for a `complex float` argument, which
 * silently pulls in f64 soft-float. The real-valued macros dispatch
 * correctly. We therefore pin those three complex names to their f32
 * variants in the float build; conj/creal/cimag dispatch fine and are left
 * to tgmath.
 */
#ifndef SCALAR_TYPES_H
#define SCALAR_TYPES_H

#include <tgmath.h> /* implies <math.h> + <complex.h> type-generic math */

/* <complex.h> defines the bare macro `I` for the imaginary unit, which
 * collides with the `I` (in-phase) struct members of the public ChannelMeas
 * / ChannelMeasI16 API. Capture the imaginary unit as E_I (below) via the
 * underlying _Complex_I and drop the `I` macro so those members compile. No
 * pipeline call site uses bare `I`; they use E_I. */
#undef I

#ifdef USE_F64_VALIDATION
typedef double ereal;
typedef double _Complex ecplx;
#else
typedef float ereal;
typedef float _Complex ecplx;

/* Complex libm dispatch fix (float build only). Keep call sites on the
 * plain names; force the f32 implementation so no double routine leaks in.
 * Under USE_F64_VALIDATION these stay as tgmath's double dispatch, which is
 * bit-for-bit identical to the original all-double port. */
#undef cexp
#define cexp(z) cexpf(z)
#undef cabs
#define cabs(z) cabsf(z)
#undef csqrt
#define csqrt(z) csqrtf(z)
#endif

/* Cast a double-typed literal or expression to the active scalar type.
 *
 * Use this on numeric literals that take part in `ereal` arithmetic or
 * comparisons so the operation stays single-precision in the float build
 * (otherwise a bare `1.5` / `1e-9` would promote the whole expression to
 * double and pull in f64 soft-float). In the USE_F64_VALIDATION build
 * ER(x) is `(double)(double-literal)`, i.e. the identity, so the host
 * reference remains bit-for-bit unchanged.
 *
 * Constants that are already #defines are wrapped at their definition;
 * inline one-off literals flagged by -Wdouble-promotion are wrapped here.
 */
#define ER(x) ((ereal)(x))

/* Pi in the active scalar type. Replaces the per-file M_PI definitions so
 * the constant never appears as a bare double in an ereal expression. */
#define E_PI ER(3.14159265358979323846)

/* Imaginary unit in the active complex type. The standard <complex.h> `I`
 * is `complex double`, so `I * <ereal>` would promote the whole expression
 * to `complex double` and make tgmath dispatch cexp/etc. to the double
 * variant (pulling in f64 soft-float). Casting to `ecplx` first keeps the
 * product single-precision in the float build and identical under
 * USE_F64_VALIDATION. */
#define E_I ((ecplx)_Complex_I)

#endif /* SCALAR_TYPES_H */

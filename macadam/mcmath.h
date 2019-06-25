//
// # -*- coding: utf-8, tab-width: 3 -*-

// mcmath.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/details/mc_math.h>

#ifndef MCMATH_H
#define MCMATH_H

#	if MC_TARGET_CPP98
#	if MC_TARGET_CPP11
#		define mcmath_float_t       ::std::float_t
#		define mcmath_double_t      ::std::double_t
#		define mcmath_fpclassify    ::std::fpclassify
#		define mcmath_isnormal      ::std::isnormal
#		define mcmath_isfinite      ::std::isfinite
#		define mcmath_isinf         ::std::isinf
#		define mcmath_isnan         ::std::isnan
#		define mcmath_signbit       ::std::signbit
#	else
#		define mcmath_float_t       ::float_t
#		define mcmath_double_t      ::double_t
#		define mcmath_fpclassify    ::fpclassify
#		define mcmath_isnormal      ::isnormal
#		define mcmath_isfinite      ::isfinite
#		define mcmath_isinf         ::isinf
#		define mcmath_isnan         ::isnan
#		define mcmath_signbit       ::signbit
#	endif
#	elif MC_TARGET_C99
#		define mcmath_float_t       float_t
#		define mcmath_double_t      double_t
#		define mcmath_fpclassify    fpclassify
#		define mcmath_isnormal      isnormal
#		define mcmath_isfinite      isfinite
#		define mcmath_isinf         isinf
#		define mcmath_isnan         isnan
#		define mcmath_signbit       signbit
#	else
#		define mcmath_float_t       float
#		define mcmath_double_t      double
#		define mcmath_fpclassify(x) 0
#		define mcmath_isnormal(x)   0
#		define mcmath_isfinite(x)   0
#		define mcmath_isinf(x)      0
#		define mcmath_isnan(x)      0
#		define mcmath_signbit(x)    0
#	endif

#	ifdef MC_TARGET_CPP98
#		define mcmath_acos(x)          ::std::acos(x)
#		define mcmath_asin(x)          ::std::asin(x)
#		define mcmath_atan(x)          ::std::atan(x)
#		define mcmath_atan2(x, y)      ::std::atan2(x, y)
#		define mcmath_cos(x)           ::std::cos(x)
#		define mcmath_sin(x)           ::std::sin(x)
#		define mcmath_tan(x)           ::std::tan(x)
#		define mcmath_acosh(x)         ::std::acosh(x)
#		define mcmath_asinh(x)         ::std::asinh(x)
#		define mcmath_atanh(x)         ::std::atanh(x)
#		define mcmath_cosh(x)          ::std::cosh(x)
#		define mcmath_sinh(x)          ::std::sinh(x)
#		define mcmath_tanh(x)          ::std::tanh(x)
#		define mcmath_exp(x)           ::std::exp(x)
#		define mcmath_exp2(x)          ::std::exp2(x)
#		define mcmath_expm1(x)         ::std::expm1(x)
#		define mcmath_log(x)           ::std::log(x)
#		define mcmath_log10(x)         ::std::log10(x)
#		define mcmath_log2(x)          ::std::log2(x)
#	ifndef __APPLE__
#		define mcmath_log1p(x)         ::std::log1p(x)
#	endif
#		define mcmath_logb(x)          ::std::logb(x)
#		define mcmath_ldexp(x, y)      ::std::ldexp(x, y)
#		define mcmath_frexp(x, y)      ::std::frexp(x, y)
#		define mcmath_ilogb(x)         ::std::ilogb(x)
#		define mcmath_scalbn(x, y)     ::std::scalbn(x, y)
#		define mcmath_scalbln(x, y)    ::std::scalbln(x, y)
#	if MC_TARGET_CPP11
#		define mcmath_fabs(x)          ::std::fabs(x)
#		define mcmath_cbrt(x)          ::std::cbrt(x)
#		define mcmath_hypot(x, y)      ::std::hypot(x, y)
#		define mcmath_hypotc(x, y, z)  ::std::hypot(x, y, z)
#		define mcmath_pow(x, y)        ::std::pow(x, y)
#		define mcmath_sqrt(x)          ::std::sqrt(x)
#	endif
#		define mcmath_erf(x)           ::std::erf(x)
#		define mcmath_erfc(x)          ::std::erfc(x)
#		define mcmath_lgamma(x)        ::std::lgamma(x)
#		define mcmath_tgamma(x)        ::std::tgamma(x)
#		define mcmath_ceil(x)          ::std::ceil(x)
#		define mcmath_floor(x)         ::std::floor(x)
#		define mcmath_nearbyint(x)     ::std::nearbyint(x)
#		define mcmath_rint(x)          ::std::rint(x)
#		define mcmath_lrint(x)         ::std::lrint(x)
#	if MC_TARGET_CPP11
#		define mcmath_llrint(x)        ::std::llrint(x)
#	else
#		define mcmath_llrint(x)        ::std::lrint(x)
#	endif
#		define mcmath_round(x)         ::std::round(x)
#		define mcmath_lround(x)        ::std::lround(x)
#	if MC_TARGET_CPP11
#		define mcmath_llround(x)       ::std::llround(x)
#	else
#		define mcmath_llround(x)       ::std::lround(x)
#	endif
#		define mcmath_trunc(x)         ::std::trunc(x)
#		define mcmath_fmod(x, y)       ::std::fmod(x, y)
#		define mcmath_remainder(x, y)  ::std::remainder(x, y)
#		define mcmath_remquo(x, y, z)  ::std::remquo(x, y, z)
#		define mcmath_copysign(x, y)   ::std::copysign(x, y)
#		define mcmath_nextafter(x, y)  ::std::nextafter(x, y)
#		define mcmath_nexttoward(x, y) ::std::nexttoward(x, y)
#		define mcmath_fdim(x, y)       ::std::fdim(x, y)
#	if MC_TARGET_CPP11
#		define mcmath_fmax(x, y)       ::std::fmax(x, y)
#		define mcmath_fmin(x, y)       ::std::fmin(x, y)
#	endif
#		define mcmath_fma(x, y, z)     ::std::fma((x),(y), (z))
#		define mcmath_carg(x)          ::std::arg(x)
#		define mcmath_cimag(x)         ::std::imag(x)
#		define mcmath_conj(x)          ::std::conj(x)
#		define mcmath_cproj(x)         ::std::proj(x)
#		define mcmath_creal(x)         ::std::real(x)
#	elif MC_TARGET_HAVE_TGMATH
#		define mcmath_acos(x)          acos(x)
#		define mcmath_asin(x)          asin(x)
#		define mcmath_atan(x)          atan(x)
#		define mcmath_atan2(x, y)      atan2(x, y)
#		define mcmath_cos(x)           cos(x)
#		define mcmath_sin(x)           sin(x)
#		define mcmath_tan(x)           tan(x)
#		define mcmath_acosh(x)         acosh(x)
#		define mcmath_asinh(x)         asinh(x)
#		define mcmath_atanh(x)         atanh(x)
#		define mcmath_cosh(x)          cosh(x)
#		define mcmath_sinh(x)          sinh(x)
#		define mcmath_tanh(x)          tanh(x)
#		define mcmath_exp(x)           exp(x)
#		define mcmath_exp2(x)          exp2(x)
#		define mcmath_expm1(x)         expm1(x)
#		define mcmath_log(x)           log(x)
#		define mcmath_log10(x)         log10(x)
#		define mcmath_log2(x)          log2(x)
#	ifndef __APPLE__
#		define mcmath_log1p(x)         log1p(x)
#	endif
#		define mcmath_logb(x)          logb(x)
#		define mcmath_ldexp(x, y)      ldexp(x, y)
#		define mcmath_frexp(x, y)      frexp(x, y)
#		define mcmath_ilogb(x)         ilogb(x)
#		define mcmath_scalbn(x, y)     scalbn(x, y)
#		define mcmath_scalbln(x, y)    scalbln(x, y)
#		define mcmath_fabs(x)          fabs(x)
#		define mcmath_cbrt(x)          cbrt(x)
#		define mcmath_hypot(x, y)      hypot(x, y)
#		define mcmath_pow(x, y)        pow(x, y)
#		define mcmath_sqrt(x)          sqrt(x)
#		define mcmath_erf(x)           erf(x)
#		define mcmath_erfc(x)          erfc(x)
#		define mcmath_lgamma(x)        lgamma(x)
#		define mcmath_tgamma(x)        tgamma(x)
#		define mcmath_ceil(x)          ceil(x)
#		define mcmath_floor(x)         floor(x)
#		define mcmath_nearbyint(x)     nearbyint(x)
#		define mcmath_rint(x)          rint(x)
#		define mcmath_lrint(x)         lrint(x)
#		define mcmath_llrint(x)        llrint(x)
#		define mcmath_round(x)         round(x)
#		define mcmath_lround(x)        lround(x)
#		define mcmath_llround(x)       llround(x)
#		define mcmath_trunc(x)         trunc(x)
#		define mcmath_fmod(x, y)       fmod(x, y)
#		define mcmath_remainder(x, y)  remainder(x, y)
#		define mcmath_remquo(x, y, z)  remquo(x, y, z)
#		define mcmath_copysign(x, y)   copysign(x, y)
#		define mcmath_nextafter(x, y)  nextafter(x, y)
#		define mcmath_nexttoward(x, y) nexttoward(x, y)
#		define mcmath_fdim(x, y)       fdim(x, y)
#		define mcmath_fmax(x, y)       fmax(x, y)
#		define mcmath_fmin(x, y)       fmin(x, y)
#		define mcmath_fma(x, y, z)     fma((x),(y), (z))
#		define mcmath_carg(x)          carg(x)
#		define mcmath_cimag(x)         cimag(x)
#		define mcmath_conj(x)          conj(x)
#		define mcmath_cproj(x)         cproj(x)
#		define mcmath_creal(x)         creal(x)
#	endif

#pragma mark - mcmath_imod -

#	ifndef mcmath_imod
#	define mcmath_imod(x, y) ((x) % (y))
#	endif

#pragma mark - mcmath_ipmod -

#	ifndef mcmath_ipmod
#	define mcmath_ipmod(x, y) ((((x) % (y)) + (y)) % (y))
#	endif

#pragma mark - mcmath_acos -

/*! Computes the arc cosine of x.
 *
 * \brief Computing the principle value of the arc cosine of x.
 *        The result is within the range [0, pi].
 *        - If |x| > 1 NAN is returned and an exception is raised.
 *        - If x = 1 +0 is returned.
 *
 * <macro T> inline T mcmath_acos(T x);
 *
 * \param x Cosine of x.
 * \result  Arc cosine of x.
 *
 */
#	ifndef mcmath_acos
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_acos              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_acos<float>       (const float& x)       { return ::acosf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_acos<double>      (const double& x)      { return ::acos(x);           }
template <>        MC_TARGET_INLINE long double mcmath_acos<long double> (const long double& x) { return ::acosl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_acos (float x)       { return acosf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_acos (double x)      { return acos(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_acos (long double x) { return acosl(x); }
#	elif MC_TARGET_C11
#	define mcmath_acos(x) _Generic(x \
	, float       : acosf \
	, double      : acos  \
	, long double : acosl \
) (x)
#	else
#	define mcmath_acos(x) \
	( \
		  sizeof(x) == sizeof(float)       ? acosf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? acos  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? acosl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_asin -

/*! Computes the arc sine of x.
 *
 * \brief Computing the principle value of the arc sine of x.
 *        The result is within the range [-pi/2, +pi/2].
 *        - If |x| > 1 NAN is returned and an exception is raised.
 *        - If x = +-0 +-0 is returned.
 *
 * <macro T> inline T mcmath_asin(T x);
 *
 * \param x Sine of x.
 * \result  Arc sine of x.
 *
 */
#	ifndef mcmath_asin
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_asin              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_asin<float>       (const float& x)       { return ::asinf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_asin<double>      (const double& x)      { return ::asin(x);           }
template <>        MC_TARGET_INLINE long double mcmath_asin<long double> (const long double& x) { return ::asinl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_asin (float x)       { return asinf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_asin (double x)      { return asin(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_asin (long double x) { return asinl(x); }
#	elif MC_TARGET_C11
#	define mcmath_asin(x) _Generic(x \
	, float       : asinf \
	, double      : asin  \
	, long double : asinl \
) (x)
#	else
#	define mcmath_asin(x) \
	( \
		  sizeof(x) == sizeof(float)       ? asinf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? asin  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? asinl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atan -

#	ifndef mcmath_atan
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atan              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atan<float>       (const float& x)       { return ::atanf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_atan<double>      (const double& x)      { return ::atan(x);           }
template <>        MC_TARGET_INLINE long double mcmath_atan<long double> (const long double& x) { return ::atanl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_atan (float x)       { return atanf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_atan (double x)      { return atan(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_atan (long double x) { return atanl(x); }
#	elif MC_TARGET_C11
#	define mcmath_atan(x) _Generic(x \
	, float       : atanf \
	, double      : atan  \
	, long double : atanl \
) (x)
#	else
#	define mcmath_atan(x) \
	( \
		  sizeof(x) == sizeof(float)       ? atanf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? atan  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? atanl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atan2 -

#	ifndef mcmath_atan2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atan2              (const T& y, const T& x)                     { mc_cast(void, y); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atan2<float>       (const float& y, const float& x)             { return ::atan2f(y, x);                        }
template <>        MC_TARGET_INLINE double      mcmath_atan2<double>      (const double& y, const double& x)           { return ::atan2(y, x);                         }
template <>        MC_TARGET_INLINE long double mcmath_atan2<long double> (const long double& y, const long double& x) { return ::atan2l(y, x);                        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_atan2 (float y, float x)             { return atan2f(y, x); }
static MC_TARGET_OVERLOADABLE double      mcmath_atan2 (double y, double x)           { return atan2(y, x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_atan2 (long double y, long double x) { return atan2l(y, x); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_atan2(y, x) _Generic(x \
	, float       : atan2f \
	, double      : atan2  \
	, long double : atan2l \
) (y, mc_cast_exp(MC_TARGET_TYPEOF(y), x))
#	else
#	define mcmath_atan2(y, x) \
	( \
		  sizeof(x) == sizeof(float)       ? atan2f (mc_cast_exp(float, y), mc_cast_exp(float, x))             \
		: sizeof(x) == sizeof(double)      ? atan2  (mc_cast_exp(double, y), mc_cast_exp(double, x))           \
		: sizeof(x) == sizeof(long double) ? atan2l (mc_cast_exp(long double, y), mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cos -

#	ifndef mcmath_cos
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cos              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cos<float>       (const float& x)       { return ::cosf(x);           }
template <>        MC_TARGET_INLINE double      mcmath_cos<double>      (const double& x)      { return ::cos(x);            }
template <>        MC_TARGET_INLINE long double mcmath_cos<long double> (const long double& x) { return ::cosl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_cos (float x)       { return cosf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_cos (double x)      { return cos(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_cos (long double x) { return cosl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cos(x) _Generic(x \
	, float       : cosf \
	, double      : cos  \
	, long double : cosl \
) (x)
#	else
#	define mcmath_cos(x) \
	( \
		  sizeof(x) == sizeof(float)       ? cosf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? cos  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? cosl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sin -

#	ifndef mcmath_sin
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sin              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sin<float>       (const float& x)       { return ::sinf(x);           }
template <>        MC_TARGET_INLINE double      mcmath_sin<double>      (const double& x)      { return ::sin(x);            }
template <>        MC_TARGET_INLINE long double mcmath_sin<long double> (const long double& x) { return ::sinl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_sin (float x)       { return sinf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_sin (double x)      { return sin(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_sin (long double x) { return sinl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sin(x) _Generic(x \
	, float       : sinf \
	, double      : sin  \
	, long double : sinl \
) (x)
#	else
#	define mcmath_sin(x) \
	( \
		  sizeof(x) == sizeof(float)       ? sinf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? sin  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? sinl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tan -

#	ifndef mcmath_tan
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tan              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tan<float>       (const float& x)       { return ::tanf(x);           }
template <>        MC_TARGET_INLINE double      mcmath_tan<double>      (const double& x)      { return ::tan(x);            }
template <>        MC_TARGET_INLINE long double mcmath_tan<long double> (const long double& x) { return ::tanl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_tan (float x)       { return tanf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_tan (double x)      { return tan(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_tan (long double x) { return tanl(x); }
#	elif MC_TARGET_C11
#	define mcmath_tan(x) _Generic(x \
	, float       : tanf \
	, double      : tan  \
	, long double : tanl \
) (x)
#	else
#	define mcmath_tan(x) \
	( \
		  sizeof(x) == sizeof(float)       ? tanf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? tan  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? tanl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_acosh -

#	ifndef mcmath_acosh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_acosh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_acosh<float>       (const float& x)       { return ::acoshf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_acosh<double>      (const double& x)      { return ::acosh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_acosh<long double> (const long double& x) { return ::acoshl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_acosh (float x)       { return acoshf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_acosh (double x)      { return acosh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_acosh (long double x) { return acoshl(x); }
#	elif MC_TARGET_C11
#	define mcmath_acosh(x) _Generic(x \
	, float       : acoshf \
	, double      : acosh  \
	, long double : acoshl \
) (x)
#	else
#	define mcmath_acosh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? acoshf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? acosh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? acoshl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_asinh -

#	ifndef mcmath_asinh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_asinh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_asinh<float>       (const float& x)       { return ::asinhf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_asinh<double>      (const double& x)      { return ::asinh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_asinh<long double> (const long double& x) { return ::asinhl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_asinh (float x)       { return asinhf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_asinh (double x)      { return asinh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_asinh (long double x) { return asinhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_asinh(x) _Generic(x \
	, float       : asinhf \
	, double      : asinh  \
	, long double : asinhl \
) (x)
#	else
#	define mcmath_asinh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? asinhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? asinh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? asinhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atanh -

#	ifndef mcmath_atanh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atanh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atanh<float>       (const float& x)       { return ::atanhf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_atanh<double>      (const double& x)      { return ::atanh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_atanh<long double> (const long double& x) { return ::atanhl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_atanh (float x)       { return atanhf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_atanh (double x)      { return atanh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_atanh (long double x) { return atanhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_atanh(x) _Generic(x \
	, float       : atanhf \
	, double      : atanh  \
	, long double : atanhl \
) (x)
#	else
#	define mcmath_atanh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? atanhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? atanh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? atanhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cosh -

#	ifndef mcmath_cosh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cosh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cosh<float>       (const float& x)       { return ::coshf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_cosh<double>      (const double& x)      { return ::cosh(x);           }
template <>        MC_TARGET_INLINE long double mcmath_cosh<long double> (const long double& x) { return ::coshl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_cosh (float x)       { return coshf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_cosh (double x)      { return cosh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_cosh (long double x) { return coshl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cosh(x) _Generic(x \
	, float       : coshf \
	, double      : cosh  \
	, long double : coshl \
) (x)
#	else
#	define mcmath_cosh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? coshf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? cosh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? coshl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sinh -

#	ifndef mcmath_sinh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sinh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sinh<float>       (const float& x)       { return ::sinhf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_sinh<double>      (const double& x)      { return ::sinh(x);           }
template <>        MC_TARGET_INLINE long double mcmath_sinh<long double> (const long double& x) { return ::sinhl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_sinh (float x)       { return sinhf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_sinh (double x)      { return sinh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_sinh (long double x) { return sinhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sinh(x) _Generic(x \
	, float       : sinhf \
	, double      : sinh  \
	, long double : sinhl \
) (x)
#	else
#	define mcmath_sinh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? sinhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? sinh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? sinhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tanh -

#	ifndef mcmath_tanh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tanh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tanh<float>       (const float& x)       { return ::tanhf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_tanh<double>      (const double& x)      { return ::tanh(x);           }
template <>        MC_TARGET_INLINE long double mcmath_tanh<long double> (const long double& x) { return ::tanhl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_tanh (float x)       { return tanhf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_tanh (double x)      { return tanh(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_tanh (long double x) { return tanhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_tanh(x) _Generic(x \
	, float       : tanhf \
	, double      : tanh  \
	, long double : tanhl \
) (x)
#	else
#	define mcmath_tanh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? tanhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? tanh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? tanhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_exp -

#	ifndef mcmath_exp
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_exp              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_exp<float>       (const float& x)       { return ::expf(x);           }
template <>        MC_TARGET_INLINE double      mcmath_exp<double>      (const double& x)      { return ::exp(x);            }
template <>        MC_TARGET_INLINE long double mcmath_exp<long double> (const long double& x) { return ::expl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_exp (float x)       { return expf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_exp (double x)      { return exp(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_exp (long double x) { return expl(x); }
#	elif MC_TARGET_C11
#	define mcmath_exp(x) _Generic(x \
	, float       : expf \
	, double      : exp  \
	, long double : expl \
) (x)
#	else
#	define mcmath_exp(x) \
	( \
		  sizeof(x) == sizeof(float)       ? expf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? exp  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? expl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_exp2 -

#	ifndef mcmath_exp2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_exp2              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_exp2<float>       (const float& x)       { return ::exp2f(x);          }
template <>        MC_TARGET_INLINE double      mcmath_exp2<double>      (const double& x)      { return ::exp2(x);           }
template <>        MC_TARGET_INLINE long double mcmath_exp2<long double> (const long double& x) { return ::exp2l(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_exp2 (float x)       { return exp2f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_exp2 (double x)      { return exp2(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_exp2 (long double x) { return exp2l(x); }
#	elif MC_TARGET_C11
#	define mcmath_exp2(x) _Generic(x \
	, float       : exp2f \
	, double      : exp2  \
	, long double : exp2l \
) (x)
#	else
#	define mcmath_exp2(x) \
	( \
		  sizeof(x) == sizeof(float)       ? exp2f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? exp2  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? exp2l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_exp10 -

#	ifndef mcmath_exp10
#	if MC_TARGET_CPP98

template <class T> MC_TARGET_INLINE T           mcmath_exp10              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_exp10<float>       (const float& x)       { return mc_exp10f(x);        }
template <>        MC_TARGET_INLINE double      mcmath_exp10<double>      (const double& x)      { return mc_exp10(x);         }
template <>        MC_TARGET_INLINE long double mcmath_exp10<long double> (const long double& x) { return mc_exp10l(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_exp10 (float x)       { return mc_exp10f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_exp10 (double x)      { return mc_exp10(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_exp10 (long double x) { return mc_exp10l(x); }
#	elif MC_TARGET_C11
#	define mcmath_exp10(x) _Generic(x \
	, float       : mc_exp10f \
	, double      : mc_exp10  \
	, long double : mc_exp10l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_exp10(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_exp10f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_exp10  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_exp10l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_exp10(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_exp10f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_exp10  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_exp10l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_expm1 -

#	ifndef mcmath_expm1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_expm1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_expm1<float>       (const float& x)       { return ::expm1f(x);         }
template <>        MC_TARGET_INLINE double      mcmath_expm1<double>      (const double& x)      { return ::expm1(x);          }
template <>        MC_TARGET_INLINE long double mcmath_expm1<long double> (const long double& x) { return ::expm1l(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_expm1 (float x)       { return expm1f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_expm1 (double x)      { return expm1(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_expm1 (long double x) { return expm1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_expm1(x) _Generic(x \
	, float       : expm1f \
	, double      : expm1  \
	, long double : expm1l \
) (x)
#	else
#	define mcmath_expm1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? expm1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? expm1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? expm1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log -

#	ifndef mcmath_log
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log<float>       (const float& x)       { return ::logf(x);           }
template <>        MC_TARGET_INLINE double      mcmath_log<double>      (const double& x)      { return ::log(x);            }
template <>        MC_TARGET_INLINE long double mcmath_log<long double> (const long double& x) { return ::logl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log (float x)       { return logf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log (double x)      { return log(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log (long double x) { return logl(x); }
#	elif MC_TARGET_C11
#	define mcmath_log(x) _Generic(x \
	, float       : logf \
	, double      : log  \
	, long double : logl \
) (x)
#	else
#	define mcmath_log(x) \
	( \
		  sizeof(x) == sizeof(float)       ? logf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? log  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? logl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log10 -

#	ifndef mcmath_log10
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log10              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log10<float>       (const float& x)       { return ::log10f(x);         }
template <>        MC_TARGET_INLINE double      mcmath_log10<double>      (const double& x)      { return ::log10(x);          }
template <>        MC_TARGET_INLINE long double mcmath_log10<long double> (const long double& x) { return ::log10l(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log10 (float x)       { return log10f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log10 (double x)      { return log10(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log10 (long double x) { return log10l(x); }
#	elif MC_TARGET_C11
#	define mcmath_log10(x) _Generic(x \
	, float       : log10f \
	, double      : log10  \
	, long double : log10l \
) (x)
#	else
#	define mcmath_log10(x) \
	( \
		  sizeof(x) == sizeof(float)       ? log10f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? log10  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? log10l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log2 -

#	ifndef mcmath_log2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log2              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log2<float>       (const float& x)       { return ::log2f(x);          }
template <>        MC_TARGET_INLINE double      mcmath_log2<double>      (const double& x)      { return ::log2(x);           }
template <>        MC_TARGET_INLINE long double mcmath_log2<long double> (const long double& x) { return ::log2l(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log2 (float x)       { return log2f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log2 (double x)      { return log2(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log2 (long double x) { return log2l(x); }
#	elif MC_TARGET_C11
#	define mcmath_log2(x) _Generic(x \
	, float       : log2f \
	, double      : log2  \
	, long double : log2l \
) (x)
#	else
#	define mcmath_log2(x) \
	( \
		  sizeof(x) == sizeof(float)       ? log2f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? log2  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? log2l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log1p -

#	ifndef mcmath_log1p
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log1p              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log1p<float>       (const float& x)       { return mc_log1pf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_log1p<double>      (const double& x)      { return mc_log1p(x);         }
template <>        MC_TARGET_INLINE long double mcmath_log1p<long double> (const long double& x) { return mc_log1pl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log1p (float x)       { return mc_log1pf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log1p (double x)      { return mc_log1p(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log1p (long double x) { return mc_log1pl(x); }
#	elif MC_TARGET_C11
#	define mcmath_log1p(x) _Generic(x \
	, float       : mc_log1pf \
	, double      : mc_log1p  \
	, long double : mc_log1pl \
) (x)
#	else
#	define mcmath_log1p(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log1pf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log1p  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log1pl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_logp1 -

#	ifndef mcmath_logp1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_logp1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_logp1<float>       (const float& x)       { return mc_logp1f(x);        }
template <>        MC_TARGET_INLINE double      mcmath_logp1<double>      (const double& x)      { return mc_logp1(x);         }
template <>        MC_TARGET_INLINE long double mcmath_logp1<long double> (const long double& x) { return mc_logp1l(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_logp1 (float x)       { return mc_logp1f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_logp1 (double x)      { return mc_logp1(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_logp1 (long double x) { return mc_logp1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_logp1(x) _Generic(x \
	, float       : mc_logp1f \
	, double      : mc_logp1  \
	, long double : mc_logp1l \
) (x)
#	else
#	define mcmath_logp1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_logp1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_logp1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_logp1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log1m -

#	ifndef mcmath_log1m
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log1m              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log1m<float>       (const float& x)       { return mc_log1mf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_log1m<double>      (const double& x)      { return mc_log1m(x);         }
template <>        MC_TARGET_INLINE long double mcmath_log1m<long double> (const long double& x) { return mc_log1ml(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log1m (float x)       { return mc_log1mf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log1m (double x)      { return mc_log1m(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log1m (long double x) { return mc_log1ml(x); }
#	elif MC_TARGET_C11
#	define mcmath_log1m(x) _Generic(x \
	, float       : mc_log1mf \
	, double      : mc_log1m  \
	, long double : mc_log1ml \
) (x)
#	else
#	define mcmath_log1m(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log1mf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log1m  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log1ml (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log1pe -

#	ifndef mcmath_log1pe
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log1pe              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log1pe<float>       (const float& x)       { return mc_log1pef(x);       }
template <>        MC_TARGET_INLINE double      mcmath_log1pe<double>      (const double& x)      { return mc_log1pe(x);        }
template <>        MC_TARGET_INLINE long double mcmath_log1pe<long double> (const long double& x) { return mc_log1pel(x);       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log1pe (float x)       { return mc_log1pef(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log1pe (double x)      { return mc_log1pe(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log1pe (long double x) { return mc_log1pel(x); }
#	elif MC_TARGET_C11
#	define mcmath_log1pe(x) _Generic(x \
	, float       : mc_log1pef \
	, double      : mc_log1pe  \
	, long double : mc_log1pel \
) (x)
#	else
#	define mcmath_log1pe(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log1pef (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log1pe  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log1pel (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#	ifndef mcmath_log1me
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log1me              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log1me<float>       (const float& x)       { return mc_log1mef(x);       }
template <>        MC_TARGET_INLINE double      mcmath_log1me<double>      (const double& x)      { return mc_log1me(x);        }
template <>        MC_TARGET_INLINE long double mcmath_log1me<long double> (const long double& x) { return mc_log1mel(x);       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_log1me (float x)       { return mc_log1mef(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_log1me (double x)      { return mc_log1me(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_log1me (long double x) { return mc_log1mel(x); }
#	elif MC_TARGET_C11
#	define mcmath_log1me(x) _Generic(x \
	, float       : mc_log1mef \
	, double      : mc_log1me  \
	, long double : mc_log1mel \
) (x)
#	else
#	define mcmath_log1me(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log1mef (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log1me  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log1mel (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_logb -

#	ifndef mcmath_logb
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_logb              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_logb<float>       (const float& x)       { return ::logbf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_logb<double>      (const double& x)      { return ::logb(x);           }
template <>        MC_TARGET_INLINE long double mcmath_logb<long double> (const long double& x) { return ::logbl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_logb (float x)       { return logbf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_logb (double x)      { return logb(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_logb (long double x) { return logbl(x); }
#	elif MC_TARGET_C11
#	define mcmath_logb(x) _Generic(x \
	, float       : logbf \
	, double      : logb  \
	, long double : logbl \
) (x)
#	else
#	define mcmath_logb(x) \
	( \
		  sizeof(x) == sizeof(float)       ? logbf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? logb  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? logbl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_modf -

#	ifndef mcmath_modf
#	define mcmath_modf(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? modff (mc_cast_exp(float, x), mc_cast_exp(float *, y))             \
		: sizeof(x) == sizeof(double)      ? modf  (mc_cast_exp(double, x), mc_cast_exp(double *, y))           \
		: sizeof(x) == sizeof(long double) ? modfl (mc_cast_exp(long double, x), mc_cast_exp(long double *, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_ldexp -

#	ifndef mcmath_ldexp
#	define mcmath_ldexp(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? ldexpf (mc_cast_exp(float, x), mc_cast_exp(int, y))       \
		: sizeof(x) == sizeof(double)      ? ldexp  (mc_cast_exp(double, x), mc_cast_exp(int, y))      \
		: sizeof(x) == sizeof(long double) ? ldexpl (mc_cast_exp(long double, x), mc_cast_exp(int, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_frexp -

#	ifndef mcmath_frexp
#	define mcmath_frexp(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? frexpf (mc_cast_exp(float, x), mc_cast_exp(int *, y))       \
		: sizeof(x) == sizeof(double)      ? frexp  (mc_cast_exp(double, x), mc_cast_exp(int *, y))      \
		: sizeof(x) == sizeof(long double) ? frexpl (mc_cast_exp(long double, x), mc_cast_exp(int *, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_ilogb -

#	ifndef mcmath_ilogb
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE int mcmath_ilogb              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE int mcmath_ilogb<float>       (const float& x)       { return ::ilogbf(x);         }
template <>        MC_TARGET_INLINE int mcmath_ilogb<double>      (const double& x)      { return ::ilogb(x);          }
template <>        MC_TARGET_INLINE int mcmath_ilogb<long double> (const long double& x) { return ::ilogbl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_ilogb (float x)       { return ilogbf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_ilogb (double x)      { return ilogb(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_ilogb (long double x) { return ilogbl(x); }
#	elif MC_TARGET_C11
#	define mcmath_ilogb(x) _Generic(x \
	, float       : ilogbf \
	, double      : ilogb  \
	, long double : ilogbl \
) (x)
#	else
#	define mcmath_ilogb(x) \
	( \
		  sizeof(x) == sizeof(float)       ? ilogbf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? ilogb  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? ilogbl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_scalbn -

#	ifndef mcmath_scalbn
#	define mcmath_scalbn(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? scalbnf (mc_cast_exp(float, x), mc_cast_exp(int, y))       \
		: sizeof(x) == sizeof(double)      ? scalbn  (mc_cast_exp(double, x), mc_cast_exp(int, y))      \
		: sizeof(x) == sizeof(long double) ? scalbnl (mc_cast_exp(long double, x), mc_cast_exp(int, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_scalbln -

#	ifndef mcmath_scalbln
#	define mcmath_scalbln(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? scalblnf (mc_cast_exp(float, x), mc_cast_exp(long, y))       \
		: sizeof(x) == sizeof(double)      ? scalbln  (mc_cast_exp(double, x), mc_cast_exp(long, y))      \
		: sizeof(x) == sizeof(long double) ? scalblnl (mc_cast_exp(long double, x), mc_cast_exp(long, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_fabs -

#	ifndef mcmath_fabs
#	if MC_TARGET_CPP98

template <class T> MC_TARGET_INLINE T           mcmath_fabs              (const T& x)           { return ::std::abs(x);   }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE float       mcmath_fabs<float>       (const float& x)       { return ::std::fabsf(x); }
template <>        MC_TARGET_INLINE double      mcmath_fabs<double>      (const double& x)      { return ::std::fabs(x);  }
template <>        MC_TARGET_INLINE long double mcmath_fabs<long double> (const long double& x) { return ::std::fabsl(x); }
#	else
template <>        MC_TARGET_INLINE float       mcmath_fabs<float>       (const float& x)       { return ::fabsf(x);      }
template <>        MC_TARGET_INLINE double      mcmath_fabs<double>      (const double& x)      { return ::fabs(x);       }
template <>        MC_TARGET_INLINE long double mcmath_fabs<long double> (const long double& x) { return ::fabsl(x);      }
#	endif
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_fabs (float x)       { return fabsf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_fabs (double x)      { return fabs(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_fabs (long double x) { return fabsl(x); }
#	elif MC_TARGET_C11
#	define mcmath_fabs(x) _Generic(x \
	, float       : fabsf \
	, double      : fabs  \
	, long double : fabsl \
) (x)
#	else
#	define mcmath_fabs(x) \
	( \
		  sizeof(x) == sizeof(float)       ? fabsf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? fabs  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? fabsl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cbrt -

#	ifndef mcmath_cbrt
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cbrt              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cbrt<float>       (const float& x)       { return ::cbrtf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_cbrt<double>      (const double& x)      { return ::cbrt(x);           }
template <>        MC_TARGET_INLINE long double mcmath_cbrt<long double> (const long double& x) { return ::cbrtl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_cbrt (float x)       { return cbrtf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_cbrt (double x)      { return cbrt(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_cbrt (long double x) { return cbrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cbrt(x) _Generic(x \
	, float       : cbrtf \
	, double      : cbrt  \
	, long double : cbrtl \
) (x)
#	else
#	define mcmath_cbrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? cbrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? cbrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? cbrtl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_fhrt -

#	ifndef mcmath_fhrt
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_fhrt              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_fhrt<float>       (const float& x)       { return mc_fhrtf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_fhrt<double>      (const double& x)      { return mc_fhrt(x);          }
template <>        MC_TARGET_INLINE long double mcmath_fhrt<long double> (const long double& x) { return mc_fhrtl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_fhrt (float x)       { return mc_fhrtf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_fhrt (double x)      { return mc_fhrt(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_fhrt (long double x) { return mc_fhrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_fhrt(x) _Generic(x \
	, float       : mc_fhrtf \
	, double      : mc_fhrt  \
	, long double : mc_fhrtl \
) (x)
#	else
#	define mcmath_fhrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_fhrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_fhrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_fhrtl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_rootn -

#pragma mark - mcmath_rootn -

#	ifndef mcmath_rootn
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_rootn              (const T& x, unsigned int n)           { mc_cast(void, x); mc_cast(void, n); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_rootn<float>       (const float& x, unsigned int n)       { return mc_rootnf(x, n);                       }
template <>        MC_TARGET_INLINE double      mcmath_rootn<double>      (const double& x, unsigned int n)      { return mc_rootn(x, n);                        }
template <>        MC_TARGET_INLINE long double mcmath_rootn<long double> (const long double& x, unsigned int n) { return mc_rootnl(x, n);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_rootn (float x, unsigned int n)       { return mc_rootnf(x, n); }
static MC_TARGET_OVERLOADABLE double      mcmath_rootn (double x, unsigned int n)      { return mc_rootn(x, n);  }
static MC_TARGET_OVERLOADABLE long double mcmath_rootn (long double x, unsigned int n) { return mc_rootnl(x, n); }
#	elif MC_TARGET_C11
#	define mcmath_rootn(x, n) _Generic(x \
	, float       : mc_rootnf \
	, double      : mc_rootn  \
	, long double : mc_rootnl \
) (x, mc_cast_exp(unsigned int, n))
#	else
#	define mcmath_rootn(x, n) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_rootnf (mc_cast_exp(float, x), mc_cast_exp(unsigned int, n))       \
		: sizeof(x) == sizeof(double)      ? mc_rootn  (mc_cast_exp(double, x), mc_cast_exp(unsigned int, n))      \
		: sizeof(x) == sizeof(long double) ? mc_rootnl (mc_cast_exp(long double, x), mc_cast_exp(unsigned int, n)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_hypot -

#	ifndef mcmath_hypot
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_hypot              (const T& x, const T& y)                     { return ::hypot(mc_cast(double, x), mc_cast(double, y)); }
template <>        MC_TARGET_INLINE float       mcmath_hypot<float>       (const float& x, const float& y)             { return ::hypotf(x, y);                                  }
template <>        MC_TARGET_INLINE double      mcmath_hypot<double>      (const double& x, const double& y)           { return ::hypot(x, y);                                   }
template <>        MC_TARGET_INLINE long double mcmath_hypot<long double> (const long double& x, const long double& y) { return ::hypotl(x, y);                                  }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_hypot (float x, float y)             { return hypotf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_hypot (double x, double y)           { return hypot(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_hypot (long double x, long double y) { return hypotl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_hypot(x, y) _Generic(x \
	, float       : hypotf \
	, double      : hypot  \
	, long double : hypotl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_hypot(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? hypotf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? hypot  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? hypotl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#	ifndef mcmath_hypotc
#	if MC_TARGET_CPP98
#	if MC_TARGET_CPP17
template <class T> MC_TARGET_INLINE T           mcmath_hypotc              (const T& x, const T& y, const T& z)                               { return ::std::hypot(mc_cast(double, x), mc_cast(double, y), mc_cast(double, z)); }
template <>        MC_TARGET_INLINE float       mcmath_hypotc<float>       (const float& x, const float& y, const float& z)                   { return ::std::hypot(x, y, z);                                                    }
template <>        MC_TARGET_INLINE double      mcmath_hypotc<double>      (const double& x, const double& y, const double& z)                { return ::std::hypot(x, y, z);                                                    }
template <>        MC_TARGET_INLINE long double mcmath_hypotc<long double> (const long double& x, const long double& y, const long double& z) { return ::std::hypot(x, y, z);                                                    }
#	else
template <class T> MC_TARGET_INLINE T           mcmath_hypotc              (const T& x, const T& y, const T& z)                               { return mc_hypotc(mc_cast(double, x), mc_cast(double, y), mc_cast(double, z));    }
template <>        MC_TARGET_INLINE float       mcmath_hypotc<float>       (const float& x, const float& y, const float& z)                   { return mc_hypotcf(x, y, z);                                                      }
template <>        MC_TARGET_INLINE double      mcmath_hypotc<double>      (const double& x, const double& y, const double& z)                { return mc_hypotc(x, y, z);                                                       }
template <>        MC_TARGET_INLINE long double mcmath_hypotc<long double> (const long double& x, const long double& y, const long double& z) { return mc_hypotcl(x, y, z);                                                      }
#	endif
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_hypotc (float x, float y, float z)                   { return mc_hypotcf(x, y, z); }
static MC_TARGET_OVERLOADABLE double      mcmath_hypotc (double x, double y, double z)                { return mc_hypotc(x, y, z);  }
static MC_TARGET_OVERLOADABLE long double mcmath_hypotc (long double x, long double y, long double z) { return mc_hypotcl(x, y, z); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_hypotc(x, y, z) _Generic(x \
	, float       : mc_hypotcf \
	, double      : mc_hypotc  \
	, long double : mc_hypotcl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y), mc_cast_exp(MC_TARGET_TYPEOF(x), z))
#	else
#	define mcmath_hypotc(x, y, z) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_hypotcf (mc_cast_exp(float, x), mc_cast_exp(float, y), mc_cast_exp(float, z))                   \
		: sizeof(x) == sizeof(double)      ? mc_hypotc  (mc_cast_exp(double, x), mc_cast_exp(double, y), mc_cast_exp(double, z))                \
		: sizeof(x) == sizeof(long double) ? mc_hypotcl (mc_cast_exp(long double, x), mc_cast_exp(long double, y), mc_cast_exp(long double, z)) \
		: 0 \
	)
#	endif
#	endif

#	ifndef mcmath_hypotq
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_hypotq              (const T& x, const T& y)                     { return mc_hypotq(mc_cast(double, x), mc_cast(double, y)); }
template <>        MC_TARGET_INLINE float       mcmath_hypotq<float>       (const float& x, const float& y)             { return mc_hypotqf(x, y);                                  }
template <>        MC_TARGET_INLINE double      mcmath_hypotq<double>      (const double& x, const double& y)           { return mc_hypotq(x, y);                                   }
template <>        MC_TARGET_INLINE long double mcmath_hypotq<long double> (const long double& x, const long double& y) { return mc_hypotql(x, y);                                  }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_hypotq (float x, float y)             { return mc_hypotqf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_hypotq (double x, double y)           { return mc_hypotq(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_hypotq (long double x, long double y) { return mc_hypotql(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_hypotq(x, y) _Generic(x \
	, float       : mc_hypotqf \
	, double      : mc_hypotq  \
	, long double : mc_hypotql \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_hypotq(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_hypotqf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_hypotq  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_hypotql (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_pow -

#	ifndef mcmath_pow
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_pow              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_pow<float>       (const float& x, const float& y)             { return ::powf(x, y);                          }
template <>        MC_TARGET_INLINE double      mcmath_pow<double>      (const double& x, const double& y)           { return ::pow(x, y);                           }
template <>        MC_TARGET_INLINE long double mcmath_pow<long double> (const long double& x, const long double& y) { return ::powl(x, y);                          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_pow (float x, float y)             { return powf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_pow (double x, double y)           { return pow(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_pow (long double x, long double y) { return powl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_pow(x, y) _Generic(x \
	, float       : powf \
	, double      : pow  \
	, long double : powl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_pow(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? powf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? pow  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? powl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#	ifndef mcmath_pow2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_pow2              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_pow2<float>       (const float& x)       { return mc_pow2f(x);         }
template <>        MC_TARGET_INLINE double      mcmath_pow2<double>      (const double& x)      { return mc_pow2(x);          }
template <>        MC_TARGET_INLINE long double mcmath_pow2<long double> (const long double& x) { return mc_pow2l(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_pow2 (float x)       { return mc_pow2f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_pow2 (double x)      { return mc_pow2(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_pow2 (long double x) { return mc_pow2l(x); }
#	elif MC_TARGET_C11
#	define mcmath_pow2(x) _Generic(x \
	, float       : mc_pow2f \
	, double      : mc_pow2  \
	, long double : mc_pow2l \
) (x)
#	else
#	define mcmath_pow2(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_pow2f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_pow2  (mc_cast_exp(double, x))       \
		: sizeof(x) == sizeof(long double) ? mc_pow2l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sqrt -

#	ifndef mcmath_sqrt
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sqrt              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sqrt<float>       (const float& x)       { return ::sqrtf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_sqrt<double>      (const double& x)      { return ::sqrt(x);           }
template <>        MC_TARGET_INLINE long double mcmath_sqrt<long double> (const long double& x) { return ::sqrtl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_sqrt (float x)       { return sqrtf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_sqrt (double x)      { return sqrt(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_sqrt (long double x) { return sqrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sqrt(x) _Generic(x \
	, float       : sqrtf \
	, double      : sqrt  \
	, long double : sqrtl \
) (x)
#	else
#	define mcmath_sqrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? sqrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? sqrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? sqrtl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_rsqrt -

#	ifndef mcmath_rsqrt
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_rsqrt              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_rsqrt<float>       (const float& x)       { return mc_rsqrtf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_rsqrt<double>      (const double& x)      { return mc_rsqrt(x);         }
template <>        MC_TARGET_INLINE long double mcmath_rsqrt<long double> (const long double& x) { return mc_rsqrtl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_rsqrt (float x)       { return mc_rsqrtf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_rsqrt (double x)      { return mc_rsqrt(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_rsqrt (long double x) { return mc_rsqrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_rsqrt(x) _Generic(x \
	, float       : mc_rsqrtf \
	, double      : mc_rsqrt  \
	, long double : mc_rsqrtl \
) (x)
#	else
#	define mcmath_rsqrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_rsqrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_rsqrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_rsqrtl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_erf -

#	ifndef mcmath_erf
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_erf              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_erf<float>       (const float& x)       { return ::erff(x);           }
template <>        MC_TARGET_INLINE double      mcmath_erf<double>      (const double& x)      { return ::erf(x);            }
template <>        MC_TARGET_INLINE long double mcmath_erf<long double> (const long double& x) { return ::erfl(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_erf (float x)       { return erff(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_erf (double x)      { return erf(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_erf (long double x) { return erfl(x); }
#	elif MC_TARGET_C11
#	define mcmath_erf(x) _Generic(x \
	, float       : erff \
	, double      : erf  \
	, long double : erfl \
) (x)
#	else
#	define mcmath_erf(x) \
	( \
		  sizeof(x) == sizeof(float)       ? erff (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? erf  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? erfl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_erfc -

#	ifndef mcmath_erfc
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_erfc              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_erfc<float>       (const float& x)       { return ::erfcf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_erfc<double>      (const double& x)      { return ::erfc(x);           }
template <>        MC_TARGET_INLINE long double mcmath_erfc<long double> (const long double& x) { return ::erfcl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_erfc (float x)       { return erfcf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_erfc (double x)      { return erfc(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_erfc (long double x) { return erfcl(x); }
#	elif MC_TARGET_C11
#	define mcmath_erfc(x) _Generic(x \
	, float       : erfcf \
	, double      : erfc  \
	, long double : erfcl \
) (x)
#	else
#	define mcmath_erfc(x) \
	( \
		  sizeof(x) == sizeof(float)       ? erfcf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? erfc  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? erfcl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lgamma -

#	ifndef mcmath_lgamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_lgamma              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_lgamma<float>       (const float& x)       { return ::lgammaf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_lgamma<double>      (const double& x)      { return ::lgamma(x);         }
template <>        MC_TARGET_INLINE long double mcmath_lgamma<long double> (const long double& x) { return ::lgammal(x);        }
#	elif MC_TARGET_C11
#	define mcmath_lgamma(x) _Generic(x \
	, float       : lgammaf \
	, double      : lgamma  \
	, long double : lgammal \
) (x)
#	else
#	define mcmath_lgamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? lgammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? lgamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? lgammal (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tgamma -

#	ifndef mcmath_tgamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tgamma              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tgamma<float>       (const float& x)       { return ::tgammaf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_tgamma<double>      (const double& x)      { return ::tgamma(x);         }
template <>        MC_TARGET_INLINE long double mcmath_tgamma<long double> (const long double& x) { return ::tgammal(x);        }
#	elif MC_TARGET_C11
#	define mcmath_tgamma(x) _Generic(x \
	, float       : tgammaf \
	, double      : tgamma  \
	, long double : tgammal \
) (x)
#	else
#	define mcmath_tgamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? tgammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? tgamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? tgammal (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_digamma -

#	ifndef mcmath_digamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_digamma              (const T& x)           { mc_cast(void, x); return 0;   }
template <>        MC_TARGET_INLINE float       mcmath_digamma<float>       (const float& x)       { return mc_digammaf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_digamma<double>      (const double& x)      { return mc_digamma(x);         }
template <>        MC_TARGET_INLINE long double mcmath_digamma<long double> (const long double& x) { return mc_digammal(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_digamma (float x)       { return mc_digammaf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_digamma (double x)      { return mc_digamma(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_digamma (long double x) { return mc_digammal(x); }
#	elif MC_TARGET_C11
#	define mcmath_digamma(x) _Generic(x \
	, float       : mc_digammaf \
	, double      : mc_digamma  \
	, long double : mc_digammal \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_digamma(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_digammaf (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_digamma  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_digammal (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_digamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_digammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_digamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_digammal (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_trigamma -

#	ifndef mcmath_trigamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_trigamma              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_trigamma<float>       (const float& x)       { return mc_trigammaf(x);     }
template <>        MC_TARGET_INLINE double      mcmath_trigamma<double>      (const double& x)      { return mc_trigamma(x);      }
template <>        MC_TARGET_INLINE long double mcmath_trigamma<long double> (const long double& x) { return mc_trigammal(x);     }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_trigamma (float x)       { return mc_trigammaf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_trigamma (double x)      { return mc_trigamma(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_trigamma (long double x) { return mc_trigammal(x); }
#	elif MC_TARGET_C11
#	define mcmath_trigamma(x) _Generic(x \
	, float       : mc_trigammaf \
	, double      : mc_trigamma  \
	, long double : mc_trigammal \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_trigamma(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_trigammaf (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_trigamma  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_trigammal (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_trigamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_trigammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_trigamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_trigammal (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#	define mcmath_gamma(x)   mcmath_tgamma(x)
#	define mcmath_gammaln(x) mcmath_lgamma(x)

#pragma mark - mcmath_ceil -

#	ifndef mcmath_ceil
#	if MC_TARGET_C11
#	define mcmath_ceil(x) _Generic(x \
	, float       : ceilf \
	, double      : ceil  \
	, long double : ceill \
) (x)
#	else
#	define mcmath_ceil(x) \
	( \
		  sizeof(x) == sizeof(float)       ? ceilf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? ceil  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? ceill (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_floor -

#	ifndef mcmath_floor
#	if MC_TARGET_C11
#	define mcmath_floor(x) _Generic(x \
	, float       : floorf \
	, double      : floor  \
	, long double : floorl \
) (x)
#	else
#	define mcmath_floor(x) \
	( \
		  sizeof(x) == sizeof(float)       ? floorf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? floor  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? floorl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_nearbyint -

#	ifndef mcmath_nearbyint
#	if MC_TARGET_C11
#	define mcmath_nearbyint(x) _Generic(x \
	, float       : nearbyintf \
	, double      : nearbyint  \
	, long double : nearbyintl \
) (x)
#	else
#	define mcmath_nearbyint(x) \
	( \
		  sizeof(x) == sizeof(float)       ? nearbyintf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? nearbyint  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? nearbyintl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_rint -

#	ifndef mcmath_rint
#	if MC_TARGET_C11
#	define mcmath_rint(x) _Generic(x \
	, float       : rintf \
	, double      : rint  \
	, long double : rintl \
) (x)
#	else
#	define mcmath_rint(x) \
	( \
		  sizeof(x) == sizeof(float)       ? rintf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? rint  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? rintl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lrint -

#	ifndef mcmath_lrint
#	if MC_TARGET_C11
#	define mcmath_lrint(x) _Generic(x \
	, float       : lrintf \
	, double      : lrint  \
	, long double : lrintl \
) (x)
#	else
#	define mcmath_lrint(x) \
	( \
		  sizeof(x) == sizeof(float)       ? lrintf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? lrint  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? lrintl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_llrint -

#	ifndef mcmath_llrint
#	if MC_TARGET_C99
#	if MC_TARGET_C11
#	define mcmath_llrint(x) _Generic(x \
	, float       : llrintf \
	, double      : llrint  \
	, long double : llrintl \
) (x)
#	else
#	define mcmath_llrint(x) \
	( \
		  sizeof(x) == sizeof(float)       ? llrintf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? llrint  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? llrintl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_llrint mcmath_lrint
#	endif
#	endif

#pragma mark - mcmath_round -

#	ifndef mcmath_round
#	if MC_TARGET_C11
#	define mcmath_round(x) _Generic(x \
	, float       : roundf \
	, double      : round  \
	, long double : roundl \
) (x)
#	else
#	define mcmath_round(x) \
	( \
		  sizeof(x) == sizeof(float)       ? roundf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? round  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? roundl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lround -

#	ifndef mcmath_lround
#	if MC_TARGET_C11
#	define mcmath_lround(x) _Generic(x \
	, float       : lroundf \
	, double      : lround  \
	, long double : lroundl \
) (x)
#	else
#	define mcmath_lround(x) \
	( \
		  sizeof(x) == sizeof(float)       ? lroundf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? lround  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? lroundl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_llround -

#	ifndef mcmath_llround
#	if MC_TARGET_C99
#	if MC_TARGET_C11
#	define mcmath_llround(x) _Generic(x \
	, float       : llroundf \
	, double      : llround  \
	, long double : llroundl \
) (x)
#	else
#	define mcmath_llround(x) \
	( \
		  sizeof(x) == sizeof(float)       ? llroundf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? llround  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? llroundl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_llround mcmath_lround
#	endif
#	endif

#pragma mark - mcmath_trunc -

#	ifndef mcmath_trunc
#	if MC_TARGET_C11
#	define mcmath_trunc(x) _Generic(x \
	, float       : truncf \
	, double      : trunc  \
	, long double : truncl \
) (x)
#	else
#	define mcmath_trunc(x) \
	( \
		  sizeof(x) == sizeof(float)       ? truncf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? trunc  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? truncl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_fmod -

#	ifndef mcmath_fmod
#	define mcmath_fmod(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? fmodf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? fmod  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? fmodl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_remainder -

#	ifndef mcmath_remainder
#	define mcmath_remainder(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? remainderf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? remainder  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? remainderl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_remquo -

#	ifndef mcmath_remquo
#	define mcmath_remquo(x, y, z) \
	( \
		  sizeof(x) == sizeof(float)       ? remquof (mc_cast_exp(float, x), mc_cast_exp(float, y), mc_cast_exp(int *, z))             \
		: sizeof(x) == sizeof(double)      ? remquo  (mc_cast_exp(double, x), mc_cast_exp(double, y), mc_cast_exp(int *, z))           \
		: sizeof(x) == sizeof(long double) ? remquol (mc_cast_exp(long double, x), mc_cast_exp(long double, y), mc_cast_exp(int *, z)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_copysign -

#	ifndef mcmath_copysign
#	define mcmath_copysign(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? copysignf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? copysign  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? copysignl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_nan -

#	ifndef mcmath_nan
#	define mcmath_nan(x, p) \
	(x) = ( \
		  sizeof(x) == sizeof(float)       ? nanf (mc_cast_exp(const char *, p)) \
		: sizeof(x) == sizeof(double)      ? nan  (mc_cast_exp(const char *, p)) \
		: sizeof(x) == sizeof(long double) ? nanl (mc_cast_exp(const char *, p)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_nextafter -

#	ifndef mcmath_nextafter
#	define mcmath_nextafter(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? nextafterf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? nextafter  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? nextafterl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_nexttoward -

#	ifndef mcmath_nexttoward
#	define mcmath_nexttoward(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? nexttowardf (mc_cast_exp(float, x), mc_cast_exp(long double, y))       \
		: sizeof(x) == sizeof(double)      ? nexttoward  (mc_cast_exp(double, x), mc_cast_exp(long double, y))      \
		: sizeof(x) == sizeof(long double) ? nexttowardl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_fdim -

#	ifndef mcmath_fdim
#	define mcmath_fdim(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? fdimf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? fdim  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? fdiml (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_fmax -

#	ifndef mcmath_fmax
#	define mcmath_fmax(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? fmaxf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? fmax  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? fmaxl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_fmin -

#	ifndef mcmath_fmin
#	define mcmath_fmin(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? fminf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? fmin  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? fminl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_fma -

#	ifndef mcmath_fma
#	define mcmath_fma(x, y, z) \
	( \
		  sizeof(x) == sizeof(float)       ? fmaf (mc_cast_exp(float, x), mc_cast_exp(float, y), mc_cast_exp(float, z))                   \
		: sizeof(x) == sizeof(double)      ? fma  (mc_cast_exp(double, x), mc_cast_exp(double, y), mc_cast_exp(double, z))                \
		: sizeof(x) == sizeof(long double) ? fmal (mc_cast_exp(long double, x), mc_cast_exp(long double, y), mc_cast_exp(long double, z)) \
		: 0 \
	)
#	endif

#pragma mark - mcmath_abs -

#	ifndef mcmath_abs
#	if MC_TARGET_CPP98

template <class T> MC_TARGET_INLINE T                    mcmath_abs                      (const T& x)                  { return ::std::abs(x);       }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE float                mcmath_abs<float>               (const float& x)              { return ::std::fabsf(x);     }
template <>        MC_TARGET_INLINE double               mcmath_abs<double>              (const double& x)             { return ::std::fabs(x);      }
template <>        MC_TARGET_INLINE long double          mcmath_abs<long double>         (const long double& x)        { return ::std::fabsl(x);     }
#	else
template <>        MC_TARGET_INLINE float                mcmath_abs<float>               (const float& x)              { return ::fabsf(x);          }
template <>        MC_TARGET_INLINE double               mcmath_abs<double>              (const double& x)             { return ::fabs(x);           }
template <>        MC_TARGET_INLINE long double          mcmath_abs<long double>         (const long double& x)        { return ::fabsl(x);          }
#	endif
template <>        MC_TARGET_INLINE signed char          mcmath_abs<signed char>         (const signed char& x)        { return mc_babs(x);          }
template <>        MC_TARGET_INLINE short                mcmath_abs<short>               (const short& x)              { return mc_sabs(x);          }
template <>        MC_TARGET_INLINE int                  mcmath_abs<int>                 (const int& x)                { return mc_iabs(x);          }
template <>        MC_TARGET_INLINE long                 mcmath_abs<long>                (const long& x)               { return mc_labs(x);          }

template <>        MC_TARGET_INLINE unsigned char        mcmath_abs<unsigned char>       (const unsigned char& x)      { return mc_uchar_abs(x);     }
template <>        MC_TARGET_INLINE unsigned short       mcmath_abs<unsigned short>      (const unsigned short& x)     { return mc_ushort_abs(x);    }
template <>        MC_TARGET_INLINE unsigned int         mcmath_abs<unsigned int>        (const unsigned int& x)       { return mc_uint_abs(x);      }
template <>        MC_TARGET_INLINE unsigned long        mcmath_abs<unsigned long>       (const unsigned long& x)      { return mc_ulong_abs(x);     }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE long long            mcmath_abs<long long>           (const long long& x)          { return mc_llabs(x);         }
template <>        MC_TARGET_INLINE unsigned long long   mcmath_abs<unsigned  long long> (const unsigned long long& x) { return mc_ulonglong_abs(x); }
#	endif

#	else

#	if MC_TARGET_HAVE_OVERLOADABLE

static MC_TARGET_OVERLOADABLE float              mcmath_abs (float x)              { return fabsf(x);            }
static MC_TARGET_OVERLOADABLE double             mcmath_abs (double x)             { return fabs(x);             }
static MC_TARGET_OVERLOADABLE long double        mcmath_abs (long double x)        { return fabsl(x);            }

static MC_TARGET_OVERLOADABLE signed char        mcmath_abs (signed char x)        { return mc_babs(x);          }
static MC_TARGET_OVERLOADABLE short              mcmath_abs (short x)              { return mc_sabs(x);          }
static MC_TARGET_OVERLOADABLE int                mcmath_abs (int x)                { return mc_iabs(x);          }
static MC_TARGET_OVERLOADABLE long               mcmath_abs (long x)               { return mc_labs(x);          }

static MC_TARGET_OVERLOADABLE unsigned char      mcmath_abs (unsigned char x)      { return mc_uchar_abs(x);     }
static MC_TARGET_OVERLOADABLE unsigned short     mcmath_abs (unsigned short x)     { return mc_ushort_abs(x);    }
static MC_TARGET_OVERLOADABLE unsigned int       mcmath_abs (unsigned int x)       { return mc_uint_abs(x);      }
static MC_TARGET_OVERLOADABLE unsigned long      mcmath_abs (unsigned long x)      { return mc_ulong_abs(x);     }

#	if MC_TARGET_C99

static MC_TARGET_OVERLOADABLE long long          mcmath_abs (long long x)          { return mc_llabs(x);         }
static MC_TARGET_OVERLOADABLE unsigned long long mcmath_abs (unsigned long long x) { return mc_ulonglong_abs(x); }

#	endif

#	elif MC_TARGET_C11
#	define mcmath_abs(x) _Generic(x \
	, float              : fabsf            \
	, double             : fabs             \
	, long double        : fabsl            \
	, signed char        : mc_babs          \
	, short              : mc_sabs          \
	, int                : mc_iabs          \
	, long               : mc_labs          \
	, long long          : mc_llabs         \
	, unsigned char      : mc_uchar_abs     \
	, unsigned short     : mc_ushort_abs    \
	, unsigned int       : mc_uint_abs      \
	, unsigned long      : mc_ulong_abs     \
	, unsigned long long : mc_ulonglong_abs \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#		if MC_TARGET_C99
#		define mcmath_abs(x) mc_cast(MC_TARGET_TYPEOF(x), \
		( \
			  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)              ? fabsf           (mc_cast_exp(float, x))               \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)             ? fabs            (mc_cast_exp(double, x))              \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double)        ? fabsl           (mc_cast_exp(long double, x))         \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), signed char)        ? mc_babs         (mc_cast_exp(signed char, x))         \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), short)              ? mc_sabs         (mc_cast_exp(short, x))               \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), int)                ? mc_iabs         (mc_cast_exp(int,x))                  \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long)               ? mc_labs         (mc_cast_exp(long, x))                \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long long)          ? mc_llabs         (mc_cast_exp(long long, x))          \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned char)      ? mc_uchar_abs     (mc_cast_exp(unsigned char, x))      \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned short)     ? mc_ushort_abs    (mc_cast_exp(unsigned short, x))     \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned int)       ? mc_uint_abs      (mc_cast_exp(unsigned int,x))        \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long)      ? mc_ulong_abs     (mc_cast_exp(unsigned long, x))      \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long long) ? mc_ulonglong_abs (mc_cast_exp(unsigned long long, x)) \
			: 0 \
		))
#		else
#		define mcmath_abs(x) mc_cast(MC_TARGET_TYPEOF(x), \
		( \
			  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)              ? fabsf         (mc_cast_exp(float, x))          \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)             ? fabs          (mc_cast_exp(double, x))         \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double)        ? fabsl         (mc_cast_exp(long double, x))    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), signed char)        ? mc_babs       (mc_cast_exp(signed char, x))    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), short)              ? mc_sabs       (mc_cast_exp(short, x))          \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), int)                ? mc_iabs       (mc_cast_exp(int,x))             \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long)               ? mc_labs       (mc_cast_exp(long, x))           \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned char)      ? mc_uchar_abs  (mc_cast_exp(unsigned char, x))  \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned short)     ? mc_ushort_abs (mc_cast_exp(unsigned short, x)) \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned int)       ? mc_uint_abs   (mc_cast_exp(unsigned int,x))    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long)      ? mc_ulong_abs  (mc_cast_exp(unsigned long, x))  \
			: 0 \
		))
#		endif
#	elif defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wsign-compare"
#	define mcmath_abs(x) ((x) < 0 ? (-(x)) : (x))
#	pragma clang diagnostic pop
#	elif defined(__GNUC__)
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wsign-compare"
#	define mcmath_abs(x) ((x) < 0 ? (-(x)) : (x))
#	pragma GCC diagnostic pop
#	elif defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable:4018)
#	define mcmath_abs(x) ((x) < 0 ? (-(x)) : (x))
#	pragma warning(pop)
#	else
#	define mcmath_abs(x) ((x) < 0 ? (-(x)) : (x))
#	endif
#	endif
#	endif

#pragma mark - mcmath_min -

#	ifndef mcmath_min
#	if MC_TARGET_CPP98

template <class T> MC_TARGET_INLINE T           mcmath_min              (const T& x, const T& y)                     { return ::std::min(x, y);   }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE float       mcmath_min<float>       (const float& x, const float& y)             { return ::std::fminf(x, y); }
template <>        MC_TARGET_INLINE double      mcmath_min<double>      (const double& x, const double& y)           { return ::std::fmin(x, y);  }
template <>        MC_TARGET_INLINE long double mcmath_min<long double> (const long double& x, const long double& y) { return ::std::fminl(x, y); }
#	else
template <>        MC_TARGET_INLINE float       mcmath_min<float>       (const float& x, const float& y)             { return ::fminf(x, y);      }
template <>        MC_TARGET_INLINE double      mcmath_min<double>      (const double& x, const double& y)           { return ::fmin(x, y);       }
template <>        MC_TARGET_INLINE long double mcmath_min<long double> (const long double& x, const long double& y) { return ::fminl(x, y);      }
#	endif

#	else

#	if MC_TARGET_HAVE_OVERLOADABLE

static MC_TARGET_OVERLOADABLE float       mcmath_min (float x, float y)             { return fminf(x, y);     }
static MC_TARGET_OVERLOADABLE double      mcmath_min (double x, double y)           { return fmin(x, y);      }
static MC_TARGET_OVERLOADABLE long double mcmath_min (long double x, long double y) { return fminl(x, y);     }

static MC_TARGET_OVERLOADABLE signed char mcmath_min (signed char x, signed char y)  { return mc_bmin(x, y);  }
static MC_TARGET_OVERLOADABLE short       mcmath_min (short x, short y)              { return mc_smin(x, y);  }
static MC_TARGET_OVERLOADABLE int         mcmath_min (int x, int y)                  { return mc_imin(x, y);  }
static MC_TARGET_OVERLOADABLE long        mcmath_min (long x, long y)                { return mc_lmin(x, y);  }

#	if MC_TARGET_C99

static MC_TARGET_OVERLOADABLE long long   mcmath_min (long long x, long long y)      { return mc_llmin(x, y); }

#	endif

#	elif MC_TARGET_C99
#	if MC_TARGET_HAVE_AUTOTYPE
#	define mcmath_min(a, b) \
	__extension__ ({ \
		MC_TARGET_AUTOTYPE __mcmath_min_aa = (a); \
		MC_TARGET_AUTOTYPE __mcmath_min_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_min_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), float)       ? fminf (__mcmath_min_aa, mc_cast(float, __mcmath_min_bb))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), double)      ? fmin  (__mcmath_min_aa, mc_cast(double, __mcmath_min_bb))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), long double) ? fminl (__mcmath_min_aa, mc_cast(long double, __mcmath_min_bb)) \
		: (__mcmath_min_aa < __mcmath_min_bb ? __mcmath_min_aa : __mcmath_min_bb)                                                               \
		)); \
	})
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_min(a, b) \
	__extension__ ({ \
		MC_TARGET_TYPEOF((a)) __mcmath_min_aa = (a); \
		MC_TARGET_TYPEOF((b)) __mcmath_min_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_min_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), float)       ? fminf (__mcmath_min_aa, mc_cast(float, __mcmath_min_bb))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), double)      ? fmin  (__mcmath_min_aa, mc_cast(double, __mcmath_min_bb))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), long double) ? fminl (__mcmath_min_aa, mc_cast(long double, __mcmath_min_bb)) \
		: (__mcmath_min_aa < __mcmath_min_bb ? __mcmath_min_aa : __mcmath_min_bb)                                                               \
		)); \
	})
#	else
#	define mcmath_min(a, b) (((a) < (b)) ? (a) : (b))
#	endif
#	else
#	define mcmath_min(a, b) (((a) < (b)) ? (a) : (b))
#	endif
#	endif
#	endif

#pragma mark - mcmath_max -

#	ifndef mcmath_max
#	if MC_TARGET_CPP98

template <class T> MC_TARGET_INLINE T           mcmath_max              (const T& x, const T& y)                     { return ::std::max(x, y);   }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE float       mcmath_max<float>       (const float& x, const float& y)             { return ::std::fmaxf(x, y); }
template <>        MC_TARGET_INLINE double      mcmath_max<double>      (const double& x, const double& y)           { return ::std::fmax(x, y);  }
template <>        MC_TARGET_INLINE long double mcmath_max<long double> (const long double& x, const long double& y) { return ::std::fmaxl(x, y); }
#	else
template <>        MC_TARGET_INLINE float       mcmath_max<float>       (const float& x, const float& y)             { return ::fmaxf(x, y);      }
template <>        MC_TARGET_INLINE double      mcmath_max<double>      (const double& x, const double& y)           { return ::fmax(x, y);       }
template <>        MC_TARGET_INLINE long double mcmath_max<long double> (const long double& x, const long double& y) { return ::fmaxl(x, y);      }
#	endif

#	else

#	if MC_TARGET_HAVE_OVERLOADABLE

static MC_TARGET_OVERLOADABLE float       mcmath_max (float x, float y)             { return fmaxf(x, y);    }
static MC_TARGET_OVERLOADABLE double      mcmath_max (double x, double y)           { return fmax(x, y);     }
static MC_TARGET_OVERLOADABLE long double mcmath_max (long double x, long double y) { return fmaxl(x, y);    }

static MC_TARGET_OVERLOADABLE signed char mcmath_max (signed char x, signed char y) { return mc_bmax(x, y);  }
static MC_TARGET_OVERLOADABLE short       mcmath_max (short x, short y)             { return mc_smax(x, y);  }
static MC_TARGET_OVERLOADABLE int         mcmath_max (int x, int y)                 { return mc_imax(x, y);  }
static MC_TARGET_OVERLOADABLE long        mcmath_max (long x, long y)               { return mc_lmax(x, y);  }

#	if MC_TARGET_C99

static MC_TARGET_OVERLOADABLE long long   mcmath_max (long long x, long long y)     { return mc_llmax(x, y); }

#	endif

#	elif MC_TARGET_C99
#	if MC_TARGET_HAVE_AUTOTYPE
#	define mcmath_max(a, b) \
	__extension__ ({ \
		MC_TARGET_AUTOTYPE __mcmath_max_aa = (a); \
		MC_TARGET_AUTOTYPE __mcmath_max_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_max_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), float)       ? fmaxf (__mcmath_max_aa, mc_cast(float, __mcmath_max_bb))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), double)      ? fmax  (__mcmath_max_aa, mc_cast(double, __mcmath_max_bb))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), long double) ? fmaxl (__mcmath_max_aa, mc_cast(long double, __mcmath_max_bb)) \
		: (__mcmath_max_aa > __mcmath_max_bb ? __mcmath_max_aa : __mcmath_max_bb)                                                               \
		)); \
	})
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_max(a, b) \
	__extension__ ({ \
		MC_TARGET_TYPEOF((a)) __mcmath_max_aa = (a); \
		MC_TARGET_TYPEOF((b)) __mcmath_max_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_max_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), float)       ? fmaxf (__mcmath_max_aa, mc_cast(float, __mcmath_max_bb))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), double)      ? fmax  (__mcmath_max_aa, mc_cast(double, __mcmath_max_bb))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_max_aa)), long double) ? fmaxl (__mcmath_max_aa, mc_cast(long double, __mcmath_max_bb)) \
		: (__mcmath_max_aa > __mcmath_max_bb ? __mcmath_max_aa : __mcmath_max_bb)                                                               \
		)); \
	})
#	else
#	define mcmath_max(a, b) (((a) > (b)) ? (a) : (b))
#	endif
#	else
#	define mcmath_max(a, b) (((a) > (b)) ? (a) : (b))
#	endif
#	endif
#	endif

#	if MC_TARGET_CPP11
#		define mcmath_isgreater(x, y)      ::std::isgreater(x, y)
#		define mcmath_isgreaterequal(x, y) ::std::isgreaterequal(x, y)
#		define mcmath_isless(x, y)         ::std::isless(x, y)
#		define mcmath_islessequal(x, y)    ::std::islessequal(x, y)
#		define mcmath_islessgreater(x, y)  ::std::islessgreater(x, y)
#		define mcmath_isunordered(x, y)    ::std::isunordered(x, y)
#	elif MC_TARGET_CPP98
#		define mcmath_isgreater(x, y)      ::isgreater(x, y)
#		define mcmath_isgreaterequal(x, y) ::isgreaterequal(x, y)
#		define mcmath_isless(x, y)         ::isless(x, y)
#		define mcmath_islessequal(x, y)    ::islessequal(x, y)
#		define mcmath_islessgreater(x, y)  ::islessgreater(x, y)
#		define mcmath_isunordered(x, y)    ::isunordered(x, y)
#	else
#		define mcmath_isgreater(x, y)      isgreater(x, y)
#		define mcmath_isgreaterequal(x, y) isgreaterequal(x, y)
#		define mcmath_isless(x, y)         isless(x, y)
#		define mcmath_islessequal(x, y)    islessequal(x, y)
#		define mcmath_islessgreater(x, y)  islessgreater(x, y)
#		define mcmath_isunordered(x, y)    isunordered(x, y)
#	endif

#	ifndef mcmath_i0
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_i0              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_i0<float>       (const float& x)       { return mc_i0f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_i0<double>      (const double& x)      { return mc_i0(x);            }
template <>        MC_TARGET_INLINE long double mcmath_i0<long double> (const long double& x) { return mc_i0l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_i0 (float x)       { return mc_i0f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_i0 (double x)      { return mc_i0(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_i0 (long double x) { return mc_i0l(x); }
#	elif MC_TARGET_C11
#	define mcmath_i0(x) _Generic(x \
	, float       : mc_i0f \
	, double      : mc_i0  \
	, long double : mc_i0l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_i0(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_i0f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_i0  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_i0l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_i0(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_i0f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_i0  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_i0l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_i1 -

#	ifndef mcmath_i1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_i1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_i1<float>       (const float& x)       { return mc_i1f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_i1<double>      (const double& x)      { return mc_i1(x);            }
template <>        MC_TARGET_INLINE long double mcmath_i1<long double> (const long double& x) { return mc_i1l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_i1 (float x)       { return mc_i1f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_i1 (double x)      { return mc_i1(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_i1 (long double x) { return mc_i1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_i1(x) _Generic(x \
	, float       : mc_i1f \
	, double      : mc_i1  \
	, long double : mc_i1l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_i1(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_i1f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_i1  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_i1l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_i1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_i1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_i1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_i1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_in -

#	ifndef mcmath_in
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_in              (int n, const T& x)           { mc_cast(void, n); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_in<float>       (int n, const float& x)       { return mc_inf(n, x);                          }
template <>        MC_TARGET_INLINE double      mcmath_in<double>      (int n, const double& x)      { return mc_in(n, x);                           }
template <>        MC_TARGET_INLINE long double mcmath_in<long double> (int n, const long double& x) { return mc_inl(n, x);                          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_in (int n, float x)       { return mc_inf(n, x); }
static MC_TARGET_OVERLOADABLE double      mcmath_in (int n, double x)      { return mc_in(n, x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_in (int n, long double x) { return mc_inl(n, x); }
#	else
#	define mcmath_in(n, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_inf (mc_cast_exp(int, n), mc_cast_exp(float, x)))       \
		: sizeof(x) == sizeof(double)      ? mc_in  (mc_cast_exp(int, n), mc_cast_exp(double, x))       \
		: sizeof(x) == sizeof(long double) ? mc_inl (mc_cast_exp(int, n), mc_cast_exp(long double, x))) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_in(n, x) (x)
#	endif

#pragma mark - mcmath_j0 -

#	ifndef mcmath_j0
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_j0              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_j0<float>       (const float& x)       { return mc_j0f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_j0<double>      (const double& x)      { return mc_j0(x);            }
template <>        MC_TARGET_INLINE long double mcmath_j0<long double> (const long double& x) { return mc_j0l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_j0 (float x)       { return mc_j0f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_j0 (double x)      { return mc_j0(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_j0 (long double x) { return mc_j0l(x); }
#	elif MC_TARGET_C11
#	define mcmath_j0(x) _Generic(x \
	, float       : mc_j0f \
	, double      : mc_j0  \
	, long double : mc_j0l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_j0(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_j0f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_j0  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_j0l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_j0(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_j0f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_j0  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_j0l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_j0(x) (x)
#	endif

#pragma mark - mcmath_j1 -

#	ifndef mcmath_j1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_j1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_j1<float>       (const float& x)       { return mc_j1f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_j1<double>      (const double& x)      { return mc_j1(x);            }
template <>        MC_TARGET_INLINE long double mcmath_j1<long double> (const long double& x) { return mc_j1l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_j1 (float x)       { return mc_j1f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_j1 (double x)      { return mc_j1(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_j1 (long double x) { return mc_j1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_j1(x) _Generic(x \
	, float       : mc_j1f \
	, double      : mc_j1  \
	, long double : mc_j1l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_j1(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_j1f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_j1  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_j1l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_j1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_j1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_j1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_j1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_j1(x) (x)
#	endif

#pragma mark - mcmath_jn -

#	ifndef mcmath_jn
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_jn              (int n, const T& x)           { mc_cast(void, n); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_jn<float>       (int n, const float& x)       { return mc_jnf(n, x);                          }
template <>        MC_TARGET_INLINE double      mcmath_jn<double>      (int n, const double& x)      { return mc_jn(n, x);                           }
template <>        MC_TARGET_INLINE long double mcmath_jn<long double> (int n, const long double& x) { return mc_jnl(n, x);                          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_jn (int n, float x)       { return mc_jnf(n, x); }
static MC_TARGET_OVERLOADABLE double      mcmath_jn (int n, double x)      { return mc_jn(n, x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_jn (int n, long double x) { return mc_jnl(n, x); }
#	else
#	define mcmath_jn(n, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_jnf (mc_cast_exp(int, n), mc_cast_exp(float, x)))       \
		: sizeof(x) == sizeof(double)      ? mc_jn  (mc_cast_exp(int, n), mc_cast_exp(double, x))       \
		: sizeof(x) == sizeof(long double) ? mc_jnl (mc_cast_exp(int, n), mc_cast_exp(long double, x))) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_jn(n, x) (x)
#	endif

#pragma mark - mcmath_y0 -

#	ifndef mcmath_y0
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_y0              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_y0<float>       (const float& x)       { return mc_y0f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_y0<double>      (const double& x)      { return mc_y0(x);            }
template <>        MC_TARGET_INLINE long double mcmath_y0<long double> (const long double& x) { return mc_y0l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_y0 (float x)       { return mc_y0f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_y0 (double x)      { return mc_y0(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_y0 (long double x) { return mc_y0l(x); }
#	elif MC_TARGET_C11
#	define mcmath_y0(x) _Generic(x \
	, float       : mc_y0f \
	, double      : mc_y0  \
	, long double : mc_y0l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_y0(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_y0f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_y0  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_y0l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_y0(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_y0f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_y0  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_y0l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_y0(x) (x)
#	endif

#pragma mark - mcmath_y1 -

#	ifndef mcmath_y1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_y1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_y1<float>       (const float& x)       { return mc_y1f(x);           }
template <>        MC_TARGET_INLINE double      mcmath_y1<double>      (const double& x)      { return mc_y1(x);            }
template <>        MC_TARGET_INLINE long double mcmath_y1<long double> (const long double& x) { return mc_y1l(x);           }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_y1 (float x)       { return mc_y1f(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_y1 (double x)      { return mc_y1(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_y1 (long double x) { return mc_y1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_y1(x) _Generic(x \
	, float       : mc_y1f \
	, double      : mc_y1  \
	, long double : mc_y1l \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_y1(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_y1f (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_y1  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_y1l (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_y1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_y1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_y1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_y1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_y1(x) (x)
#	endif

#pragma mark - mcmath_yn -

#	ifndef mcmath_yn
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_yn              (int n, const T& x)           { mc_cast(void, n); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_yn<float>       (int n, const float& x)       { return mc_ynf(n, x);                          }
template <>        MC_TARGET_INLINE double      mcmath_yn<double>      (int n, const double& x)      { return mc_yn(n, x);                           }
template <>        MC_TARGET_INLINE long double mcmath_yn<long double> (int n, const long double& x) { return mc_ynl(n, x);                          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_yn (int n, float x)       { return mc_ynf(n, x); }
static MC_TARGET_OVERLOADABLE double      mcmath_yn (int n, double x)      { return mc_yn(n, x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_yn (int n, long double x) { return mc_ynl(n, x); }
#	else
#	define mcmath_yn(n, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_ynf (mc_cast_exp(int, n), mc_cast_exp(float, x)))       \
		: sizeof(x) == sizeof(double)      ? mc_yn  (mc_cast_exp(int, n), mc_cast_exp(double, x))       \
		: sizeof(x) == sizeof(long double) ? mc_ynl (mc_cast_exp(int, n), mc_cast_exp(long double, x))) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_yn(n, x) (x)
#	endif

#pragma mark - mcmath_scalb -

#	ifndef mcmath_scalb
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_scalb              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_scalb<float>       (const float& x, const float& y)             { return mc_scalbf(x, y);                       }
template <>        MC_TARGET_INLINE double      mcmath_scalb<double>      (const double& x, const double& y)           { return mc_scalb(x, y);                        }
template <>        MC_TARGET_INLINE long double mcmath_scalb<long double> (const long double& x, const long double& y) { return mc_scalbl(x, y);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_scalb (float x, float y)             { return mc_scalbf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_scalb (double x, double y)           { return mc_scalb(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_scalb (long double x, long double y) { return mc_scalbl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_lbeta(x, y) _Generic(x \
	, float       : mcmath_scalbf \
	, double      : mcmath_scalb  \
	, long double : mcmath_scalbl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_scalb(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_scalbf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_scalb  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_scalbl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	else
#	define mcmath_scalb(x, y) (x)
#	endif

#pragma mark - mcmath_ibeta -

#	ifndef mcmath_ibeta
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_ibeta              (const T& a, const T& b, const T& x)                               { mc_cast(void, a); mc_cast(void, b); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_ibeta<float>       (const float& a, const float& b, const float& x)                   { return mc_ibetaf(a, b, x);                                      }
template <>        MC_TARGET_INLINE double      mcmath_ibeta<double>      (const double& a, const double& b, const double& x)                { return mc_ibeta(a, b, x);                                       }
template <>        MC_TARGET_INLINE long double mcmath_ibeta<long double> (const long double& a, const long double& b, const long double& x) { return mc_ibetal(a, b, x);                                      }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_ibeta (float a, float b, float x)                   { return mc_ibetaf(a, b, x); }
static MC_TARGET_OVERLOADABLE double      mcmath_ibeta (double a, double b, double x)                { return mc_ibeta(a, b, x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_ibeta (long double a, long double b, long double x) { return mc_ibetal(a, b, x); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_ibeta(a, b, x) _Generic(a \
	, float       : mc_ibetaf \
	, double      : mc_ibeta  \
	, long double : mc_ibetal \
) (a, mc_cast_exp(MC_TARGET_TYPEOF(a), b), mc_cast_exp(MC_TARGET_TYPEOF(a), x))
#	else
#	define mcmath_ibeta(a, b, x) \
	( \
		  sizeof(a) == sizeof(float)       ? mc_ibetaf (mc_cast_exp(float, a), mc_cast_exp(float, b), mc_cast_exp(float, x))                   \
		: sizeof(a) == sizeof(double)      ? mc_ibeta  (mc_cast_exp(double, a), mc_cast_exp(double, b), mc_cast_exp(double, x))                \
		: sizeof(a) == sizeof(long double) ? mc_ibetal (mc_cast_exp(long double, a), mc_cast_exp(long double, b), mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lbeta -

#	ifndef mcmath_lbeta
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_lbeta              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_lbeta<float>       (const float& x, const float& y)             { return mc_lbetaf(x, y);                       }
template <>        MC_TARGET_INLINE double      mcmath_lbeta<double>      (const double& x, const double& y)           { return mc_lbeta(x, y);                        }
template <>        MC_TARGET_INLINE long double mcmath_lbeta<long double> (const long double& x, const long double& y) { return mc_lbetal(x, y);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_lbeta (float x, float y)             { return mc_lbetaf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_lbeta (double x, double y)           { return mc_lbeta(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_lbeta (long double x, long double y) { return mc_lbetal(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_lbeta(x, y) _Generic(x \
	, float       : mc_lbetaf \
	, double      : mc_lbeta  \
	, long double : mc_lbetal \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_lbeta(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_lbetaf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_lbeta  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_lbetal (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_beta -

#	ifndef mcmath_beta
#	if MC_TARGET_CPP17 && MC_TARGET_HAVE_BETAFN
#	define mcmath_betaf ::std::betaf
#	define mcmath_beta  ::std::beta
#	define mcmath_betal ::std::betal
#	else
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_beta              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_beta<float>       (const float& x, const float& y)             { return mc_betaf(x, y);                        }
template <>        MC_TARGET_INLINE double      mcmath_beta<double>      (const double& x, const double& y)           { return mc_beta(x, y);                         }
template <>        MC_TARGET_INLINE long double mcmath_beta<long double> (const long double& x, const long double& y) { return mc_betal(x, y);                        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_beta (float x, float y)             { return mc_betaf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_beta (double x, double y)           { return mc_beta(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_beta (long double x, long double y) { return mc_betal(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_beta(x, y) _Generic(x \
	, float       : mc_betaf \
	, double      : mc_beta  \
	, long double : mc_betal \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_beta(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_betaf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_beta  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_betal (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif
#	endif

#	define mcmath_betainc(a, b, x) mcmath_ibeta(a, b, x)
#	define mcmath_betaln(x, y)     mcmath_lbeta(x, y)

#pragma mark - mcmath_xlogy -

#	ifndef mcmath_xlogy
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_xlogy              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_xlogy<float>       (const float& x, const float& y)             { return mc_xlogyf(x, y);                       }
template <>        MC_TARGET_INLINE double      mcmath_xlogy<double>      (const double& x, const double& y)           { return mc_xlogy(x, y);                        }
template <>        MC_TARGET_INLINE long double mcmath_xlogy<long double> (const long double& x, const long double& y) { return mc_xlogyl(x, y);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_xlogy (float x, float y)             { return mc_xlogyf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_xlogy (double x, double y)           { return mc_xlogy(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_xlogy (long double x, long double y) { return mc_xlogyl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_xlogy(x, y) _Generic(x \
	, float       : mc_xlogyf \
	, double      : mc_xlogy  \
	, long double : mc_xlogyl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_xlogy(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_xlogyf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_xlogy  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_xlogyl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_xlog1py -

#	ifndef mcmath_xlog1py
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_xlog1py              (const T& x, const T& y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_xlog1py<float>       (const float& x, const float& y)             { return mc_xlog1pyf(x, y);                     }
template <>        MC_TARGET_INLINE double      mcmath_xlog1py<double>      (const double& x, const double& y)           { return mc_xlog1py(x, y);                      }
template <>        MC_TARGET_INLINE long double mcmath_xlog1py<long double> (const long double& x, const long double& y) { return mc_xlog1pyl(x, y);                     }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_xlog1py (float x, float y)             { return mc_xlog1pyf(x, y); }
static MC_TARGET_OVERLOADABLE double      mcmath_xlog1py (double x, double y)           { return mc_xlog1py(x, y);  }
static MC_TARGET_OVERLOADABLE long double mcmath_xlog1py (long double x, long double y) { return mc_xlog1pyl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_xlog1py(x, y) _Generic(x \
	, float       : mc_xlog1pyf \
	, double      : mc_xlog1py  \
	, long double : mc_xlog1pyl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_xlog1py(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_xlog1pyf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_xlog1py  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_xlog1pyl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_xlog1px -

#	ifndef mcmath_xlog1px
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_xlog1px              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_xlog1px<float>       (const float& x)       { return mc_xlog1pxf(x);      }
template <>        MC_TARGET_INLINE double      mcmath_xlog1px<double>      (const double& x)      { return mc_xlog1px(x);       }
template <>        MC_TARGET_INLINE long double mcmath_xlog1px<long double> (const long double& x) { return mc_xlog1pxl(x);      }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_xlog1px (float x)       { return mc_xlog1pxf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_xlog1px (double x)      { return mc_xlog1px(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_xlog1px (long double x) { return mc_xlog1pxl(x); }
#	elif MC_TARGET_C11
#	define mcmath_xlog1px(x) _Generic(x \
	, float       : mc_xlog1pxf \
	, double      : mc_xlog1px  \
	, long double : mc_xlog1pxl \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_xlog1px(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_xlog1pxf (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_xlog1px  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_xlog1pxl (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_xlog1px(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_xlog1pxf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_xlog1px  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_xlog1pxl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_xlogx -

#	ifndef mcmath_xlogx
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_xlogx              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_xlogx<float>       (const float& x)       { return mc_xlogxf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_xlogx<double>      (const double& x)      { return mc_xlogx(x);         }
template <>        MC_TARGET_INLINE long double mcmath_xlogx<long double> (const long double& x) { return mc_xlogxl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_xlogx (float x)       { return mc_xlogxf(x); }
static MC_TARGET_OVERLOADABLE double      mcmath_xlogx (double x)      { return mc_xlogx(x);  }
static MC_TARGET_OVERLOADABLE long double mcmath_xlogx (long double x) { return mc_xlogxl(x); }
#	elif MC_TARGET_C11
#	define mcmath_xlogx(x) _Generic(x \
	, float       : mc_xlogxf \
	, double      : mc_xlogx  \
	, long double : mc_xlogxl \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_xlogx(x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_xlogxf (mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_xlogx  (mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_xlogxl (mc_cast_exp(long double, x)) \
		: 0 \
	))
#	else
#	define mcmath_xlogx(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_xlogxf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_xlogx  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_xlogxl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#	ifndef mcmath_logradix
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_logradix              (const T& x, int n)           { mc_cast(void, x); mc_cast(void, n); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_logradix<float>       (const float& x, int n)       { return mc_logradixf(x, n);                    }
template <>        MC_TARGET_INLINE double      mcmath_logradix<double>      (const double& x, int n)      { return mc_logradix(x, n);                     }
template <>        MC_TARGET_INLINE long double mcmath_logradix<long double> (const long double& x, int n) { return mc_logradixl(x, n);                    }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_logradix (float x, int n)       { return mc_logradixf(x, n); }
static MC_TARGET_OVERLOADABLE double      mcmath_logradix (double x, int n)      { return mc_logradix(x, n);  }
static MC_TARGET_OVERLOADABLE long double mcmath_logradix (long double x, int n) { return mc_logradixl(x, n); }
#	elif MC_TARGET_C11
#	define mcmath_logradix(x, n) _Generic(x \
	, float       : mc_logradixf \
	, double      : mc_logradix  \
	, long double : mc_logradixl \
) (x, mc_cast_exp(int, n))
#	else
#	define mcmath_logradix(x, n) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_logradixf (mc_cast_exp(float, x), mc_cast_exp(int, n))       \
		: sizeof(x) == sizeof(double)      ? mc_logradix  (mc_cast_exp(double, x), mc_cast_exp(int, n))      \
		: sizeof(x) == sizeof(long double) ? mc_logradixl (mc_cast_exp(long double, x), mc_cast_exp(int, n)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lerp -

#	ifndef mcmath_lerp
#	if MC_TARGET_CPP20 && MC_TARGET_HAVE_LERPFN
#	define mcmath_lerpf ::std::lerp
#	define mcmath_lerp  ::std::lerp
#	define mcmath_lerpl ::std::lerp
#	else
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_lerp              (const T& x, const T& y, const T& z)                               { mc_cast(void, x); mc_cast(void, y); mc_cast(void, z); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_lerp<float>       (const float& x, const float& y, const float& z)                   { return mc_lerpf(x, y, z);                                       }
template <>        MC_TARGET_INLINE double      mcmath_lerp<double>      (const double& x, const double& y, const double& z)                { return mc_lerp(x, y, z);                                        }
template <>        MC_TARGET_INLINE long double mcmath_lerp<long double> (const long double& x, const long double& y, const long double& z) { return mc_lerpl(x, y, z);                                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
static MC_TARGET_OVERLOADABLE float       mcmath_lerp (float x, float y, float z)                   { return mc_lerpf(x, y, z); }
static MC_TARGET_OVERLOADABLE double      mcmath_lerp (double x, double y, double z)                { return mc_lerp(x, y, z);  }
static MC_TARGET_OVERLOADABLE long double mcmath_lerp (long double x, long double y, long double z) { return mc_lerpl(x, y, z); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_lerp(x, y, z) _Generic(x \
	, float       : mc_lerpf \
	, double      : mc_lerp  \
	, long double : mc_lerpl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y), mc_cast_exp(MC_TARGET_TYPEOF(x), z))
#	else
#	define mcmath_lerp(x, y, z) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_lerpf (mc_cast_exp(float, x), mc_cast_exp(float, y), mc_cast_exp(float, z))                   \
		: sizeof(x) == sizeof(double)      ? mc_lerp  (mc_cast_exp(double, x), mc_cast_exp(double, y), mc_cast_exp(double, z))                \
		: sizeof(x) == sizeof(long double) ? mc_lerpl (mc_cast_exp(long double, x), mc_cast_exp(long double, y), mc_cast_exp(long double, z)) \
		: 0 \
	)
#	endif
#	endif
#	endif

#endif /* !MCMATH_H */

/* EOF */
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
#		define mcmath_atan2(y, x)      ::std::atan2(y, x)
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
#		define mcmath_atan2(y, x)      atan2(y, x)
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
 */
#	ifndef mcmath_acos
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_acos              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_acos<float>       (const float& x)       { return mc_acosf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_acos<double>      (const double& x)      { return mc_acos(x);          }
template <>        MC_TARGET_INLINE long double mcmath_acos<long double> (const long double& x) { return mc_acosl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_acos (float x)       { return mc_acosf(x); }
MC_TARGET_ALIAS double      mcmath_acos (double x)      { return mc_acos(x);  }
MC_TARGET_ALIAS long double mcmath_acos (long double x) { return mc_acosl(x); }
#	elif MC_TARGET_C11
#	define mcmath_acos(x) _Generic(x \
	, float       : mc_acosf \
	, double      : mc_acos  \
	, long double : mc_acosl \
) (x)
#	else
#	define mcmath_acos(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_acosf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_acos  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_acosl (mc_cast_exp(long double, x)) \
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
 */
#	ifndef mcmath_asin
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_asin              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_asin<float>       (const float& x)       { return mc_asinf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_asin<double>      (const double& x)      { return mc_asin(x);          }
template <>        MC_TARGET_INLINE long double mcmath_asin<long double> (const long double& x) { return mc_asinl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_asin (float x)       { return mc_asinf(x); }
MC_TARGET_ALIAS double      mcmath_asin (double x)      { return mc_asin(x);  }
MC_TARGET_ALIAS long double mcmath_asin (long double x) { return mc_asinl(x); }
#	elif MC_TARGET_C11
#	define mcmath_asin(x) _Generic(x \
	, float       : mc_asinf \
	, double      : asin  \
	, long double : mc_asinl \
) (x)
#	else
#	define mcmath_asin(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_asinf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_asin  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_asinl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atan -

#	ifndef mcmath_atan
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atan              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atan<float>       (const float& x)       { return mc_atanf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_atan<double>      (const double& x)      { return mc_atan(x);          }
template <>        MC_TARGET_INLINE long double mcmath_atan<long double> (const long double& x) { return mc_atanl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_atan (float x)       { return mc_atanf(x); }
MC_TARGET_ALIAS double      mcmath_atan (double x)      { return mc_atan(x);  }
MC_TARGET_ALIAS long double mcmath_atan (long double x) { return mc_atanl(x); }
#	elif MC_TARGET_C11
#	define mcmath_atan(x) _Generic(x \
	, float       : mc_atanf \
	, double      : mc_atan  \
	, long double : mc_atanl \
) (x)
#	else
#	define mcmath_atan(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_atanf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_atan  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_atanl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atan2 -

#	ifndef mcmath_atan2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atan2              (const T& y, const T& x)                     { mc_cast(void, y); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atan2<float>       (const float& y, const float& x)             { return mc_atan2f(y, x);                       }
template <>        MC_TARGET_INLINE double      mcmath_atan2<double>      (const double& y, const double& x)           { return mc_atan2(y, x);                        }
template <>        MC_TARGET_INLINE long double mcmath_atan2<long double> (const long double& y, const long double& x) { return mc_atan2l(y, x);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_atan2 (float y, float x)             { return mc_atan2f(y, x); }
MC_TARGET_ALIAS double      mcmath_atan2 (double y, double x)           { return mc_atan2(y, x);  }
MC_TARGET_ALIAS long double mcmath_atan2 (long double y, long double x) { return mc_atan2l(y, x); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_atan2(y, x) _Generic(x \
	, float       : mc_atan2f \
	, double      : mc_atan2  \
	, long double : mc_atan2l \
) (y, mc_cast_exp(MC_TARGET_TYPEOF(y), x))
#	else
#	define mcmath_atan2(y, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_atan2f (mc_cast_exp(float, y), mc_cast_exp(float, x))             \
		: sizeof(x) == sizeof(double)      ? mc_atan2  (mc_cast_exp(double, y), mc_cast_exp(double, x))           \
		: sizeof(x) == sizeof(long double) ? mc_atan2l (mc_cast_exp(long double, y), mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cos -

#	ifndef mcmath_cos
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cos              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cos<float>       (const float& x)       { return mc_cosf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_cos<double>      (const double& x)      { return mc_cos(x);           }
template <>        MC_TARGET_INLINE long double mcmath_cos<long double> (const long double& x) { return mc_cosl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_cos (float x)       { return mc_cosf(x); }
MC_TARGET_ALIAS double      mcmath_cos (double x)      { return mc_cos(x);  }
MC_TARGET_ALIAS long double mcmath_cos (long double x) { return mc_cosl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cos(x) _Generic(x \
	, float       : mc_cosf \
	, double      : mc_cos  \
	, long double : mc_cosl \
) (x)
#	else
#	define mcmath_cos(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_cosf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_cos  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_cosl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sin -

#	ifndef mcmath_sin
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sin              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sin<float>       (const float& x)       { return mc_sinf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_sin<double>      (const double& x)      { return mc_sin(x);           }
template <>        MC_TARGET_INLINE long double mcmath_sin<long double> (const long double& x) { return mc_sinl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_sin (float x)       { return mc_sinf(x); }
MC_TARGET_ALIAS double      mcmath_sin (double x)      { return mc_sin(x);  }
MC_TARGET_ALIAS long double mcmath_sin (long double x) { return mc_sinl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sin(x) _Generic(x \
	, float       : mc_sinf \
	, double      : mc_sin  \
	, long double : mc_sinl \
) (x)
#	else
#	define mcmath_sin(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_sinf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_sin  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_sinl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tan -

#	ifndef mcmath_tan
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tan              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tan<float>       (const float& x)       { return mc_tanf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_tan<double>      (const double& x)      { return mc_tan(x);           }
template <>        MC_TARGET_INLINE long double mcmath_tan<long double> (const long double& x) { return mc_tanl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_tan (float x)       { return mc_tanf(x); }
MC_TARGET_ALIAS double      mcmath_tan (double x)      { return mc_tan(x);  }
MC_TARGET_ALIAS long double mcmath_tan (long double x) { return mc_tanl(x); }
#	elif MC_TARGET_C11
#	define mcmath_tan(x) _Generic(x \
	, float       : mc_tanf \
	, double      : mc_tan  \
	, long double : mc_tanl \
) (x)
#	else
#	define mcmath_tan(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_tanf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_tan  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_tanl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_acosh -

#	ifndef mcmath_acosh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_acosh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_acosh<float>       (const float& x)       { return mc_acoshf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_acosh<double>      (const double& x)      { return mc_acosh(x);         }
template <>        MC_TARGET_INLINE long double mcmath_acosh<long double> (const long double& x) { return mc_acoshl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_acosh (float x)       { return mc_acoshf(x); }
MC_TARGET_ALIAS double      mcmath_acosh (double x)      { return mc_acosh(x);  }
MC_TARGET_ALIAS long double mcmath_acosh (long double x) { return mc_acoshl(x); }
#	elif MC_TARGET_C11
#	define mcmath_acosh(x) _Generic(x \
	, float       : mc_acoshf \
	, double      : mc_acosh  \
	, long double : mc_acoshl \
) (x)
#	else
#	define mcmath_acosh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_acoshf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_acosh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_acoshl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_asinh -

#	ifndef mcmath_asinh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_asinh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_asinh<float>       (const float& x)       { return mc_asinhf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_asinh<double>      (const double& x)      { return mc_asinh(x);         }
template <>        MC_TARGET_INLINE long double mcmath_asinh<long double> (const long double& x) { return mc_asinhl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_asinh (float x)       { return mc_asinhf(x); }
MC_TARGET_ALIAS double      mcmath_asinh (double x)      { return mc_asinh(x);  }
MC_TARGET_ALIAS long double mcmath_asinh (long double x) { return mc_asinhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_asinh(x) _Generic(x \
	, float       : mc_asinhf \
	, double      : mc_asinh  \
	, long double : mc_asinhl \
) (x)
#	else
#	define mcmath_asinh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_asinhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_asinh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_asinhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_atanh -

#	ifndef mcmath_atanh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_atanh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_atanh<float>       (const float& x)       { return mc_atanhf(x);        }
template <>        MC_TARGET_INLINE double      mcmath_atanh<double>      (const double& x)      { return mc_atanh(x);         }
template <>        MC_TARGET_INLINE long double mcmath_atanh<long double> (const long double& x) { return mc_atanhl(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_atanh (float x)       { return mc_atanhf(x); }
MC_TARGET_ALIAS double      mcmath_atanh (double x)      { return mc_atanh(x);  }
MC_TARGET_ALIAS long double mcmath_atanh (long double x) { return mc_atanhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_atanh(x) _Generic(x \
	, float       : mc_atanhf \
	, double      : mc_atanh  \
	, long double : mc_atanhl \
) (x)
#	else
#	define mcmath_atanh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_atanhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_atanh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_atanhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cosh -

#	ifndef mcmath_cosh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cosh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cosh<float>       (const float& x)       { return mc_coshf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_cosh<double>      (const double& x)      { return mc_cosh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_cosh<long double> (const long double& x) { return mc_coshl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_cosh (float x)       { return mc_coshf(x); }
MC_TARGET_ALIAS double      mcmath_cosh (double x)      { return mc_cosh(x);  }
MC_TARGET_ALIAS long double mcmath_cosh (long double x) { return mc_coshl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cosh(x) _Generic(x \
	, float       : mc_coshf \
	, double      : mc_cosh  \
	, long double : mc_coshl \
) (x)
#	else
#	define mcmath_cosh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_coshf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_cosh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_coshl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sinh -

#	ifndef mcmath_sinh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sinh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sinh<float>       (const float& x)       { return mc_sinhf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_sinh<double>      (const double& x)      { return mc_sinh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_sinh<long double> (const long double& x) { return mc_sinhl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_sinh (float x)       { return mc_sinhf(x); }
MC_TARGET_ALIAS double      mcmath_sinh (double x)      { return mc_sinh(x);  }
MC_TARGET_ALIAS long double mcmath_sinh (long double x) { return mc_sinhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sinh(x) _Generic(x \
	, float       : mc_sinhf \
	, double      : mc_sinh  \
	, long double : mc_sinhl \
) (x)
#	else
#	define mcmath_sinh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_sinhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_sinh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_sinhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tanh -

#	ifndef mcmath_tanh
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tanh              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tanh<float>       (const float& x)       { return mc_tanhf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_tanh<double>      (const double& x)      { return mc_tanh(x);          }
template <>        MC_TARGET_INLINE long double mcmath_tanh<long double> (const long double& x) { return mc_tanhl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_tanh (float x)       { return mc_tanhf(x); }
MC_TARGET_ALIAS double      mcmath_tanh (double x)      { return mc_tanh(x);  }
MC_TARGET_ALIAS long double mcmath_tanh (long double x) { return mc_tanhl(x); }
#	elif MC_TARGET_C11
#	define mcmath_tanh(x) _Generic(x \
	, float       : mc_tanhf \
	, double      : mc_tanh  \
	, long double : mc_tanhl \
) (x)
#	else
#	define mcmath_tanh(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_tanhf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_tanh  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_tanhl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_exp -

#	ifndef mcmath_exp
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_exp              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_exp<float>       (const float& x)       { return mc_expf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_exp<double>      (const double& x)      { return mc_exp(x);           }
template <>        MC_TARGET_INLINE long double mcmath_exp<long double> (const long double& x) { return mc_expl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_exp (float x)       { return mc_expf(x); }
MC_TARGET_ALIAS double      mcmath_exp (double x)      { return mc_exp(x);  }
MC_TARGET_ALIAS long double mcmath_exp (long double x) { return mc_expl(x); }
#	elif MC_TARGET_C11
#	define mcmath_exp(x) _Generic(x \
	, float       : mc_expf \
	, double      : mc_exp  \
	, long double : mc_expl \
) (x)
#	else
#	define mcmath_exp(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_expf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_exp  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_expl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_exp2 -

#	ifndef mcmath_exp2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_exp2              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_exp2<float>       (const float& x)       { return mc_exp2f(x);         }
template <>        MC_TARGET_INLINE double      mcmath_exp2<double>      (const double& x)      { return mc_exp2(x);          }
template <>        MC_TARGET_INLINE long double mcmath_exp2<long double> (const long double& x) { return mc_exp2l(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_exp2 (float x)       { return mc_exp2f(x); }
MC_TARGET_ALIAS double      mcmath_exp2 (double x)      { return mc_exp2(x);  }
MC_TARGET_ALIAS long double mcmath_exp2 (long double x) { return mc_exp2l(x); }
#	elif MC_TARGET_C11
#	define mcmath_exp2(x) _Generic(x \
	, float       : mc_exp2f \
	, double      : mc_exp2  \
	, long double : mc_exp2l \
) (x)
#	else
#	define mcmath_exp2(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_exp2f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_exp2  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_exp2l (mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_exp10 (float x)       { return mc_exp10f(x); }
MC_TARGET_ALIAS double      mcmath_exp10 (double x)      { return mc_exp10(x);  }
MC_TARGET_ALIAS long double mcmath_exp10 (long double x) { return mc_exp10l(x); }
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
template <>        MC_TARGET_INLINE float       mcmath_expm1<float>       (const float& x)       { return mc_expm1f(x);        }
template <>        MC_TARGET_INLINE double      mcmath_expm1<double>      (const double& x)      { return mc_expm1(x);         }
template <>        MC_TARGET_INLINE long double mcmath_expm1<long double> (const long double& x) { return mc_expm1l(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_expm1 (float x)       { return mc_expm1f(x); }
MC_TARGET_ALIAS double      mcmath_expm1 (double x)      { return mc_expm1(x);  }
MC_TARGET_ALIAS long double mcmath_expm1 (long double x) { return mc_expm1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_expm1(x) _Generic(x \
	, float       : mc_expm1f \
	, double      : mc_expm1  \
	, long double : mc_expm1l \
) (x)
#	else
#	define mcmath_expm1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_expm1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_expm1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_expm1l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log -

#	ifndef mcmath_log
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log<float>       (const float& x)       { return mc_logf(x);          }
template <>        MC_TARGET_INLINE double      mcmath_log<double>      (const double& x)      { return mc_log(x);           }
template <>        MC_TARGET_INLINE long double mcmath_log<long double> (const long double& x) { return mc_logl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_log (float x)       { return mc_logf(x); }
MC_TARGET_ALIAS double      mcmath_log (double x)      { return mc_log(x);  }
MC_TARGET_ALIAS long double mcmath_log (long double x) { return mc_logl(x); }
#	elif MC_TARGET_C11
#	define mcmath_log(x) _Generic(x \
	, float       : mc_logf \
	, double      : mc_log  \
	, long double : mc_logl \
) (x)
#	else
#	define mcmath_log(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_logf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_logl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log10 -

#	ifndef mcmath_log10
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log10              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log10<float>       (const float& x)       { return mc_log10f(x);        }
template <>        MC_TARGET_INLINE double      mcmath_log10<double>      (const double& x)      { return mc_log10(x);         }
template <>        MC_TARGET_INLINE long double mcmath_log10<long double> (const long double& x) { return mc_log10l(x);        }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_log10 (float x)       { return mc_log10f(x); }
MC_TARGET_ALIAS double      mcmath_log10 (double x)      { return mc_log10(x);  }
MC_TARGET_ALIAS long double mcmath_log10 (long double x) { return mc_log10l(x); }
#	elif MC_TARGET_C11
#	define mcmath_log10(x) _Generic(x \
	, float       : mc_log10f \
	, double      : mc_log10  \
	, long double : mc_log10l \
) (x)
#	else
#	define mcmath_log10(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log10f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log10  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log10l (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_log2 -

#	ifndef mcmath_log2
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_log2              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_log2<float>       (const float& x)       { return mc_log2f(x);         }
template <>        MC_TARGET_INLINE double      mcmath_log2<double>      (const double& x)      { return mc_log2(x);          }
template <>        MC_TARGET_INLINE long double mcmath_log2<long double> (const long double& x) { return mc_log2l(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_log2 (float x)       { return mc_log2f(x); }
MC_TARGET_ALIAS double      mcmath_log2 (double x)      { return mc_log2(x);  }
MC_TARGET_ALIAS long double mcmath_log2 (long double x) { return mc_log2l(x); }
#	elif MC_TARGET_C11
#	define mcmath_log2(x) _Generic(x \
	, float       : mc_log2f \
	, double      : mc_log2  \
	, long double : mc_log2l \
) (x)
#	else
#	define mcmath_log2(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_log2f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_log2  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_log2l (mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_log1p (float x)       { return mc_log1pf(x); }
MC_TARGET_ALIAS double      mcmath_log1p (double x)      { return mc_log1p(x);  }
MC_TARGET_ALIAS long double mcmath_log1p (long double x) { return mc_log1pl(x); }
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
MC_TARGET_ALIAS float       mcmath_logp1 (float x)       { return mc_logp1f(x); }
MC_TARGET_ALIAS double      mcmath_logp1 (double x)      { return mc_logp1(x);  }
MC_TARGET_ALIAS long double mcmath_logp1 (long double x) { return mc_logp1l(x); }
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
MC_TARGET_ALIAS float       mcmath_log1m (float x)       { return mc_log1mf(x); }
MC_TARGET_ALIAS double      mcmath_log1m (double x)      { return mc_log1m(x);  }
MC_TARGET_ALIAS long double mcmath_log1m (long double x) { return mc_log1ml(x); }
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
MC_TARGET_ALIAS float       mcmath_log1pe (float x)       { return mc_log1pef(x); }
MC_TARGET_ALIAS double      mcmath_log1pe (double x)      { return mc_log1pe(x);  }
MC_TARGET_ALIAS long double mcmath_log1pe (long double x) { return mc_log1pel(x); }
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
MC_TARGET_ALIAS float       mcmath_log1me (float x)       { return mc_log1mef(x); }
MC_TARGET_ALIAS double      mcmath_log1me (double x)      { return mc_log1me(x);  }
MC_TARGET_ALIAS long double mcmath_log1me (long double x) { return mc_log1mel(x); }
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
MC_TARGET_ALIAS float       mcmath_logb (float x)       { return logbf(x); }
MC_TARGET_ALIAS double      mcmath_logb (double x)      { return logb(x);  }
MC_TARGET_ALIAS long double mcmath_logb (long double x) { return logbl(x); }
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
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_modf              (const T& x, T * y)                     { mc_cast(void, x); mc_cast(void, y); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_modf<float>       (const float& x, float * y)             { return mc_modff (x, y);                       }
template <>        MC_TARGET_INLINE double      mcmath_modf<double>      (const double& x, double * y)           { return mc_modf  (x, y);                       }
template <>        MC_TARGET_INLINE long double mcmath_modf<long double> (const long double& x, long double * y) { return mc_modfl (x, y);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_modf (float x, float * y)             { return mc_modff (x, y); }
MC_TARGET_ALIAS double      mcmath_modf (double x, double * y)           { return mc_modf  (x, y); }
MC_TARGET_ALIAS long double mcmath_modf (long double x, long double * y) { return mc_modfl (x, y); }
#	elif MC_TARGET_C11  && MC_TARGET_HAVE_TYPEOF
#	define mcmath_modf(x, y) _Generic(x \
	, float       : mc_modff \
	, double      : mc_modf  \
	, long double : mc_modfl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x) *, y))
#	else
#	define mcmath_modf(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_modff (mc_cast_exp(float, x), mc_cast_exp(float *, y))             \
		: sizeof(x) == sizeof(double)      ? mc_modf  (mc_cast_exp(double, x), mc_cast_exp(double *, y))           \
		: sizeof(x) == sizeof(long double) ? mc_modfl (mc_cast_exp(long double, x), mc_cast_exp(long double *, y)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_ldexp -

#	ifndef mcmath_ldexp
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_ldexp              (const T& x, int n)           { mc_cast(void, x); mc_cast(void, n); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_ldexp<float>       (const float& x, int n)       { return mc_ldexpf (x, n);                      }
template <>        MC_TARGET_INLINE double      mcmath_ldexp<double>      (const double& x, int n)      { return mc_ldexp  (x, n);                      }
template <>        MC_TARGET_INLINE long double mcmath_ldexp<long double> (const long double& x, int n) { return mc_ldexpl (x, n);                      }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_ldexp (float x, int n)       { return mc_ldexpf(x, n); }
MC_TARGET_ALIAS double      mcmath_ldexp (double x, int n)      { return mc_ldexp(x, n);  }
MC_TARGET_ALIAS long double mcmath_ldexp (long double x, int n) { return mc_ldexpl(x, n); }
#	elif MC_TARGET_C11
#	define mcmath_ldexp(x, n) _Generic(x \
	, float       : mc_ldexpf \
	, double      : mc_ldexp  \
	, long double : mc_ldexpl \
) (x, mc_cast_exp(int, n))
#	else
#	define mcmath_ldexp(x, n) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_ldexpf (mc_cast_exp(float, x), mc_cast_exp(int, n))       \
		: sizeof(x) == sizeof(double)      ? mc_ldexp  (mc_cast_exp(double, x), mc_cast_exp(int, n))      \
		: sizeof(x) == sizeof(long double) ? mc_ldexpl (mc_cast_exp(long double, x), mc_cast_exp(int, n)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_frexp -

#	ifndef mcmath_frexp
#	define mcmath_frexp(x, e) \
	( \
		  sizeof(x) == sizeof(float)       ? frexpf (mc_cast_exp(float, x), mc_cast_exp(int *, e))       \
		: sizeof(x) == sizeof(double)      ? frexp  (mc_cast_exp(double, x), mc_cast_exp(int *, e))      \
		: sizeof(x) == sizeof(long double) ? frexpl (mc_cast_exp(long double, x), mc_cast_exp(int *, e)) \
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
MC_TARGET_ALIAS float       mcmath_ilogb (float x)       { return ilogbf(x); }
MC_TARGET_ALIAS double      mcmath_ilogb (double x)      { return ilogb(x);  }
MC_TARGET_ALIAS long double mcmath_ilogb (long double x) { return ilogbl(x); }
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
template <class T> MC_TARGET_INLINE T           mcmath_fabs              (const T& x)           { return ::std::abs(x); }
template <>        MC_TARGET_INLINE float       mcmath_fabs<float>       (const float& x)       { return mc_fabsf (x);  }
template <>        MC_TARGET_INLINE double      mcmath_fabs<double>      (const double& x)      { return mc_fabs  (x);  }
template <>        MC_TARGET_INLINE long double mcmath_fabs<long double> (const long double& x) { return mc_fabsl (x);  }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_fabs (float x)       { return mc_fabsf(x); }
MC_TARGET_ALIAS double      mcmath_fabs (double x)      { return mc_fabs(x);  }
MC_TARGET_ALIAS long double mcmath_fabs (long double x) { return mc_fabsl(x); }
#	elif MC_TARGET_C11
#	define mcmath_fabs(x) _Generic(x \
	, float       : mc_fabsf \
	, double      : mc_fabs  \
	, long double : mc_fabsl \
) (x)
#	else
#	define mcmath_fabs(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_fabsf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_fabs  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_fabsl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_cbrt -

#	ifndef mcmath_cbrt
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_cbrt              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_cbrt<float>       (const float& x)       { return mc_cbrtf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_cbrt<double>      (const double& x)      { return mc_cbrt(x);          }
template <>        MC_TARGET_INLINE long double mcmath_cbrt<long double> (const long double& x) { return mc_cbrtl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_cbrt (float x)       { return mc_cbrtf(x); }
MC_TARGET_ALIAS double      mcmath_cbrt (double x)      { return mc_cbrt(x);  }
MC_TARGET_ALIAS long double mcmath_cbrt (long double x) { return mc_cbrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_cbrt(x) _Generic(x \
	, float       : mc_cbrtf \
	, double      : mc_cbrt  \
	, long double : mc_cbrtl \
) (x)
#	else
#	define mcmath_cbrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_cbrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_cbrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_cbrtl (mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_fhrt (float x)       { return mc_fhrtf(x); }
MC_TARGET_ALIAS double      mcmath_fhrt (double x)      { return mc_fhrt(x);  }
MC_TARGET_ALIAS long double mcmath_fhrt (long double x) { return mc_fhrtl(x); }
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

#	ifndef mcmath_rootn
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_rootn              (unsigned int n, const T& x)           { mc_cast(void, x); mc_cast(void, n); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_rootn<float>       (unsigned int n, const float& x)       { return mc_rootnf(n, x);                       }
template <>        MC_TARGET_INLINE double      mcmath_rootn<double>      (unsigned int n, const double& x)      { return mc_rootn(n, x);                        }
template <>        MC_TARGET_INLINE long double mcmath_rootn<long double> (unsigned int n, const long double& x) { return mc_rootnl(n, x);                       }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_rootn (unsigned int n, float x)       { return mc_rootnf(n, x); }
MC_TARGET_ALIAS double      mcmath_rootn (unsigned int n, double x)      { return mc_rootn(n, x);  }
MC_TARGET_ALIAS long double mcmath_rootn (unsigned int n, long double x) { return mc_rootnl(n, x); }
#	elif MC_TARGET_C11
#	define mcmath_rootn(n, x) _Generic(x \
	, float       : mc_rootnf \
	, double      : mc_rootn  \
	, long double : mc_rootnl \
) (mc_cast_exp(unsigned int, n), x)
#	else
#	define mcmath_rootn(n, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_rootnf (mc_cast_exp(unsigned int, n), mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_rootn  (mc_cast_exp(unsigned int, n), mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_rootnl (mc_cast_exp(unsigned int, n), mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_hypot -

#	ifndef mcmath_hypot
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_hypot              (const T& x, const T& y)                     { return mc_hypot(mc_cast(double, x), mc_cast(double, y)); }
template <>        MC_TARGET_INLINE float       mcmath_hypot<float>       (const float& x, const float& y)             { return mc_hypotf(x, y);                                  }
template <>        MC_TARGET_INLINE double      mcmath_hypot<double>      (const double& x, const double& y)           { return mc_hypot(x, y);                                   }
template <>        MC_TARGET_INLINE long double mcmath_hypot<long double> (const long double& x, const long double& y) { return mc_hypotl(x, y);                                  }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_hypot (float x, float y)             { return mc_hypotf(x, y); }
MC_TARGET_ALIAS double      mcmath_hypot (double x, double y)           { return mc_hypot(x, y);  }
MC_TARGET_ALIAS long double mcmath_hypot (long double x, long double y) { return mc_hypotl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_hypot(x, y) _Generic(x \
	, float       : mc_hypotf \
	, double      : mc_hypot  \
	, long double : mc_hypotl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_hypot(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_hypotf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_hypot  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_hypotl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
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
MC_TARGET_ALIAS float       mcmath_hypotc (float x, float y, float z)                   { return mc_hypotcf(x, y, z); }
MC_TARGET_ALIAS double      mcmath_hypotc (double x, double y, double z)                { return mc_hypotc(x, y, z);  }
MC_TARGET_ALIAS long double mcmath_hypotc (long double x, long double y, long double z) { return mc_hypotcl(x, y, z); }
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
MC_TARGET_ALIAS float       mcmath_hypotq (float x, float y)             { return mc_hypotqf(x, y); }
MC_TARGET_ALIAS double      mcmath_hypotq (double x, double y)           { return mc_hypotq(x, y);  }
MC_TARGET_ALIAS long double mcmath_hypotq (long double x, long double y) { return mc_hypotql(x, y); }
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
template <>        MC_TARGET_INLINE float       mcmath_pow<float>       (const float& x, const float& y)             { return mc_powf(x, y);                         }
template <>        MC_TARGET_INLINE double      mcmath_pow<double>      (const double& x, const double& y)           { return mc_pow(x, y);                          }
template <>        MC_TARGET_INLINE long double mcmath_pow<long double> (const long double& x, const long double& y) { return mc_powl(x, y);                         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_pow (float x, float y)             { return mc_powf(x, y); }
MC_TARGET_ALIAS double      mcmath_pow (double x, double y)           { return mc_pow(x, y);  }
MC_TARGET_ALIAS long double mcmath_pow (long double x, long double y) { return mc_powl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_pow(x, y) _Generic(x \
	, float       : mc_powf \
	, double      : mc_pow  \
	, long double : mc_powl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	else
#	define mcmath_pow(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_powf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_pow  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_powl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
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
MC_TARGET_ALIAS float       mcmath_pow2 (float x)       { return mc_pow2f(x); }
MC_TARGET_ALIAS double      mcmath_pow2 (double x)      { return mc_pow2(x);  }
MC_TARGET_ALIAS long double mcmath_pow2 (long double x) { return mc_pow2l(x); }
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
template <>        MC_TARGET_INLINE float       mcmath_sqrt<float>       (const float& x)       { return mc_sqrtf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_sqrt<double>      (const double& x)      { return mc_sqrt(x);          }
template <>        MC_TARGET_INLINE long double mcmath_sqrt<long double> (const long double& x) { return mc_sqrtl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_sqrt (float x)       { return mc_sqrtf(x); }
MC_TARGET_ALIAS double      mcmath_sqrt (double x)      { return mc_sqrt(x);  }
MC_TARGET_ALIAS long double mcmath_sqrt (long double x) { return mc_sqrtl(x); }
#	elif MC_TARGET_C11
#	define mcmath_sqrt(x) _Generic(x \
	, float       : mc_sqrtf \
	, double      : mc_sqrt  \
	, long double : mc_sqrtl \
) (x)
#	else
#	define mcmath_sqrt(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_sqrtf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_sqrt  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_sqrtl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_sqrt1pm1 -

#	ifndef mcmath_sqrt1pm1
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_sqrt1pm1              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_sqrt1pm1<float>       (const float& x)       { return mc_sqrt1pm1f(x);     }
template <>        MC_TARGET_INLINE double      mcmath_sqrt1pm1<double>      (const double& x)      { return mc_sqrt1pm1(x);      }
template <>        MC_TARGET_INLINE long double mcmath_sqrt1pm1<long double> (const long double& x) { return mc_sqrt1pm1l(x);     }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_sqrt1pm1 (float x)       { return mc_sqrt1pm1f(x); }
MC_TARGET_ALIAS double      mcmath_sqrt1pm1 (double x)      { return mc_sqrt1pm1(x);  }
MC_TARGET_ALIAS long double mcmath_sqrt1pm1 (long double x) { return mc_sqrt1pm1l(x); }
#	elif MC_TARGET_C11
#	define mcmath_sqrt1pm1(x) _Generic(x \
	, float       : mc_sqrt1pm1f \
	, double      : mc_sqrt1pm1  \
	, long double : mc_sqrt1pm1l \
) (x)
#	else
#	define mcmath_sqrt1pm1(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_sqrt1pm1f (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_sqrt1pm1  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_sqrt1pm1l (mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_rsqrt (float x)       { return mc_rsqrtf(x); }
MC_TARGET_ALIAS double      mcmath_rsqrt (double x)      { return mc_rsqrt(x);  }
MC_TARGET_ALIAS long double mcmath_rsqrt (long double x) { return mc_rsqrtl(x); }
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
template <>        MC_TARGET_INLINE float       mcmath_erf<float>       (const float& x)       { return mc_erff(x);          }
template <>        MC_TARGET_INLINE double      mcmath_erf<double>      (const double& x)      { return mc_erf(x);           }
template <>        MC_TARGET_INLINE long double mcmath_erf<long double> (const long double& x) { return mc_erfl(x);          }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_erf (float x)       { return mc_erff(x); }
MC_TARGET_ALIAS double      mcmath_erf (double x)      { return mc_erf(x);  }
MC_TARGET_ALIAS long double mcmath_erf (long double x) { return mc_erfl(x); }
#	elif MC_TARGET_C11
#	define mcmath_erf(x) _Generic(x \
	, float       : mc_erff \
	, double      : mc_erf  \
	, long double : mc_erfl \
) (x)
#	else
#	define mcmath_erf(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_erff (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_erf  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_erfl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_erfc -

#	ifndef mcmath_erfc
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_erfc              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_erfc<float>       (const float& x)       { return mc_erfcf(x);         }
template <>        MC_TARGET_INLINE double      mcmath_erfc<double>      (const double& x)      { return mc_erfc(x);          }
template <>        MC_TARGET_INLINE long double mcmath_erfc<long double> (const long double& x) { return mc_erfcl(x);         }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_erfc (float x)       { return mc_erfcf(x); }
MC_TARGET_ALIAS double      mcmath_erfc (double x)      { return mc_erfc(x);  }
MC_TARGET_ALIAS long double mcmath_erfc (long double x) { return mc_erfcl(x); }
#	elif MC_TARGET_C11
#	define mcmath_erfc(x) _Generic(x \
	, float       : mc_erfcf \
	, double      : mc_erfc  \
	, long double : mc_erfcl \
) (x)
#	else
#	define mcmath_erfc(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_erfcf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_erfc  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_erfcl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_lgamma -

#	ifndef mcmath_lgamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_lgamma              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_lgamma<float>       (const float& x)       { return mc_lgammaf(x);       }
template <>        MC_TARGET_INLINE double      mcmath_lgamma<double>      (const double& x)      { return mc_lgamma(x);        }
template <>        MC_TARGET_INLINE long double mcmath_lgamma<long double> (const long double& x) { return mc_lgammal(x);       }
#	elif MC_TARGET_C11
#	define mcmath_lgamma(x) _Generic(x \
	, float       : mc_lgammaf \
	, double      : mc_lgamma  \
	, long double : mc_lgammal \
) (x)
#	else
#	define mcmath_lgamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_lgammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_lgamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_lgammal (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_tgamma -

#	ifndef mcmath_tgamma
#	if MC_TARGET_CPP98
template <class T> MC_TARGET_INLINE T           mcmath_tgamma              (const T& x)           { mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_tgamma<float>       (const float& x)       { return mc_tgammaf(x);       }
template <>        MC_TARGET_INLINE double      mcmath_tgamma<double>      (const double& x)      { return mc_tgamma(x);        }
template <>        MC_TARGET_INLINE long double mcmath_tgamma<long double> (const long double& x) { return mc_tgammal(x);       }
#	elif MC_TARGET_C11
#	define mcmath_tgamma(x) _Generic(x \
	, float       : mc_tgammaf \
	, double      : mc_tgamma  \
	, long double : mc_tgammal \
) (x)
#	else
#	define mcmath_tgamma(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_tgammaf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_tgamma  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_tgammal (mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_digamma (float x)       { return mc_digammaf(x); }
MC_TARGET_ALIAS double      mcmath_digamma (double x)      { return mc_digamma(x);  }
MC_TARGET_ALIAS long double mcmath_digamma (long double x) { return mc_digammal(x); }
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
MC_TARGET_ALIAS float       mcmath_trigamma (float x)       { return mc_trigammaf(x); }
MC_TARGET_ALIAS double      mcmath_trigamma (double x)      { return mc_trigamma(x);  }
MC_TARGET_ALIAS long double mcmath_trigamma (long double x) { return mc_trigammal(x); }
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
	, float       : mc_ceilf \
	, double      : mc_ceil  \
	, long double : mc_ceill \
) (x)
#	else
#	define mcmath_ceil(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_ceilf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_ceil  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_ceill (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_floor -

#	ifndef mcmath_floor
#	if MC_TARGET_C11
#	define mcmath_floor(x) _Generic(x \
	, float       : mc_floorf \
	, double      : mc_floor  \
	, long double : mc_floorl \
) (x)
#	else
#	define mcmath_floor(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_floorf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_floor  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_floorl (mc_cast_exp(long double, x)) \
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
	, float       : mc_truncf \
	, double      : mc_trunc  \
	, long double : mc_truncl \
) (x)
#	else
#	define mcmath_trunc(x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_truncf (mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_trunc  (mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_truncl (mc_cast_exp(long double, x)) \
		: 0 \
	)
#	endif
#	endif

#pragma mark - mcmath_fmod -

#	ifndef mcmath_fmod
#	define mcmath_fmod(x, y) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_fmodf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: sizeof(x) == sizeof(double)      ? mc_fmod  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: sizeof(x) == sizeof(long double) ? mc_fmodl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
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

template <class T> MC_TARGET_INLINE T                    mcmath_abs                      (const T& x)                  { return ::std::abs(x); }
template <>        MC_TARGET_INLINE float                mcmath_abs<float>               (const float& x)              { return mc_fabsf(x);   }
template <>        MC_TARGET_INLINE double               mcmath_abs<double>              (const double& x)             { return mc_fabs(x);    }
template <>        MC_TARGET_INLINE long double          mcmath_abs<long double>         (const long double& x)        { return mc_fabsl(x);   }

template <>        MC_TARGET_INLINE signed char          mcmath_abs<signed char>         (const signed char& x)        { return mc_babs(x);    }
template <>        MC_TARGET_INLINE short                mcmath_abs<short>               (const short& x)              { return mc_sabs(x);    }
template <>        MC_TARGET_INLINE int                  mcmath_abs<int>                 (const int& x)                { return mc_iabs(x);    }
template <>        MC_TARGET_INLINE long                 mcmath_abs<long>                (const long& x)               { return mc_labs(x);    }

template <>        MC_TARGET_INLINE unsigned char        mcmath_abs<unsigned char>       (const unsigned char& x)      { return x;             }
template <>        MC_TARGET_INLINE unsigned short       mcmath_abs<unsigned short>      (const unsigned short& x)     { return x;             }
template <>        MC_TARGET_INLINE unsigned int         mcmath_abs<unsigned int>        (const unsigned int& x)       { return x;             }
template <>        MC_TARGET_INLINE unsigned long        mcmath_abs<unsigned long>       (const unsigned long& x)      { return x;             }

#	if MC_TARGET_CPP11
template <>        MC_TARGET_INLINE long long            mcmath_abs<long long>           (const long long& x)          { return x;             }
template <>        MC_TARGET_INLINE unsigned long long   mcmath_abs<unsigned  long long> (const unsigned long long& x) { return x;             }
#	endif

#	elif MC_TARGET_C11

#	define mcmath_abs(x) _Generic(x \
	, float              : mc_fabsf            \
	, double             : mc_fabs             \
	, long double        : mc_fabsl            \
	, signed char        : mc_babs             \
	, short              : mc_sabs             \
	, int                : mc_iabs             \
	, long               : mc_labs             \
	, long long          : mc_llabs            \
	, unsigned char      : MC_TARGET_UCHAR     \
	, unsigned short     : MC_TARGET_USHORT    \
	, unsigned int       : MC_TARGET_UINT      \
	, unsigned long      : MC_TARGET_ULONG     \
	, unsigned long long : MC_TARGET_ULONGLONG \
) (x)
#	elif MC_TARGET_HAVE_TYPEOF
#		if MC_TARGET_C99
#		define mcmath_abs(x) mc_cast(MC_TARGET_TYPEOF(x), \
		( \
			  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)              ? mc_fabsf (mc_cast_exp(float, x))       \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)             ? mc_fabs  (mc_cast_exp(double, x))      \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double)        ? mc_fabsl (mc_cast_exp(long double, x)) \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), signed char)        ? mc_babs  (mc_cast_exp(signed char, x)) \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), short)              ? mc_sabs  (mc_cast_exp(short, x))       \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), int)                ? mc_iabs  (mc_cast_exp(int,x))          \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long)               ? mc_labs  (mc_cast_exp(long, x))        \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long long)          ? mc_llabs (mc_cast_exp(long long, x))   \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned char)      ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned short)     ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned int)       ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long)      ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long long) ? (x)                                    \
			: 0 \
		))
#		else
#		define mcmath_abs(x) mc_cast(MC_TARGET_TYPEOF(x), \
		( \
			  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)              ? mc_fabsf (mc_cast_exp(float, x))       \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)             ? mc_fabs  (mc_cast_exp(double, x))      \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double)        ? mc_fabsl (mc_cast_exp(long double, x)) \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), signed char)        ? mc_babs  (mc_cast_exp(signed char, x)) \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), short)              ? mc_sabs  (mc_cast_exp(short, x))       \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), int)                ? mc_iabs  (mc_cast_exp(int,x))          \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long)               ? mc_labs  (mc_cast_exp(long, x))        \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned char)      ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned short)     ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned int)       ? (x)                                    \
			: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), unsigned long)      ? (x)                                    \
			: 0 \
		))
#		endif
#	else
#	define mcmath_abs(x) mc_absmag(x)
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

#	elif MC_TARGET_C99 && MC_TARGET_HAVE_AUTOTYPE
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
#	elif MC_TARGET_C99 && MC_TARGET_HAVE_TYPEOF
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
#	define mcmath_max(a, b) mc_maxmag(a, b)
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

#	elif MC_TARGET_C99 && MC_TARGET_HAVE_AUTOTYPE
#	define mcmath_min(a, b) \
	__extension__ ({ \
		MC_TARGET_AUTOTYPE __mcmath_min_aa = (a); \
		MC_TARGET_AUTOTYPE __mcmath_min_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_min_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), float)       ? fminf (mc_cast(float, __mcmath_min_aa), mc_cast(float, __mcmath_min_bb))             \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), double)      ? fmin  (mc_cast(double, __mcmath_min_aa), mc_cast(double, __mcmath_min_bb))           \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), long double) ? fminl (mc_cast(long double, __mcmath_min_aa), mc_cast(long double, __mcmath_min_bb)) \
		: (__mcmath_min_aa < __mcmath_min_bb ? __mcmath_min_aa : __mcmath_min_bb)                                                                                     \
		)); \
	})
#	elif MC_TARGET_C99 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_min(a, b) \
	__extension__ ({ \
		MC_TARGET_TYPEOF((a)) __mcmath_min_aa = (a); \
		MC_TARGET_TYPEOF((b)) __mcmath_min_bb = (b); \
		mc_cast(MC_TARGET_TYPEOF(__mcmath_min_aa), \
		( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), float)       ? fminf (mc_cast(float, __mcmath_min_aa), mc_cast(float, __mcmath_min_bb))             \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), double)      ? fmin  (mc_cast(double, __mcmath_min_aa), mc_cast(double, __mcmath_min_bb))           \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF((__mcmath_min_aa)), long double) ? fminl (mc_cast(long double, __mcmath_min_aa), mc_cast(long double, __mcmath_min_bb)) \
		: (__mcmath_min_aa < __mcmath_min_bb ? __mcmath_min_aa : __mcmath_min_bb)                                                                                     \
		)); \
	})
#	else
#	define mcmath_min(a, b) mc_minmag(a, b)
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
MC_TARGET_ALIAS float       mcmath_i0 (float x)       { return mc_i0f(x); }
MC_TARGET_ALIAS double      mcmath_i0 (double x)      { return mc_i0(x);  }
MC_TARGET_ALIAS long double mcmath_i0 (long double x) { return mc_i0l(x); }
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
MC_TARGET_ALIAS float       mcmath_i1 (float x)       { return mc_i1f(x); }
MC_TARGET_ALIAS double      mcmath_i1 (double x)      { return mc_i1(x);  }
MC_TARGET_ALIAS long double mcmath_i1 (long double x) { return mc_i1l(x); }
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
MC_TARGET_ALIAS float       mcmath_in (int n, float x)       { return mc_inf(n, x); }
MC_TARGET_ALIAS double      mcmath_in (int n, double x)      { return mc_in(n, x);  }
MC_TARGET_ALIAS long double mcmath_in (int n, long double x) { return mc_inl(n, x); }
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_in(n, x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_inf (mc_cast_exp(int, n), mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_in  (mc_cast_exp(int, n), mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_inl (mc_cast_exp(int, n), mc_cast_exp(long double, x)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_j0 (float x)       { return mc_j0f(x); }
MC_TARGET_ALIAS double      mcmath_j0 (double x)      { return mc_j0(x);  }
MC_TARGET_ALIAS long double mcmath_j0 (long double x) { return mc_j0l(x); }
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
MC_TARGET_ALIAS float       mcmath_j1 (float x)       { return mc_j1f(x); }
MC_TARGET_ALIAS double      mcmath_j1 (double x)      { return mc_j1(x);  }
MC_TARGET_ALIAS long double mcmath_j1 (long double x) { return mc_j1l(x); }
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
MC_TARGET_ALIAS float       mcmath_jn (int n, float x)       { return mc_jnf(n, x); }
MC_TARGET_ALIAS double      mcmath_jn (int n, double x)      { return mc_jn(n, x);  }
MC_TARGET_ALIAS long double mcmath_jn (int n, long double x) { return mc_jnl(n, x); }
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_jn(n, x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_jnf (mc_cast_exp(int, n), mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_jn  (mc_cast_exp(int, n), mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_jnl (mc_cast_exp(int, n), mc_cast_exp(long double, x)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_y0 (float x)       { return mc_y0f(x); }
MC_TARGET_ALIAS double      mcmath_y0 (double x)      { return mc_y0(x);  }
MC_TARGET_ALIAS long double mcmath_y0 (long double x) { return mc_y0l(x); }
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
MC_TARGET_ALIAS float       mcmath_y1 (float x)       { return mc_y1f(x); }
MC_TARGET_ALIAS double      mcmath_y1 (double x)      { return mc_y1(x);  }
MC_TARGET_ALIAS long double mcmath_y1 (long double x) { return mc_y1l(x); }
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
MC_TARGET_ALIAS float       mcmath_yn (int n, float x)       { return mc_ynf(n, x); }
MC_TARGET_ALIAS double      mcmath_yn (int n, double x)      { return mc_yn(n, x);  }
MC_TARGET_ALIAS long double mcmath_yn (int n, long double x) { return mc_ynl(n, x); }
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_yn(n, x) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_ynf (mc_cast_exp(int, n), mc_cast_exp(float, x))       \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_yn  (mc_cast_exp(int, n), mc_cast_exp(double, x))      \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_ynl (mc_cast_exp(int, n), mc_cast_exp(long double, x)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_scalb (float x, float y)             { return mc_scalbf(x, y); }
MC_TARGET_ALIAS double      mcmath_scalb (double x, double y)           { return mc_scalb(x, y);  }
MC_TARGET_ALIAS long double mcmath_scalb (long double x, long double y) { return mc_scalbl(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_lbeta(x, y) _Generic(x \
	, float       : mcmath_scalbf \
	, double      : mcmath_scalb  \
	, long double : mcmath_scalbl \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_scalb(x, y) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_scalbf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_scalb  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_scalbl (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_ibeta (float a, float b, float x)                   { return mc_ibetaf(a, b, x); }
MC_TARGET_ALIAS double      mcmath_ibeta (double a, double b, double x)                { return mc_ibeta(a, b, x);  }
MC_TARGET_ALIAS long double mcmath_ibeta (long double a, long double b, long double x) { return mc_ibetal(a, b, x); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_ibeta(a, b, x) _Generic(a \
	, float       : mc_ibetaf \
	, double      : mc_ibeta  \
	, long double : mc_ibetal \
) (a, mc_cast_exp(MC_TARGET_TYPEOF(a), b), mc_cast_exp(MC_TARGET_TYPEOF(a), x))
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_ibeta(a, b, x) mc_cast(MC_TARGET_TYPEOF(a), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(a), float)       ? mc_ibetaf (mc_cast_exp(float, a), mc_cast_exp(float, b), mc_cast_exp(float, x))                   \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(a), double)      ? mc_ibeta  (mc_cast_exp(double, a), mc_cast_exp(double, b), mc_cast_exp(double, x))                \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(a), long double) ? mc_ibetal (mc_cast_exp(long double, a), mc_cast_exp(long double, b), mc_cast_exp(long double, x)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_lbeta (float x, float y)             { return mc_lbetaf(x, y); }
MC_TARGET_ALIAS double      mcmath_lbeta (double x, double y)           { return mc_lbeta(x, y);  }
MC_TARGET_ALIAS long double mcmath_lbeta (long double x, long double y) { return mc_lbetal(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_lbeta(x, y) _Generic(x \
	, float       : mc_lbetaf \
	, double      : mc_lbeta  \
	, long double : mc_lbetal \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_lbeta(x, y) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_lbetaf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_lbeta  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_lbetal (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_beta (float x, float y)             { return mc_betaf(x, y); }
MC_TARGET_ALIAS double      mcmath_beta (double x, double y)           { return mc_beta(x, y);  }
MC_TARGET_ALIAS long double mcmath_beta (long double x, long double y) { return mc_betal(x, y); }
#	elif MC_TARGET_C11 && MC_TARGET_HAVE_TYPEOF
#	define mcmath_beta(x, y) _Generic(x \
	, float       : mc_betaf \
	, double      : mc_beta  \
	, long double : mc_betal \
) (x, mc_cast_exp(MC_TARGET_TYPEOF(x), y))
#	elif MC_TARGET_HAVE_TYPEOF
#	define mcmath_beta(x, y) mc_cast(MC_TARGET_TYPEOF(x), \
	( \
		  MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), float)       ? mc_betaf (mc_cast_exp(float, x), mc_cast_exp(float, y))             \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), double)      ? mc_beta  (mc_cast_exp(double, x), mc_cast_exp(double, y))           \
		: MC_TARGET_TYPEISOF(MC_TARGET_TYPEOF(x), long double) ? mc_betal (mc_cast_exp(long double, x), mc_cast_exp(long double, y)) \
		: 0 \
	))
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
MC_TARGET_ALIAS float       mcmath_xlogy (float x, float y)             { return mc_xlogyf(x, y); }
MC_TARGET_ALIAS double      mcmath_xlogy (double x, double y)           { return mc_xlogy(x, y);  }
MC_TARGET_ALIAS long double mcmath_xlogy (long double x, long double y) { return mc_xlogyl(x, y); }
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
MC_TARGET_ALIAS float       mcmath_xlog1py (float x, float y)             { return mc_xlog1pyf(x, y); }
MC_TARGET_ALIAS double      mcmath_xlog1py (double x, double y)           { return mc_xlog1py(x, y);  }
MC_TARGET_ALIAS long double mcmath_xlog1py (long double x, long double y) { return mc_xlog1pyl(x, y); }
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
MC_TARGET_ALIAS float       mcmath_xlog1px (float x)       { return mc_xlog1pxf(x); }
MC_TARGET_ALIAS double      mcmath_xlog1px (double x)      { return mc_xlog1px(x);  }
MC_TARGET_ALIAS long double mcmath_xlog1px (long double x) { return mc_xlog1pxl(x); }
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
MC_TARGET_ALIAS float       mcmath_xlogx (float x)       { return mc_xlogxf(x); }
MC_TARGET_ALIAS double      mcmath_xlogx (double x)      { return mc_xlogx(x);  }
MC_TARGET_ALIAS long double mcmath_xlogx (long double x) { return mc_xlogxl(x); }
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
template <class T> MC_TARGET_INLINE T           mcmath_logradix              (unsigned int n, const T& x)           { mc_cast(void, n); mc_cast(void, x); return 0; }
template <>        MC_TARGET_INLINE float       mcmath_logradix<float>       (unsigned int n, const float& x)       { return mc_logradixf(n, x);                    }
template <>        MC_TARGET_INLINE double      mcmath_logradix<double>      (unsigned int n ,const double& x)      { return mc_logradix(n, x);                     }
template <>        MC_TARGET_INLINE long double mcmath_logradix<long double> (unsigned int n, const long double& x) { return mc_logradixl(n, x);                    }
#	elif MC_TARGET_HAVE_OVERLOADABLE
MC_TARGET_ALIAS float       mcmath_logradix (unsigned int n, float x)       { return mc_logradixf(n, x); }
MC_TARGET_ALIAS double      mcmath_logradix (unsigned int n, double x)      { return mc_logradix(n, x);  }
MC_TARGET_ALIAS long double mcmath_logradix (unsigned int n, long double x) { return mc_logradixl(n, x); }
#	elif MC_TARGET_C11
#	define mcmath_logradix(n, x) _Generic(x \
	, float       : mc_logradixf \
	, double      : mc_logradix  \
	, long double : mc_logradixl \
) (mc_cast_exp(unsigned int, n), x)
#	else
#	define mcmath_logradix(n, x) \
	( \
		  sizeof(x) == sizeof(float)       ? mc_logradixf (mc_cast_exp(unsigned int, n), mc_cast_exp(float, x))       \
		: sizeof(x) == sizeof(double)      ? mc_logradix  (mc_cast_exp(unsigned int, n), mc_cast_exp(double, x))      \
		: sizeof(x) == sizeof(long double) ? mc_logradixl (mc_cast_exp(unsigned int, n), mc_cast_exp(long double, x)) \
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
MC_TARGET_ALIAS float       mcmath_lerp (float x, float y, float z)                   { return mc_lerpf(x, y, z); }
MC_TARGET_ALIAS double      mcmath_lerp (double x, double y, double z)                { return mc_lerp(x, y, z);  }
MC_TARGET_ALIAS long double mcmath_lerp (long double x, long double y, long double z) { return mc_lerpl(x, y, z); }
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
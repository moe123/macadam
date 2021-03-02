//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lgamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_copysign.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fisint.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sin.h>
#include <macadam/details/math/mc_sinpi.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_LGAMMA_H
#define MC_LGAMMA_H

#pragma mark - mc_lgamma_approx0 -

MC_TARGET_PROC float mc_lgammaf_approx0(const float x)
{
//!# Stirling's formula for x >= 13.
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x * MCK_KF(MCK_1_E);
	return mc_logf(mc_sqrtf(a) * mc_powf(b, x));
}

MC_TARGET_PROC double mc_lgamma_approx0(const double x)
{
//!# Stirling's formula formula for x >= 13.
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x * MCK_K(MCK_1_E);
	return mc_log(mc_sqrt(a) * mc_pow(b, x));
}

MC_TARGET_PROC long double mc_lgammal_approx0(const long double x)
{
//!# Stirling's formula formula for x >= 13.
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x * MCK_KL(MCK_1_E);
	return mc_logl(mc_sqrtl(a) * mc_powl(b, x));
}

#pragma mark - mc_lgamma_approx1 -

MC_TARGET_PROC float mc_lgammaf_approx1(const float x, int * sign)
{
//!# Hybrid Lanczos approximation, computes log(|gamma(x)|).
	const float lanczos_g  = +5.000000000000000000000000000000000000E+00f;
	const float lanczos_c0 = +1.000000000190014892709200466924812644E+00f;
	const float lanczos_c1 = +7.618009172947145657417422626167535781E+01f;
	const float lanczos_c2 = -8.650532032941677584858553018420934677E+01f;
	const float lanczos_c3 = +2.401409824083091137936207815073430538E+01f;
	const float lanczos_c4 = -1.231739572450154973637381772277876734E+00f;
	const float lanczos_c5 = +1.208650973866179020865807558493543183E-03f;
	const float lanczos_c6 = -5.395239384953000327544564429516071868E-06f;

	const int have_sign    = mc_nonnullptr(sign);
	float s = 0.0f, a, b, r;

	if (x >= 0.5f) {
		if (have_sign) {
			*sign = +1;
		}
		a = x - 1.0f;
		b = a + lanczos_g + 0.5f;
		s = s + (lanczos_c6 / (a + 6.0f));
		s = s + (lanczos_c5 / (a + 5.0f));
		s = s + (lanczos_c4 / (a + 4.0f));
		s = s + (lanczos_c3 / (a + 3.0f));
		s = s + (lanczos_c2 / (a + 2.0f));
		s = s + (lanczos_c1 / (a + 1.0f));
		s = s + lanczos_c0;
		r  = ((MCK_KF(MCK_LOGESQRT2PI) + mc_logf(s)) - b) + mc_logf(b) * (a + 0.5f);
	} else if (x == 0.0f) {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_copysignf(MCK_INF, x);
	} else if (x < 0.0f) {
		r = x * mc_sinpif(x);
		if (have_sign) {
			*sign = r < 0.0f ? +1 : -1;
		}
		r = mc_fabsf(MCK_KF(MCK_PI) / r);
		r = mc_logf(r) - mc_lgammaf_approx1(-x, MC_NULLPTR);
	} else {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_sinpif(x);
		r = MCK_KF(MCK_PI) / r;
		r = mc_logf(r) - mc_lgammaf_approx1(1.0f - x, MC_NULLPTR);
	}
	return r;
}

MC_TARGET_PROC double mc_lgamma_approx1(const double x, int * sign)
{
//!# Hybrid Lanczos approximation, computes log(|gamma(x)|).
	const double lanczos_g  = +5.0000000000000000000000000000000000000000E+00;
	const double lanczos_c0 = +1.0000000001900148927092004669248126447201E+00;
	const double lanczos_c1 = +7.6180091729471456574174226261675357818604E+01;
	const double lanczos_c2 = -8.6505320329416775848585530184209346771240E+01;
	const double lanczos_c3 = +2.4014098240830911379362078150734305381775E+01;
	const double lanczos_c4 = -1.2317395724501549736373817722778767347336E+00;
	const double lanczos_c5 = +1.2086509738661790208658075584935431834310E-03;
	const double lanczos_c6 = -5.3952393849530003275445644295160718684201E-06;

	const int have_sign     = mc_nonnullptr(sign);
	double s = 0.0, a, b, r;

	if (x >= 0.5) {
		if (have_sign) {
			*sign = +1;
		}
		a = x - 1.0;
		b = a + lanczos_g + 0.5;
		s = s + (lanczos_c6 / (a + 6.0));
		s = s + (lanczos_c5 / (a + 5.0));
		s = s + (lanczos_c4 / (a + 4.0));
		s = s + (lanczos_c3 / (a + 3.0));
		s = s + (lanczos_c2 / (a + 2.0));
		s = s + (lanczos_c1 / (a + 1.0));
		s = s + lanczos_c0;
		r  = ((MCK_K(MCK_LOGESQRT2PI) + mc_log(s)) - b) + mc_log(b) * (a + 0.5);
	} else if (x == 0.0) {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_copysign(MCK_INF, x);
	} else if (x < 0.0) {
		r = x * mc_sinpi(x);
		if (have_sign) {
			*sign = r < 0.0 ? +1 : -1;
		}
		r = mc_fabs(MCK_K(MCK_PI) / r);
		r = mc_log(r) - mc_lgamma_approx1(-x, MC_NULLPTR);
	} else {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_sinpi(x);
		r = MCK_K(MCK_PI) / r;
		r = mc_log(r) - mc_lgamma_approx1(1.0 - x, MC_NULLPTR);
	}
	return r;
}

MC_TARGET_PROC long double mc_lgammal_approx1(const long double x, int * sign)
{
//!# Hybrid Lanczos approximation, computes log(|gamma(x)|).
#	if !MC_TARGET_LONG_DOUBLE_UNAVAILABLE
	const long double lanczos_g  = +5.000000000000000000000000000000000000000000000000000000000000000E+00L;
	const long double lanczos_c0 = +1.000000000190014892709200466924812644720077514648437500000000000E+00L;
	const long double lanczos_c1 = +7.618009172947145657417422626167535781860351562500000000000000000E+01L;
	const long double lanczos_c2 = -8.650532032941677584858553018420934677124023437500000000000000000E+01L;
	const long double lanczos_c3 = +2.401409824083091137936207815073430538177490234375000000000000000E+01L;
	const long double lanczos_c4 = -1.231739572450154973637381772277876734733581542968750000000000000E+00L;
	const long double lanczos_c5 = +1.208650973866179020865807558493543183431029319763183593750000000E-03L;
	const long double lanczos_c6 = -5.395239384953000327544564429516071868420112878084182739257812500E-06L;

	const int have_sign          = mc_nonnullptr(sign);
	long double s = 0.0L, a, b, r;

	if (x >= 0.5L) {
		if (have_sign) {
			*sign = +1;
		}
		a = x - 1.0L;
		b = a + lanczos_g + 0.5L;
		s = s + (lanczos_c6 / (a + 6.0L));
		s = s + (lanczos_c5 / (a + 5.0L));
		s = s + (lanczos_c4 / (a + 4.0L));
		s = s + (lanczos_c3 / (a + 3.0L));
		s = s + (lanczos_c2 / (a + 2.0L));
		s = s + (lanczos_c1 / (a + 1.0L));
		s = s + lanczos_c0;
		r  = ((MCK_KL(MCK_LOGESQRT2PI) + mc_logl(s)) - b) + mc_logl(b) * (a + 0.5L);
	} else if (x == 0.0L) {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_copysignl(MCK_INF, x);
	} else if (x < 0.0) {
		r = x * mc_sinpil(x);
		if (have_sign) {
			*sign = r < 0.0L ? +1 : -1;
		}
		r = mc_fabsl(MCK_KL(MCK_PI) / r);
		r = mc_logl(r) - mc_lgammal_approx1(-x, MC_NULLPTR);
	} else {
		if (have_sign) {
			*sign = +1;
		}
		r = mc_sinpil(x);
		r = MCK_KL(MCK_PI) / r;
		r = mc_logl(r) - mc_lgammal_approx1(1.0 - x, MC_NULLPTR);
	}
	return r;
#	else
	const double xx = mc_cast(double, x);
	return mc_cast(long double, mc_lgamma_approx1(xx, sign));
#	endif
}

#pragma mark - mc_lgamma -

MC_TARGET_FUNC float mc_lgammaf(const float x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0.0f && mc_fisintf(x)) {
		return MCK_INFP;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f || x == 2.0f) {
		return 0.0f;
	}
	const float y = mc_fabsf(x);
	if (y <= FLT_MIN) {
		return -mc_logf(y);
	}
	if (y > (MCLIMITS_MAXF / mc_logf(MCLIMITS_MAXF))) {
		return MCK_INFP;
	}
	return mc_lgammaf_approx1(x, MC_NULLPTR);
#	else
#	if MC_TARGET_CPP98
	return ::lgammaf(x);
#	else
	return lgammaf(x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_lgamma(const double x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0.0 && mc_fisint(x)) {
		return MCK_INFP;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0 || x == 2.0) {
		return 0.0;
	}
	const double y = mc_fabs(x);
	if (y <= DBL_MIN) {
		return -mc_log(y);
	}
	if (y > (MCLIMITS_MAX / mc_log(MCLIMITS_MAX))) {
		return MCK_INFP;
	}
	return mc_lgamma_approx1(x, MC_NULLPTR);
#	else
#	if MC_TARGET_CPP98
	return ::lgamma(x);
#	else
	return lgamma(x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_lgammal(const long double x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0.0L && mc_fisintl(x)) {
		return MCK_INFP;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L || x == 2.0L) {
		return 0.0L;
	}
	const long double y = mc_fabsl(x);
	if (y <= LDBL_MIN) {
		return -mc_logl(y);
	}
	if (y > (MCLIMITS_MAXL / mc_logl(MCLIMITS_MAXL))) {
		return MCK_INFP;
	}
	return mc_lgammal_approx1(x, MC_NULLPTR);
#	else
#	if MC_TARGET_CPP98
	return ::lgammal(x);
#	else
	return lgammal(x);
#	endif
#	endif
}

#endif /* !MC_LGAMMA_H */

/* EOF */
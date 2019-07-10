//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lgamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_sin.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/math/mc_trunc.h>

#ifndef MC_LGAMMA_H
#define MC_LGAMMA_H

#pragma mark - mc_lgamma_approx0 -

static MC_TARGET_INLINE double mc_lgammaf_approx0(float x)
{
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x * MCK_KF(MCK_1_E);
	return mc_logf(mc_sqrtf(a) * mc_powf(b, x));
}

static MC_TARGET_INLINE double mc_lgamma_approx0(double x)
{
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x * MCK_K(MCK_1_E);
	return mc_log(mc_sqrt(a) * mc_pow(b, x));
}

static MC_TARGET_INLINE long double mc_lgammal_approx0(long double x)
{
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x * MCK_KL(MCK_1_E);
	return mc_logl(mc_sqrtl(a) * mc_powl(b, x));
}

#pragma mark - mc_lgamma -

static MC_TARGET_INLINE float mc_lgammaf(float x)
{
#	if MC_TARGET_EMBEDDED
	const float lanczos_g  = +5.000000000000000000000000000000000000E+00f;
	const float lanczos_c0 = +1.000000000190014892709200466924812644E+00f;
	const float lanczos_c1 = +7.618009172947145657417422626167535781E+01f;
	const float lanczos_c2 = -8.650532032941677584858553018420934677E+01f;
	const float lanczos_c3 = +2.401409824083091137936207815073430538E+01f;
	const float lanczos_c4 = -1.231739572450154973637381772277876734E+00f;
	const float lanczos_c5 = +1.208650973866179020865807558493543183E-03f;
	const float lanczos_c6 = -5.395239384953000327544564429516071868E-06f;
	float s, b, r = MCK_NAN;

	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0 && x == mc_truncf(x)) {
		return MCK_INFP;
	}
	const float y = mc_fabsf(x);
	if (y <= FLT_MIN) {
		return -mc_logf(y);
	}
	if (y > (MCLIMITS_MAXF / mc_logf(MCLIMITS_MAXF))) {
		return MCK_INFP;
	}
	if (x >= 0.5f) {
		x  = x - 1.0f;
		b  = x + lanczos_g + 0.5f;
		s  = lanczos_c6 / (x + 6.0f);
		s += lanczos_c5 / (x + 5.0f);
		s += lanczos_c4 / (x + 4.0f);
		s += lanczos_c3 / (x + 3.0f);
		s += lanczos_c2 / (x + 2.0f);
		s += lanczos_c1 / (x + 1.0f);
		s += lanczos_c0;
		r  = ((MCK_KF(MCK_LSQRT2PI) + mc_logf(s)) - b) + mc_logf(b) * (x + 0.5f);
	} else {
		r = mc_logf(MCK_KF(MCK_PI) / mc_sinf(MCK_KF(MCK_PI) * x)) - mc_lgammaf(1.0f - x);
	}
	return r;
#	else
#	if MC_TARGET_CPP98
	return ::lgammaf(x);
#	else
	return lgammaf(x);
#	endif
#	endif
}

static MC_TARGET_INLINE double mc_lgamma(double x)
{
#	if MC_TARGET_EMBEDDED
	const double lanczos_g  = +5.0000000000000000000000000000000000000000E+00;
	const double lanczos_c0 = +1.0000000001900148927092004669248126447201E+00;
	const double lanczos_c1 = +7.6180091729471456574174226261675357818604E+01;
	const double lanczos_c2 = -8.6505320329416775848585530184209346771240E+01;
	const double lanczos_c3 = +2.4014098240830911379362078150734305381775E+01;
	const double lanczos_c4 = -1.2317395724501549736373817722778767347336E+00;
	const double lanczos_c5 = +1.2086509738661790208658075584935431834310E-03;
	const double lanczos_c6 = -5.3952393849530003275445644295160718684201E-06;
	double s, b, r = MCK_NAN;

	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0 && x == mc_trunc(x)) {
		return MCK_INFP;
	}
	const double y = mc_fabs(x);
	if (y <= DBL_MIN) {
		return -mc_log(y);
	}
	if (y > (MCLIMITS_MAX / mc_log(MCLIMITS_MAX))) {
		return MCK_INFP;
	}
	if (x >= 0.5) {
		x  = x - 1.0;
		b  = x + lanczos_g + 0.5;
		s  = lanczos_c6 / (x + 6.0);
		s += lanczos_c5 / (x + 5.0);
		s += lanczos_c4 / (x + 4.0);
		s += lanczos_c3 / (x + 3.0);
		s += lanczos_c2 / (x + 2.0);
		s += lanczos_c1 / (x + 1.0);
		s += lanczos_c0;
		r  = ((MCK_K(MCK_LSQRT2PI) + mc_log(s)) - b) + mc_log(b) * (x + 0.5);
	} else {
		r = mc_log(MCK_K(MCK_PI) / mc_sin(MCK_K(MCK_PI) * x)) - mc_lgamma(1.0 - x);
	}
	return r;
#	else
#	if MC_TARGET_CPP98
	return ::lgamma(x);
#	else
	return lgamma(x);
#	endif
#	endif
}

static MC_TARGET_INLINE long double mc_lgammal(long double x)
{
#	if MC_TARGET_EMBEDDED
#	if !MC_TARGET_MSVC_CPP
	const long double lanczos_g  = +5.000000000000000000000000000000000000000000000000000000000000000E+00L;
	const long double lanczos_c0 = +1.000000000190014892709200466924812644720077514648437500000000000E+00L;
	const long double lanczos_c1 = +7.618009172947145657417422626167535781860351562500000000000000000E+01L;
	const long double lanczos_c2 = -8.650532032941677584858553018420934677124023437500000000000000000E+01L;
	const long double lanczos_c3 = +2.401409824083091137936207815073430538177490234375000000000000000E+01L;
	const long double lanczos_c4 = -1.231739572450154973637381772277876734733581542968750000000000000E+00L;
	const long double lanczos_c5 = +1.208650973866179020865807558493543183431029319763183593750000000E-03L;
	const long double lanczos_c6 = -5.395239384953000327544564429516071868420112878084182739257812500E-06L;
	long double s, b, r = MCK_NAN;

	if (mc_isnan(x)) {
		return x;
	}
	if (mc_isinf(x)) {
		return x;
	}
	if (x <= 0 && x == mc_truncl(x)) {
		return MCK_INFP;
	}
	const long double y = mc_fabsl(x);
	if (y <= LDBL_MIN) {
		return -mc_logl(y);
	}
	if (y > (MCLIMITS_MAXL / mc_logl(MCLIMITS_MAXL))) {
		return MCK_INFP;
	}
	if (x >= 0.5L) {
		x  = x - 1.0L;
		b  = x + lanczos_g + 0.5L;
		s  = lanczos_c6 / (x + 6.0L);
		s += lanczos_c5 / (x + 5.0L);
		s += lanczos_c4 / (x + 4.0L);
		s += lanczos_c3 / (x + 3.0L);
		s += lanczos_c2 / (x + 2.0L);
		s += lanczos_c1 / (x + 1.0L);
		s += lanczos_c0;
		r  = ((MCK_KL(MCK_LSQRT2PI) + mc_logl(s)) - b) + mc_logl(b) * (x + 0.5L);
	} else {
		r = mc_logl(MCK_KL(MCK_PI) / mc_sinl(MCK_KL(MCK_PI) * x)) - mc_lgammal(1.0L - x);
	}
	return r;
#	else
	const double xx = mc_cast(double, x);
	return mc_cast(long double, mc_lgamma(xx));
#	endif
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
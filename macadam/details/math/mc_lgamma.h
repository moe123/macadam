//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lgamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LGAMMA_H
#define MC_LGAMMA_H

#pragma mark - mc_lgamma_approx0 -

static MC_TARGET_INLINE double mc_lgammaf_approx0(float x)
{
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x / MCK_KF(MCK_E);
#	if MC_TARGET_CPP98
	return ::logf(::sqrtf(a) * ::powf(b, x));
#	else
	return logf(sqrtf(a) * powf(b, x));
#	endif
}

static MC_TARGET_INLINE double mc_lgamma_approx0(double x)
{
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x / MCK_K(MCK_E);
#	if MC_TARGET_CPP98
	return ::log(::sqrt(a) * ::pow(b, x));
#	else
	return log(sqrt(a) * pow(b, x));
#	endif
}

static MC_TARGET_INLINE long double mc_lgammal_approx0(long double x)
{
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x / MCK_KL(MCK_E);
#	if MC_TARGET_CPP98
	return ::logl(::sqrtl(a) * ::powl(b, x));
#	else
	return logl(sqrtl(a) * powl(b, x));
#	endif
}

#pragma mark - mc_lgamma -

static MC_TARGET_INLINE float mc_lgammaf(float x)
{
#	if MC_TARGET_EMBEDDED
	const float lanczos_g  = +5.0f;
	const float lanczos_c0 = +1.00000000019001489270920046692481264472E+00f;
	const float lanczos_c1 = +7.61800917294714565741742262616753578186E+01f;
	const float lanczos_c2 = -8.65053203294167758485855301842093467712E+01f;
	const float lanczos_c3 = +2.40140982408309113793620781507343053818E+01f;
	const float lanczos_c4 = -1.23173957245015497363738177227787673473E+00f;
	const float lanczos_c5 = +1.20865097386617902086580755849354318343E-03f;
	const float lanczos_c6 = -5.39523938495300032754456442951607186842E-06f;
	float s, b, r = MCK_NAN;

#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return x;
	}
	if (::isinf(x)) {
		return x;
	}
	if (x <= 0 && x == ::truncf(x)) {
		return MCK_INFP;
	}
	const float y = ::fabsf(x);
	if (y <= FLT_MIN) {
		return -(::logf(y));
	}
	if (y > (FLT_MAX / ::logf(FLT_MAX))) {
		return MCK_INFP;
	}
#	else
	if (isnan(x)) {
		return x;
	}
	if (isinf(x)) {
		return x;
	}
	if (x <= 0 && x == truncf(x)) {
		return MCK_INFP;
	}
	const float y = fabsf(x);
	if (y <= FLT_MIN) {
		return -logf(y);
	}
	if (y > (FLT_MAX / logf(FLT_MAX))) {
		return MCK_INFP;
	}
#	endif

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
#	if MC_TARGET_CPP98
		r  = ((MCK_KF(MCK_LSQRT2PI) + ::logf(s)) - b) + ::logf(b) * (x + 0.5f);
#	else
		r  = ((MCK_KF(MCK_LSQRT2PI) + logf(s)) - b) + logf(b) * (x + 0.5f);
#	endif
	} else {
#	if MC_TARGET_CPP98
		r = ::logf(MCK_KF(MCK_PI) / ::sinf(MCK_KF(MCK_PI) * x)) - mc_lgammaf(1.0f - x);
#	else
		r = logf(MCK_KF(MCK_PI) / sinf(MCK_KF(MCK_PI) * x)) - mc_lgammaf(1.0f - x);
#	endif
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
	const double lanczos_g  = +5.0;
	const double lanczos_c0 = +1.0000000001900148927092004669248126447201E+00;
	const double lanczos_c1 = +7.6180091729471456574174226261675357818604E+01;
	const double lanczos_c2 = -8.6505320329416775848585530184209346771240E+01;
	const double lanczos_c3 = +2.4014098240830911379362078150734305381775E+01;
	const double lanczos_c4 = -1.2317395724501549736373817722778767347336E+00;
	const double lanczos_c5 = +1.2086509738661790208658075584935431834310E-03;
	const double lanczos_c6 = -5.3952393849530003275445644295160718684201E-06;
	double s, b, r = MCK_NAN;

#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return x;
	}
	if (::isinf(x)) {
		return x;
	}
	if (x <= 0 && x == ::trunc(x)) {
		return MCK_INFP;
	}
	const double y = ::fabs(x);
	if (y <= DBL_MIN) {
		return -(::log(y));
	}
	if (y > (DBL_MAX / ::log(DBL_MAX))) {
		return MCK_INFP;
	}
#	else
	if (isnan(x)) {
		return x;
	}
	if (isinf(x)) {
		return x;
	}
	if (x <= 0 && x == trunc(x)) {
		return MCK_INFP;
	}
	const double y = fabs(x);
	if (y <= DBL_MIN) {
		return -log(y);
	}
	if (y > (DBL_MAX / log(DBL_MAX))) {
		return MCK_INFP;
	}
#	endif

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
#	if MC_TARGET_CPP98
		r  = ((MCK_K(MCK_LSQRT2PI) + ::log(s)) - b) + ::log(b) * (x + 0.5);
#	else
		r  = ((MCK_K(MCK_LSQRT2PI) + log(s)) - b) + log(b) * (x + 0.5);
#	endif
	} else {
#	if MC_TARGET_CPP98
		r = ::log(MCK_K(MCK_PI) / ::sin(MCK_K(MCK_PI) * x)) - mc_lgamma(1.0 - x);
#	else
		r = log(MCK_K(MCK_PI) / sin(MCK_K(MCK_PI) * x)) - mc_lgamma(1.0 - x);
#	endif
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
	const long double lanczos_g  = +5.0L;
	const long double lanczos_c0 =+1.000000000190014892709200466924812644720077514648437500000000000E+00L;
	const long double lanczos_c1 =+7.618009172947145657417422626167535781860351562500000000000000000E+01L;
	const long double lanczos_c2 =-8.650532032941677584858553018420934677124023437500000000000000000E+01L;
	const long double lanczos_c3 =+2.401409824083091137936207815073430538177490234375000000000000000E+01L;
	const long double lanczos_c4 =-1.231739572450154973637381772277876734733581542968750000000000000E+00L;
	const long double lanczos_c5 =+1.208650973866179020865807558493543183431029319763183593750000000E-03L;
	const long double lanczos_c6 =-5.395239384953000327544564429516071868420112878084182739257812500E-06L;
	long double s, b, r = MCK_NAN;

#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return x;
	}
	if (::isinf(x)) {
		return x;
	}
	if (x <= 0 && x == ::truncl(x)) {
		return MCK_INFP;
	}
	const long double y = ::fabsl(x);
	if (y <= LDBL_MIN) {
		return -(::logl(y));
	}
	if (y > (LDBL_MAX / ::logl(LDBL_MAX))) {
		return MCK_INFP;
	}
#	else
	if (isnan(x)) {
		return x;
	}
	if (isinf(x)) {
		return x;
	}
	if (x <= 0 && x == truncl(x)) {
		return MCK_INFP;
	}
	const long double y = fabsl(x);
	if (y <= LDBL_MIN) {
		return -logl(y);
	}
	if (y > (LDBL_MAX / logl(LDBL_MAX))) {
		return MCK_INFP;
	}
#	endif

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
#	if MC_TARGET_CPP98
		r  = ((MCK_KL(MCK_LSQRT2PI) + ::logl(s)) - b) + ::logl(b) * (x + 0.5L);
#	else
		r  = ((MCK_KL(MCK_LSQRT2PI) + logl(s)) - b) + logl(b) * (x + 0.5L);
#	endif
	} else {
#	if MC_TARGET_CPP98
		r = ::logl(MCK_KL(MCK_PI) / ::sinl(MCK_KL(MCK_PI) * x)) - mc_lgammal(1.0L - x);
#	else
		r = logl(MCK_KL(MCK_PI) / sinl(MCK_KL(MCK_PI) * x)) - mc_lgammal(1.0L - x);
#	endif
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
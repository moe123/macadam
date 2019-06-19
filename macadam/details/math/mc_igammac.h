//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_igammac.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gamma.h>

#ifndef MC_IGAMMA_H
#define MC_IGAMMA_H

#pragma mark - mc_gamma_pseries_approx -

static MC_TARGET_INLINE float mc_gamma_pseriesf_approx0(float a, float x)
{
	const float e = MCLIMITS_EPSILONF;
	float term    = 1.0f / a;
	float sum     = term;
	float w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0f;
		term *= x / w;
		sum  += term;
	} while (::fabsf(term) > ::fabsf(sum) * e);
#	else
	do {
		w    += 1.0f;
		term *= x / w;
		sum  += term;
	} while (fabsf(term) > fabsf(sum) * e);
#	endif
	return sum;
}

static MC_TARGET_INLINE double mc_gamma_pseries_approx0(double a, double x)
{
	const double e = MCLIMITS_EPSILON;
	double term    = 1.0 / a;
	double sum     = term;
	double w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0;
		term *= x / w;
		sum  += term;
	} while (::fabs(term) > ::fabs(sum) * e);
#	else
	do {
		w    += 1.0;
		term *= x / w;
		sum  += term;
	} while (fabs(term) > fabs(sum) * e);
#	endif
	return sum;
}

static MC_TARGET_INLINE long double mc_gamma_pseriesl_approx0(long double a, long double x)
{
	const long double e = MCLIMITS_EPSILONL;
	long double term    = 1.0L / a;
	long double sum     = term;
	long double w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0L;
		term *= x / w;
		sum  += term;
	} while (::fabsl(term) > ::fabsl(sum) * e);
#	else
	do {
		w    += 1.0L;
		term *= x / w;
		sum  += term;
	} while (fabsl(term) > fabsl(sum) * e);
#	endif
	return sum;
}

#pragma mark - mc_igammac -

static MC_TARGET_INLINE float mc_igammacf(float a, float x)
{
	if (a > 0.0f && x > 0.0f) {
#	if MC_TARGET_CPP98
		const float y = a * ::logf(x) - x;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_pseriesf_approx0(a, x) * ::expf(y);
#	else
		const float y = a * logf(x) - x;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_pseriesf_approx0(a, x) * expf(y);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE double mc_igammac(double a, double x)
{
	if (a > 0.0 && x > 0.0) {
#	if MC_TARGET_CPP98
		const double y = a * ::log(x) - x;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_pseries_approx0(a, x) * ::exp(y);
#	else
		const double y = a * log(x) - x;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_pseries_approx0(a, x) * exp(y);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE long double mc_igammacl(long double a, long double x)
{
	if (a > 0.0L && x > 0.0L) {
#	if MC_TARGET_CPP98
		const long double y = a * ::logl(x) - x;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_pseriesl_approx0(a, x) * ::expl(y);
#	else
		const long double y = a * logl(x) - x;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_pseriesl_approx0(a, x) * expl(y);
#	endif
	}
	return MCK_NAN;
}

#endif /* !MC_IGAMMA_H */

/* EOF */
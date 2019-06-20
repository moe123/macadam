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

static MC_TARGET_INLINE float mc_gamma_pseriesf_approx0(float a, float z)
{
	const float e = MCLIMITS_EPSILONF;
	float term    = 1.0f / a;
	float sum     = term;
	float w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0f;
		term *= z / w;
		sum  += term;
	} while (::fabsf(term) > ::fabsf(sum) * e);
#	else
	do {
		w    += 1.0f;
		term *= z / w;
		sum  += term;
	} while (fabsf(term) > fabsf(sum) * e);
#	endif
	return sum;
}

static MC_TARGET_INLINE double mc_gamma_pseries_approx0(double a, double z)
{
	const double e = MCLIMITS_EPSILON;
	double term    = 1.0 / a;
	double sum     = term;
	double w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0;
		term *= z / w;
		sum  += term;
	} while (::fabs(term) > ::fabs(sum) * e);
#	else
	do {
		w    += 1.0;
		term *= z / w;
		sum  += term;
	} while (fabs(term) > fabs(sum) * e);
#	endif
	return sum;
}

static MC_TARGET_INLINE long double mc_gamma_pseriesl_approx0(long double a, long double z)
{
	const long double e = MCLIMITS_EPSILONL;
	long double term    = 1.0L / a;
	long double sum     = term;
	long double w       = a;
#	if MC_TARGET_CPP98
	do {
		w    += 1.0L;
		term *= z / w;
		sum  += term;
	} while (::fabsl(term) > ::fabsl(sum) * e);
#	else
	do {
		w    += 1.0L;
		term *= z / w;
		sum  += term;
	} while (fabsl(term) > fabsl(sum) * e);
#	endif
	return sum;
}

#pragma mark - mc_igammac -

static MC_TARGET_INLINE float mc_igammacf(float a, float z)
{
	if (a > 0.0f && z > 0.0f) {
#	if MC_TARGET_CPP98
		const float y = a * ::logf(z) - z;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_pseriesf_approx0(a, z) * ::expf(y);
#	else
		const float y = a * logf(z) - z;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_pseriesf_approx0(a, z) * expf(y);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE double mc_igammac(double a, double z)
{
	if (a > 0.0 && z > 0.0) {
#	if MC_TARGET_CPP98
		const double y = a * ::log(z) - z;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_pseries_approx0(a, z) * ::exp(y);
#	else
		const double y = a * log(z) - z;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_pseries_approx0(a, z) * exp(y);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE long double mc_igammacl(long double a, long double z)
{
	if (a > 0.0L && z > 0.0L) {
#	if MC_TARGET_CPP98
		const long double y = a * ::logl(z) - z;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_pseriesl_approx0(a, z) * ::expl(y);
#	else
		const long double y = a * logl(z) - z;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_pseriesl_approx0(a, z) * expl(y);
#	endif
	}
	return MCK_NAN;
}

#endif /* !MC_IGAMMA_H */

/* EOF */
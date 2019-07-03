//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_igammac.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_log.h>
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
	do {
		w    += 1.0f;
		term *= z / w;
		sum  += term;
	} while (mc_fabsf(term) > mc_fabsf(sum) * e);
	return sum;
}

static MC_TARGET_INLINE double mc_gamma_pseries_approx0(double a, double z)
{
	const double e = MCLIMITS_EPSILON;
	double term    = 1.0 / a;
	double sum     = term;
	double w       = a;
	do {
		w    += 1.0;
		term *= z / w;
		sum  += term;
	} while (mc_fabs(term) > mc_fabs(sum) * e);
	return sum;
}

static MC_TARGET_INLINE long double mc_gamma_pseriesl_approx0(long double a, long double z)
{
	const long double e = MCLIMITS_EPSILONL;
	long double term    = 1.0L / a;
	long double sum     = term;
	long double w       = a;
	do {
		w    += 1.0L;
		term *= z / w;
		sum  += term;
	} while (mc_fabsl(term) > mc_fabsl(sum) * e);
	return sum;
}

#pragma mark - mc_igammac -

/*! Computes the non-regularized incomplete gamma upper tail function.
 *
 * \brief Computing the non-regularized incomplete gamma upper tail function.
 *
 * float mc_igammacf(float a, float z);
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma upper tail function of a and z.
 *
 */
static MC_TARGET_INLINE float mc_igammacf(float a, float z)
{
	if (a > 0.0f && z > 0.0f) {
		const float y = a * mc_logf(z) - z;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_pseriesf_approx0(a, z) * mc_expf(y);
	}
	return MCK_NAN;
}

/*! Computes the non-regularized incomplete gamma upper tail function.
 *
 * \brief Computing the non-regularized incomplete gamma upper tail function.
 *
 * double mc_igammac(double a, double z);
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma upper tail function of a and z.
 */
static MC_TARGET_INLINE double mc_igammac(double a, double z)
{
	if (a > 0.0 && z > 0.0) {
		const double y = a * mc_log(z) - z;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_pseries_approx0(a, z) * mc_exp(y);
	}
	return MCK_NAN;
}

/*! Computes the non-regularized incomplete gamma upper tail function.
 *
 * \brief Computing the non-regularized incomplete gamma upper tail function.
 *
 * long double mc_igammacl(long double a, long double z);
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma upper tail function of a and z.
 */
static MC_TARGET_INLINE long double mc_igammacl(long double a, long double z)
{
	if (a > 0.0L && z > 0.0L) {
		const long double y = a * mc_logl(z) - z;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_pseriesl_approx0(a, z) * mc_expl(y);
	}
	return MCK_NAN;
}

#endif /* !MC_IGAMMA_H */

/* EOF */
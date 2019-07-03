//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_igammad.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_gamma.h>

#ifndef MC_IGAMMAD_H
#define MC_IGAMMAD_H

#pragma mark - mc_gamma_cfrac_approx -

static MC_TARGET_INLINE float mc_gamma_cfracf_approx0(float a, float z)
{
	const float e1 = MCLIMITS_EPSILONF;
	const float e3 = e1 * 3.0f;
	float k = 1.0f, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0f - a;
	c2 = 1.0f / e3;
	c3 = 1.0f / c1;
	c5 = c3;
	do {
		c0  = k * (a - k);
		c1 += 2.0f;
		c3  = c0 * c3 + c1;
		c3  = mc_fabsf(c3) < e3 ? e3 : c3;
		c2  = c1 + c0 / c2;
		c2  = mc_fabsf(c2) < e3 ? e3 : c2;
		c3  = 1.0f / c3;
		c4  = c3 * c2;
		c5 *= c4;
		k  += 1.0f;
	} while (mc_fabsf(c4 - 1.0f) > e1);
	return c5;
}

static MC_TARGET_INLINE double mc_gamma_cfrac_approx0(double a, double z)
{
	const double e1 = MCLIMITS_EPSILON;
	const double e3 = e1 * 3.0;
	double k = 1.0, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0 - a;
	c2 = 1.0 / e3;
	c3 = 1.0 / c1;
	c5 = c3;
	do {
		c0  = k * (a - k);
		c1 += 2.0;
		c3  = c0 * c3 + c1;
		c3  = mc_fabs(c3) < e3 ? e3 : c3;
		c2  = c1 + c0 / c2;
		c2  = mc_fabs(c2) < e3 ? e3 : c2;
		c3  = 1.0 / c3;
		c4  = c3 * c2;
		c5 *= c4;
		k  += 1.0;
	} while (mc_fabs(c4 - 1.0) > e1);
	return c5;
}

static MC_TARGET_INLINE long double mc_gamma_cfracl_approx0(long double a, long double z)
{
	const long double e1 = MCLIMITS_EPSILONL;
	const long double e3 = e1 * 3.0L;
	double k = 1.0L, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0L - a;
	c2 = 1.0L / e3;
	c3 = 1.0L / c1;
	c5 = c3;
	do {
		c0  = k * (a - k);
		c1 += 2.0L;
		c3  = c0 * c3 + c1;
		c3  = mc_fabsl(c3) < e3 ? e3 : c3;
		c2  = c1 + c0 / c2;
		c2  = mc_fabsl(c2) < e3 ? e3 : c2;
		c3  = 1.0L / c3;
		c4  = c3 * c2;
		c5 *= c4;
		k  += 1.0L;
	} while (mc_fabsl(c4 - 1.0L) > e1);
	return c5;
}

#pragma mark - mc_igammad -

/*! Computes the non-regularized incomplete gamma lower tail function.
 *
 * \brief Computing the non-regularized incomplete gamma lower tail function.
 *
 * float mc_igammadf(long float a, float z)
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma lower tail function of a and z.
 */
static MC_TARGET_INLINE float mc_igammadf(float a, float z)
{
	if (a > 0.0f && z > 0.0f) {
		const float w = a * mc_logf(z) - z;
		if (w < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_gamma_cfracf_approx0(a, z) * mc_expf(w);
	}
	return MCK_NAN;
}

/*! Computes the non-regularized incomplete gamma lower tail function.
 *
 * \brief Computing the non-regularized incomplete gamma lower tail function.
 *
 * double mc_igammad(double a, double z)
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma lower tail function of a and z.
 */
static MC_TARGET_INLINE double mc_igammad(double a, double z)
{
	if (a > 0.0 && z > 0.0) {
		const double w = a * mc_log(z) - z;
		if (w < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_gamma_cfrac_approx0(a, z) * mc_exp(w);
	}
	return MCK_NAN;
}

/*! Computes the non-regularized incomplete gamma lower tail function.
 *
 * \brief Computing the non-regularized incomplete gamma lower tail function.
 *
 * long double mc_igammadl(long double a, long double z)
 *
 * \param a.
 * \param z.
 * \result  The non-normalised incomplete gamma lower tail function of a and z.
 */
static MC_TARGET_INLINE long double mc_igammadl(long double a, long double z)
{
	if (a > 0.0L && z > 0.0L) {
		const long double w = a * mc_logl(z) - z;
		if (w < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_gamma_cfracl_approx0(a, z) * mc_expl(w);
	}
	return MCK_NAN;
}

#endif /* !MC_IGAMMAD_H */

/* EOF */
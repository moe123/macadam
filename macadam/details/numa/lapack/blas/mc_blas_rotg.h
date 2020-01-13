// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_rotg.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?rotg computes the parameters for a Givens rotation.
 * 
 * \synopsis
 *    real-floating ?rotg(a, b, c, s)
 *    real-floating a, b, c, s
 *
 * \purpose
 *    ?rotg computes the parameters for a Givens rotation. Given the Cartesian coordinates (a, b)
 *    of a point, returns the parameters c, s, r, and z associated with the Givens rotation.
 *
 * \parameters
 *    [out] a    - real-floating. Provides the x-coordinate of the point p, a is overwritten by
 *    the parameter r associated with the Givens rotation.
 *
 *    [out] b    - real-floating. Provides the y-coordinate of the point p, b is overwritten by
 *    the parameter z associated with the Givens rotation.
 *
 *    [out] c    - real-floating. Contains the cosine associated with the Givens rotation.
 *    [out] s    - real-floating. Contains the sine associated with the Givens rotation.
 *
 * \examples
 *
 * \level 1 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Linpack.
 */

#include <macadam/details/math/mc_copysign.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_BLAS_ROTG_H
#define MC_BLAS_ROTG_H

#pragma mark - mc_blas_srotg -

MC_TARGET_FUNC void mc_blas_srotg(float * a, float * b, float * c, float * s)
{
	float r, roe, scale, z;

	roe = *b;
	if (mc_fabsf(*a) > mc_fabsf(*b)) {
		roe = *a;
	}
	scale = mc_fabsf(*a) + mc_fabsf(*b);
	if (scale == 0.0f) {
		*c = 1.0f;
		*s = 0.0f;
		 r = 0.0f;
		 z = 0.0f;
	} else {
		 r = scale * mc_sqrtf(mc_raise2f(*a / scale) + mc_raise2f(*b / scale));
		 r = mc_copysignf(1.0f, roe) * r;
		*c = *a / r;
		*s = *b / r;
		 z = 1.0f;
		if (mc_fabsf(*a) > mc_fabsf(*b)) {
			z = *s;
		}
		if (mc_fabsf(*b) >= mc_fabsf(*a) && *c != 0.0f) {
			z = 1.0f / *c;
		}
	}
	*a = r;
	*b = z;
}

#pragma mark - mc_blas_drotg -

MC_TARGET_FUNC void mc_blas_drotg(double * a, double * b, double * c, double * s)
{
	double r, roe, scale, z;

	roe = *b;
	if (mc_fabs(*a) > mc_fabs(*b)) {
		roe = *a;
	}
	scale = mc_fabs(*a) + mc_fabs(*b);
	if (scale == 0.0) {
		*c = 1.0;
		*s = 0.0;
		 r = 0.0;
		 z = 0.0;
	} else {
		 r = scale * mc_sqrt(mc_raise2(*a / scale) + mc_raise2(*b / scale));
		 r = mc_copysign(1.0, roe) * r;
		*c = *a / r;
		*s = *b / r;
		 z = 1.0;
		if (mc_fabs(*a) > mc_fabs(*b)) {
			z = *s;
		}
		if (mc_fabs(*b) >= mc_fabs(*a) && *c != 0.0) {
			z = 1.0 / *c;
		}
	}
	*a = r;
	*b = z;
}

#pragma mark - mc_blas_lrotg -

MC_TARGET_FUNC void mc_blas_lrotg(long double * a, long double * b, long double * c, long double * s)
{
	long double r, roe, scale, z;

	roe = *b;
	if (mc_fabsl(*a) > mc_fabsl(*b)) {
		roe = *a;
	}
	scale = mc_fabsl(*a) + mc_fabsl(*b);
	if (scale == 0.0L) {
		*c = 1.0L;
		*s = 0.0L;
		 r = 0.0L;
		 z = 0.0L;
	} else {
		 r = scale * mc_sqrtl(mc_raise2l(*a / scale) + mc_raise2l(*b / scale));
		 r = mc_copysignl(1.0L, roe) * r;
		*c = *a / r;
		*s = *b / r;
		 z = 1.0L;
		if (mc_fabsl(*a) > mc_fabsl(*b)) {
			z = *s;
		}
		if (mc_fabsl(*b) >= mc_fabsl(*a) && *c != 0.0L) {
			z = 1.0L / *c;
		}
	}
	*a = r;
	*b = z;
}

#endif /* !MC_BLAS_ROTG_H */

/* EOF */
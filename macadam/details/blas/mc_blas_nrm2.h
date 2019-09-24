// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_nrm2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?nrm2 returns the euclidean norm of a vector.
 * 
 * \synopsis
 *    real-floating ?nrm2(n, x, incx)
 *    int           incx, n
 *    real-floating x(*)
 *
 * \purpose
 *    ?nrm2 returns the euclidean norm of a vector: norm2=sqrt(x'*x).
 *
 * \parameters
 *    [in] n     - int. Specifies the number of elements in the input vector x.
 *    [in] x     - real-floating array of size at least (1+(n-1)*abs(incx)).
 *    [in] incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 * \examples
 *
 * \level 1 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Sven Hammarling, Nag Ltd.
 */

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_BLAS_NRM2_H
#define MC_BLAS_NRM2_H

#pragma mark - mc_blas_snrm2 -

MC_TARGET_FUNC float mc_blas_snrm2(int n, const float * x, int incx)
{
	const float one = 1.0f, zero = 0.0f;

	float ssq, norm, scale, absxi;
	int ix;

	if (n < 1 || incx < 1) {
		norm = zero;
	} else if (n == 1) {
		norm = mc_fabsf(MC_BLAS_VAT(x, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (n - 1) * incx + 1 : ix <= (n - 1) * incx + 1; ix += incx) {
			if (MC_BLAS_VAT(x, ix) != zero) {
				absxi = mc_fabsf(MC_BLAS_VAT(x, ix));
				if (scale < absxi) {
					ssq   = one + (ssq * mc_raise2f(scale / absxi));
					scale = absxi;
				} else {
					ssq = ssq + mc_raise2f(absxi / scale);
				}
			}
		}
		norm = scale * mc_sqrtf(ssq);
	}
	return norm;
}

#pragma mark - mc_blas_sdnrm2 -

MC_TARGET_FUNC double mc_blas_sdnrm2(int n, const float * x, int incx)
{
	const double one = 1.0, zero = 0.0;

	double ssq, norm, scale, absxi;
	int ix;

	if (n < 1 || incx < 1) {
		norm = zero;
	} else if (n == 1) {
		norm = mc_fabs(mc_cast(double, MC_BLAS_VAT(x, 1)));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (n - 1) * incx + 1 : ix <= (n - 1) * incx + 1; ix += incx) {
			if (mc_cast(double, MC_BLAS_VAT(x, ix)) != zero) {
				absxi = mc_fabs(mc_cast(double, MC_BLAS_VAT(x, ix)));
				if (scale < absxi) {
					ssq   = one + (ssq * mc_raise2(scale / absxi));
					scale = absxi;
				} else {
					ssq = ssq + mc_raise2(absxi / scale);
				}
			}
		}
		norm = scale * mc_sqrt(ssq);
	}
	return norm;
}

#pragma mark - mc_blas_dnrm2 -

MC_TARGET_FUNC double mc_blas_dnrm2(int n, const double * x, int incx)
{
	const double one = 1.0, zero = 0.0;

	double ssq, norm, scale, absxi;
	int ix;

	if (n < 1 || incx < 1) {
		norm = zero;
	} else if (n == 1) {
		norm = mc_fabs(MC_BLAS_VAT(x, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (n - 1) * incx + 1 : ix <= (n - 1) * incx + 1; ix += incx) {
			if (MC_BLAS_VAT(x, ix) != zero) {
				absxi = mc_fabs(MC_BLAS_VAT(x, ix));
				if (scale < absxi) {
					ssq   = one + (ssq * mc_raise2(scale / absxi));
					scale = absxi;
				} else {
					ssq = ssq + mc_raise2(absxi / scale);
				}
			}
		}
		norm = scale * mc_sqrt(ssq);
	}
	return norm;
}

#pragma mark - mc_blas_lnrm2 -

MC_TARGET_FUNC long double mc_blas_lnrm2(int n, const long double * x, int incx)
{
	const long double one = 1.0L, zero = 0.0L;

	long double ssq, norm, scale, absxi;
	int ix;

	if (n < 1 || incx < 1) {
		norm = zero;
	} else if (n == 1) {
		norm = mc_fabsl(MC_BLAS_VAT(x, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (n - 1) * incx + 1 : ix <= (n - 1) * incx + 1; ix += incx) {
			if (MC_BLAS_VAT(x, ix) != zero) {
				absxi = mc_fabsl(MC_BLAS_VAT(x, ix));
				if (scale < absxi) {
					ssq   = one + (ssq * mc_raise2l(scale / absxi));
					scale = absxi;
				} else {
					ssq = ssq + mc_raise2l(absxi / scale);
				}
			}
		}
		norm = scale * mc_sqrtl(ssq);
	}
	return norm;
}

#endif /* !MC_BLAS_NRM2_H */

/* EOF */
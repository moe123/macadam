// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_nrm2_c.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?nrm2_c returns the euclidean norm of a vector.
 * 
 * \synopsis
 *    real-floating ?nrm2_c(m, x, ldx, nx, indx, incx)
 *    int           indx, incx, ldx, m, nx
 *    real-floating x(ldx, *)
 *
 * \purpose
 *    ?nrm2_c returns the euclidean norm of a column-vector: norm2=sqrt(x'*x).
 *
 * \parameters
 *    [in] m    - int. Specifies the number of elements within a column of x.

 *    [in] x    - real-floating array of dimension (ldx, nx) where ldx is at least (1+(m-1)*abs(incx)).
 *    [in] ldx  - int. Specifies the first dimension of x, ldx is at least (1+(m-1)*abs(incx)).
 *    [in] nx   - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in] indx - int. Specifies the column-vector index of x, indx must be within range [1, nx].
 *    [in] incx - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 * \examples
 *
 * \nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_BLAS_NRM2_C_H
#define MC_BLAS_NRM2_C_H

#pragma mark - mc_blas_snrm2_c -

MC_TARGET_FUNC float mc_blas_snrm2_c(int m, const float * x, int ldx, int nx, int indx, int incx)
{
	const float one = 1.0f, zero = 0.0f;

	float ssq, norm, scale, absxi;
	int ix;

	if (m < 1 || incx < 1) {
		mc_cast(void, ldx);
		mc_cast(void, nx);
		norm = zero;
	} else if (m == 1) {
		norm = mc_fabsf(mc_blas_matrix_at(x, ldx, nx, indx, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (m - 1) * incx + 1 : ix <= (m - 1) * incx + 1; ix += incx) {
			absxi = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			if (absxi != zero) {
				absxi = mc_fabsf(absxi);
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

#pragma mark - mc_blas_sdnrm2_c -

MC_TARGET_FUNC double mc_blas_sdnrm2_c(int m, const float * x, int ldx, int nx, int indx, int incx)
{
	const double one = 1.0, zero = 0.0;

	double ssq, norm, scale, absxi;
	int ix;

	if (m < 1 || incx < 1) {
		mc_cast(void, ldx);
		mc_cast(void, nx);
		norm = zero;
	} else if (m == 1) {
		norm = mc_fabs(mc_cast(double, mc_blas_matrix_at(x, ldx, nx, indx, 1)));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (m - 1) * incx + 1 : ix <= (m - 1) * incx + 1; ix += incx) {
			absxi = mc_cast(double, mc_blas_matrix_at(x, ldx, nx, indx, ix));
			if (absxi != zero) {
				absxi = mc_fabs(absxi);
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

#pragma mark - mc_blas_dnrm2_c -

MC_TARGET_FUNC double mc_blas_dnrm2_c(int m, const double * x, int ldx, int nx, int indx, int incx)
{
	const double one = 1.0, zero = 0.0;

	double ssq, norm, scale, absxi;
	int ix;

	if (m < 1 || incx < 1) {
		mc_cast(void, ldx);
		mc_cast(void, nx);
		norm = zero;
	} else if (m == 1) {
		norm = mc_fabs(mc_blas_matrix_at(x, ldx, nx, indx, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (m - 1) * incx + 1 : ix <= (m - 1) * incx + 1; ix += incx) {
			absxi = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			if (absxi != zero) {
				absxi = mc_fabs(absxi);
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

#pragma mark - mc_blas_lnrm2_c -

MC_TARGET_FUNC long double mc_blas_lnrm2_c(int m, const long double * x, int ldx, int nx, int indx, int incx)
{
	const long double one = 1.0L, zero = 0.0L;

	long double ssq, norm, scale, absxi;
	int ix;

	if (m < 1 || incx < 1) {
		mc_cast(void, ldx);
		mc_cast(void, nx);
		norm = zero;
	} else if (m == 1) {
		norm = mc_fabsl(mc_blas_matrix_at(x, ldx, nx, indx, 1));
	} else {
		scale = zero;
		ssq   = one;
		for (ix = 1; incx < 0 ? ix >= (m - 1) * incx + 1 : ix <= (m - 1) * incx + 1; ix += incx) {
			absxi = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			if (absxi != zero) {
				absxi = mc_fabsl(absxi);
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

#endif /* !MC_BLAS_NRM2_C_H */

/* EOF */
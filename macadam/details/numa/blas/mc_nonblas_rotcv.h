// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_rotcv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?rotcv applies a plane rotation to column-vectors.
 * 
 * \synopsis
 *    real-floating ?rotcv(m, n, x, ldx, nx, indx, incx, y, ldy, ny, indy, incy, c, s)
 *    real-floating c, s
 *    int           incx, incy, indx, indy, ldx, ldy, m, n, nx, ny
 *    real-floating x(ldx, *), y(ldy, *)
 *
 * \purpose
 *    ?rotcv applies a plane rotation matrix to a real sequence of ordered pairs.
 *    If coefficients c and s satisfy c+s=1, the rotation matrix is orthogonal,
 *    and the transformation is called a Givens plane rotation.
 *
 * \parameters
 *    [in]  m    - int. Specifies the number of elements within a column of x and y.
 *
 *    [out] x    - real-floating array of dimension (ldx, nx) where ldx is at least (1+(m-1)*abs(incx)).
 *    [in]  ldx  - int. Specifies the first dimension of x, ldx is at least (1+(m-1)*abs(incx)).
 *    [in]  nx   - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  indx - int. Specifies the column-vector index of x, indx must be within range [1, nx].
 *    [in]  incx - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [out] y    - real-floating array of dimension (ldy, ny) where ldy is at least  (1+(m-1)*abs(incy)).
 *    [in]  ldy  - int. Specifies the first dimension of y, ldx is at least (1+(m-1)*abs(incy)).
 *    [in]  ny   - int. Specifies the second dimension of y, nx must be at least 1.
 *    [in]  indy - int. Specifies the column-vector index of y, indy must be within range [1, ny].
 *    [in]  incy - int. Specifies the increment for the elements of y, incy must not be zero.
 *
 *    [in]  c    - float-floating. Specifies the cosine of the angle of rotation.
 *    [in]  s    - float-floating. Specifies the sine of the angle of rotation.
 *
 * \examples
 *
 * \nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/numa/blas/mc_blas_access.h>

#ifndef MC_NONBLAS_ROTCV_H
#define MC_NONBLAS_ROTCV_H

#pragma mark - mc_nonblas_srotcv -

MC_TARGET_FUNC void mc_nonblas_srotcv(int m, float * x, int ldx, int nx, int indx, int incx, float * y, int ldy, int ny, int indy, int incy, float c, float s)
{
	float temp;
	int i, ix, iy;

	if (m <= 1) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= m; ++i) {
			temp                                   = c * mc_blas_matrix_at(x, ldx, nx, indx, i) + s * mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i) = c * mc_blas_matrix_at(y, ldy, ny, indy, i) - s * mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = c * mc_blas_matrix_at(x, ldx, nx, indx, ix) + s * mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = c * mc_blas_matrix_at(y, ldy, ny, indy, iy) - s * mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#pragma mark - mc_nonblas_drotcv -

MC_TARGET_FUNC void mc_nonblas_drotcv(int m, double * x, int ldx, int nx, int indx, int incx, double * y, int ldy, int ny, int indy, int incy, double c, double s)
{
	double temp;
	int i, ix, iy;

	if (m <= 1) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= m; ++i) {
			temp                                   = c * mc_blas_matrix_at(x, ldx, nx, indx, i) + s * mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i) = c * mc_blas_matrix_at(y, ldy, ny, indy, i) - s * mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = c * mc_blas_matrix_at(x, ldx, nx, indx, ix) + s * mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = c * mc_blas_matrix_at(y, ldy, ny, indy, iy) - s * mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#pragma mark - mc_nonblas_lrotcv -

MC_TARGET_FUNC void mc_nonblas_lrotcv(int m, long double * x, int ldx, int nx, int indx, int incx, long double * y, int ldy, int ny, int indy, int incy, long double c, long double s)
{
	long double temp;
	int i, ix, iy;

	if (m <= 1) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= m; ++i) {
			temp                                   = c * mc_blas_matrix_at(x, ldx, nx, indx, i) + s * mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i) = c * mc_blas_matrix_at(y, ldy, ny, indy, i) - s * mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = c * mc_blas_matrix_at(x, ldx, nx, indx, ix) + s * mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = c * mc_blas_matrix_at(y, ldy, ny, indy, iy) - s * mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#endif /* !MC_NONBLAS_ROTCV_H */

/* EOF */
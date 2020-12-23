// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_rot.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?rot applies a plane rotation.
 * 
 * \synopsis
 *    real-floating ?rot(n, x, incx, y, incy, c, s)
 *    real-floating c, s
 *    int           incx, incy, n
 *    real-floating x(*), y(*)
 *
 * \purpose
 *    ?rot applies a plane rotation matrix to a real sequence of ordered pairs.
 *    If coefficients c and s satisfy c+s=1, the rotation matrix is orthogonal,
 *    and the transformation is called a Givens plane rotation.
 *
 * \parameters
 *    [in]  n    - int. Specifies the number of elements in the input vector x and y.
 *
 *    [out] x    - real-floating array of size at least (1+(n-1)*abs(incx)).
 *    [in]  incx - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [out] y    - real-floating array of size at least (1+(n-1)*abs(incy)).
 *    [in]  incy - int. Specifies the increment for the elements of y, incy must not be zero.
 *
 *    [in]  c    - float-floating. Specifies the cosine of the angle of rotation.
 *    [in]  s    - float-floating. Specifies the sine of the angle of rotation.
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

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>

#ifndef MC_BLAS_ROT_H
#define MC_BLAS_ROT_H

#pragma mark - mc_blas_srot -

MC_TARGET_FUNC void mc_blas_srot(const int n, float * x, const int incx, float * y, const int incy, float c, float s)
{
	float temp;
	int i, ix, iy;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= n; ++i) {
			temp                    = c * mc_blas_vector_at(x, i) + s * mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i) = c * mc_blas_vector_at(y, i) - s * mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = c * mc_blas_vector_at(x, ix) + s * mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = c * mc_blas_vector_at(y, iy) - s * mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_drot -

MC_TARGET_FUNC void mc_blas_drot(const int n, double * x, const int incx, double * y, const int incy, double c, double s)
{
	double temp;
	int i, ix, iy;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= n; ++i) {
			temp                    = c * mc_blas_vector_at(x, i) + s * mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i) = c * mc_blas_vector_at(y, i) - s * mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = c * mc_blas_vector_at(x, ix) + s * mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = c * mc_blas_vector_at(y, iy) - s * mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_lrot -

MC_TARGET_FUNC void mc_blas_lrot(const int n, long double * x, const int incx, long double * y, const int incy, long double c, long double s)
{
	long double temp;
	int i, ix, iy;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= n; ++i) {
			temp                    = c * mc_blas_vector_at(x, i) + s * mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i) = c * mc_blas_vector_at(y, i) - s * mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = c * mc_blas_vector_at(x, ix) + s * mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = c * mc_blas_vector_at(y, iy) - s * mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#endif /* !MC_BLAS_ROT_H */

/* EOF */
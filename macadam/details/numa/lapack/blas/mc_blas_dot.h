//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_dot.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?dot computes the inner product of two vectors.
 *
 * \synopsis
 *    real-floating ?dot(n, x, incx, y, incy)
 *    int           incx, incy, n
 *    real-floating x(*), y(*)
 *
 * \purpose
 *    ?dot computes the inner product of two vectors.
 *
 * \parameters
 *    [in] n     - int. Specifies the number of elements in the input vectors x and y.
 *    [in] x     - real-floating array of size at least (1+(n-1)*abs(incx)).
 *    [in] incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *    [in] y     - real-floating arrays of size at least (1+(n-1)*abs(incy)).
 *    [in] incy  - int. Specifies the increment for the elements of y. incy must not be zero.
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

#ifndef MC_BLAS_DOT_H
#define MC_BLAS_DOT_H

#pragma mark - mc_blas_sdot -

MC_TARGET_FUNC float mc_blas_sdot(int n, const float * x, int incx, const float * y , int incy)
{
	int i, m, ix, iy, mp1;
	float temp;

	temp = 0.0f;
	if (n <= 0) {
		return temp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_vector_at(x, i) * mc_blas_vector_at(y, i));
			}
			if (n < 5) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			temp = temp + (
				  (mc_blas_vector_at(x, i    ) * mc_blas_vector_at(y, i    ))
				+ (mc_blas_vector_at(x, i + 1) * mc_blas_vector_at(y, i + 1))
				+ (mc_blas_vector_at(x, i + 2) * mc_blas_vector_at(y, i + 2))
				+ (mc_blas_vector_at(x, i + 3) * mc_blas_vector_at(y, i + 3))
				+ (mc_blas_vector_at(x, i + 4) * mc_blas_vector_at(y, i + 4))
			);
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
			temp = temp + (mc_blas_vector_at(x, ix) * mc_blas_vector_at(y, iy));
			ix   = ix + incx;
			iy   = iy + incy;
		}
	}
	return temp;
}

#pragma mark - mc_blas_dsdot -

MC_TARGET_FUNC double mc_blas_dsdot(int n, const float * x, int incx, const float * y , int incy)
{
	int i, m, ix, iy, mp1;
	double temp;

	temp = 0.0;
	if (n <= 0) {
		return temp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_cast(double, mc_blas_vector_at(x, i)) * mc_cast(double, mc_blas_vector_at(y, i)));
			}
			if (n < 5) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			temp = temp + (
				  (mc_cast(double, mc_blas_vector_at(x, i    )) * mc_cast(double, mc_blas_vector_at(y, i    )))
				+ (mc_cast(double, mc_blas_vector_at(x, i + 1)) * mc_cast(double, mc_blas_vector_at(y, i + 1)))
				+ (mc_cast(double, mc_blas_vector_at(x, i + 2)) * mc_cast(double, mc_blas_vector_at(y, i + 2)))
				+ (mc_cast(double, mc_blas_vector_at(x, i + 3)) * mc_cast(double, mc_blas_vector_at(y, i + 3)))
				+ (mc_cast(double, mc_blas_vector_at(x, i + 4)) * mc_cast(double, mc_blas_vector_at(y, i + 4)))
			);
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
			temp = temp + (mc_cast(double, mc_blas_vector_at(x, ix)) * mc_cast(double, mc_blas_vector_at(y, iy)));
			ix   = ix + incx;
			iy   = iy + incy;
		}
	}
	return temp;
}

#pragma mark - mc_blas_sdsdot -

MC_TARGET_FUNC float mc_blas_sdsdot(int n, float b, const float * x, int incx, const float * y , int incy)
{
	return mc_cast(float, (mc_cast(double, b) + mc_blas_dsdot(n, x, incx, y, incy)));
}

#pragma mark - mc_blas_ddot -

MC_TARGET_FUNC double mc_blas_ddot(int n, const double * x, int incx, const double * y , int incy)
{
	int i, m, ix, iy, mp1;
	double temp;

	temp = 0.0;
	if (n <= 0) {
		return temp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_vector_at(x, i) * mc_blas_vector_at(y, i));
			}
			if (n < 5) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			temp = temp + (
				  (mc_blas_vector_at(x, i    ) * mc_blas_vector_at(y, i    ))
				+ (mc_blas_vector_at(x, i + 1) * mc_blas_vector_at(y, i + 1))
				+ (mc_blas_vector_at(x, i + 2) * mc_blas_vector_at(y, i + 2))
				+ (mc_blas_vector_at(x, i + 3) * mc_blas_vector_at(y, i + 3))
				+ (mc_blas_vector_at(x, i + 4) * mc_blas_vector_at(y, i + 4))
			);
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
			temp = temp + (mc_blas_vector_at(x, ix) * mc_blas_vector_at(y, iy));
			ix   = ix + incx;
			iy   = iy + incy;
		}
	}
	return temp;
}

#pragma mark - mc_blas_ldot -

MC_TARGET_FUNC long double mc_blas_ldot(int n, const long double * x, int incx, const long double * y , int incy)
{
	int i, m, ix, iy, mp1;
	long double temp;

	temp = 0.0L;
	if (n <= 0) {
		return temp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_vector_at(x, i) * mc_blas_vector_at(y, i));
			}
			if (n < 5) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			temp = temp + (
				  (mc_blas_vector_at(x, i    ) * mc_blas_vector_at(y, i    ))
				+ (mc_blas_vector_at(x, i + 1) * mc_blas_vector_at(y, i + 1))
				+ (mc_blas_vector_at(x, i + 2) * mc_blas_vector_at(y, i + 2))
				+ (mc_blas_vector_at(x, i + 3) * mc_blas_vector_at(y, i + 3))
				+ (mc_blas_vector_at(x, i + 4) * mc_blas_vector_at(y, i + 4))
			);
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
			temp = temp + (mc_blas_vector_at(x, ix) * mc_blas_vector_at(y, iy));
			ix   = ix + incx;
			iy   = iy + incy;
		}
	}
	return temp;
}

#endif /* !MC_BLAS_DOT_H */

/* EOF */
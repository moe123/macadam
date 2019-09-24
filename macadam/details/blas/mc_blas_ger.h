// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_ger.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?ger performs the rank 1 operation: a=alpha*x*y' + a.
 *
 * \synopsis
 *    void ?ger(trans, m, n, alpha, x, incx, y, incy, a, lda)
 *    float-floating alpha
 *    int            incx, incy, lda, m, n
 *    char           trans
 *    float-floating a(lda, *), x(*), y(*)
 *
 * \purpose
 *    ?ger erforms the rank 1 operation: a=alpha*x*y' + a where alpha is a scalar,
 *    x is an m element vector, y is an n element vector and a is an m by n matrix.
 *
 * \parameters
 *    [in] m     - int. Specifies the number of rows of the matrix a, m must be at least zero.
 *    [in] n     - int. Specifies the number of columns of the matrix a, must be at least zero.
 *
 *    [in] alpha - float-floating. Specifies the scalar alpha.
 *
 *    [in] x     - float-floating array of dimension at least (1+(m-1)*abs(incx)). The incremented
 *    array x must contain the m element vector x.
 *
 *    [in] incx  - int. Specifies the increment for the elements of x, incx must not be zero.

 *    [in] y     - float-floating array of dimension at least (1+(n-1)*abs(incy)). The incremented
 *    array y must contain the n element vector y.
 *
 *    [in] incy  - int. Specifies the increment for the elements of y, incy must not be zero.
 *
 *    [out] a     - float-floating array of dimension (lda, n), the leading m by n part of the
 *    array a must contain the matrix of coefficients. a is overwritten by the updated matrix.
 *
 *    [in] lda   - int. Specifies the first dimension of a, d must be at least max(1, m).
 * 
 * \examples
 *
 * \level 2 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Argonne National Lab.
 *     \author Jeremy Du Croz, Nag Central Office.
 *     \author Sven Hammarling, Nag Central Office.
 *     \author Richard Hanson, Sandia National Labs.
 */

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_GER_H
#define MC_BLAS_GER_H

#pragma mark - mc_blas_sger -

MC_TARGET_FUNC void mc_blas_sger(int m, int n, float alpha, const float * x, int incx, const float * y, int incy, float * a, int lda)
{
	const float zero = 0.0f;

	float temp;
	int i, info, j, ix, jy, kx;

	info = 0;
	if (m < 0) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, m)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("SGER  ", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, i) * temp);
				}
			}
			jy = jy + incy;
		}
	} else {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (m - 1) * incx;
		}
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, ix) * temp);
					ix                           = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#pragma mark - mc_blas_dger -

MC_TARGET_FUNC void mc_blas_dger(int m, int n, double alpha, const double * x, int incx, const double * y, int incy, double * a, int lda)
{
	const double zero = 0.0;

	double temp;
	int i, info, j, ix, jy, kx;

	info = 0;
	if (m < 0) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, m)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("DGER  ", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, i) * temp);
				}
			}
			jy = jy + incy;
		}
	} else {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (m - 1) * incx;
		}
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, ix) * temp);
					ix                           = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#pragma mark - mc_blas_lger -

MC_TARGET_FUNC void mc_blas_lger(int m, int n, long double alpha, const long double * x, int incx, const long double * y, int incy, long double * a, int lda)
{
	const long double zero = 0.0L;

	long double temp;
	int i, info, j, ix, jy, kx;

	info = 0;
	if (m < 0) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, m)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("LGER  ", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, i) * temp);
				}
			}
			jy = jy + incy;
		}
	} else {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (m - 1) * incx;
		}
		for (j = 1; j <= n; ++j) {
			if (MC_BLAS_VAT(y, jy) != zero) {
				temp = alpha * MC_BLAS_VAT(y, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(a, lda, n, i, j) = MC_BLAS_MAT(a, lda, n, i, j) + (MC_BLAS_VAT(x, ix) * temp);
					ix                           = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#endif /* !MC_BLAS_GER_H */

/* EOF */
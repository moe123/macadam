// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_ger_c.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?ger_c performs the rank 1 operation: a=alpha*x*y' + a.
 *
 * \synopsis
 *    void ?ger_c(m, n, alpha, x, ldx, nx, indx, incx, y, ldy, ny, indy, incy, a, lda)
 *    float-floating alpha
 *    int            incx, incy, indx, indy, lda, ldx, ldy, m, n, nx, ny
 *    float-floating a(lda, *), x(ldx, *), y(ldy, *)
 *
 * \purpose
 *    ?ger_c performs the rank 1 operation: a=alpha*x*y' + a where alpha is a scalar,
 *    x is an m element column-vector, y is an n element column-vector and a is an m by n matrix.
 *
 * \parameters
 *    [in]  m     - int. Specifies the number of rows of the matrix a, m must be at least zero.
 *    [in]  n     - int. Specifies the number of columns of the matrix a, must be at least zero.
 *
 *    [in]  alpha - float-floating. Specifies the scalar alpha.
 *
 *    [in]  x     - real-floating array of dimension (ldx, nx). The incremented column of x must contain
 *    the vector x.
 *    [in]  ldx   - int. Specifies the first dimension of x, ldx is at least (1+(m-1)*abs(incx)).
 *    [in]  nx    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [in] incx  - int. Specifies the increment for the elements of x, incx must not be zero.

 *    [in] y     - real-floating array of dimension (ldy, ny). The incremented column of y must contain the
 *    vector y.
 *    [in]  ldy   - int. Specifies the first dimension of x, ldx is at least (1+(n-1)*abs(incy)).
 *    [in]  ny    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  incy  - int. Specifies the increment for the elements of y, incy must not be zero.
 *
 *
 *    [out] a     - float-floating array of dimension (lda, n), the leading m by n part of the
 *    array a must contain the matrix of coefficients. a is overwritten by the updated matrix.
 *
 *    [in]  lda   - int. Specifies the first dimension of a, d must be at least max(1, m).
 * 
 * \examples
 *
 * \nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_NONLAS_GER_V_H
#define MC_NONLAS_GER_V_H

#pragma mark - mc_nonblas_sger_c -

MC_TARGET_FUNC void mc_nonblas_sger_c(int m, int n, float alpha, const float * x, int ldx, int nx, int indx, int incx, const float * y, int ldy, int ny, int indy, int incy, float * a, int lda)
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
		mc_blas_xerbla("SGER_V", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, i) * temp);
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
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, ix) * temp);
					ix                                 = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#pragma mark - mc_nonblas_dger_c -

MC_TARGET_FUNC void mc_nonblas_dger_c(int m, int n, double alpha, const double * x, int ldx, int nx, int indx, int incx, const double * y, int ldy, int ny, int indy, int incy, double * a, int lda)
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
		mc_blas_xerbla("DGER_V", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, i) * temp);
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
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, ix) * temp);
					ix                                 = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#pragma mark - mc_nonblas_lger_c -

MC_TARGET_FUNC void mc_nonblas_lger_c(int m, int n, long double alpha, const long double * x, int ldx, int nx, int indx, int incx, const long double * y, int ldy, int ny, int indy, int incy, long double * a, int lda)
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
		mc_blas_xerbla("LGER_V", info);
		return;
	}

	if (m == 0 || n == 0 || alpha == zero) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (incy > 0) {
		jy = 1;
	} else {
		jy = 1 - (n - 1) * incy;
	}
	if (incx == 1) {
		for (j = 1; j <= n; ++j) {
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, i) * temp);
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
			if (mc_blas_matrix_at(y, ldy, ny, indy, jy) != zero) {
				temp = alpha * mc_blas_matrix_at(y, ldy, ny, indy, jy);
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_matrix_at(x, ldx, nx, indx, ix) * temp);
					ix                                 = ix + incx;
				}
			}
			jy = jy + incy;
		}
	}
}

#endif /* !MC_NONLAS_GER_V_H */

/* EOF */
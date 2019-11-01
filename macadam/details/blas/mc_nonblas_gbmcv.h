//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_gbmcv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?gbmcv - performs one of the matrix-column-vector operations:
 *    y=alpha*a*x + beta*y, or y=alpha*a'*x + beta*y.
 *
 * \synopsis
 *    void ?gbmcv(trans, m, n, kl, ku, alpha, a, lda, x, ldx, nx, indx, incx, beta, y, ldy, ny, indy, incy)
 *    real-floating alpha, beta
 *    int           incx, incy, indx, indy, kl, ku, lda, ldx, ldy, m, n, nx, ny
 *    char          trans
 *    real-floating a(lda,*), x(ldx,*), y(ldy,*)
 *
 * \purpose
 *   ?gbmcv performs one of the matrix-column-vector operations where alpha and beta are scalars, x
 *   and y are column vectors and a is an m by n band matrix, with kl sub-diagonals and ku super-diagonals.
 *
 * \parameters
 *    [in]  trans - char. Specifies the operation to be performed as follows:
 *    trans='N' or 'n' y=alpha*a*x  + beta*y.
 *    trans='T' or 't' y=alpha*a'*x + beta*y.
 *    trans='C' or 'c' y=alpha*a'*x + beta*y.
 *
 *    [in]  m     - int. Specifies the number of rows of the matrix a, m must be at least zero.
 *    [in]  n     - int. Specifies the number of columns of the matrix a, n must be at least zero.
 *    [in]  kl    - int. Specifies the number of sub-diagonals of the matrix a. kl must satisfy 0 < kl.
 *    [in]  ku    - int. Specifies the number of super-diagonals of the matrix a. ku must satisfy 0 < ku.
 *
 *    [in]  alpha - real-floating. Specifies the scalar alpha.
 *
 *    [in]  a     - real-floating array of dimension (lda, n). The leading (kl + ku + 1) by n part of
 *    the array a must contain the matrix of coefficients, supplied column by column, with the leading
 *    diagonal of the matrix in row (ku + 1) of the array, the first super-diagonal starting at position
 *    1 in row ku, the first sub-diagonal starting at position 0 in row (ku + 1), and so on. Elements in
 *    the array a that do not correspond to elements in the band matrix (such as the top left ku by ku
 *    triangle) are not referenced.
 *
 *    [in]  lda   - int. Specifies the first dimension of a band matrix, lda must be at least (kl + ku + 1).
 *
 *    [in]  x     - real-floating array of dimension (ldx, nx). The incremented column of x must contain
 *    the vector x.
 *    [in]  ldx   - int. Specifies the first dimension of x, ldx is at least (1+(n-1)*abs(incx)) when
 *    trans = 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 *    [in]  nx    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  indx  - int. Specifies the column vector index of x, indx must be within range [1, nx].
 *    [in]  incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [in]  beta  - real-floating. Specifies the scalar beta. when beta is supplied as zero then y need not
 *    be set on input.

 *    [out] y     - real-floating array of dimension (ldx, nx). The incremented column of y must contain the
 *    vector y, y column is overwritten by the updated vector y.
 *    is overwritten by the updated vector y.
 *    [in]  ldy   - int. Specifies the first dimension of x, ldx is at least (1+(m-1)*abs(incy)) when
 *    trans = 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise.
 *    [in]  ny    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  incy - int. Specifies the increment for the elements of y. incy must not be zero.
 *
 * \examples
 *              | 1 1 1 0 |
 *              | 2 2 2 2 |
 *     a[5x4] = | 3 3 3 3 |
 *              | 4 4 4 4 |
 *              | 0 5 5 5 |
 *
 *     const real-floating a_band[] = {
 *          0, 0, 1, 2
 *        , 0, 1, 2, 3
 *        , 1, 2, 3, 4
 *        , 2, 3, 4, 5
 *        , 3, 4, 5, 0
 *        , 4, 5, 0, 0
 *        , 0, 0, 0, 0
 *        , 0, 0, 0, 0
 *     };
 *     const real-floating x[] = {
 *          1
 *        , 2
 *        , 3
 *        , 4
 *     };
 *           real-floating y[] = {
 *          0, 0, 1, 0
 *        , 0, 0, 0, 0
 *        , 0, 0, 2, 0
 *        , 0, 0, 0, 0
 *        , 0, 0, 3, 0
 *        , 0, 0, 0, 0
 *        , 0, 0, 4, 0
 *        , 0, 0, 0, 0
 *        , 0, 0, 5, 0
 *        , 0, 0, 0, 0
 *     };
 *     mc_blas_?gbmcv('N', 5, 4, 3, 2, 2, a, 8, x, 4, 1, 1, 1, 10, y, 10, 4, 3, 2);
 *     on output -> y = {
 *          0, 0,  22, 0
 *        , 0, 0,   0, 0
 *        , 0, 0,  60, 0
 *        , 0, 0,   0, 0
 *        , 0, 0,  90, 0
 *        , 0, 0,   0, 0
 *        , 0, 0, 120, 0
 *        , 0, 0,   0, 0
 *        , 0, 0, 140, 0
 *        , 0, 0,   0, 0
 *     }
 *
 *              | 1 1 1 1 1 |
 *     a[4x5] = | 2 2 2 2 2 |
 *              | 3 3 3 3 3 |
 *              | 4 4 4 4 4 |
 *
 *     const real-floating a_band[] = {
 *          0, 0, 0, 0, 0
 *        , 0, 0, 0, 0, 1
 *        , 0, 0, 0, 1, 2
 *        , 0, 0, 1, 2, 3
 *        , 0, 1, 2, 3, 4
 *        , 1, 2, 3, 4, 0
 *        , 2, 3, 4, 0, 0
 *        , 3, 4, 0, 0, 0
 *        , 4, 0, 0, 0, 0
 *        , 0, 0, 0, 0, 0
 *        , 0, 0, 0, 0, 0
 *        , 0, 0, 0, 0, 0
 *     };
 *     const real-floating x[] = { 
 *          1
 *        , 2
 *        , 3
 *        , 4
 *        , 5
 *     };
 *           real-floating y[] = { 
 *          1
 *        , 0
 *        , 2
 *        , 0
 *        , 3
 *        , 0
 *        , 4
 *        , 0
 *     };
 *     mc_blas_?gbmcv('N', 4, 5, 6, 5, 2, a_band, 12, x, 5, 1, 1, 1, 10, y, 8, 1, 1, 2);
 *     on output -> y[] = {
 *           40
 *        ,   0
 *        ,  80
 *        ,   0
 *        , 120
 *        ,   0
 *        , 160
 *        ,   0
 *     }
 *
 * \level 3 nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>
#include <macadam/details/math/mc_minmag.h>

#ifndef MC_NONBLAS_GBMCV_H
#define MC_NONBLAS_GBMCV_H

#pragma mark - mc_nonblas_sgbmcv -

MC_TARGET_FUNC void mc_nonblas_sgbmcv(const char trans, int m, int n, int kl, int ku, float alpha, const float * a, int lda, const float * x, int ldx, int nx, int indx, int incx, float beta, float * y, int ldy, int ny, int indy, int incy)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("SGBMCV", info);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = zero;
					iy                      = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = beta * mc_blas_matrix_at(y, ldy, ny, indy, iy);
					iy                                      = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = mc_blas_matrix_at(y, ldy, ny, indy, iy) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
					iy                                      = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, ix));
					ix   = ix + incx;
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#pragma mark - mc_nonblas_dgbmcv -

MC_TARGET_FUNC void mc_nonblas_dgbmcv(const char trans, int m, int n, int kl, int ku, double alpha, const double * a, int lda, const double * x, int ldx, int nx, int indx, int incx, double beta, double * y, int ldy, int ny, int indy, int incy)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("DGBMCV", info);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = zero;
					iy                      = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = beta * mc_blas_matrix_at(y, ldy, ny, indy, iy);
					iy                                      = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = mc_blas_matrix_at(y, ldy, ny, indy, iy) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
					iy                                      = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, ix));
					ix   = ix + incx;
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#pragma mark - mc_nonblas_lgbmcv -

MC_TARGET_FUNC void mc_nonblas_lgbmcv(const char trans, int m, int n, int kl, int ku, long double alpha, const long double * a, int lda, const long double * x, int ldx, int nx, int indx, int incx, long double beta, long double * y, int ldy, int ny, int indy, int incy)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("LGBMCV", info);
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = zero;
					iy                      = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = beta * mc_blas_matrix_at(y, ldy, ny, indy, iy);
					iy                                      = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_matrix_at(x, ldx, nx, indx, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					mc_blas_matrix_at(y, ldy, ny, indy, iy) = mc_blas_matrix_at(y, ldy, ny, indy, iy) + (temp * mc_blas_matrix_at(a, lda, n, k + i, j));
					iy                                      = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, k + i, j) * mc_blas_matrix_at(x, ldx, nx, indx, ix));
					ix   = ix + incx;
				}
				mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (alpha * temp);
				jy                                      = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#endif /* !MC_NONBLAS_GBMCV_H */

/* EOF */
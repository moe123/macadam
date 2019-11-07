//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_ugecv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?ugecv performs one of the matrix-column-vector operations:
 *    y=a*x + beta*y or y=a'*x + beta*y.
 *
 * \synopsis
 *    void ?ugecv(trans, m, n, a, lda, x, ldx, nx, indx, incx, beta, y, ldy, ny, indy, incy)
 *    real-floating alpha, beta
 *    int           indx, indy, incx, incy, lda, ldx, ldy, m, n, nx, ny
 *    char          trans
 *    real-floating a(lda, *), x(ldx, *), y(ldy, *)
 *
 * \purpose
 *    ?ugecv performs one of the matrix-column-vector operations: y=a*x + beta*y or
 *    y=a'*x + beta*y where alpha and beta are scalars, x and y are vectors
 *    and a is an m by n matrix.
 *
 * \parameters
 *    [in]  trans - char. Specifies the operation to be performed as follows:
 *    trans= 'N' or 'n' y=a*x + beta*y.
 *    trans= 'T' or 't' y=a'*x + beta*y.
 *    trans= 'C' or 'c' y=a'*x + beta*y.
 *
 *    [in]  m     - int. Specifies the number of rows of the matrix a, m must be at least zero.
 *    [in]  n     - int. Specifies the number of columns of the matrix a, must be at least zero.
 *
 *    [in]  alpha - real-floating. Specifies the scalar alpha.
 *
 *    [in]  a     - real-floating array of dimension (lda, n), the leading m by n part of the
 *    array a must contain the matrix of coefficients.
 *
 *    [in] lda    - int. Specifies the first dimension of a, d must be at least max(1, m).
 *
 *    [in]  x     - real-floating array of dimension (ldx, nx). The incremented column of x must contain
 *    the vector x.
 *    [in]  ldx   - int. Specifies the first dimension of x, ldx is at least (1+(n-1)*abs(incx)) when
 *    trans = 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 *    [in]  nx    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [in]  beta  - real-floating. Specifies the scalar beta. When beta is supplied as zero then y need
 *    not be set on input.

 *    [out] y     - real-floating array of dimension (ldy, ny). The incremented column of y must contain the
 *    vector y, y column is overwritten by the updated vector y.
 *    is overwritten by the updated vector y.
 *    [in]  ldy   - int. Specifies the first dimension of x, ldx is at least (1+(m-1)*abs(incy)) when
 *    trans = 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise.
 *    [in]  ny    - int. Specifies the second dimension of x, nx must be at least 1.
 *    [in]  incy  - int. Specifies the increment for the elements of y, incy must not be zero.
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

#ifndef MC_NONBLAS_UGECV_H
#define MC_NONBLAS_UGECV_H

#pragma mark - mc_nonblas_sugecv -

MC_TARGET_FUNC void mc_nonblas_sugecv(const char trans, int m, int n, const float * a, int lda, const float * x, int ldx, int nx, int indx, float beta, float * y, int ldy, int ny, int indy)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, j, jx, jy, kx, ky, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	}
	if (info != 0) {
		mc_blas_xerbla("SUGECV", info);
		return;
	}

	if (m == 0 || n == 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		leny = m;
	} else {
		leny = n;
	}
	kx = 1;
	ky = 1;

	if (beta != one) {
		if (beta == zero) {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_matrix_at(x, ldx, nx, indx, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
			}
			mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (temp);
			jy                                      = jy + 1;
		}
	}
}

#pragma mark - mc_nonblas_dugecv -

MC_TARGET_FUNC void mc_nonblas_dugecv(const char trans, int m, int n, const double * a, int lda, const double * x, int ldx, int nx, int indx, double beta, double * y, int ldy, int ny, int indy)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, j, jx, jy, kx, ky, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	}
	if (info != 0) {
		mc_blas_xerbla("DUGECV", info);
		return;
	}

	if (m == 0 || n == 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		leny = m;
	} else {
		leny = n;
	}
	kx = 1;
	ky = 1;

	if (beta != one) {
		if (beta == zero) {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_matrix_at(x, ldx, nx, indx, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
			}
			mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (temp);
			jy                                      = jy + 1;
		}
	}
}

#pragma mark - mc_nonblas_lugecv -

MC_TARGET_FUNC void mc_nonblas_lugecv(const char trans, int m, int n, const long double * a, int lda, const long double * x, int ldx, int nx, int indx, long double beta, long double * y, int ldy, int ny, int indy)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, info, j, jx, jy, kx, ky, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	}
	if (info != 0) {
		mc_blas_xerbla("LUGECV", info);
		return;
	}

	if (m == 0 || n == 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		leny = m;
	} else {
		leny = n;
	}
	kx = 1;
	ky = 1;

	if (beta != one) {
		if (beta == zero) {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = beta * mc_blas_matrix_at(y, ldy, ny, indy, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_matrix_at(x, ldx, nx, indx, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(y, ldy, ny, indy, i) = mc_blas_matrix_at(y, ldy, ny, indy, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_matrix_at(x, ldx, nx, indx, i));
			}
			mc_blas_matrix_at(y, ldy, ny, indy, jy) = mc_blas_matrix_at(y, ldy, ny, indy, jy) + (temp);
			jy                                      = jy + 1;
		}
	}
}

#endif /* !MC_NONBLAS_UGECV_H */

/* EOF */
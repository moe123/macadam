//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_ugemv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?ugemv performs one of the matrix-vector operations:
 *    y=a*x + beta*y or y=a'*x + beta*y.
 *
 * \synopsis
 *    void ?ugemv(trans, m, n, a, lda, x, beta0, y)
 *    int           beta0, lda, m, n
 *    char          trans
 *    real-floating a(lda, *), x(*), y(*)
 *
 * \purpose
 *    ?ugemv performs one of the matrix-vector operations: y=a*x + beta*y or
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
 *    [in]  a     - real-floating array of dimension (lda, n), the leading m by n part of the
 *    array a must contain the matrix of coefficients.
 *
 *    [in]  lda   - int. Specifies the first dimension of a, d must be at least max(1, m).
 *
 *    [in]  x     - real-floating array of dimension at least n when trans='N' or 'n'
 *    and at least m otherwise. The incremented array x must contain the vector x.
 *
 *    [in]  beta  - real-floating. Specifies the scalar beta. When beta is supplied as zero then y need
 *    not be set on input.
 *
 *    [out] y     - real-floating array of dimension at least m when trans='N' or 'n'
 *    and at least n otherwise. With beta non-zero, the incremented array y must contain
 *    the vector y, y is overwritten by the updated vector y.
 *
 * \examples
 *
 * \nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_NONBLAS_UGEMV_H
#define MC_NONBLAS_UGEMV_H

#pragma mark - mc_nonblas_sugemv -

MC_TARGET_FUNC void mc_nonblas_sugemv(const char trans, int m, int n, const float * a, int lda, const float * x, float beta, float * y)
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
		mc_blas_xerbla("SUGEMV", info);
		return;
	}

	if (m == 0 || n == 0) {
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
				mc_blas_vector_at(y, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_vector_at(x, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
			}
			mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp);
			jy                       = jy + 1;
		}
	}
}

#pragma mark - mc_nonblas_dugemv -

MC_TARGET_FUNC void mc_nonblas_dugemv(const char trans, int m, int n, const double * a, int lda, const double * x, double beta, double * y)
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
		mc_blas_xerbla("DUGEMV", info);
		return;
	}

	if (m == 0 || n == 0) {
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
				mc_blas_vector_at(y, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_vector_at(x, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
			}
			mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp);
			jy                       = jy + 1;
		}
	}
}

#pragma mark - mc_nonblas_lugemv -

MC_TARGET_FUNC void mc_nonblas_lugemv(const char trans, int m, int n, const long double * a, int lda, const long double * x, long double beta, long double * y)
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
		mc_blas_xerbla("LUGEMV", info);
		return;
	}

	if (m == 0 || n == 0) {
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
				mc_blas_vector_at(y, i) = zero;
			}
		} else {
			for (i = 1; i <= leny; ++i) {
				mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
			}
		}
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		for (j = 1; j <= n; ++j) {
			temp = mc_blas_vector_at(x, jx);
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
			}
			jx   = jx + 1;
		}
	} else {
		jy = ky;
		for (j = 1; j <= n; ++j) {
			temp = zero;
			for (i = 1; i <= m; ++i) {
				temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
			}
			mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp);
			jy                       = jy + 1;
		}
	}
}

#endif /* !MC_NONBLAS_UGEMV_H */

/* EOF */
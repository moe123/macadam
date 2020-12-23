//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_gemv.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?gemv performs one of the matrix-vector operations:
 *    y=alpha*a*x + beta*y or y=alpha*a'*x + beta*y.
 *
 * \synopsis
 *    void ?gemv(trans, m, n, alpha, a, lda, x, incx, beta, y, incy)
 *    real-floating alpha, beta
 *    int           incx, incy, lda, m, n
 *    char          trans
 *    real-floating a(lda, *), x(*), y(*)
 *
 * \purpose
 *    ?gemv performs one of the matrix-vector operations: y=alpha*a*x + beta*y or
 *    y=alpha*a'*x + beta*y where alpha and beta are scalars, x and y are vectors
 *    and a is an m by n matrix.
 *
 * \parameters
 *    [in]  trans - char. Specifies the operation to be performed as follows:
 *    trans= 'N' or 'n' y=alpha*a*x + beta*y.
 *    trans= 'T' or 't' y=alpha*a'*x + beta*y.
 *    trans= 'C' or 'c' y=alpha*a'*x + beta*y.
 *
 *    [in]  m     - int. Specifies the number of rows of the matrix a, m must be at least zero.
 *    [in]  n     - int. Specifies the number of columns of the matrix a, must be at least zero.
 *
 *    [in]  alpha - real-floating. Specifies the scalar alpha.
 *
 *    [in]  a     - real-floating array of dimension (lda, n), the leading m by n part of the
 *    array a must contain the matrix of coefficients.
 *
 *    [in]  lda   - int. Specifies the first dimension of a, lda must be at least max(1, m).
 *
 *    [in]  x     - real-floating array of dimension at least (1+(n-1)*abs(incx)) when trans='N' or 'n'
 *    and at least (1+(m-1)*abs(incx)) otherwise. The incremented array x must contain the vector x.
 *
 *    [in]  incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [in]  beta  - real-floating. Specifies the scalar beta. When beta is supplied as zero then y need
 *    not be set on input.

 *    [out] y     - real-floating array of dimension at least (1+(m-1)*abs(incy)) when trans='N' or 'n'
 *    and at least (1+(n-1)*abs(incy)) otherwise. With beta non-zero, the incremented array y must contain
 *    the vector y, y is overwritten by the updated vector y.
 *
 *    [in]  incy  - int. Specifies the increment for the elements of y, incy must not be zero.
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

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_GEMV_H
#define MC_BLAS_GEMV_H

#pragma mark - mc_blas_sgemv -

MC_TARGET_FUNC void mc_blas_sgemv(const char trans, const int m, const int n, float alpha, const float * a, const int lda, const float * x, const int incx, float beta, float * y, const int incy)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, ix, iy, j, jx, jy, kx, ky, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("SGEMV ", info);
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
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				iy   = ky;
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
					iy                       = iy + incy;
				}
				jx   = jx + incx;
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, ix));
					ix   = ix + incx;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_dgemv -

MC_TARGET_FUNC void mc_blas_dgemv(const char trans, const int m, const int n, double alpha, const double * a, const int lda, const double * x, const int incx, double beta, double * y, const int incy)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, ix, iy, j, jx, jy, kx, ky, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("DGEMV ", info);
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
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				iy   = ky;
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
					iy                       = iy + incy;
				}
				jx   = jx + incx;
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, ix));
					ix   = ix + incx;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_lgemv -

MC_TARGET_FUNC void mc_blas_lgemv(const char trans, const int m, const int n, long double alpha, const long double * a, const int lda, const long double * x, const int incx, long double beta, long double * y, const int incy)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, info, ix, iy, j, jx, jy, kx, ky, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (lda < mc_maxmag(1, m)) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("LGEMV ", info);
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
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * mc_blas_vector_at(x, jx);
				iy   = ky;
				for (i = 1; i <= m; ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp * mc_blas_matrix_at(a, lda, n, i, j));
					iy                       = iy + incy;
				}
				jx   = jx + incx;
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				for (i = 1; i <= m; ++i) {
					temp = temp + (mc_blas_matrix_at(a, lda, n, i, j) * mc_blas_vector_at(x, ix));
					ix   = ix + incx;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp);
				jy                       = jy + incy;
			}
		}
	}
}

#endif /* !MC_BLAS_GEMV_H */

/* EOF */
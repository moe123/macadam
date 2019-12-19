//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_gemm.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?gemm performs one of the matrix-matrix operations:
 *    c=alpha*op(a)*op(b) + beta*c where op(x)=x or op(x)=x'.
 *
 * \synopsis
 *    void ?gemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
 *    real-floating alpha, beta
 *    int           k, lda, ldb, ldc, m, n
 *    char          transa, transb
 *    real-floating a(lda, *), b(ldb, *), c(ldc, *)
 *
 * \purpose
 *    ?gemm performs one of the matrix-matrix operations: c=alpha*op(a)*op(b) + beta*c where
 *    op(x)=x or op(x)=x' alpha and beta are scalars, and a, b and c are matrices, with op(a)
 *    an m by k matrix, op(b) a k by n matrix and c an m by n matrix.
 *
 * \parameters
 *    [in] transa - char. Specifies the form of op(a) to be used in the matrix multiplication as follows:
 *    transa='N' or 'n', op(a)=a.
 *    transa='T' or 't', op(a)=a'.
 *    transa='C' or 'c', op(a)=a'.
 *
 *    [in] transb - char. Specifies the form of op(b) to be used in the matrix multiplication as follows:
 *    transb='N' or 'n', op(b)=b.
 *    transb='T' or 't', op(b)=b'.
 *    transb='C' or 'c', op(b)=b'.
 *
 *    [in] m      - int. Specifies the number of rows of the matrix op(a) and of the matrix c, m must be
 *    at least zero.
 *
 *    [in] n      - int. Specifies the number of columns of the matrix op(b) and the number of columns of
 *    the matrix c, n must be at least zero.
 *
 *    [in] k      - int. Specifies  the number of columns of the matrix op(a) and the number of rows of
 *    the matrix op(b), k must be at least zero.
 *
 *    [in] alpha  - real-floating. Specifies the scalar alpha.
 *
 *    [in] a      - real-floating array of dimension (lda, ka), where ka is k when transa='N' or 'n' and
 *    is m otherwise. Prior entry with transa='N' or 'n', the leading m by k part of the array a must
 *    contain the matrix a, otherwise the leading k by m part of the array a must contain the matrix a.
 *
 *    [in] lda    - int. Specifies the first dimension of a. When transa='N' or 'n' then
 *    lda must be at least max(1, m), otherwise lda must be at least max(1, k).
 *
 *    [in] b      - real-floating array of dimension (ldb, kb), where kb is n when transb='N' or 'n' and
 *    is k otherwise. Prior entry with transb='N' or 'n', the leading k by n part of the array b must
 *    contain the matrix b, otherwise the leading n by k part of the array b must contain the matrix b.
 *
 *    [in] ldb    - int. Specifies the first dimension of b. When transb='N' or 'n' then
 *    ldb must be at least max(1, k), otherwise ldb must be at least max(1, n).
 *
 *    [in] beta   - real-floating. Specifies the scalar beta. When beta is supplied as zero then c need
 *    not be set on input.
 *
 *    [out] c     - real-floating array of dimension (ldc, n). Prior entry the leading  m by n part of the
 *    array c must contain the matrix c, except when beta is set to zero, in which case c need not be set
 *    on entry, c is overwritten by the m by n matrix (alpha*op(a)*op(b) + beta*c).
 *
 *    [in] ldc    - int. Specifies the first dimension of c, ldc must be at least max(1, m).
 *
 * \examples
 *
 * \level 3 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Argonne National Laboratory.
 *     \author Iain Duff, AERE Harwell.
 *     \author Jeremy Du Croz, Numerical Algorithms Group Ltd.
 *     \author Sven Hammarling, Numerical Algorithms Group Ltd.
 */

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_GEMM_H
#define MC_BLAS_GEMM_H

#pragma mark - mc_blas_sgemm -

MC_TARGET_FUNC void mc_blas_sgemm(const char transa, const char transb, int m, int n, int k, float alpha, const float * a, int lda, const float * b, int ldb, float beta, float * c, int ldc)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, j, l, ncola, nrowa, nrowb, ka, kb;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');

# if MCTARGET_BLAS_USE_CLAYOUT
# if MCTARGET_BLAS_USE_CLONE
	mcswap_var(i, m, n);
	k   = n;
//# ldc is set to wrong value in row-major @see info = 13.
	ldc = m;
# endif
	if (nota) {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);

	} else {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = n;
		nrowb = n;
	} else {
		kb    = k;
		nrowb = k;
	}
#	else
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);

	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = k;
		nrowb = k;
	} else {
		kb    = n;
		nrowb = n;
	}
#	endif

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
		info = 1;
	} else if (!notb && !mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (k < 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 8;
	} else if (ldb < mc_maxmag(1, nrowb)) {
		info = 10;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("SGEMM ", info);
		return;
	}

	if (m == 0 || n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (beta == zero) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
				}
			}
		}
		return;
	}

	if (notb) {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_dgemm -

MC_TARGET_FUNC void mc_blas_dgemm(const char transa, const char transb, int m, int n, int k, double alpha, const double * a, int lda, const double * b, int ldb, double beta, double * c, int ldc)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, j, l, ncola, nrowa, nrowb, ka, kb;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');

# if MCTARGET_BLAS_USE_CLAYOUT
# if MCTARGET_BLAS_USE_CLONE
	mcswap_var(i, m, n);
	k   = n;
//# ldc is set to wrong value in row-major @see info = 13.
	ldc = m;
# endif
	if (nota) {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);

	} else {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = n;
		nrowb = n;
	} else {
		kb    = k;
		nrowb = k;
	}
#	else
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);

	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = k;
		nrowb = k;
	} else {
		kb    = n;
		nrowb = n;
	}
#	endif

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
		info = 1;
	} else if (!notb && !mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (k < 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 8;
	} else if (ldb < mc_maxmag(1, nrowb)) {
		info = 10;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("DGEMM ", info);
		return;
	}

	if (m == 0 || n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (beta == zero) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
				}
			}
		}
		return;
	}

	if (notb) {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_lgemm -

MC_TARGET_FUNC void mc_blas_lgemm(const char transa, const char transb, int m, int n, int k, long double alpha, const long double * a, int lda, const long double * b, int ldb, long double beta, long double * c, int ldc)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, info, j, l, ncola, nrowa, nrowb, ka, kb;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');

# if MCTARGET_BLAS_USE_CLAYOUT
# if MCTARGET_BLAS_USE_CLONE
	mcswap_var(i, m, n);
	k   = n;
//# ldc is set to wrong value in row-major @see info = 13.
	ldc = m;
# endif
	if (nota) {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);

	} else {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = n;
		nrowb = n;
	} else {
		kb    = k;
		nrowb = k;
	}
#	else
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
		mc_cast(void, ncola);

	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
		mc_cast(void, ncola);
	}
	if (notb) {
		kb    = k;
		nrowb = k;
	} else {
		kb    = n;
		nrowb = n;
	}
#	endif

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
		info = 1;
	} else if (!notb && !mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (k < 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 8;
	} else if (ldb < mc_maxmag(1, nrowb)) {
		info = 10;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("LGEMM ", info);
		return;
	}

	if (m == 0 || n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (beta == zero) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
				}
			}
		}
		return;
	}

	if (notb) {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#endif /* !MC_BLAS_GEMM_H */

/* EOF */
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_symm.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_SYMM_H
#define MC_BLAS_SYMM_H

#pragma mark - mc_blas_ssymm -

MC_TARGET_FUNC void mc_blas_ssymm(const char side, const char uplo, int m, int n, float alpha, const float * a, int lda, const float * b, int ldb, float beta, float * c, int ldc)
{
	const float one = 1.0f, zero = 0.0f;

	float temp1, temp2;
	int i, info, j, k, nrowa, ka;
	int upper;

	if (mc_blas_lsame(side, 'L')) {
		ka    = n;
		nrowa = m;
	} else {
		ka    = m;
		nrowa = n;
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!mc_blas_lsame(side, 'L') && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("SSYMM ", info);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
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

	if (mc_blas_lsame(side, 'L')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = 1; k <= (i - 1); ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha *  temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = m; i >= 1; --i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = i + 1; k <= m; ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					}
				}
			}
		}
	} else {
		for (j = 1; j <= n; ++j) {
			temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, j);
			if (beta == zero) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			} else {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			}
			for (k = 1; k <= (j - 1); ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
			for (k = j + 1; k <= n; ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
		}
	}
}

#pragma mark - mc_blas_dsymm -

MC_TARGET_FUNC void mc_blas_dsymm(const char side, const char uplo, int m, int n, double alpha, const double * a, int lda, const double * b, int ldb, double beta, double * c, int ldc)
{
	const double one = 1.0, zero = 0.0;

	double temp1, temp2;
	int i, info, j, k, nrowa, ka;
	int upper;

	if (mc_blas_lsame(side, 'L')) {
		ka    = n;
		nrowa = m;
	} else {
		ka    = m;
		nrowa = n;
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!mc_blas_lsame(side, 'L') && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("DSYMM ", info);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
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

	if (mc_blas_lsame(side, 'L')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = 1; k <= (i - 1); ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha *  temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = m; i >= 1; --i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = i + 1; k <= m; ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					}
				}
			}
		}
	} else {
		for (j = 1; j <= n; ++j) {
			temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, j);
			if (beta == zero) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			} else {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			}
			for (k = 1; k <= (j - 1); ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
			for (k = j + 1; k <= n; ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
		}
	}
}

#pragma mark - mc_blas_lsymm -

MC_TARGET_FUNC void mc_blas_lsymm(const char side, const char uplo, int m, int n, long double alpha, const long double * a, int lda, const long double * b, int ldb, long double beta, long double * c, int ldc)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp1, temp2;
	int i, info, j, k, nrowa, ka;
	int upper;

	if (mc_blas_lsame(side, 'L')) {
		ka    = n;
		nrowa = m;
	} else {
		ka    = m;
		nrowa = n;
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!mc_blas_lsame(side, 'L') && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (m < 0) {
		info = 3;
	} else if (n < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, m)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("LSYMM ", info);
		return;
	}

	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
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

	if (mc_blas_lsame(side, 'L')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = 1; k <= (i - 1); ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha *  temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = m; i >= 1; --i) {
					temp1 = alpha * mc_blas_matrix_at(b, ldb, n, i, j);
					temp2 = zero;
					for (k = i + 1; k <= m; ++k) {
						mc_blas_matrix_at(c, ldc, n, k, j) = mc_blas_matrix_at(c, ldc, n, k, j) + (temp1 * mc_blas_matrix_at(a, lda, ka, k, i));
						temp2                              = temp2 + (mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, i));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(a, lda, ka, i, i) + alpha * temp2;
					}
				}
			}
		}
	} else {
		for (j = 1; j <= n; ++j) {
			temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, j);
			if (beta == zero) {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			} else {
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + temp1 * mc_blas_matrix_at(b, ldb, n, i, j);
				}
			}
			for (k = 1; k <= (j - 1); ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
			for (k = j + 1; k <= n; ++k) {
				if (upper) {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
				} else {
					temp1 = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
				}
				for (i = 1; i <= m; ++i) {
					mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp1 * mc_blas_matrix_at(b, ldb, n, i, k));
				}
			}
		}
	}
}

#endif /* !MC_BLAS_SYMM_H */

/* EOF */
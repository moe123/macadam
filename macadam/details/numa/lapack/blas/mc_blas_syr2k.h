// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_syr2k.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_SYR2K_H
#define MC_BLAS_SYR2K_H

#pragma mark - mc_blas_ssyr2k -

MC_TARGET_FUNC void mc_blas_ssyr2k(const char uplo, const char trans, const int n, const int k, float alpha, const float * a, const int lda, const float * b, const int ldb, float beta, float * c, const int ldc)
{
	const float one = 1.0f, zero = 0.0f;

	float temp1, temp2;
	int i, info, j, l, nrowa, ka, kb;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		kb    = k;
		nrowa = n;
		mc_unused(ka);
		mc_unused(kb);
	} else {
		ka    = n;
		kb    = n;
		nrowa = k;
		mc_unused(ka);
		mc_unused(kb);
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (k < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, n)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("SSYR2K", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		}
	} else {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_dsyr2k -

MC_TARGET_FUNC void mc_blas_dsyr2k(const char uplo, const char trans, const int n, const int k, double alpha, const double * a, const int lda, const double * b, const int ldb, double beta, double * c, const int ldc)
{
	const double one = 1.0, zero = 0.0;

	double temp1, temp2;
	int i, info, j, l, nrowa, ka, kb;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		kb    = k;
		nrowa = n;
		mc_unused(ka);
		mc_unused(kb);
	} else {
		ka    = n;
		kb    = n;
		nrowa = k;
		mc_unused(ka);
		mc_unused(kb);
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (k < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, n)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("DSYR2K", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		}
	} else {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_lsyr2k -

MC_TARGET_FUNC void mc_blas_lsyr2k(const char uplo, const char trans, const int n, const int k, long double alpha, const long double * a, const int lda, const long double * b, const int ldb, long double beta, long double * c, const int ldc)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp1, temp2;
	int i, info, j, l, nrowa, ka, kb;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		kb    = k;
		nrowa = n;
		mc_unused(ka);
		mc_unused(kb);
	} else {
		ka    = n;
		kb    = n;
		nrowa = k;
		mc_unused(ka);
		mc_unused(kb);
	}
	upper = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (k < 0) {
		info = 4;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 7;
	} else if (ldb < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldc < mc_maxmag(1, n)) {
		info = 12;
	}
	if (info != 0) {
		mc_blas_xerbla("LSYR2K", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		}
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero || mc_blas_matrix_at(b, ldb, kb, j, l) != zero) {
						temp1 = alpha * mc_blas_matrix_at(b, ldb, kb, j, l);
						temp2 = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + mc_blas_matrix_at(a, lda, ka, i, l) * temp1 + mc_blas_matrix_at(b, ldb, kb, i, l) * temp2;
						}
					}
				}
			}
		}
	} else {
		if (upper) {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp1 = zero;
					temp2 = zero;
					for (l = 1; l <= k; ++l) {
						temp1 = temp1 + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(b, ldb, kb, l, j));
						temp2 = temp2 + (mc_blas_matrix_at(b, ldb, kb, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp1 + alpha * temp2;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j) + alpha * temp1 + alpha * temp2;
					}
				}
			}
		}
	}
}

#endif /* !MC_BLAS_SYR2K_H */

/* EOF */
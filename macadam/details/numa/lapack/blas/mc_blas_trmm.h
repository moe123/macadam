// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_trmm.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_TRMM_H
#define MC_BLAS_TRMM_H

#pragma mark - mc_blas_strmm -

MC_TARGET_FUNC void mc_blas_strmm(const char side, const char uplo, const char transa, const char diag, int m, int n, float alpha, const float * a, int lda, float * b, int ldb)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, j, k, nrowa, ka;
	int lside, nounit, upper;

	lside = mc_blas_lsame(side, 'L');
	if (lside) {
		ka    = m;
		nrowa = m;
	} else {
		ka    = n;
		nrowa = n;
	}
	nounit = mc_blas_lsame(diag, 'N');
	upper  = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!lside && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (!mc_blas_lsame(transa, 'N') && !mc_blas_lsame(transa, 'T') && !mc_blas_lsame(transa, 'C')) {
		info = 3;
	} else if (!mc_blas_lsame(diag, 'U') && !mc_blas_lsame(diag, 'N')) {
		info = 4;
	} else if (m < 0) {
		info = 5;
	} else if (n < 0) {
		info = 6;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("STRMM ", info);
		return;
	}

	if (m == 0 || n == 0) {
		return;
	}

	if (alpha == zero) {
		for (j = 1; j <= n; ++j) {
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(b, ldb, n, i, j) = zero;
			}
		}
		return;
	}

	if (lside) {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (k = 1; k <= m; ++k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							for (i = 1; i <= (k - 1); ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
							if (nounit) {
								temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (k = m; k >= 1; --k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
							if (nounit) {
								mc_blas_matrix_at(b, ldb, n, k, j) = mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							for (i = k + 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (i = m; i >= 1; --i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = 1; k <= (i - 1); ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= m; ++i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = i + 1; k <= m; ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			}
		}
	} else {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = n; j >= 1; --j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = 1; k <= (j - 1); ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = j + 1; k <= n; ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (k = 1; k <= n; ++k) {
					for (j = 1; j <= (k - 1); ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			} else {
				for (k = n; k >= 1; --k) {
					for (j = k + 1; j <= n; ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_dtrmm -

MC_TARGET_FUNC void mc_blas_dtrmm(const char side, const char uplo, const char transa, const char diag, int m, int n, double alpha, const double * a, int lda, double * b, int ldb)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, j, k, nrowa, ka;
	int lside, nounit, upper;

	lside = mc_blas_lsame(side, 'L');
	if (lside) {
		ka    = m;
		nrowa = m;
	} else {
		ka    = n;
		nrowa = n;
	}
	nounit = mc_blas_lsame(diag, 'N');
	upper  = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!lside && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (!mc_blas_lsame(transa, 'N') && !mc_blas_lsame(transa, 'T') && !mc_blas_lsame(transa, 'C')) {
		info = 3;
	} else if (!mc_blas_lsame(diag, 'U') && !mc_blas_lsame(diag, 'N')) {
		info = 4;
	} else if (m < 0) {
		info = 5;
	} else if (n < 0) {
		info = 6;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("DTRMM ", info);
		return;
	}

	if (m == 0 || n == 0) {
		return;
	}

	if (alpha == zero) {
		for (j = 1; j <= n; ++j) {
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(b, ldb, n, i, j) = zero;
			}
		}
		return;
	}

	if (lside) {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (k = 1; k <= m; ++k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							for (i = 1; i <= (k - 1); ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
							if (nounit) {
								temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (k = m; k >= 1; --k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
							if (nounit) {
								mc_blas_matrix_at(b, ldb, n, k, j) = mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							for (i = k + 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (i = m; i >= 1; --i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = 1; k <= (i - 1); ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= m; ++i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = i + 1; k <= m; ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			}
		}
	} else {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = n; j >= 1; --j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = 1; k <= (j - 1); ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = j + 1; k <= n; ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (k = 1; k <= n; ++k) {
					for (j = 1; j <= (k - 1); ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			} else {
				for (k = n; k >= 1; --k) {
					for (j = k + 1; j <= n; ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_ltrmm -

MC_TARGET_FUNC void mc_blas_ltrmm(const char side, const char uplo, const char transa, const char diag, int m, int n, long double alpha, const long double * a, int lda, long double * b, int ldb)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, info, j, k, nrowa, ka;
	int lside, nounit, upper;

	lside = mc_blas_lsame(side, 'L');
	if (lside) {
		ka    = m;
		nrowa = m;
	} else {
		ka    = n;
		nrowa = n;
	}
	nounit = mc_blas_lsame(diag, 'N');
	upper  = mc_blas_lsame(uplo, 'U');

	info = 0;
	if (!lside && !mc_blas_lsame(side, 'R')) {
		info = 1;
	} else if (!upper && !mc_blas_lsame(uplo, 'L')) {
		info = 2;
	} else if (!mc_blas_lsame(transa, 'N') && !mc_blas_lsame(transa, 'T') && !mc_blas_lsame(transa, 'C')) {
		info = 3;
	} else if (!mc_blas_lsame(diag, 'U') && !mc_blas_lsame(diag, 'N')) {
		info = 4;
	} else if (m < 0) {
		info = 5;
	} else if (n < 0) {
		info = 6;
	} else if (lda < mc_maxmag(1, nrowa)) {
		info = 9;
	} else if (ldb < mc_maxmag(1, m)) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("DTRMM ", info);
		return;
	}

	if (m == 0 || n == 0) {
		return;
	}

	if (alpha == zero) {
		for (j = 1; j <= n; ++j) {
			for (i = 1; i <= m; ++i) {
				mc_blas_matrix_at(b, ldb, n, i, j) = zero;
			}
		}
		return;
	}

	if (lside) {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (k = 1; k <= m; ++k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							for (i = 1; i <= (k - 1); ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
							if (nounit) {
								temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (k = m; k >= 1; --k) {
						if (mc_blas_matrix_at(b, ldb, n, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(b, ldb, n, k, j);
							mc_blas_matrix_at(b, ldb, n, k, j) = temp;
							if (nounit) {
								mc_blas_matrix_at(b, ldb, n, k, j) = mc_blas_matrix_at(b, ldb, n, k, j) * mc_blas_matrix_at(a, lda, ka, k, k);
							}
							for (i = k + 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (j = 1; j <= n; ++j) {
					for (i = m; i >= 1; --i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = 1; k <= (i - 1); ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= m; ++i) {
						temp = mc_blas_matrix_at(b, ldb, n, i, j);
						if (nounit) {
							temp = temp * mc_blas_matrix_at(a, lda, ka, i, i);
						}
						for (k = i + 1; k <= m; ++k) {
							temp = temp + (mc_blas_matrix_at(a, lda, ka, k, i) * mc_blas_matrix_at(b, ldb, n, k, j));
						}
						mc_blas_matrix_at(b, ldb, n, i, j) = alpha * temp;
					}
				}
			}
		}
	} else {
		if (mc_blas_lsame(transa, 'N')) {
			if (upper) {
				for (j = n; j >= 1; --j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = 1; k <= (j - 1); ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			} else {
				for (j = 1; j <= n; ++j) {
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, j, j);
					}
					for (i = 1; i <= m; ++i) {
						mc_blas_matrix_at(b, ldb, n, i, j) = temp * mc_blas_matrix_at(b, ldb, n, i, j);
					}
					for (k = j + 1; k <= n; ++k) {
						if (mc_blas_matrix_at(a, lda, ka, k, j) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, k, j);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
				}
			}
		} else {
			if (upper) {
				for (k = 1; k <= n; ++k) {
					for (j = 1; j <= (k - 1); ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			} else {
				for (k = n; k >= 1; --k) {
					for (j = k + 1; j <= n; ++j) {
						if (mc_blas_matrix_at(a, lda, ka, j, k) != zero) {
							temp = alpha * mc_blas_matrix_at(a, lda, ka, j, k);
							for (i = 1; i <= m; ++i) {
								mc_blas_matrix_at(b, ldb, n, i, j) = mc_blas_matrix_at(b, ldb, n, i, j) + (temp * mc_blas_matrix_at(b, ldb, n, i, k));
							}
						}
					}
					temp = alpha;
					if (nounit) {
						temp = temp * mc_blas_matrix_at(a, lda, ka, k, k);
					}
					if (temp != one) {
						for (i = 1; i <= m; ++i) {
							mc_blas_matrix_at(b, ldb, n, i, k) = temp * mc_blas_matrix_at(b, ldb, n, i, k);
						}
					}
				}
			}
		}
	}
}

#endif /* !MC_BLAS_TRMM_H */

/* EOF */
//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_gemm.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_GEMM_H
#define MC_BLAS_GEMM_H

#pragma mark - mc_blas_sgemm -

MC_TARGET_FUNC void mc_blas_sgemm(const char transa, const char transb, int m, int n, int k, float alpha, const float *a, int lda, const float * b, int ldb, float beta, float * c, int ldc)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, j, l, ncola, nrowa, nrowb, kb, ka;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
	}
	if (notb) {
		kb    = n;
		nrowb = k;
	} else {
		kb    = k;
		nrowb = n;
	}

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
	info = 1;
	} else if (! notb && ! mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
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
					MC_BLAS_MAT(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
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
						MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_dgemm -

MC_TARGET_FUNC void mc_blas_dgemm(const char transa, const char transb, int m, int n, int k, double alpha, const double *a, int lda, const double * b, int ldb, double beta, double * c, int ldc)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, j, l, ncola, nrowa, nrowb, kb, ka;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
	}
	if (notb) {
		kb    = n;
		nrowb = k;
	} else {
		kb    = k;
		nrowb = n;
	}

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
	info = 1;
	} else if (! notb && ! mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
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
					MC_BLAS_MAT(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
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
						MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#pragma mark - mc_blas_lgemm -

MC_TARGET_FUNC void mc_blas_lgemm(const char transa, const char transb, int m, int n, int k, long double alpha, const long double *a, int lda, const long double * b, int ldb, long double beta, long double * c, int ldc)
{
	const long double one = 1.0, zero = 0.0;

	long double temp;
	int i, info, j, l, ncola, nrowa, nrowb, kb, ka;
	int nota, notb;

	nota = mc_blas_lsame(transa, 'N');
	notb = mc_blas_lsame(transb, 'N');
	if (nota) {
		ka    = k;
		nrowa = m;
		ncola = k;
	} else {
		ka    = m;
		nrowa = k;
		ncola = m;
	}
	if (notb) {
		kb    = n;
		nrowb = k;
	} else {
		kb    = k;
		nrowb = n;
	}

	info = 0;
	if (!nota && !mc_blas_lsame(transa, 'C') && !mc_blas_lsame(transa, 'T')) {
	info = 1;
	} else if (! notb && ! mc_blas_lsame(transb, 'C') && !mc_blas_lsame(transb, 'T')) {
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
					MC_BLAS_MAT(c, ldc, n, i, j) = zero;
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
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
						MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, l, j);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= m; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, l, j));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	} else {
		if (nota) {
			for (j = 1; j <= n; ++j) {
				if (beta == zero) {
					for (i = 1; i <= m; ++i) {
						 MC_BLAS_MAT(c, ldc, n, i, j) = zero;
					}
				} else if (beta != one) {
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
				for (l = 1; l <= k; ++l) {
					temp = alpha * MC_BLAS_MAT(b, ldb, kb, j, l);
					for (i = 1; i <= m; ++i) {
						MC_BLAS_MAT(c, ldc, n, i, j) = MC_BLAS_MAT(c, ldc, n, i, j) + (temp * MC_BLAS_MAT(a, lda, ka, i, l));
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= m; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (MC_BLAS_MAT(a, lda, ka, l, i) * MC_BLAS_MAT(b, ldb, kb, j, l));
					}
					if (beta == zero) {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp;
					} else {
						MC_BLAS_MAT(c, ldc, n, i, j) = alpha * temp + beta * MC_BLAS_MAT(c, ldc, n, i, j);
					}
				}
			}
		}
	}
}

#endif /* !MC_BLAS_GEMM_H */

/* EOF */
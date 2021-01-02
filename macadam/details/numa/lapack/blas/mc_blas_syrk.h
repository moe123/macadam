// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_syrk.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_SYRK_H
#define MC_BLAS_SYRK_H

#pragma mark - mc_blas_ssyrk -

MC_TARGET_FUNC void mc_blas_ssyrk(const char uplo, const char trans, const int n, const int k, float alpha, const float * a, const int lda, float beta, float * c, const int ldc)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, info, j, l, nrowa, ka;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		nrowa = n;
		mc_unused(ka);
	} else {
		ka    = n;
		nrowa = k;
		mc_unused(ka);
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
	} else if (ldc < mc_maxmag(1, n)) {
		info = 10;
	}
	if (info != 0) {
		mc_blas_xerbla("SSYRK ", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		}
	} else {
		if (upper) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
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

#pragma mark - mc_blas_dsyrk -

MC_TARGET_FUNC void mc_blas_dsyrk(const char uplo, const char trans, const int n, const int k, double alpha, const double * a, const int lda, double beta, double * c, const int ldc)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, info, j, l, nrowa, ka;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		nrowa = n;
		mc_unused(ka);
	} else {
		ka    = n;
		nrowa = k;
		mc_unused(ka);
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
	} else if (ldc < mc_maxmag(1, n)) {
		info = 10;
	}
	if (info != 0) {
		mc_blas_xerbla("DSYRK ", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		}
	} else {
		if (upper) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
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

#pragma mark - mc_blas_lsyrk -

MC_TARGET_FUNC void mc_blas_lsyrk(const char uplo, const char trans, const int n, const int k, long double alpha, const long double * a, const int lda, long double beta, long double * c, const int ldc)
{
	const long double one = 1.0L, zero = 0.0L;

	long double temp;
	int i, info, j, l, nrowa, ka;
	int upper;

	if (mc_blas_lsame(trans, 'N')) {
		ka    = k;
		nrowa = n;
		mc_unused(ka);
	} else {
		ka    = n;
		nrowa = k;
		mc_unused(ka);
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
	} else if (ldc < mc_maxmag(1, n)) {
		info = 10;
	}
	if (info != 0) {
		mc_blas_xerbla("LSYRK ", info);
		return;
	}

	if (n == 0 || ((alpha == zero || k == 0) && beta == one)) {
		return;
	}

	if (alpha == zero) {
		if (upper) {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
			if (beta == zero) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
				for (j = 1; j <= n; ++j) {
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(c, ldc, n, i, j) = zero;
					}
				}
			} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = 1; i <= j; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
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
					if (mc_blas_matrix_at(a, lda, ka, j, l) != zero) {
						temp = alpha * mc_blas_matrix_at(a, lda, ka, j, l);
						for (i = j; i <= n; ++i) {
							mc_blas_matrix_at(c, ldc, n, i, j) = mc_blas_matrix_at(c, ldc, n, i, j) + (temp * mc_blas_matrix_at(a, lda, ka, i, l));
						}
					}
				}
			}
		}
	} else {
		if (upper) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = 1; i <= j; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
					}
					if (beta == zero) {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp;
					} else {
						mc_blas_matrix_at(c, ldc, n, i, j) = alpha * temp + beta * mc_blas_matrix_at(c, ldc, n, i, j);
					}
				}
			}
		} else {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				for (i = j; i <= n; ++i) {
					temp = zero;
					for (l = 1; l <= k; ++l) {
						temp = temp + (mc_blas_matrix_at(a, lda, ka, l, i) * mc_blas_matrix_at(a, lda, ka, l, j));
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

#endif /* !MC_BLAS_SYRK_H */

/* EOF */
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_syr.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_SYR_H
#define MC_BLAS_SYR_H

#pragma mark - mc_blas_ssyr -

MC_TARGET_FUNC void mc_blas_ssyr(const char uplo, const int n, float alpha, const float * x, const int incx, float * a, const int lda)
{
	const float zero = 0.0f;

	float temp;
	int i, info, ix, j, jx, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, n)) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("SSYR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	} else {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	}
}

#pragma mark - mc_blas_dsyr -

MC_TARGET_FUNC void mc_blas_dsyr(const char uplo, const int n, double alpha, const double * x, const int incx, double * a, const int lda)
{
	const double zero = 0.0;

	double temp;
	int i, info, ix, j, jx, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, n)) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("DSYR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	} else {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	}
}

#pragma mark - mc_blas_lsyr -

MC_TARGET_FUNC void mc_blas_lsyr(const char uplo, const int n, long double alpha, const long double * x, const int incx, long double * a, const int lda)
{
	const long double zero = 0.0L;

	long double temp;
	int i, info, ix, j, jx, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (lda < mc_maxmag(1, n)) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("LSYR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	} else {
		if (incx == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, i) * temp);
					}
				}
			}
		} else {
			jx = kx;
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + (mc_blas_vector_at(x, ix) * temp);
						ix                                 = ix + incx;
					}
				}
				jx = jx + incx;
			}
		}
	}
}

#endif /* !MC_BLAS_SYR_H */

/* EOF */
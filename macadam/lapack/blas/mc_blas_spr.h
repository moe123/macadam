//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_spr.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

/* \name
 *    ?spmv performs the symmetric rank 1 operation:
 *    a=alpha*x*x' + a.
 *
 * \synopsis
 *    void ?spmv(uplo, n, alpha, x, incx, ap)
 *    float-floating alpha
 *    int            incx, n
 *    char           uplo
 *    float-floating ap(*), x(*)
 *
 * \purpose
 *    ?spmv performs the symmetric rank 1 operation: a=alpha*x*x' + a where alpha is a real scalar,
 *    `x` is an n element vector and `a` is an n by n symmetric matrix, supplied in packed form.
 *
 *
 * \parameters
 *    [in] uplo  - char. Specifies whether the upper or lower triangular part of the matrix `a` is supplied
 *    in the packed array `ap` as follows:
 *    UPLO='U' or 'u', the upper triangular part of `a` supplied in `ap`.
 *    UPLO='L' or 'l', the lower triangular part of `a` supplied in `ap`.
 *
 *    [in] n     - int. Specifies the order of the symmetric matrix `a`, n must be at least zero.
 *
 *    [in] alpha - float-floating. Specifies the scalar alpha.
 *
 *    [int] x    - real-floating array of size at least (1+(n-1)*abs(incx)). The incremented array `x` must
 *    contain the vector `x`.
 *
 *    [in] incx  - int. Specifies the increment for the elements of `x`, incx must not be zero.
 *
 *    [in] ap    - float-floating array of dimension (at least) ((n*(n+1))/2).
 *    With UPLO='U' or 'u', the array `ap` must contain the upper triangular part of the symmetric matrix
 *    packed sequentially, column by column, so that ap(1) contains a(1,1), ap(2) and ap(3) contain a(1,2)
 *    and a(2,2) respectively, and so on.
 *
 *    With UPLO='L' or 'l', the array ap must contain the lower triangular part of the symmetric matrix
 *    packed sequentially, column by column, so that ap(1) contains a(1,1), ap(2) and ap(3) contain a(2,1)
 *    and a(3,1) respectively, and so on.
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

#include <macadam/lapack/blas/mc_blas_access.h>
#include <macadam/lapack/blas/mc_blas_lsame.h>
#include <macadam/lapack/blas/mc_blas_xerbla.h>

#ifndef MC_BLAS_SPR_H
#define MC_BLAS_SPR_H

#pragma mark - mc_blas_sspr -

MC_TARGET_FUNC void mc_blas_sspr(const char uplo, const int n, const float alpha, const float * x, const int incx, float * ap)
{
	const float zero = 0.0f;

	float temp;
	int i, info, ix, j, jx, k, kk, kx;

#	if MC_TARGET_BLAS_USE_CLAYOUT
	const char uplo_x = mc_blas_lsame(uplo, 'U') ? 'L' : (mc_blas_lsame(uplo, 'L') ? 'U' : 'D');
#	else
	const char uplo_x = uplo;
#	endif

	info = 0;
	if (!mc_blas_lsame(uplo_x, 'U') && !mc_blas_lsame(uplo_x, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("SSPR  ", info);
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

	kk = 1;
	if (mc_blas_lsame(uplo_x, 'U')) {
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
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
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
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
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
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_dspr -

MC_TARGET_FUNC void mc_blas_dspr(const char uplo, const int n, const double alpha, const double * x, const int incx, double * ap)
{
	const double zero = 0.0;

	double temp;
	int i, info, ix, j, jx, k, kk, kx;

#	if MC_TARGET_BLAS_USE_CLAYOUT
	const char uplo_x = mc_blas_lsame(uplo, 'U') ? 'L' : (mc_blas_lsame(uplo, 'L') ? 'U' : 'D');
#	else
	const char uplo_x = uplo;
#	endif

	info = 0;
	if (!mc_blas_lsame(uplo_x, 'U') && !mc_blas_lsame(uplo_x, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("DSPR  ", info);
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

	kk = 1;
	if (mc_blas_lsame(uplo_x, 'U')) {
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
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
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
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
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
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_lspr -

MC_TARGET_FUNC void mc_blas_lspr(const char uplo, const int n, const long double alpha, const long double * x, const int incx, long double * ap)
{
	const long double zero = 0.0L;

	long double temp;
	int i, info, ix, j, jx, k, kk, kx;

#	if MC_TARGET_BLAS_USE_CLAYOUT
	const char uplo_x = mc_blas_lsame(uplo, 'U') ? 'L' : (mc_blas_lsame(uplo, 'L') ? 'U' : 'D');
#	else
	const char uplo_x = uplo;
#	endif

	info = 0;
	if (!mc_blas_lsame(uplo_x, 'U') && !mc_blas_lsame(uplo_x, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("LSPR  ", info);
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

	kk = 1;
	if (mc_blas_lsame(uplo_x, 'U')) {
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
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
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
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
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
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#endif /* !MC_BLAS_SPR_H */

/* EOF */
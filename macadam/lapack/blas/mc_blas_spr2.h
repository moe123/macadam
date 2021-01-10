//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_spr2.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/lapack/blas/mc_blas_access.h>
#include <macadam/lapack/blas/mc_blas_lsame.h>
#include <macadam/lapack/blas/mc_blas_xerbla.h>

#ifndef MC_BLAS_SPR2_H
#define MC_BLAS_SPR2_H

#pragma mark - mc_blas_sspr2 -

MC_TARGET_FUNC void mc_blas_sspr2(const char uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * ap)
{
	const float zero = 0.0f;

	float temp1, temp2;
	int i, info, ix, iy, j, jx, jy, k, kk, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("SSPR2 ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx != 1 || incy != 1) {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (n - 1) * incx;
		}
		if (incy > 0) {
			ky = 1;
		} else {
			ky = 1 - (n - 1) * incy;
		}
		jx = kx;
		jy = ky;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk +  j;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix = kx;
					iy = ky;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk +  j;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_dspr2 -

MC_TARGET_FUNC void mc_blas_dspr2(const char uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * ap)
{
	const double zero = 0.0;

	double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, k, kk, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("DSPR2 ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx != 1 || incy != 1) {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (n - 1) * incx;
		}
		if (incy > 0) {
			ky = 1;
		} else {
			ky = 1 - (n - 1) * incy;
		}
		jx = kx;
		jy = ky;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk +  j;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix = kx;
					iy = ky;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk +  j;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_lspr2 -

MC_TARGET_FUNC void mc_blas_lspr2(const char uplo, const int n, const long double alpha, const long double * x, const int incx, const long double * y, const int incy, long double * ap)
{
	const long double zero = 0.0L;

	long double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, k, kk, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	}
	if (info != 0) {
		mc_blas_xerbla("LSPR2 ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx != 1 || incy != 1) {
		if (incx > 0) {
			kx = 1;
		} else {
			kx = 1 - (n - 1) * incx;
		}
		if (incy > 0) {
			ky = 1;
		} else {
			ky = 1 - (n - 1) * incy;
		}
		jx = kx;
		jy = ky;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk +  j;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix = kx;
					iy = ky;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk +  j;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
#	if MC_TARGET_USE_OPENMP
#		if MC_TARGET_OPENMP_PARALLEL_FOR
#			pragma omp parallel for
#		elif MC_TARGET_OPENMP_FOR_SIMD
#			pragma omp for simd
#		endif
#	endif
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					k     = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
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
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                       = ix + incx;
						iy                       = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
				kk = kk + n - j + 1;
			}
		}
	}
}

#endif /* !MC_BLAS_SPR2_H */

/* EOF */
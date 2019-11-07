// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_syr2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>

#ifndef MC_BLAS_SYR2_H
#define MC_BLAS_SYR2_H

#pragma mark - mc_blas_ssyr2 -

MC_TARGET_FUNC void mc_blas_ssyr2(const char uplo, int n, float alpha, const float * x, int incx, const float * y, int incy, float * a, int lda)
{
	const float zero = 0.0f;

	float temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, n)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("SSYR2 ", info);
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

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = kx;
					iy    = ky;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_dsyr2 -

MC_TARGET_FUNC void mc_blas_dsyr2(const char uplo, int n, double alpha, const double * x, int incx, const double * y, int incy, double * a, int lda)
{
	const double zero = 0.0;

	double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, n)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("DSYR2 ", info);
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

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = kx;
					iy    = ky;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_lsyr2 -

MC_TARGET_FUNC void mc_blas_lsyr2(const char uplo, int n, long double alpha, const long double * x, int incx, const long double * y, int incy, long double * a, int lda)
{
	const long double zero = 0.0L;

	long double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kx, ky;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	} else if (incy == 0) {
		info = 7;
	} else if (lda < mc_maxmag(1, n)) {
		info = 9;
	}
	if (info != 0) {
		mc_blas_xerbla("LSYR2 ", info);
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

	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = kx;
					iy    = ky;
					for (i = 1; i <= j; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero || mc_blas_vector_at(y, j) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, j);
					temp2 = alpha * mc_blas_vector_at(x, j);
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, i) * temp1 + mc_blas_vector_at(y, i) * temp2;
					}
				}
			}
		} else {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero || mc_blas_vector_at(y, jy) != zero) {
					temp1 = alpha * mc_blas_vector_at(y, jy);
					temp2 = alpha * mc_blas_vector_at(x, jx);
					ix    = jx;
					iy    = jy;
					for (i = j; i <= n; ++i) {
						mc_blas_matrix_at(a, lda, n, i, j) = mc_blas_matrix_at(a, lda, n, i, j) + mc_blas_vector_at(x, ix) * temp1 + mc_blas_vector_at(y, iy) * temp2;
						ix                                 = ix + incx;
						iy                                 = iy + incy;
					}
				}
				jx = jx + incx;
				jy = jy + incy;
			}
		}
	}
}

#endif /* !MC_BLAS_SYR2_H */

/* EOF */
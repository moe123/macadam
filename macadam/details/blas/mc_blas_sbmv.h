// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_sbmv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>
#include <macadam/details/math/mc_minmag.h>

#ifndef MC_BLAS_SBMV_H
#define MC_BLAS_SBMV_H

#pragma mark - mc_blas_ssbmv -

MC_TARGET_FUNC void mc_blas_ssbmv(const char uplo, int n, int k, float alpha, const float * a, int lda, const float * x, int incx, float beta, float * y, int incy)
{
	const float one = 1.0f, zero = 0.0f;

	float temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kplus1, kx, ky, l;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (k < 0) {
		info = 3;
	} else if (lda < k + 1) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("SSBMV ", info);
		return;
	}

	if (n == 0 || (alpha == zero && beta == one)) {
		return;
	}

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

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		kplus1 = k + 1;
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, j);
				temp2 = zero;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, jx);
				temp2 = zero;
				ix    = kx;
				iy    = ky;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
					ix                       = ix + incx;
					iy                       = iy + incy;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
				jx                       = jx + incx;
				jy                       = jy + incy;
				if (j > k) {
					kx = kx + incx;
					ky = ky + incy;
				}
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1                   = alpha * mc_blas_vector_at(x, j);
				temp2                   = zero;
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                       = 1 - j;
				for (i = (j + 1); i <= mc_minmag(n, j + k); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (alpha * temp2);
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1                    = alpha * mc_blas_vector_at(x, jx);
				temp2                    = zero;
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                        = 1 - j;
				ix                       = jx;
				iy                       = jy;
				for (i = (j + 1); i <= mc_minmag(n , j + k); ++i) {
					ix = ix + incx;
					iy = iy + incy;
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp2);
				jx                       = jx + incx;
				jy                       = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_dsbmv -

MC_TARGET_FUNC void mc_blas_dsbmv(const char uplo, int n, int k, double alpha, const double * a, int lda, const double * x, int incx, double beta, double * y, int incy)
{
	const double one = 1.0, zero = 0.0;

	double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kplus1, kx, ky, l;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (k < 0) {
		info = 3;
	} else if (lda < k + 1) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("DSBMV ", info);
		return;
	}

	if (n == 0 || (alpha == zero && beta == one)) {
		return;
	}

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

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		kplus1 = k + 1;
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, j);
				temp2 = zero;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, jx);
				temp2 = zero;
				ix    = kx;
				iy    = ky;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
					ix                       = ix + incx;
					iy                       = iy + incy;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
				jx                       = jx + incx;
				jy                       = jy + incy;
				if (j > k) {
					kx = kx + incx;
					ky = ky + incy;
				}
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1                   = alpha * mc_blas_vector_at(x, j);
				temp2                   = zero;
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                       = 1 - j;
				for (i = (j + 1); i <= mc_minmag(n, j + k); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (alpha * temp2);
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1                    = alpha * mc_blas_vector_at(x, jx);
				temp2                    = zero;
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                        = 1 - j;
				ix                       = jx;
				iy                       = jy;
				for (i = (j + 1); i <= mc_minmag(n , j + k); ++i) {
					ix = ix + incx;
					iy = iy + incy;
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp2);
				jx                       = jx + incx;
				jy                       = jy + incy;
			}
		}
	}
}

#pragma mark - mc_blas_lsbmv -

MC_TARGET_FUNC void mc_blas_lsbmv(const char uplo, int n, int k, long double alpha, const long double * a, int lda, const long double * x, int incx, long double beta, long double * y, int incy)
{
	const long double one = 1.0, zero = 0.0;

	long double temp1, temp2;
	int i, info, ix, iy, j, jx, jy, kplus1, kx, ky, l;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (k < 0) {
		info = 3;
	} else if (lda < k + 1) {
		info = 6;
	} else if (incx == 0) {
		info = 8;
	} else if (incy == 0) {
		info = 11;
	}
	if (info != 0) {
		mc_blas_xerbla("LSBMV ", info);
		return;
	}

	if (n == 0 || (alpha == zero && beta == one)) {
		return;
	}

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

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = zero;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, i) = beta * mc_blas_vector_at(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = zero;
					iy                       = iy + incy;
				}
			} else {
				for (i = 1; i <= n; ++i) {
					mc_blas_vector_at(y, iy) = beta * mc_blas_vector_at(y, iy);
					iy                       = iy + incy;
				}
			}
		}
	}

	if (alpha == zero) {
		return;
	}

	if (mc_blas_lsame(uplo, 'U')) {
		kplus1 = k + 1;
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, j);
				temp2 = zero;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1 = alpha * mc_blas_vector_at(x, jx);
				temp2 = zero;
				ix    = kx;
				iy    = ky;
				l     = kplus1 - j;
				for (i = mc_maxmag(1, j - k); i <= (j - 1); ++i) {
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
					ix                       = ix + incx;
					iy                       = iy + incy;
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + temp1 * mc_blas_matrix_at(a, lda, n, kplus1, j) + alpha * temp2;
				jx                       = jx + incx;
				jy                       = jy + incy;
				if (j > k) {
					kx = kx + incx;
					ky = ky + incy;
				}
			}
		}
	} else {
		if (incx == 1 && incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp1                   = alpha * mc_blas_vector_at(x, j);
				temp2                   = zero;
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                       = 1 - j;
				for (i = (j + 1); i <= mc_minmag(n, j + k); ++i) {
					mc_blas_vector_at(y, i) = mc_blas_vector_at(y, i) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                   = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, i));
				}
				mc_blas_vector_at(y, j) = mc_blas_vector_at(y, j) + (alpha * temp2);
			}
		} else {
			jx = kx;
			jy = ky;
			for (j = 1; j <= n; ++j) {
				temp1                    = alpha * mc_blas_vector_at(x, jx);
				temp2                    = zero;
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (temp1 *  mc_blas_matrix_at(a, lda, n, 1, j));
				l                        = 1 - j;
				ix                       = jx;
				iy                       = jy;
				for (i = (j + 1); i <= mc_minmag(n , j + k); ++i) {
					ix = ix + incx;
					iy = iy + incy;
					mc_blas_vector_at(y, iy) = mc_blas_vector_at(y, iy) + (temp1 * mc_blas_matrix_at(a, lda, n, l + i, j));
					temp2                    = temp2 + (mc_blas_matrix_at(a, lda, n, l + i, j) * mc_blas_vector_at(x, ix));
				}
				mc_blas_vector_at(y, jy) = mc_blas_vector_at(y, jy) + (alpha * temp2);
				jx                       = jx + incx;
				jy                       = jy + incy;
			}
		}
	}
}

#endif /* !MC_BLAS_SBMV_H */

/* EOF */
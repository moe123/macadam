//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_gbmv.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/blas/mc_blas_lsame.h>
#include <macadam/details/blas/mc_blas_xerbla.h>
#include <macadam/details/math/mc_maxmag.h>
#include <macadam/details/math/mc_minmag.h>

#ifndef MC_BLAS_GBMV_H
#define MC_BLAS_GBMV_H

#pragma mark - mc_blas_sgbmv -

MC_TARGET_FUNC void mc_blas_sgbmv(const char trans, int m, int n, int kl, int ku, float alpha, const float * a, int lda, const float * x, int incx, float beta, float * y, int incy)
{
	const float one = 1.0f, zero = 0.0f;

	float temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("SGBMV ", info);
		return;
	}
	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = beta * MC_BLAS_VAT(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = zero;
					iy                 = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = beta * MC_BLAS_VAT(y, iy);
					iy                 = iy + incy;
				}
			}
		}
	}
	if (alpha == zero) {
		return;
	}
	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
					iy                 = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, i));
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, ix));
					ix   = ix + incx;
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#pragma mark - mc_blas_dgbmv -

MC_TARGET_FUNC void mc_blas_dgbmv(const char trans, int m, int n, int kl, int ku, double alpha, const double * a, int lda, const double * x, int incx, double beta, double * y, int incy)
{
	const double one = 1.0, zero = 0.0;

	double temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("DGBMV ", info);
		return;
	}
	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = beta * MC_BLAS_VAT(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = zero;
					iy                 = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = beta * MC_BLAS_VAT(y, iy);
					iy                 = iy + incy;
				}
			}
		}
	}
	if (alpha == zero) {
		return;
	}
	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
					iy                 = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, i));
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, ix));
					ix   = ix + incx;
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#pragma mark - mc_blas_lgbmv -

MC_TARGET_FUNC void mc_blas_lgbmv(const char trans, int m, int n, int kl, int ku, long double alpha, const long double * a, int lda, const long double * x, int incx, long double beta, long double * y, int incy)
{
	const long double one = 1.0, zero = 0.0;

	long double temp;
	int i, j, k, ix, iy, jx, jy, kx, ky, kup1, info, lenx, leny;

	info = 0;
	if (!mc_blas_lsame(trans, 'N') && !mc_blas_lsame(trans, 'T') && !mc_blas_lsame(trans, 'C')) {
		info = 1;
	} else if (m < 0) {
		info = 2;
	} else if (n < 0) {
		info = 3;
	} else if (kl < 0) {
		info = 4;
	} else if (ku < 0) {
		info = 5;
	} else if (lda < kl + ku + 1) {
		info = 8;
	} else if (incx == 0) {
		info = 10;
	} else if (incy == 0) {
		info = 13;
	}
	if (info != 0) {
		mc_blas_xerbla("LGBMV ", info);
		return;
	}
	if (m == 0 || n == 0 || (alpha == zero && beta == one)) {
		return;
	}

	if (mc_blas_lsame(trans, 'N')) {
		lenx = n;
		leny = m;
	} else {
		lenx = m;
		leny = n;
	}
	if (incx > 0) {
		kx = 1;
	} else {
		kx = 1 - (lenx - 1) * incx;
	}
	if (incy > 0) {
		ky = 1;
	} else {
		ky = 1 - (leny - 1) * incy;
	}

	if (beta != one) {
		if (incy == 1) {
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = zero;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, i) = beta * MC_BLAS_VAT(y, i);
				}
			}
		} else {
			iy = ky;
			if (beta == zero) {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = zero;
					iy                 = iy + incy;
				}
			} else {
				for (i = 1; i <= leny; ++i) {
					MC_BLAS_VAT(y, iy) = beta * MC_BLAS_VAT(y, iy);
					iy                 = iy + incy;
				}
			}
		}
	}
	if (alpha == zero) {
		return;
	}
	kup1 = ku + 1;
	if (mc_blas_lsame(trans, 'N')) {
		jx = kx;
		if (incy == 1) {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
				}
				jx   = jx + incx;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = alpha * MC_BLAS_VAT(x, jx);
				iy   = ky;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (temp * MC_BLAS_MAT(a, lda, n, k + i, j));
					iy                 = iy + incy;
				}
				jx   = jx + incx;
				if (j > ku) {
					ky = ky + incy;
				}
			}
		}
	} else {
		jy = ky;
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, i));
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
			}
		} else {
			for (j = 1; j <= n; ++j) {
				temp = zero;
				ix   = kx;
				k    = kup1 - j;
				for (i = mc_maxmag(1, j - ku); i <= mc_minmag(m, j + kl); ++i) {
					temp = temp + (MC_BLAS_MAT(a, lda, n, k + i, j) * MC_BLAS_VAT(x, ix));
					ix   = ix + incx;
				}
				MC_BLAS_VAT(y, jy) = MC_BLAS_VAT(y, jy) + (alpha * temp);
				jy                 = jy + incy;
				if (j > ku) {
					kx = kx + incx;
				}
			}
		}
	}
}

#endif /* !MC_BLAS_GBMV_H */

/* EOF */
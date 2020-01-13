// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_swap.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>

#ifndef MC_BLAS_SWAP_H
#define MC_BLAS_SWAP_H

#pragma mark - mc_blas_sswap -

MC_TARGET_FUNC void mc_blas_sswap(int n, float * x, int incx, float * y, int incy)
{
	float temp;
	int i, ix, iy, m, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 3;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp                    = mc_blas_vector_at(x, i);
				mc_blas_vector_at(x, i) = mc_blas_vector_at(y, i);
				mc_blas_vector_at(y, i) = temp;
			}
			if (n < 3) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 3) {
			temp                        = mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i    ) = mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i    ) = temp;
			temp                        = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 1) = mc_blas_vector_at(y, i + 1);
			mc_blas_vector_at(y, i + 1) = temp;
			temp                        = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 2) = mc_blas_vector_at(y, i + 2);
			mc_blas_vector_at(y, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_dswap -

MC_TARGET_FUNC void mc_blas_dswap(int n, double * x, int incx, double * y, int incy)
{
	double temp;
	int i, ix, iy, m, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 3;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp                    = mc_blas_vector_at(x, i);
				mc_blas_vector_at(x, i) = mc_blas_vector_at(y, i);
				mc_blas_vector_at(y, i) = temp;
			}
			if (n < 3) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 3) {
			temp                        = mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i    ) = mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i    ) = temp;
			temp                        = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 1) = mc_blas_vector_at(y, i + 1);
			mc_blas_vector_at(y, i + 1) = temp;
			temp                        = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 2) = mc_blas_vector_at(y, i + 2);
			mc_blas_vector_at(y, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_lswap -

MC_TARGET_FUNC void mc_blas_lswap(int n, long double * x, int incx, long double * y, int incy)
{
	long double temp;
	int i, ix, iy, m, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 3;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				temp                    = mc_blas_vector_at(x, i);
				mc_blas_vector_at(x, i) = mc_blas_vector_at(y, i);
				mc_blas_vector_at(y, i) = temp;
			}
			if (n < 3) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 3) {
			temp                        = mc_blas_vector_at(x, i);
			mc_blas_vector_at(x, i    ) = mc_blas_vector_at(y, i);
			mc_blas_vector_at(y, i    ) = temp;
			temp                        = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 1) = mc_blas_vector_at(y, i + 1);
			mc_blas_vector_at(y, i + 1) = temp;
			temp                        = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 2) = mc_blas_vector_at(y, i + 2);
			mc_blas_vector_at(y, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp                     = mc_blas_vector_at(x, ix);
			mc_blas_vector_at(x, ix) = mc_blas_vector_at(y, iy);
			mc_blas_vector_at(y, iy) = temp;
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#endif /* !MC_BLAS_SWAP_H */

/* EOF */
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_swap_c.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>

#ifndef MC_NONBLAS_SWAP_C_H
#define MC_NONBLAS_SWAP_C_H

#pragma mark - mc_nonblas_sswap_c -

MC_TARGET_FUNC void mc_nonblas_sswap_c(int m, float * x, int ldx, int nx, int indx, int incx, float * y, int ldy, int ny, int indy, int incy)
{
	float temp;
	int i, ix, iy, n, np1;

	if (m <= 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		n = m % 3;
		if (n != 0) {
			for (i = 1; i <= n; ++i) {
				temp                                   = mc_blas_matrix_at(x, ldx, nx, indx, i);
				mc_blas_matrix_at(x, ldx, nx, indx, i) = mc_blas_matrix_at(y, ldy, ny, indy, i);
				mc_blas_matrix_at(y, ldy, ny, indy, i) = temp;
			}
			if (m < 3) {
				return;
			}
		}
		np1 = n + 1;
		for (i = np1; i <= m; i += 3) {
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i    ) = mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i    ) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 1);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 1) = mc_blas_matrix_at(y, ldy, ny, indy, i + 1);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 1) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 2);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 2) = mc_blas_matrix_at(y, ldy, ny, indy, i + 2);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#pragma mark - mc_nonblas_dswap_c -

MC_TARGET_FUNC void mc_nonblas_dswap_c(int m, double * x, int ldx, int nx, int indx, int incx, double * y, int ldy, int ny, int indy, int incy)
{
	double temp;
	int i, ix, iy, n, np1;

	if (m <= 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		n = m % 3;
		if (n != 0) {
			for (i = 1; i <= n; ++i) {
				temp                                   = mc_blas_matrix_at(x, ldx, nx, indx, i);
				mc_blas_matrix_at(x, ldx, nx, indx, i) = mc_blas_matrix_at(y, ldy, ny, indy, i);
				mc_blas_matrix_at(y, ldy, ny, indy, i) = temp;
			}
			if (m < 3) {
				return;
			}
		}
		np1 = n + 1;
		for (i = np1; i <= m; i += 3) {
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i    ) = mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i    ) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 1);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 1) = mc_blas_matrix_at(y, ldy, ny, indy, i + 1);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 1) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 2);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 2) = mc_blas_matrix_at(y, ldy, ny, indy, i + 2);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#pragma mark - mc_nonblas_lswap_c -

MC_TARGET_FUNC void mc_nonblas_lswap_c(int m, long double * x, int ldx, int nx, int indx, int incx, long double * y, int ldy, int ny, int indy, int incy)
{
	long double temp;
	int i, ix, iy, n, np1;

	if (m <= 0) {
		mc_cast(void, ldx);
		mc_cast(void, ldy);
		mc_cast(void, nx);
		mc_cast(void, ny);
		return;
	}
	if (incx == 1 && incy == 1) {
		n = m % 3;
		if (n != 0) {
			for (i = 1; i <= n; ++i) {
				temp                                   = mc_blas_matrix_at(x, ldx, nx, indx, i);
				mc_blas_matrix_at(x, ldx, nx, indx, i) = mc_blas_matrix_at(y, ldy, ny, indy, i);
				mc_blas_matrix_at(y, ldy, ny, indy, i) = temp;
			}
			if (m < 3) {
				return;
			}
		}
		np1 = n + 1;
		for (i = np1; i <= m; i += 3) {
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i);
			mc_blas_matrix_at(x, ldx, nx, indx, i    ) = mc_blas_matrix_at(y, ldy, ny, indy, i);
			mc_blas_matrix_at(y, ldy, ny, indy, i    ) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 1);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 1) = mc_blas_matrix_at(y, ldy, ny, indy, i + 1);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 1) = temp;
			temp                                       = mc_blas_matrix_at(x, ldx, nx, indx, i + 2);
			mc_blas_matrix_at(x, ldx, nx, indx, i + 2) = mc_blas_matrix_at(y, ldy, ny, indy, i + 2);
			mc_blas_matrix_at(y, ldy, ny, indy, i + 2) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(m) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(m) + 1) * incy + 1;
		}
		for (i = 1; i <= m; ++i) {
			temp                                    = mc_blas_matrix_at(x, ldx, nx, indx, ix);
			mc_blas_matrix_at(x, ldx, nx, indx, ix) = mc_blas_matrix_at(y, ldy, ny, indy, iy);
			mc_blas_matrix_at(y, ldy, ny, indy, iy) = temp;
			ix                                      = ix + incx;
			iy                                      = iy + incy;
		}
	}
}

#endif /* !MC_NONBLAS_SWAP_C_H */

/* EOF */
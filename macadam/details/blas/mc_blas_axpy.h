//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_axpy.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>

#ifndef MC_BLAS_AXPY_H
#define MC_BLAS_AXPY_H

#pragma mark - mc_blas_saxpy -

MC_TARGET_FUNC void mc_blas_saxpy(int n, float a, const float * x, int incx, float * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (a == 0.0f) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 4;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (a * MC_BLAS_VAT(x, i));
			}
		}
		if (n < 4) {
			return;
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 4) {
			MC_BLAS_VAT(y, i    ) = MC_BLAS_VAT(y, i    ) + (a * MC_BLAS_VAT(x, i    ));
			MC_BLAS_VAT(y, i + 1) = MC_BLAS_VAT(y, i + 1) + (a * MC_BLAS_VAT(x, i + 1));
			MC_BLAS_VAT(y, i + 2) = MC_BLAS_VAT(y, i + 2) + (a * MC_BLAS_VAT(x, i + 2));
			MC_BLAS_VAT(y, i + 3) = MC_BLAS_VAT(y, i + 3) + (a * MC_BLAS_VAT(x, i + 3));
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
			MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (a * MC_BLAS_VAT(x, ix));
			ix                 = ix + incx;
			iy                 = iy + incy;
		}
	}
}

#pragma mark - mc_daxpy -

MC_TARGET_FUNC void mc_blas_daxpy(int n, double a, const double * x, int incx, double * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (a == 0.0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 4;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (a * MC_BLAS_VAT(x, i));
			}
		}
		if (n < 4) {
			return;
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 4) {
			MC_BLAS_VAT(y, i    ) = MC_BLAS_VAT(y, i    ) + (a * MC_BLAS_VAT(x, i    ));
			MC_BLAS_VAT(y, i + 1) = MC_BLAS_VAT(y, i + 1) + (a * MC_BLAS_VAT(x, i + 1));
			MC_BLAS_VAT(y, i + 2) = MC_BLAS_VAT(y, i + 2) + (a * MC_BLAS_VAT(x, i + 2));
			MC_BLAS_VAT(y, i + 3) = MC_BLAS_VAT(y, i + 3) + (a * MC_BLAS_VAT(x, i + 3));
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
			MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (a * MC_BLAS_VAT(x, ix));
			ix                 = ix + incx;
			iy                 = iy + incy;
		}
	}
}

#pragma mark - mc_blas_laxpy -

MC_TARGET_FUNC void mc_blas_laxpy(int n, long double a, const long double * x, int incx, long double * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (a == 0.0L) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 4;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				MC_BLAS_VAT(y, i) = MC_BLAS_VAT(y, i) + (a * MC_BLAS_VAT(x, i));
			}
		}
		if (n < 4) {
			return;
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 4) {
			MC_BLAS_VAT(y, i    ) = MC_BLAS_VAT(y, i    ) + (a * MC_BLAS_VAT(x, i   ));
			MC_BLAS_VAT(y, i + 1) = MC_BLAS_VAT(y, i + 1) + (a * MC_BLAS_VAT(x, i + 1));
			MC_BLAS_VAT(y, i + 2) = MC_BLAS_VAT(y, i + 2) + (a * MC_BLAS_VAT(x, i + 2));
			MC_BLAS_VAT(y, i + 3) = MC_BLAS_VAT(y, i + 3) + (a * MC_BLAS_VAT(x, i + 3));
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
			MC_BLAS_VAT(y, iy) = MC_BLAS_VAT(y, iy) + (a * MC_BLAS_VAT(x, ix));
			ix                 = ix + incx;
			iy                 = iy + incy;
		}
	}
}

#endif /* !MC_BLAS_AXPY_H */

/* EOF */
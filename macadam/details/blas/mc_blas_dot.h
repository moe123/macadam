//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_dot.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>

#ifndef MC_BLAS_DOT_H
#define MC_BLAS_DOT_H

#pragma mark - mc_blas_sdot -

MC_TARGET_FUNC float mc_blas_sdot(int n, const float * x, int incx, const float * y , int incy)
{
	int i, m, ix, iy, mp1;
	float stemp;

	stemp = 0.0f;
	if (n <= 0) {
		return stemp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				stemp = stemp + (MC_BLAS_VAT(x, i) * MC_BLAS_VAT(y, i));
			}
			if (n < 5) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			stemp = stemp + (
				  (MC_BLAS_VAT(x, i    ) * MC_BLAS_VAT(y, i    ))
				+ (MC_BLAS_VAT(x, i + 1) * MC_BLAS_VAT(y, i + 1))
				+ (MC_BLAS_VAT(x, i + 2) * MC_BLAS_VAT(y, i + 2))
				+ (MC_BLAS_VAT(x, i + 3) * MC_BLAS_VAT(y, i + 3))
				+ (MC_BLAS_VAT(x, i + 4) * MC_BLAS_VAT(y, i + 4))
			);
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
			stemp = stemp + (MC_BLAS_VAT(x, ix) * MC_BLAS_VAT(y, iy));
			ix    = ix + incx;
			iy    = iy + incy;
		}
	}
	return stemp;
}

#pragma mark - mc_blas_dsdot -

MC_TARGET_FUNC double mc_blas_dsdot(int n, const float * x, int incx, const float * y , int incy)
{
	int i, m, ix, iy, mp1;
	double stemp;

	stemp = 0.0;
	if (n <= 0) {
		return stemp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				stemp = stemp + (mc_cast(double, MC_BLAS_VAT(x, i)) * mc_cast(double, MC_BLAS_VAT(y, i)));
			}
			if (n < 5) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			stemp = stemp + (
				  (mc_cast(double, MC_BLAS_VAT(x, i    )) * mc_cast(double, MC_BLAS_VAT(y, i    )))
				+ (mc_cast(double, MC_BLAS_VAT(x, i + 1)) * mc_cast(double, MC_BLAS_VAT(y, i + 1)))
				+ (mc_cast(double, MC_BLAS_VAT(x, i + 2)) * mc_cast(double, MC_BLAS_VAT(y, i + 2)))
				+ (mc_cast(double, MC_BLAS_VAT(x, i + 3)) * mc_cast(double, MC_BLAS_VAT(y, i + 3)))
				+ (mc_cast(double, MC_BLAS_VAT(x, i + 4)) * mc_cast(double, MC_BLAS_VAT(y, i + 4)))
			);
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
			stemp = stemp + (mc_cast(double, MC_BLAS_VAT(x, ix)) * mc_cast(double, MC_BLAS_VAT(y, iy)));
			ix    = ix + incx;
			iy    = iy + incy;
		}
	}
	return stemp;
}

#pragma mark - mc_blas_ddot -

MC_TARGET_FUNC double mc_blas_ddot(int n, const double * x, int incx, const double * y , int incy)
{
	int i, m, ix, iy, mp1;
	double stemp;

	stemp = 0.0;
	if (n <= 0) {
		return stemp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				stemp = stemp + (MC_BLAS_VAT(x, i) * MC_BLAS_VAT(y, i));
			}
			if (n < 5) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			stemp = stemp + (
				  (MC_BLAS_VAT(x, i    ) * MC_BLAS_VAT(y, i    ))
				+ (MC_BLAS_VAT(x, i + 1) * MC_BLAS_VAT(y, i + 1))
				+ (MC_BLAS_VAT(x, i + 2) * MC_BLAS_VAT(y, i + 2))
				+ (MC_BLAS_VAT(x, i + 3) * MC_BLAS_VAT(y, i + 3))
				+ (MC_BLAS_VAT(x, i + 4) * MC_BLAS_VAT(y, i + 4))
			);
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
			stemp = stemp + (MC_BLAS_VAT(x, ix) * MC_BLAS_VAT(y, iy));
			ix    = ix + incx;
			iy    = iy + incy;
		}
	}
	return stemp;
}

#pragma mark - mc_blas_ldot -

MC_TARGET_FUNC long double mc_blas_ldot(int n, const long double * x, int incx, const long double * y , int incy)
{
	int i, m, ix, iy, mp1;
	long double stemp;

	stemp = 0.0L;
	if (n <= 0) {
		return stemp;
	}
	if (incx == 1 && incy == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				stemp = stemp + (MC_BLAS_VAT(x, i) * MC_BLAS_VAT(y, i));
			}
			if (n < 5) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			stemp = stemp + (
				  (MC_BLAS_VAT(x, i    ) * MC_BLAS_VAT(y, i    ))
				+ (MC_BLAS_VAT(x, i + 1) * MC_BLAS_VAT(y, i + 1))
				+ (MC_BLAS_VAT(x, i + 2) * MC_BLAS_VAT(y, i + 2))
				+ (MC_BLAS_VAT(x, i + 3) * MC_BLAS_VAT(y, i + 3))
				+ (MC_BLAS_VAT(x, i + 4) * MC_BLAS_VAT(y, i + 4))
			);
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
			stemp = stemp + (MC_BLAS_VAT(x, ix) * MC_BLAS_VAT(y, iy));
			ix    = ix + incx;
			iy    = iy + incy;
		}
	}
	return stemp;
}

#endif /* !MC_BLAS_DOT_H */

/* EOF */
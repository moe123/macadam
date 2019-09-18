//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_asum.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>
#include <macadam/details/math/mc_fabs.h>

#ifndef MC_BLAS_ASUM_H
#define MC_BLAS_ASUM_H

#pragma mark - mc_blas_sasum -

MC_TARGET_FUNC float mc_blas_sasum(int n, const float * x, int incx)
{
	int i, m, mp1, nincx;
	float stemp;

	stemp = 0.0f;
	if (n <= 0 || incx <= 0) {
		return stemp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				stemp = stemp + mc_fabsf(MC_BLAS_VAT(x, i));
			}
			if (n < 6) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			stemp = stemp + (
				  mc_fabsf(MC_BLAS_VAT(x, i    ))
				+ mc_fabsf(MC_BLAS_VAT(x, i + 1))
				+ mc_fabsf(MC_BLAS_VAT(x, i + 2))
				+ mc_fabsf(MC_BLAS_VAT(x, i + 3))
				+ mc_fabsf(MC_BLAS_VAT(x, i + 4))
				+ mc_fabsf(MC_BLAS_VAT(x, i + 5))
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			stemp = stemp + mc_fabsf(MC_BLAS_VAT(x, i));
		}
	}
	return stemp;
}

#pragma mark - mc_blas_dsasum -

MC_TARGET_FUNC double mc_blas_dsasum(int n, const float * x, int incx)
{
	int i, m, mp1, nincx;
	double stemp;

	stemp = 0.0f;
	if (n <= 0 || incx <= 0) {
		return stemp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				stemp = stemp + mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i)));
			}
			if (n < 6) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			stemp = stemp + (
				  mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i    )))
				+ mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i + 1)))
				+ mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i + 2)))
				+ mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i + 3)))
				+ mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i + 4)))
				+ mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i + 5)))
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			stemp = stemp + mc_fabs(mc_cast(double, MC_BLAS_VAT(x, i)));
		}
	}
	return stemp;
}

#pragma mark - mc_blas_dasum -

MC_TARGET_FUNC double mc_blas_dasum(int n, const double * x, int incx)
{
	int i, m, mp1, nincx;
	double stemp;

	stemp = 0.0;
	if (n <= 0 || incx <= 0) {
		return stemp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				stemp = stemp + mc_fabs(MC_BLAS_VAT(x, i));
			}
			if (n < 6) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			stemp = stemp + (
				  mc_fabs(MC_BLAS_VAT(x, i    ))
				+ mc_fabs(MC_BLAS_VAT(x, i + 1))
				+ mc_fabs(MC_BLAS_VAT(x, i + 2))
				+ mc_fabs(MC_BLAS_VAT(x, i + 3))
				+ mc_fabs(MC_BLAS_VAT(x, i + 4))
				+ mc_fabs(MC_BLAS_VAT(x, i + 5))
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			stemp = stemp + mc_fabs(MC_BLAS_VAT(x, i));
		}
	}
	return stemp;
}

#pragma mark - mc_blas_lasum -

MC_TARGET_FUNC long double mc_blas_lasum(int n, const long double * x, int incx)
{
	int i, m, mp1, nincx;
	long double stemp;

	stemp = 0.0L;
	if (n <= 0 || incx <= 0) {
		return stemp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				stemp = stemp + mc_fabsl(MC_BLAS_VAT(x, i));
			}
			if (n < 6) {
				return stemp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			stemp = stemp + (
				  mc_fabsl(MC_BLAS_VAT(x, i    ))
				+ mc_fabsl(MC_BLAS_VAT(x, i + 1))
				+ mc_fabsl(MC_BLAS_VAT(x, i + 2))
				+ mc_fabsl(MC_BLAS_VAT(x, i + 3))
				+ mc_fabsl(MC_BLAS_VAT(x, i + 4))
				+ mc_fabsl(MC_BLAS_VAT(x, i + 5))
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			stemp = stemp + mc_fabsl(MC_BLAS_VAT(x, i));
		}
	}
	return stemp;
}

#endif /* !MC_BLAS_ASUM_H */

/* EOF */
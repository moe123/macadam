//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_asum.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_ASUM_H
#define MC_ASUM_H

MC_TARGET_FUNC float mc_sasum(int n, const float * x, int incx)
{
	int i, m, mp1, nincx;
	float temp;

	temp = 0.0f;
	if (n <= 0 || incx <= 0) {
		return temp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				temp = temp + mc_fabsf(x[(i - 1)]);
			}
			if (n < 6) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			temp = temp + (
				  mc_fabsf(x[(i - 1)])
				+ mc_fabsf(x[(i - 1) + 1])
				+ mc_fabsf(x[(i - 1) + 2])
				+ mc_fabsf(x[(i - 1) + 3])
				+ mc_fabsf(x[(i - 1) + 4])
				+ mc_fabsf(x[(i - 1) + 5])
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			temp = temp + mc_fabsf(x[(i - 1)]);
		}
	}
	return temp;
}

#pragma mark - mc_dasum -

MC_TARGET_FUNC double mc_dasum(int n, const double * x, int incx)
{
	int i, m, mp1, nincx;
	double temp;

	temp = 0.0;
	if (n <= 0 || incx <= 0) {
		return temp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				temp = temp + mc_fabs(x[(i - 1)]);
			}
			if (n < 6) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			temp = temp + (
				  mc_fabs(x[(i - 1)])
				+ mc_fabs(x[(i - 1) + 1])
				+ mc_fabs(x[(i - 1) + 2])
				+ mc_fabs(x[(i - 1) + 3])
				+ mc_fabs(x[(i - 1) + 4])
				+ mc_fabs(x[(i - 1) + 5])
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			temp = temp + mc_fabs(x[(i - 1)]);
		}
	}
	return temp;
}

#pragma mark - mc_lasum -

MC_TARGET_FUNC long double mc_lasum(int n, const long double * x, int incx)
{
	int i, m, mp1, nincx;
	long double temp;

	temp = 0.0L;
	if (n <= 0 || incx <= 0) {
		return temp;
	}
	if (incx == 1) {
		m = n % 6;
		if (m != 0) {
			nincx = m;
			for (i = 1; i <= nincx; ++i) {
				temp = temp + mc_fabsl(x[(i - 1)]);
			}
			if (n < 6) {
				return temp;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 6) {
			temp = temp + (
				  mc_fabsl(x[(i - 1)])
				+ mc_fabsl(x[(i - 1) + 1])
				+ mc_fabsl(x[(i - 1) + 2])
				+ mc_fabsl(x[(i - 1) + 3])
				+ mc_fabsl(x[(i - 1) + 4])
				+ mc_fabsl(x[(i - 1) + 5])
			);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			temp = temp + mc_fabsl(x[(i - 1)]);
		}
	}
	return temp;
}

#endif /* !MC_ASUM_H */

/* EOF */
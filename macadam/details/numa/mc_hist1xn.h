//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hist1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_HIST1XN_H
#define MC_HIST1XN_H

#pragma mark - mc_hist1xn -

MC_TARGET_FUNC int mc_hist1xnf(int n, const float * x, int abs, float min, float max, int npts, int nbins, int * h)
{
//!# Requires x[n] and h[npts] where 1 < n.
	int i = 0;
	float w, scale;

	if (n > 1 && nbins > 1 && npts > 1) {
		mc_os_memzero(h, npts);
		if (min > max) {
			mcswap_var(w, min, max);
		}
		scale = mc_cast_expr(float, (abs == 1 ? mc_fabsf(max - min) : (max - min)) / (nbins - 1));
		scale = (scale != 0.0f) ? (1.0f / scale) : 1.0f;
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (abs == 1 ? mc_fabsf(x[i] - min) : (x[i] - min)) * scale);
			const int k = j % npts;
			h[k]++;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_hist1xn(int n, const double * x, int abs, double min, double max, int npts, int nbins, int * h)
{
//!# Requires x[n] and h[npts] where 1 < n.
	int i = 0;
	double w, scale;

	if (n > 1 && nbins > 1 && npts > 1) {
		mc_os_memzero(h, npts);
		if (min > max) {
			mcswap_var(w, min, max);
		}
		scale = mc_cast_expr(double, (abs == 1 ? mc_fabs(max - min) : (max - min)) / (nbins - 1));
		scale = (scale != 0.0) ? (1.0 / scale) : 1.0;
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (abs == 1 ? mc_fabs(x[i] - min) : (x[i] - min)) * scale);
			const int k = j % npts;
			h[k]++;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_hist1xnl(int n, const long double * x, int abs, long double min, long double max, int npts, int nbins, int * h)
{
//!# Requires x[n] and h[npts] where 1 < n.
	int i = 0;
	long double w, scale;

	if (n > 1 && nbins > 1 && npts > 1) {
		mc_os_memzero(h, npts);
		if (min > max) {
			mcswap_var(w, min, max);
		}
		scale = mc_cast_expr(long double, (abs == 1 ? mc_fabsl(max - min) : (max - min)) / (nbins - 1));
		scale = (scale != 0.0L) ? (1.0L / scale) : 1.0L;
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (abs == 1 ? mc_fabsl(x[i] - min) : (x[i] - min)) * scale);
			const int k = j % npts;
			h[k]++;
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_HIST1XN_H */

/* EOF */
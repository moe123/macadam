//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_histcg1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/details/mc_mem.h>

#ifndef MC_HISTCG1XN_H
#define MC_HISTCG1XN_H

#pragma mark - mc_histcg1xn -

MC_TARGET_FUNC int mc_histcg1xnf(int n, const float * x, float min, float max, int m, int * h)
{
//!# Requires x[n] and h[m] where 1 < n && 0 < m.
//!#     n     - Number of samples in x.
//!#     x     - The sample vector x.
//!#     m     - Number of bins.
//!#     h     - The histogram result.

	int i = 0;

	if (n > 1 && m > 0) {
		const float c = mc_cast_expr(float, (max - min) / m);
		mc_base_memzero(h, m);
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (x[i] - min) / c);
			if (j >= 0 && j < m) {
				h[j]++;
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_histcg1xn(int n, const double * x, double min, double max, int m, int * h)
{
//!# Requires x[n] and h[m] where 1 < n && 0 < m.
//!#     n     - Number of samples in x.
//!#     x     - The sample vector x.
//!#     m     - Number of bins.
//!#     h     - The histogram result.

	int i = 0;

	if (n > 1 && m > 0) {
		const double c = mc_cast_expr(double, (max - min) / m);
		mc_base_memzero(h, m);
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (x[i] - min) / c);
			if (j >= 0 && j < m) {
				h[j]++;
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC  int mc_histcg1xnl(int n, const long double * x, long double min, long double max, int m, int * h)
{
//!# Requires x[n] and h[m] where 1 < n && 0 < m.
//!#     n     - Number of samples in x.
//!#     x     - The sample vector x.
//!#     m     - Number of bins.
//!#     h     - The histogram result.

	int i = 0;

	if (n > 1 && m > 0) {
		const long double c = mc_cast_expr(long double, (max - min) / m);
		mc_base_memzero(h, m);
		for (; i < n; i++) {
			const int j = mc_cast_expr(int, (x[i] - min) / c);
			if (j >= 0 && j < m) {
				h[j]++;
			}
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_HISTCG1XN_H */

/* EOF */
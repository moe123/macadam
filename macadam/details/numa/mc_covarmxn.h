//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_covarmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_meanmx1.h>

#ifndef MC_COVARMXN_H
#define MC_COVARMXN_H

#pragma mark - mc_covarmxn -

MC_TARGET_FUNC int mc_covarmxnf(int m, int n, float * restrict c, const float * a, int b)
{
//!# Requires c[n x n] and a[m x n] where 1 < n <= m.
	int i, j = 0, k;
	float mj, mk;
	if (1 < n && n <= m) {
		for (; j < n; j++) {
			mj = mc_meanmx1f(m, n, j, a, b, 5);
			for (k = 0; k < n; k++) {
				mk             = mc_meanmx1f(m, n, j, a, b, 5);
				c[(n * j) + k] = 0.0f;
				for (i = 0; i < m; i++) {
					c[(n * j) + k] = c[(n * j) + k] + ((a[(n * i) + j] - mj) * (a[(n * i) + k] - mk));
				}
				c[(n * j) + k] = c[(n * j) + k] / mc_cast_expr(float, m - 1);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_covarmxnff(int m, int n, double * c, const float * a, int b)
{
//!# Requires c[n x n] and a[m x n] where 1 < n <= m.
	int i, j = 0, k;
	double mj, mk;
	if (1 < n && n <= m) {
		for (; j < n; j++) {
			mj = mc_cast(double, mc_meanmx1f(m, n, j, a, b, 5));
			for (k = 0; k < n; k++) {
				mk             = mc_cast(double, mc_meanmx1f(m, n, j, a, b, 5));
				c[(n * j) + k] = 0.0;
				for (i = 0; i < m; i++) {
					c[(n * j) + k] = c[(n * j) + k] + ((mc_cast(double, a[(n * i) + j]) - mj) * (mc_cast(double, a[(n * i) + k]) - mk));
				}
				c[(n * j) + k] = c[(n * j) + k] / mc_cast_expr(double, m - 1);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_covarmxn(int m, int n, double * restrict c, const double * a, int b)
{
//!# Requires c[n x n] and a[m x n] where 1 < n <= m.
	int i, j = 0, k;
	double mj, mk;
	if (1 < n && n <= m) {
		for (; j < n; j++) {
			mj = mc_meanmx1(m, n, j, a, b, 5);
			for (k = 0; k < n; k++) {
				mk             = mc_meanmx1(m, n, j, a, b, 5);
				c[(n * j) + k] = 0.0;
				for (i = 0; i < m; i++) {
					c[(n * j) + k] = c[(n * j) + k] + ((a[(n * i) + j] - mj) * (a[(n * i) + k] - mk));
				}
				c[(n * j) + k] = c[(n * j) + k] / mc_cast_expr(double, m - 1);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_covarmxnl(int m, int n, long double * restrict c, const long double * a, int b)
{
//!# Requires c[n x n] and a[m x n] where 1 < n <= m.
	int i, j = 0, k;
	long double mj, mk;
	if (1 < n && n <= m) {
		for (; j < n; j++) {
			mj = mc_meanmx1l(m, n, j, a, b, 5);
			for (k = 0; k < n; k++) {
				mk             = mc_meanmx1l(m, n, j, a, b, 5);
				c[(n * j) + k] = 0.0L;
				for (i = 0; i < m; i++) {
					c[(n * j) + k] = c[(n * j) + k] + ((a[(n * i) + j] - mj) * (a[(n * i) + k] - mk));
				}
				c[(n * j) + k] = c[(n * j) + k] / mc_cast_expr(long double, m - 1);
			}
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_COVARMXN_H */

/* EOF */
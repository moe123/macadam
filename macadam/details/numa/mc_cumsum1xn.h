//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cumsum1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_twosum.h>

#ifndef MC_CUMSUM1XN_H
#define MC_CUMSUM1XN_H

#pragma mark - mc_cumsum1xn -

MC_TARGET_FUNC int mc_cumsum1xnf(int n, float * u, const float * x)
{
	int i = 1;
	float a, b;
	if (n > 0) {
		u[0] = x[0];
		for (; i < n; i++) {
			mc_twosumf(u[i - 1], x[i], &a, &b);
			u[i] = a + b;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_cumsum1xnff(int n, double * u, const float * x)
{
	int i = 1;
	double a, b;
	if (n > 0) {
		u[0] = x[0];
		for (; i < n; i++) {
			mc_twosum(u[i - 1], mc_cast(double, x[i]), &a, &b);
			u[i] = a + b;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_cumsum1xn(int n, double * u, const double * x)
{
	int i = 1;
	double a, b;
	if (n > 0) {
		u[0] = x[0];
		for (; i < n; i++) {
			mc_twosum(u[i - 1], x[i], &a, &b);
			u[i] = a + b;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_cumsum1xnl(int n, long double * u, const long double * x)
{
	int i = 1;
	long double a, b;
	if (n > 0) {
		u[0] = x[0];
		for (; i < n; i++) {
			mc_twosuml(u[i - 1], x[i], &a, &b);
			u[i] = a + b;
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_CUMSUM1XN_H */

/* EOF */
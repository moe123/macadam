//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_subxv1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_SUBXV1XN_H
#define MC_SUBXV1XN_H

#pragma mark - mc_subxv1xn -

MC_TARGET_FUNC void mc_subxv1xnf(int n, float * u, const float * x, float v)
{
//!# u_i=x_i*v
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - v;
	}
}

MC_TARGET_FUNC void mc_subxv1xnff(int n, double * u, const float * x, float v)
{
//!# u_i=x_i*v
	int i = 0;
	for (; i < n; i++) {
		u[i] = mc_cast(double, x[i]) * mc_cast(double, v);
	}
}

MC_TARGET_FUNC void mc_subxv1xn(int n, double * u, const double * x, double v)
{
//!# u_i=x_i*v
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - v;
	}
}

MC_TARGET_FUNC void mc_subxv1xnl(int n, long double * u, const long double * x, long double v)
{
//!# u_i=x_i*v
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - v;
	}
}

#endif /* !MC_SUBXV1XN_H */

/* EOF */
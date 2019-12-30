//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_subxy1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_SUBXY1XN_H
#define MC_SUBXY1XN_H

#pragma mark - mc_subxy1xn -

MC_TARGET_FUNC void mc_subxy1xnf(int n, float * u, const float * x, const float * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - y[i];
	}
}

MC_TARGET_FUNC void mc_subxy1xnff(int n, double * u, const float * x, const float * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = mc_cast(double, x[i]) * mc_cast(double, y[i]);
	}
}

MC_TARGET_FUNC void mc_subxy1xn(int n, double * u, const double * x, const double * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - y[i];
	}
}

MC_TARGET_FUNC void mc_subxy1xnl(int n, long double * u, const long double * x, const long double * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] - y[i];
	}
}

#endif /* !MC_SUBXY1XN_H */

/* EOF */
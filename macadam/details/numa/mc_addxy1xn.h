//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_addxy1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ADDXY1XN_H
#define MC_ADDXY1XN_H

#pragma mark - mc_addxy1xn -

MC_TARGET_FUNC void mc_addxy1xnf(int n, float * u, const float * x, const float * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] + y[i];
	}
}

MC_TARGET_FUNC void mc_addxy1xnff(int n, double * u, const float * x, const float * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = mc_cast(double, x[i]) * mc_cast(double, y[i]);
	}
}

MC_TARGET_FUNC void mc_addxy1xn(int n, double * u, const double * x, const double * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] + y[i];
	}
}

MC_TARGET_FUNC void mc_addxy1xnl(int n, long double * u, const long double * x, const long double * y)
{
//!# u_i=x_i*y_i
	int i = 0;
	for (; i < n; i++) {
		u[i] = x[i] + y[i];
	}
}

#endif /* !MC_ADDXY1XN_H */

/* EOF */
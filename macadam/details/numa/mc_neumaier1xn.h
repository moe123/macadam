//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_neumaier1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_SUM_NEUMAIER1XN_H
#define MC_SUM_NEUMAIER1XN_H

#pragma mark - mc_neumaier1xn -

MC_TARGET_FUNC float mc_neumaier1xnf(int n, const float * x)
{
	int i   = 0;
	float s = 0.0f, c = 0.0f, u, w;
	for (; i < n; i++) {
		w = x[i];
		u = s + w;
		c = c + (mc_fabsf(s) >= mc_fabsf(w) ? (s - u) + w :  (w - u) + s);
		s = u;
	}
	return s + c;
}

MC_TARGET_FUNC double mc_neumaier1xnff(int n, const float * x)
{
	int i    = 0;
	double s = 0.0, c = 0.0, u, w;
	for (; i < n; i++) {
		w = mc_cast(double, x[i]);
		u = s + w;
		c = c + (mc_fabs(s) >= mc_fabs(w) ? (s - u) + w :  (w - u) + s);
		s = u;
	}
	return s + c;
}

MC_TARGET_FUNC double mc_neumaier1xn(int n, const double * x)
{
	int i    = 0;
	double s = 0.0, c = 0.0, u, w;
	for (; i < n; i++) {
		w = x[i];
		u = s + w;
		c = c + (mc_fabs(s) >= mc_fabs(w) ? (s - u) + w :  (w - u) + s);
		s = u;
	}
	return s + c;
}

MC_TARGET_FUNC long double mc_neumaier1xnl(int n, const long double * x)
{
	int i         = 0;
	long double s = 0.0L, c = 0.0L, u, w;
	for (; i < n; i++) {
		w = x[i];
		u = s + w;
		c = c + (mc_fabsl(s) >= mc_fabsl(w) ? (s - u) + w :  (w - u) + s);
		s = u;
	}
	return s + c;
}

#endif /* !MC_SUM_NEUMAIER1XN_H */

/* EOF */
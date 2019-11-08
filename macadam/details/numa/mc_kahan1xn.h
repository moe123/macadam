//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_kahan1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_SUM_KAHAN1XN_H
#define MC_SUM_KAHAN1XN_H

#pragma mark - mc_kahan1xn -

MC_TARGET_FUNC float mc_kahan1xnf(int n, const float * x)
{
	int i   = 0;
	float s = 0.0f, c = 0.0f;
	for (; i < n; i++) {
		const float u = x[i] - c;
		const float w = s + u;
		c             = (w - s) - u;
		s             = w;
	}
	return s;
}

MC_TARGET_FUNC double mc_kahan1xnff(int n, const float * x)
{
	int i    = 0;
	double s = 0.0, c = 0.0;
	for (; i < n; i++) {
		const double u = mc_cast(double, x[i]) - c;
		const double w = s + u;
		c              = (w - s) - u;
		s              = w;
	}
	return s;
}

MC_TARGET_FUNC double mc_kahan1xn(int n, const double * x)
{
	int i    = 0;
	double s = 0.0, c = 0.0;
	for (; i < n; i++) {
		const double u = x[i] - c;
		const double w = s + u;
		c              = (w - s) - u;
		s              = w;
	}
	return s;
}

MC_TARGET_FUNC long double mc_kahan1xnl(int n, const long double * x)
{
	int i         = 0;
	long double s = 0.0L, c = 0.0L;
	for (; i < n; i++) {
		const long double u = x[i] - c;
		const long double w = s + u;
		c                   = (w - s) - u;
		s                   = w;
	}
	return s;
}

#endif /* !MC_SUM_KAHAN1XN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mean1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_sum1xn.h>

#ifndef MC_MEAN1XN_H
#define MC_MEAN1XN_H

#pragma mark - mc_mean1xn -

MC_TARGET_FUNC float mc_mean1xnf(int n, const float * x, int b, int f)
{
	float s = 0.0f;
	if (n > 0) {
		s = mc_sum1xnf(n, x, f);
		s = s / mc_cast(float, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC double mc_mean1xnff(int n, const float * x, int b, int f)
{
	double s = 0.0f;
	if (n > 0) {
		s = mc_sum1xnff(n, x, f);
		s = s / mc_cast(double, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC double mc_mean1xn(int n, const double * x, int b, int f)
{
	double s = 0.0f;
	if (n > 0) {
		s = mc_sum1xn(n, x, f);
		s = s / mc_cast(double, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC long double mc_mean1xnl(int n, const long double * x, int b, int f)
{
	long double s = 0.0f;
	if (n > 0) {
		s = mc_sum1xnl(n, x, f);
		s = s / mc_cast(long double, (b ? n - 1 : n));
	}
	return s;
}

#endif /* !MC_MEAN1XN_H */

/* EOF */
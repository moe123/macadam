//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_meanmx1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_sum2mx1.h>

#ifndef MC_MEANMX1_H
#define MC_MEANMX1_H

#pragma mark - mc_meanmx1 -

MC_TARGET_FUNC float mc_meanmx1f(int m, int n, int j, const float * a, int b)
{
	float s = 0.0f;
	if (n > 0) {
		s = mc_sum2mx1f(m, n, j, a);
		s = s / mc_cast(float, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC double mc_meanmx1ff(int m, int n, int j, const float * a, int b)
{
	double s = 0.0;
	if (n > 0) {
		s = mc_sum2mx1ff(m, n, j, a);
		s = s / mc_cast(double, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC double mc_meanmx1(int m, int n, int j, const double * a, int b)
{
	double s = 0.0;
	if (n > 0) {
		s = mc_sum2mx1(m, n, j, a);
		s = s / mc_cast(double, (b ? n - 1 : n));
	}
	return s;
}

MC_TARGET_FUNC long double mc_meanmx1l(int m, int n, int j, const long double * a, int b)
{
	long double s = 0.0L;
	if (n > 0) {
		s = mc_sum2mx1l(m, n, j, a);
		s = s / mc_cast(long double, (b ? n - 1 : n));
	}
	return s;
}

#endif /* !MC_MEANMX1_H */

/* EOF */
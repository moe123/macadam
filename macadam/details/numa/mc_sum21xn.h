//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sum21xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_twosum.h>

#ifndef MC_SUM21XN_H
#define MC_SUM21XN_H

#pragma mark - mc_sum21xn -

MC_TARGET_FUNC float mc_sum21xnf(int n, const float * x)
{
	int i   = 1;
	float e = 0.0f, s = 0.0f, y;
	if (n > 0) {
		s = x[0];
		for (; i < n; i++) {
			mc_twosumf(s, x[i], &s, &y);
			e = e + y;
		}
	}
	return s + e;
}

MC_TARGET_FUNC double mc_sum21xnff(int n, const float * x)
{
	int i    = 1;
	double e = 0.0, s = 0.0, y;
	if (n > 0) {
		s = mc_cast(double, x[0]);
		for (; i < n; i++) {
			mc_twosum(s, mc_cast(double, x[i]), &s, &y);
			e = e + y;
		}
	}
	return s + e;
}

MC_TARGET_FUNC double mc_sum21xn(int n, const double * x)
{
	int i    = 1;
	double e = 0.0, s = 0.0, y;
	if (n > 0) {
		s = x[0];
		for (; i < n; i++) {
			mc_twosum(s, x[i], &s, &y);
			e = e + y;
		}
	}
	return s + e;
}

MC_TARGET_FUNC long double mc_sum21xnl(int n, const long double * x)
{
	int i         = 1;
	long double e = 0.0L, s = 0.0L, y;
	if (n > 0) {
		s = x[0];
		for (; i < n; i++) {
			mc_twosuml(s, x[i], &s, &y);
			e = e + y;
		}
	}
	return s + e;
}

#endif /* !MC_SUM21XN_H */

/* EOF */
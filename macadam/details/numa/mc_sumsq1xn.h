//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sumsq1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_SUMSQ1XN_H
#define MC_SUMSQ1XN_H

#pragma mark - mc_sumsq1xn -

MC_TARGET_FUNC float mc_sumsq1xnf(int n, const float * x)
{
	float mean, sumsq = 0.0f, scale;
	if (n > 0) {
		mc_mssqr1xnf(n, x, &mean, &sumsq, &scale);
		sumsq = mc_raise2f(scale) * sumsq;
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_sumsq1xnff(int n, const float * x)
{
	double mean, sumsq = 0.0, scale;
	if (n > 0) {
		mc_mssqr1xnff(n, x, &mean, &sumsq, &scale);
		sumsq = mc_raise2(scale) * sumsq;
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_sumsq1xn(int n, const double * x)
{
	double mean, sumsq = 0.0, scale;
	if (n > 0) {
		mc_mssqr1xn(n, x, &mean, &sumsq, &scale);
		sumsq = mc_raise2(scale) * sumsq;
	}
	return sumsq;
}

MC_TARGET_FUNC long double mc_sumsq1xnl(int n, const long double * x)
{
	long double mean, sumsq = 0.0L, scale;
	if (n > 0) {
		mc_mssqr1xnl(n, x, &mean, &sumsq, &scale);
		sumsq = mc_raise2l(scale) * sumsq;
	}
	return sumsq;
}

#endif /* !MC_SUMSQ1XN_H */

/* EOF */
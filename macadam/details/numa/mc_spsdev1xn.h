//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_spsdev1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_SPSDEV1XN_H
#define MC_SPSDEV1XN_H

#pragma mark - mc_spsdev1xn -

MC_TARGET_FUNC float mc_spsdev1xnf(int n, const float * x)
{
//!# Returns the sample standard deviation of vector X.
	float mean, sumsq, scale;
	if (n < 2) {
		return 0.0f;
	}
	mc_mssqr1xnf(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrtf(sumsq / mc_cast_expr(float, n - 1));
}

MC_TARGET_FUNC double mc_spsdev1xnff(int n, const float * x)
{
//!# Returns the sample standard deviation of vector X.
	double mean, sumsq, scale;
	if (n < 2) {
		return 0.0;
	}
	mc_mssqr1xnff(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrt(sumsq / mc_cast_expr(double, n - 1));
}

MC_TARGET_FUNC double mc_spsdev1xn(int n, const double * x)
{
//!# Returns the sample standard deviation of vector X.
	double mean, sumsq, scale;
	if (n < 2) {
		return 0.0;
	}
	mc_mssqr1xn(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrt(sumsq / mc_cast_expr(double, n - 1));
}

MC_TARGET_FUNC long double mc_spsdev1xnl(int n, const long double * x)
{
//!# Returns the sample standard deviation of vector X.
	long double mean, sumsq, scale;
	if (n < 2) {
		return 0.0L;
	}
	mc_mssqr1xnl(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrtl(sumsq / mc_cast_expr(long double, n - 1));
}

#endif /* !MC_SPSDEV1XN_H */

/* EOF */
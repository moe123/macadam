//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ppsdev1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_PPSDEV1XN_H
#define MC_PPSDEV1XN_H

#pragma mark - mc_ppsdev1xn -

MC_TARGET_FUNC float mc_ppsdev1xnf(int n, const float * x)
{
//!# Returns the population standard deviation of vector X.
	float mean, sumsq, scale;
	if (n < 2) {
		return 0.0f;
	}
	mc_mssqr1xnf(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrtf(sumsq / mc_cast(float, n));
}

MC_TARGET_FUNC double mc_ppsdev1xnff(int n, const float * x)
{
//!# Returns the population standard deviation of vector X.
	double mean, sumsq, scale;
	if (n < 2) {
		return 0.0;
	}
	mc_mssqr1xnff(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrt(sumsq / mc_cast(double, n));
}

MC_TARGET_FUNC double mc_ppsdev1xn(int n, const double * x)
{
//!# Returns the population standard deviation of vector X.
	double mean, sumsq, scale;
	if (n < 2) {
		return 0.0;
	}
	mc_mssqr1xn(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrt(sumsq / mc_cast(double, n));
}

MC_TARGET_FUNC long double mc_ppsdev1xnl(int n, const long double * x)
{
//!# Returns the population standard deviation of vector X.
	long double mean, sumsq, scale;
	if (n < 2) {
		return 0.0L;
	}
	mc_mssqr1xnl(n, x, 0, &mean, &sumsq, &scale);
	return scale * mc_sqrtl(sumsq / mc_cast(long double, n));
}

#endif /* !MC_PPSDEV1XN_H */

/* EOF */
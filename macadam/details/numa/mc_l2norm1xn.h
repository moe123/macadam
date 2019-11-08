//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_l2norm1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_L2NORM1XN_H
#define MC_L2NORM1XN_H

#pragma mark - mc_l2norm1xn -

MC_TARGET_FUNC float mc_l2norm1xnf(int n, const float * x)
{
	float mean, sumsq = 0.0f, scale;
	if (n > 0) {
		mc_mssqr1xnf(n, x, &mean, &sumsq, &scale);
		sumsq = scale * mc_sqrtf(sumsq);
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_l2norm1xnff(int n, const float * x)
{
	double mean, sumsq = 0.0, scale;
	if (n > 0) {
		mc_mssqr1xnff(n, x, &mean, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq);
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_l2norm1xn(int n, const double * x)
{
	double mean, sumsq = 0.0, scale;
	if (n > 0) {
		mc_mssqr1xn(n, x, &mean, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq);
	}
	return sumsq;
}

MC_TARGET_FUNC long double mc_l2norm1xnl(int n, const long double * x)
{
	long double mean, sumsq = 0.0L, scale;
	if (n > 0) {
		mc_mssqr1xnl(n, x, &mean, &sumsq, &scale);
		sumsq = scale * mc_sqrtl(sumsq);
	}
	return sumsq;
}

#endif /* !MC_L2NORM1XN_H */

/* EOF */
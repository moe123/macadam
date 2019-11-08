//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rms1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_ssqr1xn.h>

#ifndef MC_RMS1XN_H
#define MC_RMS1XN_H

#pragma mark - mc_rms1xn -

MC_TARGET_FUNC float mc_rms1xnf(int n, const float * x)
{
	float sumsq = 0.0f, scale;
	if (n > 0) {
		mc_ssqr1xnf(n, x, &sumsq, &scale);
		sumsq = scale * mc_sqrtf(sumsq / mc_cast(float, n));
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_rms1xnff(int n, const float * x)
{
	double sumsq = 0.0, scale;
	if (n > 0) {
		mc_ssqr1xnff(n, x, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq / mc_cast(double, n));
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_rms1xn(int n, const double * x)
{
	double sumsq = 0.0, scale;
	if (n > 0) {
		mc_ssqr1xn(n, x, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq / mc_cast(double, n));
	}
	return sumsq;
}

MC_TARGET_FUNC long double mc_rms1xnl(int n, const long double * x)
{
	long double sumsq = 0.0L, scale;
	if (n > 0) {
		mc_ssqr1xnl(n, x, &sumsq, &scale);
		sumsq = scale * mc_sqrtl(sumsq / mc_cast(long double, n));
	}
	return sumsq;
}

#endif /* !MC_RMS1XN_H */

/* EOF */
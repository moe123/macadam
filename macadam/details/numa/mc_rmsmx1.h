//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rmsmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_ssqrmx1.h>

#ifndef MC_RMSMX1_H
#define MC_RMSMX1_H

#pragma mark - mc_rmsmx1 -

MC_TARGET_FUNC float mc_rmsmx1f(int m, int n, int j, const float * a)
{
	float sumsq = 0.0f, scale;
	if (n > 0) {
		mc_ssqrmx1f(m, n, j, a, &sumsq, &scale);
		sumsq = scale * mc_sqrtf(sumsq / mc_cast(float, n));
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_rmsmx1ff(int m, int n, int j, const float * a)
{
	double sumsq = 0.0, scale;
	if (n > 0) {
		mc_ssqrmx1ff(m, n, j, a, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq / mc_cast(double, n));
	}
	return sumsq;
}

MC_TARGET_FUNC double mc_rmsmx1(int m, int n, int j, const double * a)
{
	double sumsq = 0.0, scale;
	if (n > 0) {
		mc_ssqrmx1(m, n, j, a, &sumsq, &scale);
		sumsq = scale * mc_sqrt(sumsq / mc_cast(double, n));
	}
	return sumsq;
}

MC_TARGET_FUNC long double mc_rmsmx1l(int m, int n, int j, const long double * a)
{
	long double sumsq = 0.0L, scale;
	if (n > 0) {
		mc_ssqrmx1l(m, n, j, a, &sumsq, &scale);
		sumsq = scale * mc_sqrtl(sumsq / mc_cast(long double, n));
	}
	return sumsq;
}

#endif /* !MC_RMSMX1_H */

/* EOF */
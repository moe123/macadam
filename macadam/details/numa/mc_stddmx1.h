//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_stddmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqrmx1.h>

#ifndef MC_STDDMX1_H
#define MC_STDDMX1_H

#pragma mark - mc_stddmx1 -

MC_TARGET_FUNC void mc_stddmx1f(const int m, const int n, const int j,const float * a, int b, float * stddev)
{
	float mean, sumsq, scale;

	*stddev = 0.0f;
	if (n > 1) {
		mc_mssqrmx1f(m, n, j, a, 0, &mean, &sumsq, &scale);
		*stddev = scale * mc_sqrtf(sumsq / mc_cast(float, (b ? (m - 1) : m)));
	}
}

MC_TARGET_FUNC void mc_stddmx1ff(const int m, const int n, const int j,const float * a, int b, double * stddev)
{
	double mean, sumsq, scale;

	*stddev = 0.0;
	if (n > 1) {
		mc_mssqrmx1ff(m, n, j, a, 0, &mean, &sumsq, &scale);
		*stddev = scale * mc_sqrt(sumsq / mc_cast(double, (b ? (m - 1) : m)));
	}
}

MC_TARGET_FUNC void mc_stddmx1(const int m, const int n, const int j,const double * a, int b, double * stddev)
{
	double mean, sumsq, scale;

	*stddev = 0.0;
	if (n > 1) {
		mc_mssqrmx1(m, n, j, a, 0, &mean, &sumsq, &scale);
		*stddev = scale * mc_sqrt(sumsq / mc_cast(double, (b ? (m - 1) : m)));
	}
}

MC_TARGET_FUNC void mc_stddmx1l(const int m, const int n, const int j,const long double * a, int b, long double * stddev)
{
	long double mean, sumsq, scale;

	*stddev = 0.0L;
	if (n > 1) {
		mc_mssqrmx1l(m, n, j, a, 0, &mean, &sumsq, &scale);
		*stddev = scale * mc_sqrtl(sumsq / mc_cast(long double, (b ? (m - 1) : m)));
	}
}

#endif /* !MC_STDDMX1_H */

/* EOF */
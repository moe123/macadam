//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_var1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_VAR1XN_H
#define MC_VAR1XN_H

#pragma mark - mc_var1xn -

MC_TARGET_FUNC void mc_var1xnf(int n, const float * x, int b, float * var)
{
	float mean, sumsq, scale;

	*var = 0.0f;
	if (n > 1) {
		mc_mssqr1xnf(n, x, &mean, &sumsq, &scale);
		*var = mc_raise2f(scale) * (sumsq / mc_cast(float, (b ? (n - 1) : n)));
	}
}

MC_TARGET_FUNC void mc_var1xnff(int n, const float * x, int b, double * var)
{
	double mean, sumsq, scale;

	*var = 0.0;
	if (n > 1) {
		mc_mssqr1xnff(n, x, &mean, &sumsq, &scale);
		*var = mc_raise2(scale) * (sumsq / mc_cast(double, (b ? (n - 1) : n)));
	}
}

MC_TARGET_FUNC void mc_var1xn(int n, const double * x, int b, double * var)
{
	double mean, sumsq, scale;

	*var = 0.0;
	if (n > 1) {
		mc_mssqr1xn(n, x, &mean, &sumsq, &scale);
		*var = mc_raise2(scale) * (sumsq / mc_cast(double, (b ? (n - 1) : n)));
	}
}

MC_TARGET_FUNC void mc_var1xnl(int n, const long double * x, int b, long double * var)
{
	long double mean, sumsq, scale;

	*var = 0.0L;
	if (n > 1) {
		mc_mssqr1xnl(n, x, &mean, &sumsq, &scale);
		*var = mc_raise2l(scale) * (sumsq / mc_cast(long double, (b ? (n - 1) : n)));
	}
}

#endif /* !MC_VAR1XN_H */

/* EOF */
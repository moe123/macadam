//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_diffk1x.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_diff1xn.h>

#ifndef MC_DIFFK1XN_H
#define MC_DIFFK1XN_H

#pragma mark - mc_diffk1x -

MC_TARGET_FUNC int mc_diffk1xf(int n, int k, float * y, const float * x)
{
//!# Requires y[n - k] and x[n] where 1 < n < (k + 1). Y and X may be the same.
//!# Calculating the k-th differences between adjacent elements of vector x.
//!# Returns the number of elements in y vectors.
	int i = 1, r = -1;
	if (0 < k && n > (k + 1)) { \
		r = mc_diff1xnf(n, y, x);
		for (i = 1; i < k; i++) {
			r = mc_diff1xnf((n - i), y, y);
		}
	}
	return r;
}

MC_TARGET_FUNC int mc_diffk1xff(int n, int k, double * y, const float * x)
{
//!# Requires y[n - k] and x[n] where 1 < n < (k + 1). Calculating the k-th
//!# differences between adjacent elements of vector x. Returns the number
//!# of elements in y vectors.
	int i = 1, r = -1;
	if (0 < k && n > (k + 1)) { \
		r = mc_diff1xnff(n, y, x);
		for (i = 1; i < k; i++) {
			r = mc_diff1xn((n - i), y, y);
		}
	}
	return r;
}

MC_TARGET_FUNC int mc_diffk1x(int n, int k, double * y, const double * x)
{
//!# Requires y[n - k] and x[n] where 1 < n < (k + 1). Y and X may be the same.
//!# Calculating the k-th differences between adjacent elements of vector x.
//!# Returns the number of elements in y vectors.
	int i = 1, r = -1;
	if (0 < k && n > (k + 1)) { \
		r = mc_diff1xn(n, y, x);
		for (i = 1; i < k; i++) {
			r = mc_diff1xn((n - i), y, y);
		}
	}
	return r;
}

MC_TARGET_FUNC int mc_diffk1xl(int n, int k, long double * y, const long double * x)
{
//!# Requires y[n - k] and x[n] where 1 < n < (k + 1). Y and X may be the same.
//!# Calculating the k-th differences between adjacent elements of vector x.
//!# Returns the number of elements in y vectors.
	int i = 1, r = -1;
	if (0 < k && n > (k + 1)) { \
		r = mc_diff1xnl(n, y, x);
		for (i = 1; i < k; i++) {
			r = mc_diff1xnl((n - i), y, y);
		}
	}
	return r;
}

#endif /* !MC_DIFFK1XN_H */

/* EOF */
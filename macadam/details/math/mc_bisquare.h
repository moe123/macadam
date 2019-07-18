//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_bisquare.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_BISQUARE_H
#define MC_BISQUARE_H

#pragma mark - mc_bisquare -

MC_TARGET_FUNCTION float mc_bisquaref(float x, float k)
{
	float w, y;
	if (mc_fabsf(x) >= k || k == 0.0f) {
		return 0.0f;
	}
	k = 1.0f / k;
	y = x * k;
	w = 1.0f - y * y;
	return w * w;
}

MC_TARGET_FUNCTION double mc_bisquare(double x, double k)
{
	double w, y;
	if (mc_fabs(x) >= k || k == 0.0) {
		return 0.0;
	}
	k = 1.0 / k;
	y = x * k;
	w = 1.0 - y * y;
	return w * w;
}

MC_TARGET_FUNCTION long double mc_bisquarel(long double x, long double k)
{
	long double w, y;
	if (mc_fabsl(x) >= k || k == 0.0L) {
		return 0.0L;
	}
	k = 1.0L / k;
	y = x * k;
	w = 1.0L - y * y;
	return w * w;
}

#endif /* !MC_BISQUARE_H */

/* EOF */
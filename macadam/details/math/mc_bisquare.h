//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_bisquare.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_BISQUARE_H
#define MC_BISQUARE_H

#pragma mark - mc_bisquare -

static MC_TARGET_INLINE float mc_bisquaref(float x, float k)
{
	float w, y;
#	if MC_TARGET_CPP98
	if(::fabsf(x) >= k || k == 0.0f) {
		return 0.0f;
	}
#	else
	if(fabsf(x) >= k || k == 0.0f) {
		return 0.0f;
	}
#	endif
	k = 1.0f / k;
	y = x * k;
	w = 1.0f - y * y;
	return w * w;
}

static MC_TARGET_INLINE double mc_bisquare(double x, double k)
{
	double w, y;
#	if MC_TARGET_CPP98
	if(::fabs(x) >= k || k == 0.0) {
		return 0.0;
	}
#	else
	if(fabs(x) >= k || k == 0.0) {
		return 0.0;
	}
#	endif
	k = 1.0 / k;
	y = x * k;
	w = 1.0 - y * y;
	return w * w;
}

static MC_TARGET_INLINE long double mc_bisquarel(long double x, long double k)
{
	long double w, y;
#	if MC_TARGET_CPP98
	if(::fabsl(x) >= k || k == 0.0L) {
		return 0.0L;
	}
#	else
	if(fabsl(x) >= k || k == 0.0L) {
		return 0.0L;
	}
#	endif
	k = 1.0L / k;
	y = x * k;
	w = 1.0L - y * y;
	return w * w;
}

#endif /* !MC_BISQUARE_H */

/* EOF */
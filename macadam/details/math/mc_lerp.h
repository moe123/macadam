//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lerp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LERP_H
#define MC_LERP_H

#pragma mark - mc_lerp -

static MC_TARGET_INLINE float mc_lerpf(float x, float y, float z)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y) || ::isnan(z)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isnan(y) || isnan(z)) {
		return MCK_NAN;
	}
#	endif
	if ((x <= 0.0f && y >= 0.0f) || (x >= 0.0f && y <= 0.0f)) {
		return (x * (1.0f - z)) + (y * z);
	} else if (z == 1.0f) {
		return y;
	}
	const float w = x + z * (y - x);
	if (z > 1.0f && y > x) {
		return y < w ? w : y;
	}
	return w < y ? w : y;
}

static MC_TARGET_INLINE double mc_lerp(double x, double y, double z)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y) || ::isnan(z)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isnan(y) || isnan(z)) {
		return MCK_NAN;
	}
#	endif
	if ((x <= 0.0 && y >= 0.0) || (x >= 0.0 && y <= 0.0)) {
		return (x * (1.0 - z)) + (y * z);
	} else if (z == 1.0) {
		return y;
	}
	const float w = x + z * (y - x);
	if (z > 1.0 && y > x) {
		return y < w ? w : y;
	}
	return w < y ? w : y;
}

static MC_TARGET_INLINE long double mc_lerpl(long double x, long double y, long double z)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y) || ::isnan(z)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isnan(y) || isnan(z)) {
		return MCK_NAN;
	}
#	endif
	if ((x <= 0.0L && y >= 0.0L) || (x >= 0.0L && y <= 0.0L)) {
		return (x * (1.0L - z)) + (y * z);
	} else if (z == 1.0L) {
		return y;
	}
	const float w = x + z * (y - x);
	if (z > 1.0L && y > x) {
		return y < w ? w : y;
	}
	return w < y ? w : y;
}

#endif /* !MC_LERP_H */

/* EOF */
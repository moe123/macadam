//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sqrt1pm1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SQRT1PM1_H
#define MC_SQRT1PM1_H

#pragma mark - mc_sqrt1pm1 -

static MC_TARGET_INLINE float mc_sqrt1pm1f(float x)
{
#	if MC_TARGET_CPP98
	if (::fabsf(x) > 0.75f) {
		return ::sqrtf(1.0f + x) - 1.0f;
	}
	return x / (1.0f + ::sqrtf(1.0f + x));
#	else
	if (fabsf(x) > 0.75f) {
		return sqrtf(1.0f + x) - 1.0f;
	}
	return x / (1.0f + sqrtf(1.0f + x));
#	endif
}

static MC_TARGET_INLINE double mc_sqrt1pm1(double x)
{
#	if MC_TARGET_CPP98
	if (::fabs(x) > 0.75) {
		return ::sqrt(1.0 + x) - 1.0;
	}
	return x / (1.0 + ::sqrt(1.0 + x));
#	else
	if (fabs(x) > 0.75) {
		return sqrt(1.0 + x) - 1.0;
	}
	return x / (1.0 + sqrt(1.0 + x));
#	endif
}

static MC_TARGET_INLINE long double mc_sqrt1pm1l(long double x)
{
#	if MC_TARGET_CPP98
	if (::fabsl(x) > 0.75L) {
		return ::sqrtl(1.0L + x) - 1.0L;
	}
	return x / (1.0L + ::sqrtl(1.0L + x));
#	else
	if (fabsl(x) > 0.75L) {
		return sqrtl(1.0L + x) - 1.0L;
	}
	return x / (1.0L + sqrtl(1.0L + x));
#	endif
}

#endif /* !MC_SQRT1PM1_H */

/* EOF */
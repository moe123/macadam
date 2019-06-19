//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlogy.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_XLOGY_H
#define MC_XLOGY_H

#pragma mark - mc_xlogy -

static MC_TARGET_INLINE float mc_xlogyf(float x, float y)
{
#	if MC_TARGET_CPP98
	return (x== 0 ? 0 : x * ::logf(y));
#	else
	return (x== 0 ? 0 : x * logf(y));
#	endif
}

static MC_TARGET_INLINE double mc_xlogy(double x, double y)
{
#	if MC_TARGET_CPP98
	return (x== 0 ? 0 : x * ::log(y));
#	else
	return (x== 0 ? 0 : x * log(y));
#	endif
}

static MC_TARGET_INLINE long double mc_xlogyl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return (x== 0 ? 0 : x * ::logl(y));
#	else
	return (x== 0 ? 0 : x * logl(y));
#	endif
}

#endif /* !MC_XLOGY_H */

/* EOF */
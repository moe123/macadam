//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_pow.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_POW_H
#define MC_POW_H

#pragma mark - mc_pow -

static MC_TARGET_INLINE float mc_powf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::powf(x, y);
#	else
	return powf(x, y);
#	endif
}

static MC_TARGET_INLINE double mc_pow(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::pow(x, y);
#	else
	return pow(x, y);
#	endif
}

static MC_TARGET_INLINE long double mc_powl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::powl(x, y);
#	else
	return powl(x, y);
#	endif
}

#endif /* !MC_POW_H */

/* EOF */
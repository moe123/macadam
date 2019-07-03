//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_floor.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FLOOR_H
#define MC_FLOOR_H

#pragma mark - mc_floor -

static MC_TARGET_INLINE float mc_floorf(float x)
{
#	if MC_TARGET_CPP98
	return ::floorf(x);
#	else
	return floorf(x);
#	endif
}

static MC_TARGET_INLINE double mc_floor(double x)
{
#	if MC_TARGET_CPP98
	return ::floor(x);
#	else
	return floor(x);
#	endif
}

static MC_TARGET_INLINE long double mc_floorl(long double x)
{
#	if MC_TARGET_CPP98
	return ::floorl(x);
#	else
	return floorl(x);
#	endif
}

#endif /* !MC_FLOOR_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cube.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_CUBE_H
#define MC_CUBE_H

#pragma mark - mc_cube -

static MC_TARGET_INLINE float mc_cubef(float x)
{
	return x * x * x;
}

static MC_TARGET_INLINE double mc_cube(double x)
{
	return x * x * x;
}

static MC_TARGET_INLINE long double mc_cubel(long double x)
{
	return x * x * x;
}

#endif /* !MC_CUBE_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_raise2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RAISE2_H
#define MC_RAISE2_H

#pragma mark - mc_raise2 -

static MC_TARGET_INLINE float mc_raise2f(float x)
{
	return x * x;
}

static MC_TARGET_INLINE double mc_raise2(double x)
{
	return x * x;
}

static MC_TARGET_INLINE long double mc_raise2l(long double x)
{
	return x * x;
}

#endif /* !MC_RAISE2_H */

/* EOF */
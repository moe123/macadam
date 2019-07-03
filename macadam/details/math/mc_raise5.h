//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_raise5.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RAISE5_H
#define MC_RAISE5_H

#pragma mark - mc_raise5 -

static MC_TARGET_INLINE float mc_raise5f(float x)
{
	return x * x * x * x * x;
}

static MC_TARGET_INLINE double mc_raise5(double x)
{
	return x * x * x * x * x;
}

static MC_TARGET_INLINE long double mc_raise5l(long double x)
{
	return x * x * x * x * x;
}

#endif /* !MC_RAISE5_H */

/* EOF */
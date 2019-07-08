//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_atan.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ACOT_H
#define MC_ACOT_H

#pragma mark - mc_acot -

static MC_TARGET_INLINE float mc_acotf(float x)
{
	return mc_atanf(1.0f / x);
}

static MC_TARGET_INLINE double mc_acot(double x)
{
	return mc_atan(1.0 / x);
}

static MC_TARGET_INLINE long double mc_acotl(long double x)
{
	return mc_atanl(1.0L / x);
}

#endif /* !MC_ACOT_H */

/* EOF */
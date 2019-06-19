//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rsqr.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RSQR_H
#define MC_RSQR_H

#pragma mark - mc_rsqr -

static MC_TARGET_INLINE float mc_rsqrf(float x)
{
	return 1.0f / (x * x);
}

static MC_TARGET_INLINE double mc_rsqr(double x)
{
	return 1.0 / (x * x);
}

static MC_TARGET_INLINE long double mc_rsqrl(long double x)
{
	return 1.0L / (x * x);
}

#endif /* !MC_RSQR_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ceil.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_CEIL_H
#define MC_CEIL_H

#pragma mark - mc_ceil -

static MC_TARGET_INLINE float mc_ceilf(float x)
{
#	if MC_TARGET_CPP98
	return ::ceilf(x);
#	else
	return ceilf(x);
#	endif
}

static MC_TARGET_INLINE double mc_ceil(double x)
{
#	if MC_TARGET_CPP98
	return ::ceil(x);
#	else
	return ceil(x);
#	endif
}

static MC_TARGET_INLINE long double mc_ceill(long double x)
{
#	if MC_TARGET_CPP98
	return ::ceill(x);
#	else
	return ceill(x);
#	endif
}

#endif /* !MC_CEIL_H */

/* EOF */
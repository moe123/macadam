//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_atan2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ATAN2_H
#define MC_ATAN2_H

#pragma mark - mc_atan2 -

static MC_TARGET_INLINE float mc_atan2f(float y, float x)
{
#	if MC_TARGET_CPP98
	return ::atan2f(y, x);
#	else
	return atan2f(y, x);
#	endif
}

static MC_TARGET_INLINE double mc_atan2(double y, double x)
{
#	if MC_TARGET_CPP98
	return ::atan2(y, x);
#	else
	return atan2(y, x);
#	endif
}

static MC_TARGET_INLINE long double mc_atan2l(long double y, long double x)
{
#	if MC_TARGET_CPP98
	return ::atan2l(y, x);
#	else
	return atan2l(y, x);
#	endif
}

#endif /* !MC_ATAN2_H */

/* EOF */
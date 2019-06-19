//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_abssqrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ABSSQRT_H
#define MC_ABSSQRT_H

#pragma mark - mc_abssqrt -

static MC_TARGET_INLINE float mc_abssqrtf(float x)
{
#	if MC_TARGET_CPP98
	return ::sqrtf(::fabsf(x));
#	else
	return sqrtf(fabsf(x));
#	endif
}

static MC_TARGET_INLINE double mc_abssqrt(double x)
{
#	if MC_TARGET_CPP98
	return ::sqrt(::fabs(x));
#	else
	return sqrt(fabs(x));
#	endif
}

static MC_TARGET_INLINE long double mc_abssqrtl(long double x)
{
#	if MC_TARGET_CPP98
	return ::sqrtl(::fabsl(x));
#	else
	return sqrtl(fabsl(x));
#	endif
}

#endif /* !MC_ABSRSQRT_H */

/* EOF */
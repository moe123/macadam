//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_absrsqrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_rsqrt.h>

#ifndef MC_ABSRSQRT_H
#define MC_ABSRSQRT_H

#pragma mark - mc_absrsqrt -

static MC_TARGET_INLINE float mc_absrsqrtf(float x)
{
#	if MC_TARGET_CPP98
	return mc_rsqrtf(::fabsf(x));
#	else
	return mc_rsqrtf(fabsf(x));
#	endif
}

static MC_TARGET_INLINE double mc_absrsqrt(double x)
{
#	if MC_TARGET_CPP98
	return mc_rsqrt(::fabs(x));
#	else
	return mc_rsqrt(fabs(x));
#	endif
}

static MC_TARGET_INLINE long double mc_absrsqrtl(long double x)
{
#	if MC_TARGET_CPP98
	return mc_rsqrtl(::fabsl(x));
#	else
	return mc_rsqrtl(fabsl(x));
#	endif
}

#endif /* !MC_ABSRSQRT_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sin.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SIN_H
#define MC_SIN_H

#pragma mark - mc_sin -

static MC_TARGET_INLINE float mc_sinf(float x)
{
#	if MC_TARGET_CPP98
	return ::sinf(x);
#	else
	return sinf(x);
#	endif
}

static MC_TARGET_INLINE double mc_sin(double x)
{
#	if MC_TARGET_CPP98
	return ::sin(x);
#	else
	return sin(x);
#	endif
}

static MC_TARGET_INLINE long double mc_sinl(long double x)
{
#	if MC_TARGET_CPP98
	return ::sinl(x);
#	else
	return sinl(x);
#	endif
}

#endif /* !MC_SIN_H */

/* EOF */
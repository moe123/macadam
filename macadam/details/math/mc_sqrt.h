//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sqrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SQRT_H
#define MC_SQRT_H

#pragma mark - mc_sqrt -

static MC_TARGET_INLINE float mc_sqrtf(float x)
{
#	if MC_TARGET_CPP98
	return ::sqrtf(x);
#	else
	return sqrtf(x);
#	endif
}

static MC_TARGET_INLINE double mc_sqrt(double x)
{
#	if MC_TARGET_CPP98
	return ::sqrt(x);
#	else
	return sqrt(x);
#	endif
}

static MC_TARGET_INLINE double mc_sqrtl(double x)
{
#	if MC_TARGET_CPP98
	return ::sqrtl(x);
#	else
	return sqrtl(x);
#	endif
}

#endif /* !MC_SQRT_H */

/* EOF */
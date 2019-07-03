//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trunc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_TRUNC_H
#define MC_TRUNC_H

#pragma mark - mc_trunc -

static MC_TARGET_INLINE float mc_truncf(float x)
{
#	if MC_TARGET_CPP98
	return ::truncf(x);
#	else
	return truncf(x);
#	endif
}

static MC_TARGET_INLINE double mc_trunc(double x)
{
#	if MC_TARGET_CPP98
	return ::trunc(x);
#	else
	return trunc(x);
#	endif
}

static MC_TARGET_INLINE long double mc_truncl(long double x)
{
#	if MC_TARGET_CPP98
	return ::truncl(x);
#	else
	return truncl(x);
#	endif
}

#endif /* !MC_TRUNC_H */

/* EOF */
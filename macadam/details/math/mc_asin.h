//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asin.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ASIN_H
#define MC_ASIN_H

#pragma mark - mc_asin -

static MC_TARGET_INLINE float mc_asinf(float x)
{
#	if MC_TARGET_CPP98
	return ::asinf(x);
#	else
	return asinf(x);
#	endif
}

static MC_TARGET_INLINE double mc_asin(double x)
{
#	if MC_TARGET_CPP98
	return ::asin(x);
#	else
	return asin(x);
#	endif
}

static MC_TARGET_INLINE long double mc_asinl(long double x)
{
#	if MC_TARGET_CPP98
	return ::asinl(x);
#	else
	return asinl(x);
#	endif
}

#endif /* !MC_ASIN_H */

/* EOF */
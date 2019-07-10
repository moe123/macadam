//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asinh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ASINH_H
#define MC_ASINH_H

#pragma mark - mc_asinh -

static MC_TARGET_INLINE float mc_asinhf(float x)
{
#	if MC_TARGET_CPP98
	return ::asinhf(x);
#	else
	return asinhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_asinh(double x)
{
#	if MC_TARGET_CPP98
	return ::asinh(x);
#	else
	return asinh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_asinhl(long double x)
{
#	if MC_TARGET_CPP98
	return ::asinhl(x);
#	else
	return asinhl(x);
#	endif
}

#endif /* !MC_ASINH_H */

/* EOF */
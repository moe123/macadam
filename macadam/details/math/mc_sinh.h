//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sinh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SINH_H
#define MC_SINH_H

#pragma mark - mc_sinh -

static MC_TARGET_INLINE float mc_sinhf(float x)
{
#	if MC_TARGET_CPP98
	return ::sinhf(x);
#	else
	return sinhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_sinh(double x)
{
#	if MC_TARGET_CPP98
	return ::sinh(x);
#	else
	return sinh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_sinhl(long double x)
{
#	if MC_TARGET_CPP98
	return ::sinhl(x);
#	else
	return sinhl(x);
#	endif
}

#endif /* !MC_SINH_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_expm1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXPM1_H
#define MC_EXPM1_H

#pragma mark - mc_expm1 -

static MC_TARGET_INLINE float mc_expm1f(float x)
{
#	if MC_TARGET_CPP98
	return ::expm1f(x);
#	else
	return expm1f(x);
#	endif
}

static MC_TARGET_INLINE double mc_expm1(double x)
{
#	if MC_TARGET_CPP98
	return ::expm1(x);
#	else
	return expm1(x);
#	endif
}

static MC_TARGET_INLINE long double mc_expm1l(long double x)
{
#	if MC_TARGET_CPP98
	return ::expm1l(x);
#	else
	return expm1l(x);
#	endif
}

#endif /* !MC_EXPM1_H */

/* EOF */
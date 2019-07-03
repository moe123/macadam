//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXP2_H
#define MC_EXP2_H

#pragma mark - mc_exp2 -

static MC_TARGET_INLINE float mc_exp2f(float x)
{
#	if MC_TARGET_CPP98
	return ::exp2f(x);
#	else
	return exp2f(x);
#	endif
}

static MC_TARGET_INLINE double mc_exp2(double x)
{
#	if MC_TARGET_CPP98
	return ::exp2(x);
#	else
	return exp2(x);
#	endif
}

static MC_TARGET_INLINE long double mc_exp2l(long double x)
{
#	if MC_TARGET_CPP98
	return ::exp2l(x);
#	else
	return exp2l(x);
#	endif
}

#endif /* !MC_EXP2_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log10.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOG10_H
#define MC_LOG10_H

#pragma mark - mc_log10 -

static MC_TARGET_INLINE float mc_log10f(float x)
{
#	if MC_TARGET_CPP98
	return ::log10f(x);
#	else
	return log10f(x);
#	endif
}

static MC_TARGET_INLINE double mc_log10(double x)
{
#	if MC_TARGET_CPP98
	return ::log10(x);
#	else
	return log10(x);
#	endif
}

static MC_TARGET_INLINE long double mc_log10l(long double x)
{
#	if MC_TARGET_CPP98
	return ::log10l(x);
#	else
	return log10l(x);
#	endif
}

#endif /* !MC_LOG10_H */

/* EOF */
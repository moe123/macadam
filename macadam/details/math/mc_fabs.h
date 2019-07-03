//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fabs.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FABS_H
#define MC_FABS_H

#pragma mark - mc_fabs -

static MC_TARGET_INLINE float mc_fabsf(float x)
{
#	if MC_TARGET_CPP98
	return ::fabsf(x);
#	else
	return fabsf(x);
#	endif
}

static MC_TARGET_INLINE double mc_fabs(double x)
{
#	if MC_TARGET_CPP98
	return ::fabs(x);
#	else
	return fabs(x);
#	endif
}

static MC_TARGET_INLINE long double mc_fabsl(long double x)
{
#	if MC_TARGET_CPP98
	return ::fabsl(x);
#	else
	return fabsl(x);
#	endif
}

#endif /* !MC_FABS_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cos.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_COS_H
#define MC_COS_H

#pragma mark - mc_cos -

static MC_TARGET_INLINE float mc_cosf(float x)
{
#	if MC_TARGET_CPP98
	return ::cosf(x);
#	else
	return cosf(x);
#	endif
}

static MC_TARGET_INLINE double mc_cos(double x)
{
#	if MC_TARGET_CPP98
	return ::cos(x);
#	else
	return cos(x);
#	endif
}

static MC_TARGET_INLINE long double mc_cosl(long double x)
{
#	if MC_TARGET_CPP98
	return ::cosl(x);
#	else
	return cosl(x);
#	endif
}

#endif /* !MC_COS_H */

/* EOF */
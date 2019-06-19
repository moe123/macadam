//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logodds.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGODDS_H
#define MC_LOGODDS_H

#pragma mark - mc_logodds -

static MC_TARGET_INLINE float mc_logoddsf(float x, float lambda)
{
#	if MC_TARGET_CPP98
	return -::logf(1.0f / x - 1.0f) / lambda;
#	else
	return -logf(1.0f / x - 1.0f) / lambda;
#	endif
}

static MC_TARGET_INLINE double mc_logodds(double x, double lambda)
{
#	if MC_TARGET_CPP98
	return -::log(1.0 / x - 1.0) / lambda;
#	else
	return -log(1.0 / x - 1.0) / lambda;
#	endif
}

static MC_TARGET_INLINE long double mc_logoddsl(long double x, long double lambda)
{
#	if MC_TARGET_CPP98
	return -::logl(1.0L / x - 1.0L) / lambda;
#	else
	return -logl(1.0L / x - 1.0L) / lambda;
#	endif
}

#endif /* !MC_LOGODDS_H */

/* EOF */
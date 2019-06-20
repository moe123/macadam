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

	const float a = 1.0f / x - 1.0f;
	const float b = 1.0f / lambda;
#	if MC_TARGET_CPP98
	return -::logf(a) * b;
#	else
	return -logf(a) * b;
#	endif
}

static MC_TARGET_INLINE double mc_logodds(double x, double lambda)
{
	const double a = 1.0 / x - 1.0;
	const double b = 1.0 / lambda;
#	if MC_TARGET_CPP98
	return -::log(a) * b;
#	else
	return -log(a) * b;
#	endif
}

static MC_TARGET_INLINE long double mc_logoddsl(long double x, long double lambda)
{
	const long double a = 1.0L / x - 1.0L;
	const long double b = 1.0L / lambda;
#	if MC_TARGET_CPP98
	return -::logl(a) * b;
#	else
	return -logl(a) * b;
#	endif
}
#endif /* !MC_LOGODDS_H */

/* EOF */
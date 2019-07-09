//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logodds.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>

#ifndef MC_LOGODDS_H
#define MC_LOGODDS_H

#pragma mark - mc_logodds -

static MC_TARGET_INLINE float mc_logoddsf(float x, float lambda)
{

	const float a = 1.0f / x - 1.0f;
	const float b = 1.0f / lambda;
	return -mc_logf(a) * b;
}

static MC_TARGET_INLINE double mc_logodds(double x, double lambda)
{
	const double a = 1.0 / x - 1.0;
	const double b = 1.0 / lambda;
	return -mc_log(a) * b;
}

static MC_TARGET_INLINE long double mc_logoddsl(long double x, long double lambda)
{
	const long double a = 1.0L / x - 1.0L;
	const long double b = 1.0L / lambda;
	return -mc_logl(a) * b;
}
#endif /* !MC_LOGODDS_H */

/* EOF */
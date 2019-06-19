//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logistic.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGISTIC_H
#define MC_LOGISTIC_H

#pragma mark - mc_logistic -

static MC_TARGET_INLINE float mc_logisticf(float x, float lambda)
{
#	if MC_TARGET_CPP98
	return 1.0f / (::expf(-lambda * x) + 1.0f);
#	else
	return 1.0f / (expf(-lambda * x) + 1.0f);
#	endif
}

static MC_TARGET_INLINE double mc_logistic(double x, double lambda)
{
#	if MC_TARGET_CPP98
	return 1.0 / (::exp(-lambda * x) + 1.0);
#	else
	return 1.0 / (exp(-lambda * x) + 1.0);
#	endif
}

static MC_TARGET_INLINE long double mc_logisticl(long double x, long double lambda)
{
#	if MC_TARGET_CPP98
	return 1.0L / (::expl(-lambda * x) + 1.0L);
#	else
	return 1.0L / (expl(-lambda * x) + 1.0L);
#	endif
}

#endif /* !MC_LOGISTIC_H */

/* EOF */
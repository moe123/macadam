//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_expit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXPITT_H
#define MC_EXPITT_H

#pragma mark - mc_expit -

static MC_TARGET_INLINE float mc_expitf(float x)
{
#	if MC_TARGET_CPP98
	return (1.0f - 2.0f * MCLIMITS_EPSILONF) / (1.0f + ::expf(-x)) + MCLIMITS_EPSILONF;
#	else
	return (1.0f - 2.0f * MCLIMITS_EPSILONF) / (1.0f + expf(-x)) + MCLIMITS_EPSILONF;
#	endif
}

static MC_TARGET_INLINE double mc_expit(double x)
{
#	if MC_TARGET_CPP98
	return (1.0 - 2.0 * MCLIMITS_EPSILON) / (1.0 + ::exp(-x)) + MCLIMITS_EPSILON;
#	else
	return (1.0 - 2.0 * MCLIMITS_EPSILON) / (1.0 + exp(-x)) + MCLIMITS_EPSILON;
#	endif
}

static MC_TARGET_INLINE long double mc_expitl(long double x)
{
#	if MC_TARGET_CPP98
	return (1.0L - 2.0L * MCLIMITS_EPSILONL) / (1.0L + ::expl(-x)) + MCLIMITS_EPSILONL;
#	else
	return (1.0L - 2.0L * MCLIMITS_EPSILONL) / (1.0L + expl(-x)) + MCLIMITS_EPSILONL;
#	endif
}

#endif /* !MC_EXPITT_H */

/* EOF */
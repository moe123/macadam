//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sigmoid.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SIGMOID_H
#define MC_SIGMOID_H

#pragma mark - mc_sigmoid -

static MC_TARGET_INLINE float mc_sigmoidf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / (::expf(-x) + 1.0f);
#	else
	return 1.0f / (expf(-x) + 1.0f);
#	endif
}

static MC_TARGET_INLINE double mc_sigmoid(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / (::exp(-x) + 1.0);
#	else
	return 1.0 / (exp(-x) + 1.0);
#	endif
}

static MC_TARGET_INLINE long double mc_sigmoidl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / (::expl(-x) + 1.0L);
#	else
	return 1.0L / (expl(-x) + 1.0L);
#	endif
}

#endif /* !MC_SIGMOID_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGIT_H
#define MC_LOGIT_H

#pragma mark - mc_logit -

static MC_TARGET_INLINE float mc_logitf(float x)
{
#	if MC_TARGET_CPP98
	return -(::logf((1.0f / x) - 1.0f));
#	else
	return -(logf((1.0f / x) - 1.0f));
#	endif
}

static MC_TARGET_INLINE double mc_logit(double x)
{
#	if MC_TARGET_CPP98
	return -(::log((1.0 / x) - 1.0));
#	else
	return -(log((1.0 / x) - 1.0));
#	endif
}

static MC_TARGET_INLINE long double mc_logitl(long double x)
{
#	if MC_TARGET_CPP98
	return -(::logl((1.0L / x) - 1.0L));
#	else
	return -(logl((1.0L / x) - 1.0L));
#	endif
}

#endif /* !MC_LOGIT_H */

/* EOF */
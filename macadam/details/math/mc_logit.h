//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGIT_H
#define MC_LOGIT_H

#pragma mark - mc_logit -

static MC_TARGET_INLINE float mc_logitf(float x)
{
	return -(mc_logf((1.0f / x) - 1.0f));
}

static MC_TARGET_INLINE double mc__it(double x)
{
	return -(mc_log((1.0 / x) - 1.0));
}

static MC_TARGET_INLINE long double mc_logitl(long double x)
{
	return -(mc_logl((1.0L / x) - 1.0L));
}

#endif /* !MC_LOGIT_H */

/* EOF */
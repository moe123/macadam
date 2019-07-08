//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log1me.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_expm1.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_log1p.h>

#ifndef MC_LOG1ME_H
#define MC_LOG1ME_H

#pragma mark - mc_log1me -

static MC_TARGET_INLINE float mc_log1mef(float x)
{
	return (x < 0.683f) ? mc_logf(mc_expm1f(-x)) : mc_log1pf(-mc_expf(-x));
}

static MC_TARGET_INLINE double mc_log1me(double x)
{
	return (x < 0.683) ? mc_log(mc_expm1(-x)) : mc_log1p(-mc_exp(-x));
}

static MC_TARGET_INLINE long double mc_log1mel(long double x)
{
	return (x < 0.683L) ? mc_logl(mc_expm1l(-x)) : mc_log1pl(-mc_expl(-x));
}

#endif /* !MC_LOG1ME_H */

/* EOF */
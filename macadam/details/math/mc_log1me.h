//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log1me.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOG1ME_H
#define MC_LOG1ME_H

#pragma mark - mc_log1me -

static MC_TARGET_INLINE float mc_log1mef(float x)
{
#	if MC_TARGET_CPP98
	return (x < 0.683f) ? ::logf(::expm1f(-x)) : mc_log1pf(-::expf(-x));
#	else
	return (x < 0.683f) ? logf(expm1f(-x)) : mc_log1pf(-expf(-x));
#	endif
}

static MC_TARGET_INLINE double mc_log1me(double x)
{
#	if MC_TARGET_CPP98
	return (x < 0.683) ? ::log(::expm1(-x)) : mc_log1p(-::exp(-x));
#	else
	return (x < 0.683) ? log(expm1(-x)) : mc_log1p(-exp(-x));
#	endif
}

static MC_TARGET_INLINE long double mc_log1mel(long double x)
{
#	if MC_TARGET_CPP98
	return (x < 0.683L) ? ::logl(::expm1l(-x)) : mc_log1pl(-::expl(-x));
#	else
	return (x < 0.683L) ? logl(expm1l(-x)) : mc_log1pl(-expl(-x));
#	endif
}

#endif /* !MC_LOG1ME_H */

/* EOF */
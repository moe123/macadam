//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logradix.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGRADIX_H
#define MC_LOGRADIX_H

#pragma mark - mc_logradix -

static MC_TARGET_INLINE float mc_logradixf(float x, int n)
{
#	if MC_TARGET_CPP98
	return ::logf(x) / ::logf(mc_cast(float, n));
#	else
	return logf(x) / logf(mc_cast(float, n));
#	endif
}

static MC_TARGET_INLINE double mc_logradix(double x, int n)
{
#	if MC_TARGET_CPP98
	return ::log(x) / ::log(mc_cast(double, n));
#	else
	return log(x) / log(mc_cast(double, n));
#	endif
}

static MC_TARGET_INLINE long double mc_logradixl(long double x, int n)
{
#	if MC_TARGET_CPP98
	return ::logl(x) / ::logl(mc_cast(long double, n));
#	else
	return logl(x) / logl(mc_cast(long double, n));
#	endif
}

#endif /* !MC_LOGRADIX_H */

/* EOF */
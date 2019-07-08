//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logradix.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>

#ifndef MC_LOGRADIX_H
#define MC_LOGRADIX_H

#pragma mark - mc_logradix -

static MC_TARGET_INLINE float mc_logradixf(float x, int n)
{
	return mc_logf(x) / mc_logf(mc_cast(float, n));
}

static MC_TARGET_INLINE double mc_logradix(double x, int n)
{
	return mc_log(x) / mc_log(mc_cast(double, n));
}

static MC_TARGET_INLINE long double mc_logradixl(long double x, int n)
{
	return mc_logl(x) / mc_logl(mc_cast(long double, n));
}

#endif /* !MC_LOGRADIX_H */

/* EOF */
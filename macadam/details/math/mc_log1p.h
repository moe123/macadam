//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log1p.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_logp1.h>

#ifndef MC_LOG1P_H
#define MC_LOG1P_H

#pragma mark - mc_log1p -

static MC_TARGET_INLINE float mc_log1pf(float x)
{
	return mc_logp1f(x);
}

static MC_TARGET_INLINE double mc_log1p(double x)
{
	return mc_logp1(x);
}

static MC_TARGET_INLINE long double mc_log1pl(long double x)
{
	return mc_logp1l(x);
}

#endif /* !MC_LOG1P_H */

/* EOF */
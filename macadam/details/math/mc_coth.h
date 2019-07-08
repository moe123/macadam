//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_coth.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_tanh.h>

#ifndef MC_COTH_H
#define MC_COTH_H

#pragma mark - mc_coth -

static MC_TARGET_INLINE float mc_cothf(float x)
{
	return 1.0f / mc_tanhf(x);
}

static MC_TARGET_INLINE double mc_coth(double x)
{
	return 1.0 / mc_tanh(x);
}

static MC_TARGET_INLINE long double mc_cothl(long double x)
{
	return 1.0L / mc_tanhl(x);
}

#endif /* !MC_COTH_H */

/* EOF */
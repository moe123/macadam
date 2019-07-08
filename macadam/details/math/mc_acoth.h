//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acoth.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_atanh.h>

#ifndef MC_ACOTH_H
#define MC_ACOTH_H

#pragma mark - mc_acoth -

static MC_TARGET_INLINE float mc_acothf(float x)
{
	return mc_atanhf(1.0f / x);
}

static MC_TARGET_INLINE double mc_acoth(double x)
{
	return mc_atanh( 1.0 / x);
}

static MC_TARGET_INLINE long double mc_acothl(long double x)
{
	return mc_atanhl(1.0L / x);
}

#endif /* !MC_ACOTH_H */

/* EOF */
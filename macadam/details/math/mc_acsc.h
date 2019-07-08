//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acsch.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_asin.h>

#ifndef MC_ACSC_H
#define MC_ACSC_H

#pragma mark - mc_acsc -

static MC_TARGET_INLINE float mc_acscf(float x)
{
	return mc_asinf(1.0f / x);
}

static MC_TARGET_INLINE double mc_acsc(double x)
{
	return mc_asin(1.0 / x);
}

static MC_TARGET_INLINE long double mc_acscl(long double x)
{
	return mc_asinl(1.0L / x);
}

#endif /* !MC_ACSC_H */

/* EOF */
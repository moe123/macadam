//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlogp1y.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xlog1py.h>

#ifndef MC_XLOGP1Y_H
#define MC_XLOGP1Y_H

#pragma mark -  mc_xlogp1y -

static MC_TARGET_INLINE float mc_xlogp1yf(float x, float y)
{
	return mc_xlog1pyf(x, y);
}

static MC_TARGET_INLINE double mc_xlogp1y(double x, double y)
{
	return mc_xlog1py(x, y);
}

static MC_TARGET_INLINE long double mc_xlogp1yl(long double x, long double y)
{
	return mc_xlog1pyl(x, y);
}

#endif /* !MC_XLOGP1Y_H */

/* EOF */
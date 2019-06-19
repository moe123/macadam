//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlog1px.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xlog1py.h>

#ifndef MC_XLOG1PX_H
#define MC_XLOG1PX_H

#pragma mark - mc_xlog1px -

static MC_TARGET_INLINE float mc_xlog1pxf(float x)
{
	return mc_xlog1pyf(x, x);
}

static MC_TARGET_INLINE double mc_xlog1px(double x)
{
	return mc_xlog1py(x, x);
}

static MC_TARGET_INLINE long double mc_xlog1pxl(long double x)
{
	return mc_xlog1pyl(x, x);
}

#endif /* !MC_XLOG1PX_H */

/* EOF */
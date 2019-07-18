//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlogp1x.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xlog1px.h>

#ifndef MC_XLOGP1X_H
#define MC_XLOGP1X_H

#pragma mark - mc_xlogp1x -

MC_TARGET_FUNC float mc_xlogp1xf(float x)
{
	return mc_xlog1pxf(x);
}

MC_TARGET_FUNC double mc_xlogp1x(double x)
{
	return mc_xlog1px(x);
}

MC_TARGET_FUNC long double mc_xlogp1xl(long double x)
{
	return mc_xlog1pxl(x);
}

#endif /* !MC_XLOGP1X_H */

/* EOF */
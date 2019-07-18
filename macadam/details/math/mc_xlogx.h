//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlogx.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xlogy.h>

#ifndef MC_XLOGX_H
#define MC_XLOGX_H

#pragma mark - mc_xlogx -

MC_TARGET_FUNCTION float mc_xlogxf(float x)
{
	return mc_xlogyf(x, x);
}

MC_TARGET_FUNCTION double mc_xlogx(double x)
{
	return mc_xlogy(x, x);
}

MC_TARGET_FUNCTION long double mc_xlogxl(long double x)
{
	return mc_xlogyl(x, x);
}

#endif /* !MC_XLOGX_H */

/* EOF */
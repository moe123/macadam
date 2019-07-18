//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlog1py.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log1p.h>

#ifndef MC_XLOG1PY_H
#define MC_XLOG1PY_H

#pragma mark - mc_xlog1py -

MC_TARGET_FUNCTION float mc_xlog1pyf(float x, float y)
{
	return (x== 0 ? 0 : x * mc_log1pf(y));
}

MC_TARGET_FUNCTION double mc_xlog1py(double x, double y)
{
	return (x== 0 ? 0 : x * mc_log1p(y));
}

MC_TARGET_FUNCTION long double mc_xlog1pyl(long double x, long double y)
{
	return (x== 0 ? 0 : x * mc_log1pl(y));
}

#endif /* !MC_XLOG1PY_H */

/* EOF */
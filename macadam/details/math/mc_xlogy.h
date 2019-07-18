//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xlogy.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>

#ifndef MC_XLOGY_H
#define MC_XLOGY_H

#pragma mark - mc_xlogy -

MC_TARGET_FUNCTION float mc_xlogyf(float x, float y)
{
	return (x== 0 ? 0 : x * mc_logf(y));
}

MC_TARGET_FUNCTION double mc_xlogy(double x, double y)
{
	return (x== 0 ? 0 : x * mc_log(y));
}

MC_TARGET_FUNCTION long double mc_xlogyl(long double x, long double y)
{
	return (x== 0 ? 0 : x * mc_logl(y));
}

#endif /* !MC_XLOGY_H */

/* EOF */
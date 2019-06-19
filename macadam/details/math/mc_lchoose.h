//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lchoose.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>

#ifndef MC_LCHOOSE_H
#define MC_LCHOOSE_H

#pragma mark - mc_lchoose -

static MC_TARGET_INLINE float mc_lchoosef(float x, float y)
{
	if (0 <= y && y <= x) {
		return mc_lgammaf(x + 1.0f) - mc_lgammaf(y + 1.0f) - mc_lgammaf(x - y + 1.0f);
	}
	return MCLIMITS_MAXF;
}

static MC_TARGET_INLINE double mc_lchoose(double x, double y)
{
	if (0 <= y && y <= x) {
		return mc_lgamma(x + 1.0) - mc_lgamma(y + 1.0) - mc_lgamma(x - y + 1.0);
	}
	return MCLIMITS_MAX;
}

static MC_TARGET_INLINE long double mc_lchoosel(long double x, long double y)
{
	if (0 <= y && y <= x) {
		return mc_lgammal(x + 1.0L) - mc_lgammal(y + 1.0L) - mc_lgammal(x - y + 1.0L);
	}
	return MCLIMITS_MAXL;
}

#endif /* !MC_LCHOOSE_H */

/* EOF */
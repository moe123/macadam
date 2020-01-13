//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammasign.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fisint.h>
#include <macadam/details/math/mc_floor.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>

#ifndef MC_GAMMASIGN_H
#define MC_GAMMASIGN_H

#pragma mark - mc_gammasign -

MC_TARGET_FUNC float mc_gammasignf(float x)
{
	if (mc_isnan(x) || mc_isinf(x) || x > 0.0f || mc_fisintf(0.5f * mc_floorf(x))) {
		return +1.0f;
	}
	return -1.0f;
}

MC_TARGET_FUNC double mc_gammasign(double x)
{
	if (mc_isnan(x) || mc_isinf(x) || x > 0.0 || mc_fisint(0.5 * mc_floor(x))) {
		return +1.0;
	}
	return -1.0;
}

MC_TARGET_FUNC long double mc_gammasignl(long double x)
{
	if (mc_isnan(x) || mc_isinf(x) || x > 0.0L || mc_fisintl(0.5L * mc_floorl(x))) {
		return +1.0L;
	}
	return -1.0L;
}

#endif /* !MC_GAMMASIGN_H */

/* EOF */
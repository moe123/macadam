//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tanpi.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_copysign.h>
#include <macadam/details/math/mc_fmod.h>
#include <macadam/details/math/mc_tan.h>

#ifndef MC_TANPI_H
#define MC_TANPI_H

#pragma mark - mc_tanpi -

MC_TARGET_FUNC float mc_tanpif(float x)
{
	x = mc_fmodf(x, 1.0f);
	x = x <= -0.5f ? x + 1.0f : x > 0.5f ? x - 1.0f : x;
	if (x == 1.0f) {
		return mc_copysignf(0.0f, x);
	}
	if (x == 0.5f) {
		return mc_copysignf(MCK_INF, x);
	}
	const float pix = MCK_KF(MCK_PI) * x;
	return mc_tanf(pix);
}

MC_TARGET_FUNC double mc_tanpi(double x)
{
	x = mc_fmod(x, 1.0);
	x = x <= -0.5 ? x + 1.0 : x > 0.5 ? x - 1.0 : x;
	if (x == 1.0) {
		return mc_copysign(0.0, x);
	}
	if (x == 0.5) {
		return mc_copysign(MCK_INF, x);
	}
	const double pix = MCK_K(MCK_PI) * x;
	return mc_tan(pix);
}

MC_TARGET_FUNC long double mc_tanpil(long double x)
{
	x = mc_fmodl(x, 1.0L);
	x = x <= -0.5L ? x + 1.0L : x > 0.5L ? x - 1.0L : x;
	if (x == 1.0L) {
		return mc_copysignl(0.0L, x);
	}
	if (x == 0.5L) {
		return mc_copysignl(MCK_INF, x);
	}
	const long double pix = MCK_KL(MCK_PI) * x;
	return mc_tanl(pix);
}

#endif /* !MC_TANPI_H */

/* EOF */
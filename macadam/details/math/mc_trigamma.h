//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trigamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqr.h>

#ifndef MC_TRIGAMMA_H
#define MC_TRIGAMMA_H

#pragma mark - mc_trigamma -

static MC_TARGET_INLINE float mc_trigammaf(float x)
{
	float g, y, z;
#	if MC_TARGET_CPP98
	if ((x <= 0) && (::floorf(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (::floorf(x) != x)) {
		return -mc_trigammaf(-x + 1.0f) + (MCK_KF(MCK_PI) / ::sinf(-MCK_KF(MCK_PI) * x)) * (MCK_KF(MCK_PI) / ::sinf(-MCK_KF(MCK_PI) * x));
	}
#	else
	if ((x <= 0) && (floorf(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (floorf(x) != x)) {
		return -mc_trigammaf(-x + 1.0f) + (MCK_KF(MCK_PI) / sinf(-MCK_KF(MCK_PI) * x)) * (MCK_KF(MCK_PI) / sinf(-MCK_KF(MCK_PI) * x));
	}
#	endif
	if (x <= 1E-5f) {
		return 1.0f / mc_sqrf(x);
	}
	z = x;
	g = 0;
	while (z < 5.0f) {
		g += 1.0f / (z * z);
		z += 1.0f;
	}
	y  = 1.0f / (z * z);
//#! Expansion as a Laurent series.
	g += 0.5f * y + (1.0f + y * (MCK_KF(MCK_BN2) + y * (MCK_KF(MCK_BN4) + y * (MCK_KF(MCK_BN6) + y * MCK_KF(MCK_BN8))))) / z;
	return g;
}

static MC_TARGET_INLINE double mc_trigamma(double x)
{
	double g, y, z;
#	if MC_TARGET_CPP98
	if ((x <= 0) && (::floor(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (::floor(x) != x)) {
		return -mc_trigamma(-x + 1.0) + (MCK_K(MCK_PI) / ::sin(-MCK_K(MCK_PI) * x)) * (MCK_K(MCK_PI) / ::sin(-MCK_K(MCK_PI) * x));
	}
#	else
	if ((x <= 0) && (floor(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (floor(x) != x)) {
		return -mc_trigamma(-x + 1.0) + (MCK_K(MCK_PI) / sin(-MCK_K(MCK_PI) * x)) * (MCK_K(MCK_PI) / sin(-MCK_K(MCK_PI) * x));
	}
#	endif
	if (x <= 1E-5) {
		return 1.0 / mc_sqr(x);
	}
	z = x;
	g = 0;
	while (z < 5.0) {
		g += 1.0 / (z * z);
		z += 1.0;
	}
	y  = 1.0 / (z * z);
//#! Expansion as a Laurent series.
	g += 0.5 * y + (1.0 + y * (MCK_K(MCK_BN2) + y * (MCK_K(MCK_BN4) + y * (MCK_K(MCK_BN6) + y * MCK_K(MCK_BN8))))) / z;
	return g;
}

static MC_TARGET_INLINE long double mc_trigammal(long double x)
{
	long double g, y, z;
#	if MC_TARGET_CPP98
	if ((x <= 0) && (::floorl(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (::floorl(x) != x)) {
		return -mc_trigammal(-x + 1.0L) + (MCK_KL(MCK_PI) / ::sinl(-MCK_KL(MCK_PI) * x)) * (MCK_KL(MCK_PI) / ::sinl(-MCK_KL(MCK_PI) * x));
	}
#	else
	if ((x <= 0) && (floorl(x) == x)) {
		return MCK_INF;
	}
	if ((x <= 0) && (floorl(x) != x)) {
		return -mc_trigammal(-x + 1.0L) + (MCK_KL(MCK_PI) / sinl(-MCK_KL(MCK_PI) * x)) * (MCK_KL(MCK_PI) / sinl(-MCK_KL(MCK_PI) * x));
	}
#	endif
	if (x <= 1E-5L) {
		return 1.0L / mc_sqrl(x);
	}
	z = x;
	g = 0;
	while (z < 5.0L) {
		g += 1.0L / (z * z);
		z += 1.0L;
	}
	y  = 1.0L / (z * z);
//#! Expansion as a Laurent series.
	g += 0.5L * y + (1.0L + y * (MCK_KL(MCK_BN2) + y * (MCK_KL(MCK_BN4) + y * (MCK_KL(MCK_BN6) + y * MCK_KL(MCK_BN8))))) / z;
	return g;
}

#endif /* !MC_TRIGAMMA_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_pow2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_floor.h>
#include <macadam/details/math/mc_ipow2.h>
#include <macadam/details/math/mc_pow.h>

#ifndef MC_POW2_H
#define MC_POW2_H

#pragma mark - mc_pow2 -

static MC_TARGET_INLINE float mc_pow2f(float x)
{
	if (mc_floorf(x) == x) {
		if (x < -1074.0f) {
			return 0.0f;
		}
		if (x > 1024.0f) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
	return mc_powf(2.0f, x);
}

static MC_TARGET_INLINE double mc_pow2(double x)
{
	if (mc_floor(x) == x) {
		if (x < -1074.0) {
			return 0.0;
		}
		if (x > 1024.0) {
			return MCK_INF;
		}
		return mc_ipow2(mc_cast(int, x));
	}
	return mc_pow(2.0, x);
}

static MC_TARGET_INLINE double mc_pow2l(long double x)
{
	if (mc_floorl(x) == x) {
		if (x < -1074.0L) {
			return 0.0L;
		}
		if (x > 1024.0L) {
			return MCK_INF;
		}
		return mc_ipow2l(mc_cast(int, x));
	}
	return mc_powl(2.0L, x);
}

#endif /* !MC_POW2_H */

/* EOF */
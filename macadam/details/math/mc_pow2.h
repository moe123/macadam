//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_pow2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_POW2_H
#define MC_POW2_H

#pragma mark - mc_pow2 -

static MC_TARGET_INLINE float mc_pow2f(float x)
{
#	if MC_TARGET_CPP98
	if (::floorf(x) == x) {
		if (x < -1074.0f) {
			return 0.0f;
		}
		if (x > 1024.0f) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	else
	if (floorf(x) == x) {
		if (x < -1074.0f) {
			return 0.0f;
		}
		if (x > 1024.0f) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	endif

#	if MC_TARGET_CPP98
	return ::powf(2.0f, x);
#	else
	return powf(2.0f, x);
#	endif
}

static MC_TARGET_INLINE double mc_pow2(double x)
{
#	if MC_TARGET_CPP98
	if (::floor(x) == x) {
		if (x < -1074.0) {
			return 0.0;
		}
		if (x > 1024.0) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	else
	if (floor(x) == x) {
		if (x < -1074.0) {
			return 0.0;
		}
		if (x > 1024.0) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	endif
#	if MC_TARGET_CPP98
	return ::pow(2.0, x);
#	else
	return pow(2.0, x);
#	endif
}

static MC_TARGET_INLINE double mc_pow2l(long double x)
{
#	if MC_TARGET_CPP98
	if (::floorl(x) == x) {
		if (x < -1074.0L) {
			return 0.0L;
		}
		if (x > 1024.0L) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	else
	if (floorl(x) == x) {
		if (x < -1074.0L) {
			return 0.0L;
		}
		if (x > 1024.0L) {
			return MCK_INF;
		}
		return mc_ipow2f(mc_cast(int, x));
	}
#	endif
#	if MC_TARGET_CPP98
	return ::powl(2.0L, x);
#	else
	return powl(2.0L, x);
#	endif
}

#endif /* !MC_POW2_H */

/* EOF */
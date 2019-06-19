//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_powm1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xlogy.h>

#ifndef MC_POWM1_H
#define MC_POWM1_H

#pragma mark - mc_powm1 -

float mc_powm1f(float x, float y)
{
	float r;
#	if MC_TARGET_CPP98
	if (x < 0.0 && ::truncf(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0f) {
		if ((::fabsf(y * (x - 1.0f)) < 0.5f) || ::fabs(y) < 0.2f) {
			r = mc_xlogyf(y, x);
			return r < 0.5f ? (::expm1f(r)) : MCK_INF;
		}
	} else if (::truncf(y / 2.0f) == y / 2.0f) {
		return mc_powm1f(-x, y);
	}
	return ::powf(x, y) - 1.0f;
#	else
	if (x < 0.0 && truncf(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0f) {
		if ((fabsf(y * (x - 1.0f)) < 0.5f) || fabs(y) < 0.2f) {
			r = mc_xlogyf(y, x);
			return r < 0.5f ? expm1f(r) : MCK_INF;
		}
	} else if (truncf(y / 2.0f) == y / 2.0f) {
		return mc_powm1f(-x, y);
	}
	return powf(x, y) - 1.0f;
#	endif
}

double mc_powm1(double x, double y)
{
	double r;
#	if MC_TARGET_CPP98
	if (x < 0.0 && ::trunc(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0) {
		if ((::fabs(y * (x - 1.0)) < 0.5) || ::fabs(y) < 0.2) {
			r = mc_xlogy(y, x);
			return r < 0.5 ? (::expm1(r)) : MCK_INF;
		}
	} else if (::trunc(y / 2.0) == y / 2.0) {
		return mc_powm1(-x, y);
	}
	return ::pow(x, y) - 1.0;
#	else
	if (x < 0.0 && trunc(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0) {
		if ((fabs(y * (x - 1.0)) < 0.5) || fabs(y) < 0.2) {
			r = mc_xlogy(y, x);
			return r < 0.5 ? expm1(r) : MCK_INF;
		}
	} else if (trunc(y / 2.0) == y / 2.0) {
		return mc_powm1(-x, y);
	}
	return pow(x, y) - 1.0;
#	endif
}

long double mc_powm1l(long double x, long double y)
{
	long double r;
#	if MC_TARGET_CPP98
	if (x < 0.0L && ::truncl(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0L) {
		if ((::fabsl(y * (x - 1.0L)) < 0.5L) || ::fabsl(y) < 0.2L) {
			r = mc_xlogyl(y, x);
			return r < 0.5L ? (::expm1l(r)) : MCK_INF;
		}
	} else if (::truncl(y / 2.0L) == y / 2.0L) {
		return mc_powm1l(-x, y);
	}
	return ::powl(x, y) - 1.0L;
#	else
	if (x < 0.0L && truncl(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0L) {
		if ((fabsl(y * (x - 1.0L)) < 0.5L) || fabsl(y) < 0.2L) {
			r = mc_xlogyl(y, x);
			return r < 0.5L ? expm1l(r) : MCK_INF;
		}
	} else if (truncl(y / 2.0L) == y / 2.0L) {
		return mc_powm1l(-x, y);
	}
	return powl(x, y) - 1.0L;
#	endif
}

#endif /* !MC_POWM1_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_powm1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_trunc.h>
#include <macadam/details/math/mc_expm1.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_xlogy.h>

#ifndef MC_POWM1_H
#define MC_POWM1_H

#pragma mark - mc_powm1 -

float mc_powm1f(float x, float y)
{
	float r;
	if (x < 0.0 && mc_truncf(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0f) {
		if ((mc_fabsf(y * (x - 1.0f)) < 0.5f) || mc_fabs(y) < 0.2f) {
			r = mc_xlogyf(y, x);
			return r < 0.5f ? mc_expm1f(r) : MCK_INFP;
		}
	} else if (mc_truncf(y / 2.0f) == y / 2.0f) {
		return mc_powm1f(-x, y);
	}
	return mc_powf(x, y) - 1.0f;
}

double mc_powm1(double x, double y)
{
	double r;
	if (x < 0.0 && mc_trunc(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0) {
		if ((mc_fabs(y * (x - 1.0)) < 0.5) || mc_fabs(y) < 0.2) {
			r = mc_xlogy(y, x);
			return r < 0.5 ? mc_expm1(r) : MCK_INFP;
		}
	} else if (mc_trunc(y / 2.0) == y / 2.0) {
		return mc_powm1(-x, y);
	}
	return mc_pow(x, y) - 1.0;
}

long double mc_powm1l(long double x, long double y)
{
	long double r;
	if (x < 0.0L && mc_truncl(y) != y) {
		return MCK_NAN;
	}
	if (x > 0.0L) {
		if ((mc_fabsl(y * (x - 1.0L)) < 0.5L) || mc_fabsl(y) < 0.2L) {
			r = mc_xlogyl(y, x);
			return r < 0.5L ? mc_expm1l(r) : MCK_INFP;
		}
	} else if (mc_truncl(y / 2.0L) == y / 2.0L) {
		return mc_powm1l(-x, y);
	}
	return mc_powl(x, y) - 1.0L;
}

#endif /* !MC_POWM1_H */

/* EOF */
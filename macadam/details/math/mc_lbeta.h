//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lbeta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>

#ifndef MC_LBETA_H
#define MC_LBETA_H

#pragma mark - mc_lbeta -

static MC_TARGET_INLINE
float mc_lbetaf(float x, float y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	if (::isinf(x) || ::isinf(y)) {
		return MCK_INF;
	}
	if (::fabsf(x) < MCLIMITS_EPSILONF || ::fabsf(y) < MCLIMITS_EPSILONF) {
		return 0.0f;
	}
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	if (isinf(x) || isinf(y)) {
		return MCK_INF;
	}
	if (fabsf(x) < MCLIMITS_EPSILONF || fabsf(y) < MCLIMITS_EPSILONF) {
		return 0.0f;
	}
#	endif
	const float a   = mc_lgammaf(x);
	const float b   = mc_lgammaf(y);
	const float apb = mc_lgammaf(x + y);
	return a + b - apb;
}

static MC_TARGET_INLINE
double mc_lbeta(double x, double y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	if (::isinf(x) || ::isinf(y)) {
		return MCK_INF;
	}
	if (::fabs(x) < MCLIMITS_EPSILON || ::fabs(y) < MCLIMITS_EPSILON) {
		return 0.0;
	}
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	if (isinf(x) || isinf(y)) {
		return MCK_INF;
	}
	if (fabs(x) < MCLIMITS_EPSILON || fabs(y) < MCLIMITS_EPSILON) {
		return 0.0;
	}
#	endif
	const double a   = mc_lgamma(x);
	const double b   = mc_lgamma(y);
	const double apb = mc_lgamma(x + y);
	return a + b - apb;
}

static MC_TARGET_INLINE
long double mc_lbetal(long double x, long double y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	if (::isinf(x) || ::isinf(y)) {
		return MCK_INF;
	}
	if (::fabsl(x) < MCLIMITS_EPSILONL || ::fabsl(y) < MCLIMITS_EPSILONL) {
		return 0.0L;
	}
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	if (isinf(x) || isinf(y)) {
		return MCK_INF;
	}
	if (fabsl(x) < MCLIMITS_EPSILONL || fabsl(y) < MCLIMITS_EPSILONL) {
		return 0.0L;
	}
#	endif
	const long double a   = mc_lgammal(x);
	const long double b   = mc_lgammal(y);
	const long double apb = mc_lgammal(x + y);
	return a + b - apb;
}

#endif /* !MC_LBETA_H */

/* EOF */
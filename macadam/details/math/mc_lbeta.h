//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lbeta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_lgamma.h>

#ifndef MC_LBETA_H
#define MC_LBETA_H

#pragma mark - mc_lbeta -

static MC_TARGET_INLINE
float mc_lbetaf(float x, float y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (mc_fabsf(x) < MCLIMITS_EPSILONF || mc_fabsf(y) < MCLIMITS_EPSILONF) {
		return 0.0f;
	}
	const float a   = mc_lgammaf(x);
	const float b   = mc_lgammaf(y);
	const float apb = mc_lgammaf(x + y);
	return a + b - apb;
}

static MC_TARGET_INLINE
double mc_lbeta(double x, double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (mc_fabs(x) < MCLIMITS_EPSILON || mc_fabs(y) < MCLIMITS_EPSILON) {
		return 0.0;
	}
	const double a   = mc_lgamma(x);
	const double b   = mc_lgamma(y);
	const double apb = mc_lgamma(x + y);
	return a + b - apb;
}

static MC_TARGET_INLINE
long double mc_lbetal(long double x, long double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (mc_fabsl(x) < MCLIMITS_EPSILONL || mc_fabsl(y) < MCLIMITS_EPSILONL) {
		return 0.0L;
	}
	const long double a   = mc_lgammal(x);
	const long double b   = mc_lgammal(y);
	const long double apb = mc_lgammal(x + y);
	return a + b - apb;
}

#endif /* !MC_LBETA_H */

/* EOF */
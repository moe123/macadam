//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_beta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_lbeta.h>

#ifndef MC_BETA_H
#define MC_BETA_H

#pragma mark - mc_beta -

static MC_TARGET_INLINE
float mc_betaf(float x, float y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	const float lb = mc_lbetaf(x, y);
	if (mc_isnan(lb)) {
		return MCK_NAN;
	}
	return mc_expf(lb);
}

static MC_TARGET_INLINE
double mc_beta(double x, double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	const double lb = mc_lbeta(x, y);
	if (mc_isnan(lb)) {
		return MCK_NAN;
	}
	return mc_exp(lb);
}

static MC_TARGET_INLINE
long double mc_betal(long double x, long double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	const long double lb = mc_lbetal(x, y);
	if (mc_isnan(lb)) {
		return MCK_NAN;
	}
	return mc_expl(lb);
}

#endif /* !MC_BETA_H */

/* EOF */
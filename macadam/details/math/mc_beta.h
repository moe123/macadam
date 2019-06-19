//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_beta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lbeta.h>

#ifndef MC_BETA_H
#define MC_BETA_H

#pragma mark - mc_beta -

static MC_TARGET_INLINE
float mc_betaf(float x, float y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	const float lb = mc_lbetaf(x, y);
	if (::isnan(lb)) {
		return MCK_NAN;
	}
	return ::expf(lb);
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	const float lb = mc_lbetaf(x, y);
	if (isnan(lb)) {
		return MCK_NAN;
	}
	return expf(lb);
#	endif
}

static MC_TARGET_INLINE
double mc_beta(double x, double y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	const double lb = mc_lbeta(x, y);
	if (::isnan(lb)) {
		return MCK_NAN;
	}
	return ::exp(lb);
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	const double lb = mc_lbeta(x, y);
	if (isnan(lb)) {
		return MCK_NAN;
	}
	return exp(lb);
#	endif
}

static MC_TARGET_INLINE
long double mc_betal(long double x, long double y)
{
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isnan(y)) {
		return MCK_NAN;
	}
	const long double lb = mc_lbetal(x, y);
	if (::isnan(lb)) {
		return MCK_NAN;
	}
	return ::expl(lb);
#	else
	if (isnan(x) || isnan(y)) {
		return MCK_NAN;
	}
	const long double lb = mc_lbetal(x, y);
	if (isnan(lb)) {
		return MCK_NAN;
	}
	return expl(lb);
#	endif
}

#endif /* !MC_BETA_H */

/* EOF */
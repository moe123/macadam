//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp10m1m1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_exp2m1.h>
#include <macadam/details/math/mc_fabs.h>

#ifndef MC_EXP10M1_H
#define MC_EXP10M1_H

#pragma mark - mc_exp10m1 -

static MC_TARGET_INLINE float mc_exp10m1f(float x)
{
	if (x == 0.0f) {
		return 0.0f;
	}
	if (mc_fabsf(x) > 0.3f) {
		return mc_expf(x) - 1.0f;
	}
	return mc_exp2m1f(MCK_KF(MCK_LOG210Q) * x + MCK_KF(MCK_LOG210R) * x);
}

static MC_TARGET_INLINE double mc_exp10m1(double x)
{
	if (x == 0.0) {
		return 0.0;
	}
	if (mc_fabs(x) > 0.3) {
		return mc_exp(x) - 1.0;
	}
	return mc_exp2m1(MCK_K(MCK_LOG210Q) * x + MCK_K(MCK_LOG210R) * x);
}

static MC_TARGET_INLINE long double mc_exp10m1l(long double x)
{
	if (x == 0.0) {
		return 0.0;
	}
	if (mc_fabsl(x) > 0.3L) {
		return mc_expl(x) - 1.0L;
	}
	return mc_exp2m1(MCK_KL(MCK_LOG210Q) * x + MCK_KL(MCK_LOG210R) * x);
}

#endif /* !MC_EXP10M1_H */

/* EOF */
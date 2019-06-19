//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp10m1m1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp2m1.h>

#ifndef MC_EXP10M1_H
#define MC_EXP10M1_H

#pragma mark - mc_exp10m1 -

static MC_TARGET_INLINE float mc_exp10m1f(float x)
{
	if (x == 0.0f) {
		return 0.0f;
	}
#	if MC_TARGET_CPP98
	if (::fabsf(x) > 0.3f) {
		return ::expf(x) - 1.0f;
	}
#	else
	if (fabsf(x) > 0.3f) {
		return expf(x) - 1.0f;
	}
#	endif
	return mc_exp2m1f(MCK_KF(MCK_LOG210Q) * x + MCK_KF(MCK_LOG210R) * x);
}

static MC_TARGET_INLINE double mc_exp10m1(double x)
{
	if (x == 0.0) {
		return 0.0;
	}
#	if MC_TARGET_CPP98
	if (::fabs(x) > 0.3) {
		return ::exp(x) - 1.0;
	}
#	else
	if (fabs(x) > 0.3) {
		return exp(x) - 1.0;
	}
#	endif
	return mc_exp2m1(MCK_K(MCK_LOG210Q) * x + MCK_K(MCK_LOG210R) * x);
}

static MC_TARGET_INLINE long double mc_exp10m1l(long double x)
{
	if (x == 0.0) {
		return 0.0;
	}
#	if MC_TARGET_CPP98
	if (::fabsl(x) > 0.3L) {
		return ::expl(x) - 1.0L;
	}
#	else
	if (fabsl(x) > 0.3L) {
		return expl(x) - 1.0L;
	}
#	endif
	return mc_exp2m1(MCK_KL(MCK_LOG210Q) * x + MCK_KL(MCK_LOG210R) * x);
}

#endif /* !MC_EXP10M1_H */

/* EOF */
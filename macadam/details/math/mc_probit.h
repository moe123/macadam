//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_probit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isfinite.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_inverf.h>

#ifndef MC_PROBIT_H
#define MC_PROBIT_H

#pragma mark - mc_probit -

static MC_TARGET_INLINE float mc_probitf(float x)
{
	float y = mc_inverff(2.0f * x - 1.0f);
	if (!mc_isnan(y) && mc_isfinite(x)) {
		y *= MCK_KF(MCK_SQRT2);
	}
	return y;
}

static MC_TARGET_INLINE double mc_probit(double x)
{
	double y = mc_inverf(2.0 * x - 1.0);
	if (!mc_isnan(y) && mc_isfinite(x)) {
		y *= MCK_K(MCK_SQRT2);
	}
	return y;
}

static MC_TARGET_INLINE long double mc_probitl(long double x)
{
	long double y = mc_inverfl(2.0L * x - 1.0L);
	if (!mc_isnan(y) && mc_isfinite(x)) {
		y *= MCK_KL(MCK_SQRT2);
	}
	return y;
}

#endif /* !MC_PROBIT_H */

/* EOF */
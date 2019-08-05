//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fisval.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>

#ifndef MC_FISVAL_H
#define MC_FISVAL_H

#pragma mark - mc_fisval -

MC_TARGET_FUNC int mc_fisvalf(float x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return 0;
	}
	if (x < 0.0f && !(x < MCLIMITS_MINF)) {
		return 0;
	}
	if (x > 0.0f && !(x < MCLIMITS_MAXF)) {
		return 0;
	}
	return 1;
}

MC_TARGET_FUNC int mc_fisval(double x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return 0;
	}
	if (x < 0.0 && !(x < MCLIMITS_MIN)) {
		return 0;
	}
	if (x > 0.0 && !(x < MCLIMITS_MAX)) {
		return 0;
	}
	return 1;
}

MC_TARGET_FUNC int mc_fisvall(long double x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return 0;
	}
	if (x < 0.0L && !(x < MCLIMITS_MINL)) {
		return 0;
	}
	if (x > 0.0L && !(x < MCLIMITS_MAXL)) {
		return 0;
	}
	return 1;
}

#endif /* !MC_FISVAL_H */

/* EOF */
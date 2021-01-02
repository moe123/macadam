//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fisnear.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_FISNEAR_H
#define MC_FISNEAR_H

#pragma mark - mc_fisnear -

MC_TARGET_FUNC int mc_fisnearf(float x, float y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	if (x == y) {
		return 1;
	}
	return mc_fabsf(y - x) < (mc_cast(float, n) * MCLIMITS_EPSILONF) ? 1 : 0;
}

MC_TARGET_FUNC int mc_fisnear(double x, double y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	if (x == y) {
		return 1;
	}
	return mc_fabs(y - x) < (mc_cast(double, n) * MCLIMITS_EPSILON) ? 1 : 0;
}

MC_TARGET_FUNC int mc_fisnearl(long double x, long double y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	if (x == y) {
		return 1;
	}
	return mc_fabsl(y - x) < (mc_cast(long double, n) * MCLIMITS_EPSILONL) ? 1 : 0;
}

#endif /* !MC_FISNEAR_H */

/* EOF */
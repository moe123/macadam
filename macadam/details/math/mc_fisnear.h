//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fisnear.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_nextafter.h>

#ifndef MC_FISNEAR_H
#define MC_FISNEAR_H

#pragma mark - mc_fisnear -

MC_TARGET_FUNC int mc_fisnearf(float x, float y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	const float a0 = x - (x - mc_nextafterf(x, -MCLIMITS_MAXF)) * mc_cast(float, n);
	const float a1 = x + (mc_nextafterf(x, MCLIMITS_MAXF) - x)  * mc_cast(float, n);
	return a0 <= y && a1 >= y ? 1 : 0;
}

MC_TARGET_FUNC int mc_fisnear(double x, double y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	const double a0 = x - (x - mc_nextafter(x, -MCLIMITS_MAX)) * mc_cast(double, n);
	const double a1 = x + (mc_nextafter(x, MCLIMITS_MAX) - x)  * mc_cast(double, n);
	return a0 <= y && a1 >= y ? 1 : 0;
}

MC_TARGET_FUNC int mc_fisnearl(long double x, long double y, int n)
{
//!# Returning if two numbers are near-equality by n epsilon steps.
	if (n < 1) {
		return -1;
	}
	const long double a0 = x - (x - mc_nextafterl(x, -MCLIMITS_MAXL)) * mc_cast(long double, n);
	const long double a1 = x + (mc_nextafterl(x, MCLIMITS_MAXL) - x)  * mc_cast(long double, n);
	return a0 <= y && a1 >= y ? 1 : 0;
}

#endif /* !MC_FISNEAR_H */

/* EOF */
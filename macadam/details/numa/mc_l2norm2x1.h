//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_l2norm2x1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_NORM2X1_H
#define MC_NORM2X1_H

#pragma mark - mc_l2norm2x1 -

MC_TARGET_PROC float mc_l2norm2x1f(int m, int n, int j, const float a[2])
{
	if (m < 2 || n < 1) {
		return MCK_NAN;
	}
	return mc_sqrtf(mc_raise2f(a[j]) + mc_raise2f(a[n + j]));
}

MC_TARGET_PROC double mc_l2norm2x1ff(int m, int n, int j, const float a[2])
{
	if (m < 2 || n < 1) {
		return MCK_NAN;
	}
	return mc_sqrt(mc_raise2(mc_cast(double, a[j])) + mc_raise2(mc_cast(double, a[n + j])));
}

MC_TARGET_PROC double mc_l2norm2x1(int m, int n, int j, const double a[2])
{
	if (m < 2 || n < 1) {
		return MCK_NAN;
	}
	return mc_sqrt(mc_raise2(a[j]) + mc_raise2(a[n + j]));
}

MC_TARGET_PROC long double mc_l2norm2x1l(int m, int n, int j, const long double a[2])
{
	if (m < 2 || n < 1) {
		return MCK_NAN;
	}
	return mc_sqrtl(mc_raise2l(a[j]) + mc_raise2l(a[n + j]));
}

#endif /* !MC_NORM2X1_H */

/* EOF */
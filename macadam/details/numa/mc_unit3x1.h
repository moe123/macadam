//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unit3x1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_norm3x1.h>

#ifndef MC_UNIT3X1_H
#define MC_UNIT3X1_H

#pragma mark - mc_unit3x1 -

MC_TARGET_FUNC void mc_unit3x1f(int m, int n, int j, float a[3])
{
	const float scale = 1.0f / mc_norm3x1f(m, n, j, a);
	a[j]              = a[j] * scale;
	a[n + j]          = a[n + j] * scale;
	a[(n * 2) + j]    = a[(n * 2) + j] * scale;
}

MC_TARGET_FUNC void mc_unit3x1(int m, int n, int j, double a[3])
{
	const double scale = 1.0 / mc_norm3x1(m, n, j, a);
	a[j]               = a[j] * scale;
	a[n + j]           = a[n + j] * scale;
	a[(n * 2) + j]     = a[(n * 2) + j] * scale;
}

MC_TARGET_FUNC void mc_unit3x1l(int m, int n, int j, long double a[3])
{
	const long double scale = 1.0L / mc_norm3x1l(m, n, j, a);
	a[j]                    = a[j] * scale;
	a[n + j]                = a[n + j] * scale;
	a[(n * 2) + j]          = a[(n * 2) + j] * scale;
}

#endif /* !MC_UNIT3X1_H */

/* EOF */
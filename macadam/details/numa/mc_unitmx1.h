//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unitmx1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_l2normmx1.h>

#ifndef MC_UNITMX1_H
#define MC_UNITMX1_H

#pragma mark - mc_unitmx1 -

MC_TARGET_FUNC void mc_unitmx1f(int m, int n, int j, float * a)
{
	const float scale = 1.0f / mc_l2normmx1f(m, n, j, a);
	int i             = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = a[(n * i) + j] * scale;
	}
}

MC_TARGET_FUNC void mc_unitmx1(int m, int n, int j, double * a)
{
	const double scale = 1.0 / mc_l2normmx1(m, n, j, a);
	int i              = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = a[(n * i) + j] * scale;
	}
}

MC_TARGET_FUNC void mc_unitmx1l(int m, int n, int j, long double * a)
{
	const long double scale = 1.0L / mc_l2normmx1l(m, n, j, a);
	int i                   = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = a[(n * i) + j] * scale;
	}
}

#endif /* !MC_UNITMX1_H */

/* EOF */
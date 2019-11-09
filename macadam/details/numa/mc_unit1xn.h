//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unit1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_l2norm1xn.h>

#ifndef MC_UNIT1XN_H
#define MC_UNIT1XN_H

#pragma mark - mc_unit1xn -

MC_TARGET_FUNC void mc_unit1xnf(int n, float * x)
{
	const float scale = 1.0f / mc_l2norm1xnf(x);
	int i             = 0;
	for (; i < n; i++) {
		x[i] = x[i] * scale;
	}
}

MC_TARGET_FUNC void mc_unit1xn(int n, double * x)
{
	const double scale = 1.0 / mc_l2norm1xn(x);
	int i              = 0;
	for (; i < n; i++) {
		x[i] = x[i] * scale;
	}
}

MC_TARGET_FUNC void mc_unit1xnl(int n, long double * x)
{
	const long double scale = 1.0L / mc_l2norm1xnl(x);
	int i                   = 0;
	for (; i < n; i++) {
		x[i] = x[i] * scale;
	}
}

#endif /* !MC_UNIT1XN_H */

/* EOF */
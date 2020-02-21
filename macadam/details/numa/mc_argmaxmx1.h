//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argmaxmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_minmaxmx1.h>

#ifndef MC_ARGMAXMX1_H
#define MC_ARGMAXMX1_H

#pragma mark - mc_argmaxmx1 -

MC_TARGET_FUNC int mc_argmaxmx1f(int m, int n, int j, const float * a)
{
	int q;
	float max;
	mc_minmaxmx1f(m, n, j, a, NULL, &max, NULL, &q);
	return q;
}

MC_TARGET_FUNC int mc_argmaxmx1(int m, int n, int j, const double * a)
{
	int q;
	double max;
	mc_minmaxmx1(m, n, j, a, NULL, &max, NULL, &q);
	return q;
}

MC_TARGET_FUNC int mc_argmaxmx1l(int m, int n, int j, const long double * a)
{
	int q;
	long double max;
	mc_minmaxmx1l(m, n, j, a, NULL, &max, NULL, &q);
	return q;
}

#endif /* !MC_ARGMAXMX1_H */

/* EOF */
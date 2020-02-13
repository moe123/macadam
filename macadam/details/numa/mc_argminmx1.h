//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argminmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_minmaxmx1.h>

#ifndef MC_ARGMINMX1_H
#define MC_ARGMINMX1_H

#pragma mark - mc_argminmx1 -

MC_TARGET_FUNC int mc_argminmx1f(int m, int n, int j, const float * a)
{
	int p;
	float min;
	mc_minmaxmx1f(m, n, j, a, &min, NULL, &p,  NULL);
	return p;
}

MC_TARGET_FUNC int mc_argminmx1(int m, int n, int j, const double * a)
{
	int p;
	double min;
	mc_minmaxmx1(m, n, j, a, &min, NULL, &p,  NULL);
	return p;
}

MC_TARGET_FUNC int mc_argminmx1l(int m, int n, int j, const long double * a)
{
	int p;
	long double min;
	mc_minmaxmx1l(m, n, j, a, &min, NULL, &p,  NULL);
	return p;
}

#endif /* !MC_ARGMINMX1_H */

/* EOF */
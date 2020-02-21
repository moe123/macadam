//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argmin1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_minmax1xn.h>

#ifndef MC_ARGMIN1XN_H
#define MC_ARGMIN1XN_H

#pragma mark - mc_argmin1xn -

MC_TARGET_FUNC int mc_argmin1xnf(int n, const float * x)
{
	int p;
	float min;
	mc_minmax1xnf(n, x, &min, NULL, &p, NULL);
	return p;
}

MC_TARGET_FUNC int mc_argmin1xn(int n, const double * x)
{
	int p;
	double min;
	mc_minmax1xn(n, x, &min, NULL, &p, NULL);
	return p;
}

MC_TARGET_FUNC long double mc_argmin1xnl(int n, const long double * x)
{
	int p;
	long double min;
	mc_minmax1xnl(n, x, &min, NULL, &p, NULL);
	return p;
}

#endif /* !MC_MIN1XN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argmax1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_minmax1xn.h>

#ifndef MC_ARGMAX1XN_H
#define MC_ARGMAX1XN_H

#pragma mark - mc_argmax1xn -

MC_TARGET_FUNC int mc_argmax1xnf(int n, const float * x)
{
	int q;
	float max;
	mc_minmax1xnf(n, x, NULL, &max, NULL, &q);
	return q;
}

MC_TARGET_FUNC int mc_argmax1xn(int n, const double * x)
{
	int q;
	double max;
	mc_minmax1xn(n, x, NULL, &max, NULL, &q);
	return q;
}

MC_TARGET_FUNC int mc_argmax1xnl(int n, const long double * x)
{
	int q;
	long double max;
	mc_minmax1xnl(n, x, NULL, &max, NULL, &q);
	return q;
}

#endif /* !MC_ARGMAX1XN_H */

/* EOF */
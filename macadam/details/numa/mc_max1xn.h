//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_max1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_minmax1xn.h>

#ifndef MC_MAX1XN_H
#define MC_MAX1XN_H

#pragma mark - mc_max1xn -

MC_TARGET_FUNC float mc_max1xnf(int n, const float * x)
{
	float max;
	mc_minmax1xnf(n, x, NULL, &max, NULL, NULL);
	return max;
}

MC_TARGET_FUNC double mc_max1xnff(int n, const float * x)
{
	double max;
	mc_minmax1xnff(n, x, NULL, &max, NULL, NULL);
	return max;
}

MC_TARGET_FUNC double mc_max1xn(int n, const double * x)
{
	double max;
	mc_minmax1xn(n, x, NULL, &max, NULL, NULL);
	return max;
}

MC_TARGET_FUNC long double mc_max1xnl(int n, const long double * x)
{
	long double max;
	mc_minmax1xnl(n, x, NULL, &max, NULL, NULL);
	return max;
}

#endif /* !MC_MAX1XN_H */

/* EOF */
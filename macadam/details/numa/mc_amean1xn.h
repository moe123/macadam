//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_amean1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mean1xn.h>

#ifndef MC_AMEAN1XN_H
#define MC_AMEAN1XN_H

#pragma mark - mc_amean1xn -

MC_TARGET_FUNC float mc_amean1xnf(int n, const float * x, int b)
{
	return mc_mean1xnf(n, x, b, 4);
}

MC_TARGET_FUNC double mc_amean1xnff(int n, const float * x, int b)
{
	return mc_mean1xnff(n, x, b, 4);
}

MC_TARGET_FUNC double mc_amean1xn(int n, const double * x, int b)
{
	return mc_mean1xn(n, x, b, 4);
}

MC_TARGET_FUNC long double mc_amean1xnl(int n, const long double * x, int b)
{
	return mc_mean1xnl(n, x, b, 4);
}

#endif /* !MC_AMEAN1XN_H */

/* EOF */
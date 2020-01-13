//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asum1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_sum1xn.h>

#ifndef MC_ASUM1XN_H
#define MC_ASUM1XN_H

#pragma mark - mc_asum1xn -

MC_TARGET_FUNC float mc_asum1xnf(int n, const float * x)
{
	return mc_sum1xnf(n, x, 4);
}

MC_TARGET_FUNC double mc_asum1xnff(int n, const float * x)
{
	return mc_sum1xnff(n, x, 4);
}

MC_TARGET_FUNC double mc_asum1xn(int n, const double * x)
{
	return mc_sum1xn(n, x, 4);
}

MC_TARGET_FUNC long double mc_asum1xnl(int n, const long double * x)
{
	return mc_sum1xnl(n, x, 4);
}

#endif /* !MC_ASUM1XN_H */

/* EOF */
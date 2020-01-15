//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_l1norm1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_asum21xn.h>

#ifndef MC_L1NORM1XN_H
#define MC_L1NORM1XN_H

#pragma mark - mc_l1norm1xn -

MC_TARGET_FUNC float mc_l1norm1xnf(int n, const float * x)
{
//!# Requires x[1 x n]. Returning the l1-norm of x.
	return mc_asum21xnf(n, x);
}

MC_TARGET_FUNC double mc_l1norm1xnff(int n, const float * x)
{
//!# Requires x[1 x n]. Returning the l1-norm of x.
	return mc_asum21xnff(n, x);
}

MC_TARGET_FUNC double mc_l1norm1xn(int n, const double * x)
{
//!# Requires x[1 x n]. Returning the l1-norm of x.
	return mc_asum21xn(n, x);
}

MC_TARGET_FUNC long double mc_l1norm1xnl(int n, const long double * x)
{
//!# Requires x[1 x n]. Returning the l1-norm of x.
	return mc_asum21xnl(n, x);
}

#endif /* !MC_L1NORM1XN_H */

/* EOF */
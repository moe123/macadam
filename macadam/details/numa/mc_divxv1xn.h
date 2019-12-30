//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_divxv1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulxv1xn.h>

#ifndef MC_DIVXV1XN_H
#define MC_DIVXV1XN_H

#pragma mark - mc_divxv1xn -

MC_TARGET_FUNC void mc_divxv1xnf(int n, float * u, const float * x, float v)
{
//!# u_i=x_i/v
	const float w = 1.0f / v;
	mc_mulxv1xnf(n, u, x, w);
}

MC_TARGET_FUNC void mc_divxv1xnff(int n, double * u, const float * x, float v)
{
//!# u_i=x_i/v
	const float w = 1.0f / v;
	mc_mulxv1xnff(n, u, x, w);
}

MC_TARGET_FUNC void mc_divxv1xn(int n, double * u, const double * x, double v)
{
//!# u_i=x_i/v
	const double w = 1.0 / v;
	mc_mulxv1xn(n, u, x, w);
}

MC_TARGET_FUNC void mc_divxv1xnl(int n, long double * u, const long double * x, long double v)
{
//!# u_i=x_i/v
	const long double w = 1.0L / v;
	mc_mulxv1xnl(n, u, x, w);
}

#endif /* !MC_DIVXV1XN_H */

/* EOF */
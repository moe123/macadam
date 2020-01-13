//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulaxnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulaxmxn.h>

#ifndef MC_MULAXNXN_H
#define MC_MULAXNXN_H

#pragma mark - mc_mulaxnxn -

MC_TARGET_FUNC void mc_mulaxnxnf(int n, float * restrict b, const float * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxnf(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulaxnxnff(int n, double * restrict b, const float * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxnff(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulaxnxnfd(int n, double * restrict b, const float * a, const double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxnfd(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulaxnxndf(int n, double * restrict b, const double * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxndf(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulaxnxn(int n, double * restrict b, const double * a, const double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxn(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulaxnxnl(int n, long double * restrict b, const long double * a, const long double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a*x
	mc_mulaxmxnl(n, n, b, a, x);
}

#endif /* !MC_MULAXNXN_H */

/* EOF */
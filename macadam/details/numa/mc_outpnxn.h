//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_outpnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_outpmxn.h>

#ifndef MC_OUTPNXN_H
#define MC_OUTPNXN_H

#pragma mark - mc_outpnxn -

MC_TARGET_FUNC void mc_outpnxnf(int n, float * a, const float * x, const float * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxnf(n, n, a, x, y);
}

MC_TARGET_FUNC void mc_outpnxnff(int n, double * a, const float * x, const float * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxnff(n, n, a, x, y);
}

MC_TARGET_FUNC void mc_outpnxnfd(int n, double * a, const float * x, const double * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxnfd(n, n, a, x, y);
}

MC_TARGET_FUNC void mc_outpnxndf(int n, double * a, const double * x, const float * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxndf(n, n, a, x, y);
}

MC_TARGET_FUNC void mc_outpnxn(int n, double * a, const double * x, const double * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxn(n, n, a, x, y);
}

MC_TARGET_FUNC void mc_outpnxnl(int n, long double * a, const long double * x, const long double * y)
{
//!# Requires a[n x n], x[n x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	mc_outpmxnl(n, n, a, x, y);
}

#endif /* !MC_OUTPNXN_H */

/* EOF */
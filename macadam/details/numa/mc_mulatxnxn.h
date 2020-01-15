//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulatxnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulatxmxn.h>

#ifndef MC_MULATXNXN_H
#define MC_MULATXNXN_H

#pragma mark - mc_mulatxnxn -

MC_TARGET_FUNC void mc_mulatxnxnf(int n, float * restrict b, const float * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxnf(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulatxnxnff(int n, double * restrict b, const float * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxnff(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulatxnxnfd(int n, double * restrict b, const float * a, const double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxnfd(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulatxnxndf(int n, double * restrict b, const double * a, const float * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxndf(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulatxnxn(int n, double * restrict b, const double * a, const double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxn(n, n, b, a, x);
}

MC_TARGET_FUNC void mc_mulatxnxnl(int n, long double * restrict b, const long double * a, const long double * x)
{
//!# Requires b[n x 1], a[n * n] and x[n x 1].
//!# b=a'*x
	mc_mulatxmxnl(n, n, b, a, x);
}

#endif /* !MC_MULATXNXN_H */

/* EOF */
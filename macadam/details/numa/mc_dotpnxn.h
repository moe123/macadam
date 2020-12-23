//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotpnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_dotpmxn.h>

#ifndef MC_DOTPNXN_H
#define MC_DOTPNXN_H

#pragma mark - mc_dotpnxn -

MC_TARGET_FUNC void mc_dotpnxnf(const int n, float * restrict c, const float * a, const float * b, int d, int f)
{
	mc_dotpmxnf(n, n, n, c, a, b, d, f);
}

MC_TARGET_FUNC void mc_dotpnxn(const int n, double * restrict c, const double * a, const double * b, int d, int f)
{
	mc_dotpmxn(n, n, n, c, a, b, d, f);
}

MC_TARGET_FUNC void mc_dotpnxnl(const int n, long double * restrict c, const long double * a, const long double * b, int d, int f)
{
	mc_dotpmxnl(n, n, n, c, a, b, d, f);
}

#endif /* !MC_DOTPNXN_H */

/* EOF */
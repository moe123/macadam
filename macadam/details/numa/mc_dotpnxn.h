//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotpnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_dotpmxn.h>

#ifndef MC_DOTPNXN_H
#define MC_DOTPNXN_H

#pragma mark - mc_dotpnxn -

MC_TARGET_FUNC void mc_dotpnxnf(int n, int p, float * restrict c, const float * a, const float * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb and m=n.
	mc_dotpmxnf(n, n, p, c, a, b);
}

MC_TARGET_FUNC void mc_dotpnxnff(int n, int p, double * c, const float * a, const float * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb and m=n.
	mc_dotpmxnff(n, n, p, c, a, b);
}

MC_TARGET_FUNC void mc_dotpnxn(int n, int p, double * restrict c, const double * a, const double * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb and m=n.
	mc_dotpmxn(n, n, p, c, a, b);
}

MC_TARGET_FUNC void mc_dotpnxnl(int n, int p, long double * restrict c, const long double * a, const long double * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb and m=n.
	mc_dotpmxnl(n, n, p, c, a, b);
}

#endif /* !MC_DOTPNXN_H */

/* EOF */
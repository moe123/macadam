//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trspnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trspmxn.h>

#ifndef MC_TRSPNXN_H
#define MC_TRSPNXN_H

#pragma mark - mc_trspnxn -

MC_TARGET_FUNC void mc_trspnxnf(int n, const float * a, float * b)
{
	mc_trspmxnf(n, n, a, b);
}

MC_TARGET_FUNC void mc_trspnxn(int n, const double * a, double * b)
{
	mc_trspmxn(n, n, a, b);
}

MC_TARGET_FUNC void mc_trspnxnl(int n, const long double * a, long double * b)
{
	mc_trspmxnl(n, n, a, b);
}

#endif /* !MC_TRSPNXN_H */

/* EOF */
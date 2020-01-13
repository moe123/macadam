//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trspnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trspmxn.h>

#ifndef MC_TRSPNXN_H
#define MC_TRSPNXN_H

#pragma mark - mc_trspnxn -

MC_TARGET_FUNC void mc_trspnxnf(int n, float * at, const float * a)
{
	mc_trspmxnf(n, n, at, a);
}

MC_TARGET_FUNC void mc_trspnxn(int n, double * at, const double * a)
{
	mc_trspmxn(n, n, at, a);
}

MC_TARGET_FUNC void mc_trspnxnl(int n, long double * at, const long double * a)
{
	mc_trspmxnl(n, n, at, a);
}

#endif /* !MC_TRSPNXN_H */

/* EOF */
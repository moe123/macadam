//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_onesnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_ones1xn.h>

#ifndef MC_ONESNXN_H
#define MC_ONESNXN_H

#pragma mark - mc_onesnxn -

MC_TARGET_FUNC void mc_onesnxnf(int n, float * a)
{
	mc_ones1xnf(n * n, a);
}

MC_TARGET_FUNC void mc_onesnxn(int n, double * a)
{
	mc_ones1xn(n * n, a);
}

MC_TARGET_FUNC void mc_onesnxnl(int n, long  double * a)
{
	mc_ones1xnl(n * n, a);
}

#endif /* !MC_ONESNXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rescalenxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_rescalemxn.h>

#ifndef MC_RESCALENXN_H
#define MC_RESCALENXN_H

#pragma mark - mc_rescalenxn -

MC_TARGET_FUNC void mc_rescalenxnf(int m, int n, float * c, float a, float b)
{
	mc_rescalemxnf(n, n, c, a,  b);
}

MC_TARGET_FUNC void mc_rescalenxn(int m, int n, double * c, double a, double b)
{
	mc_rescalemxn(n, n, c, a,  b);
}

MC_TARGET_FUNC void mc_rescalenxnl(int m, int n, long double * c, long double a, long double b)
{
	mc_rescalemxnl(n, n, c, a,  b);
}

#endif /* !MC_RESCALENXN_H */

/* EOF */
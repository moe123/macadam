//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_copymxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_copy1xn.h>

#ifndef MC_COPYMXN_H
#define MC_COPYMXN_H

#pragma mark - mc_copymxn -

MC_TARGET_FUNC void mc_copymxnf(int m, int n, float * b, const float * a)
{
	mc_copy1xnf(m * n, b, a);
}

MC_TARGET_FUNC void mc_copymxnff(int m, int n, double * b, const float * a)
{
	mc_copy1xnff(m * n, b, a);
}

MC_TARGET_FUNC void mc_copymxn(int m, int n, double * b, const double * a)
{
	mc_copy1xn(m * n, b, a);
}

MC_TARGET_FUNC void mc_copymxnl(int m, int n, long double * b, const long double * a)
{
	mc_copy1xnl(m * n, b, a);
}

#endif /* !MC_COPYMXN_H */

/* EOF */
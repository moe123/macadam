//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rescalemxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_rescale1xn.h>

#ifndef MC_RESCALEMXN_H
#define MC_RESCALEMXN_H

#pragma mark - mc_rescalemxn -

MC_TARGET_FUNC void mc_rescalemxnf(int m, int n, float * c, float a, float b)
{
	mc_rescale1xnf(m * n, c, a,  b);
}

MC_TARGET_FUNC void mc_rescalemxn(int m, int n, double * c, double a, double b)
{
	mc_rescale1xn(m * n, c, a,  b);
}

MC_TARGET_FUNC void mc_rescalemxnl(int m, int n, long double * c, long double a, long double b)
{
	mc_rescale1xnl(m * n, c, a,  b);
}

#endif /* !MC_RESCALEMXN_H */

/* EOF */
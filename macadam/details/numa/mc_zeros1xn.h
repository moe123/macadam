//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zeros1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/details/mc_mem.h>

#ifndef MC_ZEROS1XN_H
#define MC_ZEROS1XN_H

#pragma mark - mc_zeros1xn -

MC_TARGET_FUNC void mc_zeros1xnf(int n, float * x)
{
	mc_base_memzero_type(float, n, x);
}

MC_TARGET_FUNC void mc_zeros1xn(int n, double * x)
{
	mc_base_memzero_type(double, n, x);
}

MC_TARGET_FUNC void mc_zeros1xnl(int n, long double * x)
{
	mc_base_memzero_type(long double, n, x);
}

#endif /* !MC_ZEROS1XN_H */

/* EOF */
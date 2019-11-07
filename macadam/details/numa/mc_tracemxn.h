//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tracemxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_minmag.h>
#include <macadam/details/numa/mc_tracenxn.h>

#ifndef MC_TRACEMXN_H
#define MC_TRACEMXN_H

#pragma mark - mc_tracemxn -

MC_TARGET_FUNC float mc_tracemxnf(int m, int n, const float * a)
{
	return mc_tracenxnf(mc_minmag(m, n), a);
}

MC_TARGET_FUNC double mc_tracemxn(int m, int n, const double * a)
{
	return mc_tracenxn(mc_minmag(m, n), a);
}

MC_TARGET_FUNC long double mc_tracemxnl(int m, int n, const long double * a)
{
	return mc_tracenxnl(mc_minmag(m, n), a);
}

#endif /* !MC_TRACEMXN_H */

/* EOF */
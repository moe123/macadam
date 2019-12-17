//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qrmgsnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthomxn.h>

#ifndef MC_QRMGSNXN_H
#define MC_QRMGSNXN_H

#pragma mark - mc_qrmgsnxn -

int mc_qrmgsnxnf(int n, const float * a, float * q, float * restrict r)
{
	return mc_orthomxnf(n, n, a, MCLIMITS_TINYF, q, r);
}

int mc_qrmgsnxnff(int n, const float * a, double * q, double * restrict r)
{
	return mc_orthomxnff(n, n, a, MCLIMITS_TINYF, q, r);
}

int mc_qrmgsnxn(int n, const double * a, double * q, double * restrict r)
{
	return mc_orthomxn(n, n, a, MCLIMITS_TINY, q, r);
}

int mc_qrmgsnxnl(int n, const long double * a, long double * q, long double * restrict r)
{
	return mc_orthomxnl(n, n, a, MCLIMITS_TINYL, q, r);
}

#endif /* !MC_QRMGSNXN_H */

/* EOF */
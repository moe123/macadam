//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_orthonxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthomxn.h>

#ifndef MC_ORTHONXN_H
#define MC_ORTHONXN_H

#pragma mark - mc_orthonxn -

int mc_orthonxnf(int n, const float * a, float tol, float * q, float * restrict r)
{
	return mc_orthomxnf(n, n, a, tol, q, r);
}

int mc_orthonxnff(int n, const float * a, float tol, double * q, double * restrict r)
{
	return mc_orthomxnff(n, n, a, tol, q, r);
}

int mc_orthonxn(int n, const double * a, double tol, double * q, double * restrict r)
{
	return mc_orthomxn(n, n, a, tol, q, r);
}

int mc_orthonxnl(int n, const long double * a, long double tol, long double * q, long double * restrict r)
{
	return mc_orthomxnl(n, n, a, tol, q, r);
}

#endif /* !MC_ORTHONXN_H */

/* EOF */
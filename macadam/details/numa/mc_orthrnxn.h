//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_orthrnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthrmxn.h>

#ifndef MC_ORTHRNXN_H
#define MC_ORTHRNXN_H

#pragma mark - mc_orthrnxn -

MC_TARGET_FUNC int mc_orthrnxnf(const int n, const float * a, float tol, float * q, float * restrict r, float * restrict w, int * pvi)
{
//!# A and Q may be the same. Forming a orthr-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrmxnf(n, n, a, tol, q, r, w, pvi);
}

MC_TARGET_FUNC int mc_orthrnxnff(const int n, const float * a, float tol, double * q, double * restrict r, double * restrict w, int * pvi)
{
//!# Forming a orthr-normalized basis Q of a square
//!# matrix using Modified Gram-Schmidt method.
	return mc_orthrmxnff(n, n, a, tol, q, r, w, pvi);
}

MC_TARGET_FUNC int mc_orthrnxn(const int n, const double * a, double tol, double * q, double * restrict r, double * restrict w, int * pvi)
{
//!# A and Q may be the same. Forming a orthr-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrmxn(n, n, a, tol, q, r, w, pvi);
}

MC_TARGET_FUNC int mc_orthrnxnl(const int n, const long double * a, long double tol, long double * q, long double * restrict r, long double * restrict w, int * pvi)
{
//!# A and Q may be the same. Forming a orthr-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrmxnl(n, n, a, tol, q, r, w, pvi);
}

#endif /* !MC_ORTHRNXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_orthonxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthomxn.h>

#ifndef MC_ORTHONXN_H
#define MC_ORTHONXN_H

#pragma mark - mc_orthonxn -

MC_TARGET_FUNC int mc_orthonxnf(int n, const float * a, float tol, float * q, float * restrict r)
{
//!# A and Q may be the same. Forming a ortho-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthomxnf(n, n, a, tol, q, r);
}

MC_TARGET_FUNC int mc_orthonxnff(int n, const float * a, float tol, double * q, double * restrict r)
{
//!# Forming a ortho-normalized basis Q of a square
//!# matrix using Modified Gram-Schmidt method.
	return mc_orthomxnff(n, n, a, tol, q, r);
}

MC_TARGET_FUNC int mc_orthonxn(int n, const double * a, double tol, double * q, double * restrict r)
{
//!# A and Q may be the same. Forming a ortho-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthomxn(n, n, a, tol, q, r);
}

MC_TARGET_FUNC int mc_orthonxnl(int n, const long double * a, long double tol, long double * q, long double * restrict r)
{
//!# A and Q may be the same. Forming a ortho-normalized basis Q
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthomxnl(n, n, a, tol, q, r);
}

#endif /* !MC_ORTHONXN_H */

/* EOF */
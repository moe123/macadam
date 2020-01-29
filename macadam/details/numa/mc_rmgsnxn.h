//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rmgsnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthrnxn.h>

#ifndef MC_RMGSNXN_H
#define MC_RMGSNXN_H

#pragma mark - mc_rmgsnxn -

MC_TARGET_FUNC int mc_rmgsnxnf(int n, const float * a, float * q, float * restrict r, float * restrict w, int * pv)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrnxnf(n, a, MCLIMITS_TINYF, q, r , w, pv);
}

MC_TARGET_FUNC int mc_rmgsnxnff(int n, const float * a, double * q, double * restrict r, double * restrict w, int * pv)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# Performing a QR decomposition of a square matrix using
//!# Modified Gram-Schmidt method.
	return mc_orthrnxnff(n, a, MCLIMITS_TINYF, q, r , w, pv);
}

MC_TARGET_FUNC int mc_rmgsnxn(int n, const double * a, double * q, double * restrict r, double * restrict w, int * pv)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrnxn(n, a, MCLIMITS_TINY, q, r , w, pv);
}

MC_TARGET_FUNC int mc_rmgsnxnl(int n, const long double * a, long double * q, long double * restrict r, long double * restrict w, int * pv)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthrnxnl(n, a, MCLIMITS_TINYL, q, r , w, pv);
}

#endif /* !MC_RMGSNXN_H */

/* EOF */
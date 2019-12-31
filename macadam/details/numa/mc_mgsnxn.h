//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mgsnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthonxn.h>

#ifndef MC_MGSNXN_H
#define MC_MGSNXN_H

#pragma mark - mc_mgsnxn -

MC_TARGET_FUNC int mc_mgsnxnf(int n, const float * a, float * q, float * restrict r)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthonxnf(n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_mgsnxnff(int n, const float * a, double * q, double * restrict r)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# Performing a QR decomposition of a square matrix using
//!# Modified Gram-Schmidt method.
	return mc_orthonxnff(n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_mgsnxn(int n, const double * a, double * q, double * restrict r)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthonxn(n, a, MCLIMITS_TINY, q, r);
}

MC_TARGET_FUNC int mc_mgsnxnl(int n, const long double * a, long double * q, long double * restrict r)
{
//!# Requires a[n x n], q[n x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# of a square matrix using Modified Gram-Schmidt method.
	return mc_orthonxnl(n, a, MCLIMITS_TINYL, q, r);
}

#endif /* !MC_MGSNXN_H */

/* EOF */
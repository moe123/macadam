//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rmgsmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthrmxn.h>

#ifndef MC_RMGSMXN_H
#define MC_RMGSMXN_H

#pragma mark - mc_rmgsmxn -

MC_TARGET_FUNC int mc_rmgsmxnf(int m, int n, const float * a, float * q, float * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthrmxnf(m, n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_rmgsmxnff(int m, int n, const float * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# Performing a QR decomposition using Modified Gram-Schmidt method.
	return mc_orthrmxnff(m, n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_rmgsmxn(int m, int n, const double * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthrmxn(m, n, a, MCLIMITS_TINY, q, r);
}

MC_TARGET_FUNC int mc_rmgsmxnl(int m, int n, const long double * a, long double * q, long double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthrmxnl(m, n, a, MCLIMITS_TINYL, q, r);
}

#endif /* !MC_RMGSMXN_H */

/* EOF */
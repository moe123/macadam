//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mgsmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthomxn.h>

#ifndef MC_MGSMXN_H
#define MC_MGSMXN_H

#pragma mark - mc_mgsmxn -

MC_TARGET_FUNC int mc_mgsmxnf(int m, int n, const float * a, float * q, float * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m <= n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxnf(m, n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_mgsmxnff(int m, int n, const float * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m <= n.
//!# Performing a QR decomposition using Modified Gram-Schmidt method.
	return mc_orthomxnff(m, n, a, MCLIMITS_TINYF, q, r);
}

MC_TARGET_FUNC int mc_mgsmxn(int m, int n, const double * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m <= n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxn(m, n, a, MCLIMITS_TINY, q, r);
}

MC_TARGET_FUNC int mc_mgsmxnl(int m, int n, const long double * a, long double * q, long double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m <= n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxnl(m, n, a, MCLIMITS_TINYL, q, r);
}

#endif /* !MC_MGSMXN_H */

/* EOF */
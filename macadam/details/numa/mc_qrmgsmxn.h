//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qrmgsmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_orthomxn.h>

#ifndef MC_QRMGSMXN_H
#define MC_QRMGSMXN_H

#pragma mark - mc_qrmgsmxn -

int mc_qrmgsmxnf(int m, int n, const float * a, float * q, float * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxnf(m, n, a, MCLIMITS_TINYF, q, r);
}

int mc_qrmgsmxnff(int m, int n, const float * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# Performing a QR decomposition using Modified Gram-Schmidt method.
	return mc_orthomxnff(m, n, a, MCLIMITS_TINYF, q, r);
}

int mc_qrmgsmxn(int m, int n, const double * a, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxn(m, n, a, MCLIMITS_TINY, q, r);
}

int mc_qrmgsmxnl(int m, int n, const long double * a, long double * q, long double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] where 1 < m < n.
//!# A and Q may be the same. Performing a QR decomposition
//!# using Modified Gram-Schmidt method.
	return mc_orthomxnl(m, n, a, MCLIMITS_TINYL, q, r);
}

#endif /* !MC_QRMGSMXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_centernxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_centermxn.h>

#ifndef MC_CENTERNXN_H
#define MC_CENTERNXN_H

#pragma mark - mc_centernxn -

MC_TARGET_FUNC void mc_centernxnf(int n, float * c, const float * a, int f)
{
//!# Requires c[n x n] and a[n x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
//!# f=0: no scaling.
//!# f=1: standard deviations scaling.
//!# f=2: root mean square scaling and second moment.
	mc_centermxnf(n, n, c, a, f);
}

MC_TARGET_FUNC void mc_centernxnff(int n, double * c, const float * a, int f)
{
//!# Requires c[n x n] and a[n x n] where 1 < n <= m. Centering
//!# A matrix to its column mean.
//!# f=0: no scaling.
//!# f=1: standard deviations scaling.
//!# f=2: root mean square scaling and second moment.
	mc_centermxnff(n, n, c, a, f);
}

MC_TARGET_FUNC void mc_centernxn(int n, double * c, const double * a, int f)
{
//!# Requires c[n x n] and a[n x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
//!# f=0: no scaling.
//!# f=1: standard deviations scaling.
//!# f=2: root mean square scaling and second moment.
	mc_centermxn(n, n, c, a, f);
}

MC_TARGET_FUNC void mc_centernxnl(int n, long double * c, const long double * a, int f)
{
//!# Requires c[n x n] and a[n x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.//!# f=0: no scaling.
//!# f=1: standard deviations scaling.
//!# f=2: root mean square scaling and second moment.
	mc_centermxnl(n, n, c, a, f);
}

#endif /* !MC_CENTERNXN_H */

/* EOF */
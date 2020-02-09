//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_centermxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_meanmx1.h>

#ifndef MC_CENTERMXN_H
#define MC_CENTERMXN_H

#pragma mark - mc_centermxn -

MC_TARGET_FUNC void mc_centermxnf(int m, int n, float * c, const float * a)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	float mj;
	for (; j < n; j++) {
		mj = mc_meanmx1f(m, n, j, a, 1, 5);
		for (i = 0; i < m; i++) {
			c[(n * i) + j] = a[(n * i) + j] - mj;
		}
	}
}

MC_TARGET_FUNC void mc_centermxnff(int m, int n, double * c, const float * a)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. Centering
//!# A matrix to its column mean.
	int i, j = 0;
	double mj;
	for (; j < n; j++) {
		mj = mc_meanmx1ff(m, n, j, a, 1, 5);
		for (i = 0; i < m; i++) {
			c[(n * i) + j] = mc_cast(double, a[(n * i) + j]) - mj;
		}
	}
}


MC_TARGET_FUNC void mc_centermxn(int m, int n, double * c, const double * a)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	double mj;
	for (; j < n; j++) {
		mj = mc_meanmx1(m, n, j, a, 1, 5);
		for (i = 0; i < m; i++) {
			c[(n * i) + j] = a[(n * i) + j] - mj;
		}
	}
}

MC_TARGET_FUNC void mc_centermxnl(int m, int n, long double * c, const long double * a)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	long double mj;
	for (; j < n; j++) {
		mj = mc_meanmx1l(m, n, j, a, 1, 5);
		for (i = 0; i < m; i++) {
			c[(n * i) + j] = a[(n * i) + j] - mj;
		}
	}
}

#endif /* !MC_CENTERMXN_H */

/* EOF */
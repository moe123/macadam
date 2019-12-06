//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_minormxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trsimxn.h>

#ifndef MC_MINORMXN_H
#define MC_MINORMXN_H

#pragma mark - mc_minormxn -

MC_TARGET_FUNC void mc_minormxnf(int m, int n, int p, float * restrict b, const float * a)
{
	int i = 0, j;
	for (; i < p; i++) {
		b[(n * i) + i] = 1.0f;
	}
	for (i = p; i < m; i++) {
		for (j = p; j < n; j++) {
			b[(n * i) + j] = a[(n * i) + j];
		}
	}
}

MC_TARGET_FUNC void mc_minormxnff(int m, int n, int p, double * b, const float * a)
{
	int i = 0, j;
	for (; i < p; i++) {
		b[(n * i) + i] = 1.0;
	}
	for (i = p; i < m; i++) {
		for (j = p; j < n; j++) {
			b[(n * i) + j] = mc_cast(double, a[(n * i) + j]);
		}
	}
}

MC_TARGET_FUNC void mc_minormxn(int m, int n, int p, double * b, const double * a)
{
	int i = 0, j;
	for (; i < p; i++) {
		b[(n * i) + i] = 1.0;
	}
	for (i = p; i < m; i++) {
		for (j = p; j < n; j++) {
			b[(n * i) + j] = a[(n * i) + j];
		}
	}
}

MC_TARGET_FUNC void mc_minormxnl(int m, int n, int p, long double * restrict b, const long double * a)
{
	int i = 0, j;
	for (; i < p; i++) {
		b[(n * i) + i] = 1.0;
	}
	for (i = p; i < m; i++) {
		for (j = p; j < n; j++) {
			b[(n * i) + j] = a[(n * i) + j];
		}
	}
}

#endif /* !MC_MINORMXN_H */

/* EOF */
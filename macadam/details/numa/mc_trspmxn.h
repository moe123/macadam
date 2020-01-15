//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trspmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trsimxn.h>

#ifndef MC_TRSPMXN_H
#define MC_TRSPMXN_H

#pragma mark - mc_trspmxn -

MC_TARGET_FUNC void mc_trspmxnf(int m, int n, float * at, const float * a)
{
	if (a == at) {
		mc_trsimxnf(m, n, at);
	} else {
		int i = 0;
		for (; i < (m * n); i++) {
			at[i] = a[(n * (i % m)) + (i / m)];
		}
	}
}

MC_TARGET_FUNC void mc_trspmxn(int m, int n, double * at, const double * a)
{
	if (a == at) {
		mc_trsimxn(m, n, at);
	} else {
		int i = 0;
		for (; i < (m * n); i++) {
			at[i] = a[(n * (i % m)) + (i / m)];
		}
	}
}

MC_TARGET_FUNC void mc_trspmxnl(int m, int n, long double * at, const long double * a)
{
	if (a == at) {
		mc_trsimxnl(m, n, at);
	} else {
		int i = 0;
		for (; i < (m * n); i++) {
			at[i] = a[(n * (i % m)) + (i / m)];
		}
	}
}

#endif /* !MC_TRSPMXN_H */

/* EOF */
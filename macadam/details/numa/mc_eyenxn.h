//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eyenxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_EYENXN_H
#define MC_EYENXN_H

#pragma mark - mc_eyenxn -

MC_TARGET_FUNC void mc_eyenxnf(int n, float * a)
{
	int i = 0, j;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[(n * i) + j] = ((i == j) ? 1.0f : 0.0f);
		}
	}
}

MC_TARGET_FUNC void mc_eyenxn(int n, double * a)
{
	int i = 0, j;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[(n * i) + j] = ((i == j) ? 1.0 : 0.0);
		}
	}
}

MC_TARGET_FUNC void mc_eyenxnl(int n, long double * a)
{
	int i = 0, j;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[(n * i) + j] = ((i == j) ? 1.0L : 0.0L);
		}
	}
}

#endif /* !MC_EYENXN_H */

/* EOF */
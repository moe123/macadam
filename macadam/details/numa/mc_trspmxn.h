//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trspmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trsimxn.h>
#include <macadam/details/numa/mc_trsinxn.h>

#ifndef MC_TRSPMXN_H
#define MC_TRSPMXN_H

#pragma mark - mc_trspmxn -

MC_TARGET_FUNC void mc_trspmxnf(int m, int n, const float * a, float * b)
{
	if (a == b) {
		if (m == n) {
			mc_trsinxnf(n, b);
		} else {
			mc_trsimxnf(m, n, b);
		}
	} else {
		int i = 0;
		for(; i < (n * m); i++) {
			b[i] = a[(m * (i % n)) + (i / n)];
		}
	}
}

MC_TARGET_FUNC void mc_trspmxn(int m, int n, const double * a, double * b)
{
	if (a == b) {
		if (m == n) {
			mc_trsinxn(n, b);
		} else {
			mc_trsimxn(m, n, b);
		}
	} else {
		int i = 0;
		for(; i < (n * m); i++) {
			b[i] = a[(m * (i % n)) + (i / n)];
		}
	}
}

MC_TARGET_FUNC void mc_trspmxnl(int m, int n, const long double * a, long double * b)
{
	if (a == b) {
		if (m == n) {
			mc_trsinxnl(n, b);
		} else {
			mc_trsimxnl(m, n, b);
		}
	} else {
		int i = 0;
		for(; i < (n * m); i++) {
			b[i] = a[(m * (i % n)) + (i / n)];
		}
	}
}

#endif /* !MC_TRSPMXN_H */

/* EOF */
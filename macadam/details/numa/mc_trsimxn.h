//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trsimxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_trsinxn.h>

#ifndef MC_TRSISMXN_H
#define MC_TRSISMXN_H

#pragma mark - mc_trsimxn -

MC_TARGET_FUNC void mc_trsimxnf(int m, int n, float * a)
{
	if (m == n) {
		mc_trsinxnf(n, a);
	} else {
		int i = 0, j, k;
		float w;
		for (; i <= (m * n - 1); ++i) {
			k = i;
			j = 0;
			do {
				++j;
				k = (k % m) * n + k / m;
			} while (k > i);
			if (k >= i && j != 1) {
				w = a[i];
				k = i;
				do {
					j    = (k % m) * n + k / m;
					a[k] = (j == i) ? w : a[j];
					k    = j;
				} while (k > i);
			}
		}
	}
}

MC_TARGET_FUNC void mc_trsimxn(int m, int n, double * a)
{
	if (m == n) {
		mc_trsinxn(n, a);
	} else {
		int i = 0, j, k;
		double w;
		for (; i <= (m * n - 1); ++i) {
			k = i;
			j = 0;
			do {
				++j;
				k = (k % m) * n + k / m;
			} while (k > i);
			if (k >= i && j != 1) {
				w = a[i];
				k = i;
				do {
					j    = (k % m) * n + k / m;
					a[k] = (j == i) ? w : a[j];
					k    = j;
				} while (k > i);
			}
		}
	}
}

MC_TARGET_FUNC void mc_trsimxnl(int m, int n, long double * a)
{
	if (m == n) {
		mc_trsinxnl(n, a);
	} else {
		int i = 0, j, k;
		long double w;
		for (; i <= (m * n - 1); ++i) {
			k = i;
			j = 0;
			do {
				++j;
				k = (k % m) * n + k / m;
			} while (k > i);
			if (k >= i && j != 1) {
				w = a[i];
				k = i;
				do {
					j    = (k % m) * n + k / m;
					a[k] = (j == i) ? w : a[j];
					k    = j;
				} while (k > i);
			}
		}
	}
}

#endif /* !MC_TRSISMXN_H */

/* EOF */
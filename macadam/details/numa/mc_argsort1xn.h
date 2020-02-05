//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argsort1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_ARGSORT1XN_H
#define MC_ARGSORT1XN_H

#pragma mark - mc_argsort1xn -

MC_TARGET_FUNC void mc_argsort1xnf(int n, const float * x, int * k, int f)
{
	int i = 0, j, w;
	for (; i < n; i++) {
		k[i] = i;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (x[j - 1] < x[j]) : (x[j - 1] > x[j])) {
				mcswap_var(w, k[j - 1], k[j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_argsort1xn(int n, const double * x, int * k, int f)
{
	int i = 0, j, w;
	for (; i < n; i++) {
		k[i] = i;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (x[j - 1] < x[j]) : (x[j - 1] > x[j])) {
				mcswap_var(w, k[j - 1], k[j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_argsort1xnl(int n, const long double * x, int * k, int f)
{
	int i = 0, j, w;
	for (; i < n; i++) {
		k[i] = i;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (x[j - 1] < x[j]) : (x[j - 1] > x[j])) {
				mcswap_var(w, k[j - 1], k[j]);
			}
		}
	}
}

#endif /* !MC_ARGSORT1XN_H */

/* EOF */
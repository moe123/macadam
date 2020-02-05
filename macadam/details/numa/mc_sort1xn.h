//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sort1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_copy1xn.h>
#include <macadam/mcswap.h>

#ifndef MC_SORT1XN_H
#define MC_SORT1XN_H

#pragma mark - mc_sort1xn -

MC_TARGET_FUNC void mc_sort1xnf(int n, float * y, const float * x, int f)
{
	int i = 0, j;
	float w;
	if (x != y) {
		mc_copy1xnf(n, y, x);
	}
	for (; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (y[j - 1] < y[j]) : (y[j - 1] > y[j])) {
				mcswap_var(w, y[j - 1], y[j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_sort1xnff(int n, double * y, const float * x, int f)
{
	int i = 0, j;
	double w;
	mc_copy1xnff(n, y, x);
	for (; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (y[j - 1] < y[j]) : (y[j - 1] > y[j])) {
				mcswap_var(w, y[j - 1], y[j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_sort1xn(int n, double * y, const double * x, int f)
{
	int i = 0, j;
	double w;
	if (x != y) {
		mc_copy1xn(n, y, x);
	}
	for (; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (y[j - 1] < y[j]) : (y[j - 1] > y[j])) {
				mcswap_var(w, y[j - 1], y[j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_sort1xnl(int n, long double * y, const long double * x, int f)
{
	int i = 0, j;
	long double w;
	if (x != y) {
		mc_copy1xnl(n, y, x);
	}
	for (; i < n; i++) {
		for (j = 1; j < (n - i); j++) {
			if ((f == 1) ? (y[j - 1] < y[j]) : (y[j - 1] > y[j])) {
				mcswap_var(w, y[j - 1], y[j]);
			}
		}
	}
}

#endif /* !MC_SORT1XN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_swap1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_SWAP1XN_H
#define MC_SWAP1XN_H

#pragma mark - mc_swap1xn -

MC_TARGET_FUNC void mc_swap1xnf(int n, float * restrict x, float * restrict y)
{
	int i = 0;
	float w;
	if (n > 0) {
		for (; i < n; i++) {
			mcswap_var(w, x[i], y[i]);
		}
	}
}

MC_TARGET_FUNC void mc_swap1xnfd(int n, float * restrict x, double * restrict y)
{
	int i = 0;
	double w, xi, yi;
	if (n > 0) {
		for (; i < n; i++) {
			xi   = mc_cast(double, x[i]);
			yi   = y[i];
			mcswap_var(w, xi, yi);
			x[i] = mc_cast(float, yi);
			y[i] = xi;
		}
	}
}

MC_TARGET_FUNC void mc_swap1xndf(int n, double * restrict x, float * restrict y)
{
	int i = 0;
	double w, xi, yi;
	if (n > 0) {
		for (; i < n; i++) {
			xi   = x[i];
			yi   = mc_cast(double, y[i]);
			mcswap_var(w, xi, yi);
			x[i] = yi;
			y[i] = mc_cast(float, xi);
		}
	}
}

MC_TARGET_FUNC void mc_swap1xn(int n, double * restrict x, double * restrict y)
{
	int i = 0;
	double w;
	if (n > 0) {
		for (; i < n; i++) {
			mcswap_var(w, x[i], y[i]);
		}
	}
}

MC_TARGET_FUNC void mc_swap1xnl(int n, long double * restrict x, long double * restrict y)
{
	int i = 0;
	long double w;
	if (n > 0) {
		for (; i < n; i++) {
			mcswap_var(w, x[i], y[i]);
		}
	}
}

#endif /* !MC_SWAP1XN_H */

/* EOF */
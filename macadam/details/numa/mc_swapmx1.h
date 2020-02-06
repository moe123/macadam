//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_swapmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_SWAPMX1
#define MC_SWAPMX1

#pragma mark - mc_swapmx1 -

MC_TARGET_FUNC void mc_swapmx1f(int m, int n, int p, int j, int k, float * a, float * b)
{
//!# Requires a[m x n] and b[m x p].
//!# A and B may be the same. Swapping columns Aj and Bk.
	int i = 0;
	float w;
	if (m > 0) {
		for (; i < m; i++) {
			mcswap_var(w, a[(n * i) + j], b[(p * i) + k]);
		}
	}
}

MC_TARGET_FUNC void mc_swapmx1fd(int m, int n, int p, int j, int k, float * a, double * b)
{
//!# Requires a[m x n] and b[m x p].
//!# Swapping columns Aj and Bk.
	int i = 0;
	double w, ai, bi;
	if (m > 0) {
		for (; i < m; i++) {
			ai   = mc_cast(double, a[(n * i) + j]);
			bi   = b[(p * i) + k];
			mcswap_var(w, ai, bi);
			a[(n * i) + j] = mc_cast(float, bi);
			b[(p * i) + k] = ai;
		}
	}
}

MC_TARGET_FUNC void mc_swapmx1df(int m, int n, int p, int j, int k, double * a, float * b)
{
//!# Requires a[m x n] and b[m x p].
//!# Swapping columns Aj and Bk.
	int i = 0;
	double w, ai, bi;
	if (m > 0) {
		for (; i < m; i++) {
			ai   = a[(n * i) + j];
			bi   = mc_cast(double, b[(p * i) + k]);
			mcswap_var(w, ai, bi);
			a[(n * i) + j] = bi;
			b[(p * i) + k] = mc_cast(float, ai);
		}
	}
}

MC_TARGET_FUNC void mc_swapmx1(int m, int n, int p, int j, int k, double * a, double * b)
{
//!# Requires a[m x n] and b[m x p].
//!# A and B may be the same. Swapping columns Aj and Bk.
	int i = 0;
	double w;
	if (m > 0) {
		for (; i < m; i++) {
			mcswap_var(w, a[(n * i) + j], b[(p * i) + k]);
		}
	}
}

MC_TARGET_FUNC void mc_swapmx1l(int m, int n, int p, int j, int k, long double * a, long double * b)
{
//!# Requires a[m x n] and b[m x p].
//!# A and B may be the same. Swapping columns Aj and Bk.
	int i = 0;
	long double w;
	if (m > 0) {
		for (; i < m; i++) {
			mcswap_var(w, a[(n * i) + j], b[(p * i) + k]);
		}
	}
}

#endif /* !MC_SWAPMX1 */

/* EOF */
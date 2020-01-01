//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_diag1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zerosnxn.h>

#ifndef MC_DIAG1XN_H
#define MC_DIAG1XN_H

#pragma mark - mc_diag1xn -

MC_TARGET_FUNC void mc_diag1xnf(int n, float * a, const float * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0;
	if (k > 0 ) {
		mc_zerosnxnf(n + k, a);
		for (; i < n; i++) {
			a[(n * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		mc_zerosnxnf(n - k, a);
		for (; i < n; i++) {
			a[(n * (i - k)) + i] = d[i];
		}
	} else {
		mc_zerosnxnf(n, a);
		for (; i < n; i++) {
			a[(n * i) + i] = d[i];
		}
	}
}

MC_TARGET_FUNC void mc_diag1xnff(int n, double * a, const float * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0;
	if (k > 0 ) {
		mc_zerosnxn(n + k, a);
		for (; i < n; i++) {
			a[(n * i) + (i + k)] = mc_cast(double, d[i]);
		}
	} else if (k < 0 ) {
		mc_zerosnxn(n - k, a);
		for (; i < n; i++) {
			a[(n * (i - k)) + i] = mc_cast(double, d[i]);
		}
	} else {
		mc_zerosnxn(n, a);
		for (; i < n; i++) {
			a[(n * i) + i] = mc_cast(double, d[i]);
		}
	}
}

MC_TARGET_FUNC void mc_diag1xn(int n, double * a, const double * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0;
	if (k > 0 ) {
		mc_zerosnxn(n + k, a);
		for (; i < n; i++) {
			a[(n * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		mc_zerosnxn(n - k, a);
		for (; i < n; i++) {
			a[(n * (i - k)) + i] = d[i];
		}
	} else {
		mc_zerosnxn(n, a);
		for (; i < n; i++) {
			a[(n * i) + i] = d[i];
		}
	}
}

MC_TARGET_FUNC void mc_diag1xnl(int n, long double * a, const long double * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0;
	if (k > 0 ) {
		mc_zerosnxnl(n + k, a);
		for (; i < n; i++) {
			a[(n * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		mc_zerosnxnl(n - k, a);
		for (; i < n; i++) {
			a[(n * (i - k)) + i] = d[i];
		}
	} else {
		mc_zerosnxnl(n, a);
		for (; i < n; i++) {
			a[(n * i) + i] = d[i];
		}
	}
}

#endif /* !MC_DIAG1XN_H */

/* EOF */
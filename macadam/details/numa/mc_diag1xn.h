//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_diag1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zerosnxn.h>

#ifndef MC_DIAG1XN_H
#define MC_DIAG1XN_H

#pragma mark - mc_diag1xn -

MC_TARGET_FUNC void mc_diag1xnf(int n, float * a, const float * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0, m;
	if (k > 0 ) {
		m = n + k;
		mc_zerosnxnf(m, a);
		for (; i < n; i++) {
			a[(m * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		m = n - k;
		mc_zerosnxnf(m, a);
		for (; i < n; i++) {
			a[(m * (i - k)) + i] = d[i];
		}
	} else {
		m = n;
		mc_zerosnxnf(m, a);
		for (; i < n; i++) {
			a[(m * i) + i] = d[i];
		}
	}
}

MC_TARGET_FUNC void mc_diag1xnff(int n, double * a, const float * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0, m;
	if (k > 0 ) {
		m = n + k;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * i) + (i + k)] = mc_cast(double, d[i]);
		}
	} else if (k < 0 ) {
		m = n - k;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * (i - k)) + i] = mc_cast(double, d[i]);
		}
	} else {
		m = n;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * i) + i] = mc_cast(double, d[i]);
		}
	}
}

MC_TARGET_FUNC void mc_diag1xn(int n, double * a, const double * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0, m;
	if (k > 0 ) {
		m = n + k;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		m = n - k;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * (i - k)) + i] = d[i];
		}
	} else {
		m = n;
		mc_zerosnxn(m, a);
		for (; i < n; i++) {
			a[(m * i) + i] = d[i];
		}
	}
}

MC_TARGET_FUNC void mc_diag1xnl(int n, long double * a, const long double * d, int k)
{
//!# Requires a[(n + |k|) x (n + |k|)] and d[1 x n].
	int i = 0, m;
	if (k > 0 ) {
		m = n + k;
		mc_zerosnxnl(m, a);
		for (; i < n; i++) {
			a[(m * i) + (i + k)] = d[i];
		}
	} else if (k < 0 ) {
		m = n - k;
		mc_zerosnxnl(m, a);
		for (; i < n; i++) {
			a[(m * (i - k)) + i] = d[i];
		}
	} else {
		m = n;
		mc_zerosnxnl(m, a);
		for (; i < n; i++) {
			a[(m * i) + i] = d[i];
		}
	}
}

#endif /* !MC_DIAG1XN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lusolvenxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_LUSOLVENXN_H
#define MC_LUSOLVENXN_H

#pragma mark - mc_lusolvenxn -

MC_TARGET_FUNC int mc_lusolvenxnf(int n, const float * restrict lu, const float * restrict d, const float * restrict p, const int * pvi, const float * restrict b, float * restrict x) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1], x[m x 1] and b[m x 1] where m=n.
//!# d, p and pvi can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int i = 0, j;
	float w;

	mc_cast(void, d);

//!# Computing x=b[pvi[i]] according to permutation matrix or pivot indeces vector.
	if (wantpvi) {
		x[i] = b[pvi[i]];
	} else if (wantp) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (p[n * i + j] != 0.0f) {
					break;
				}
			}
			x[i] = b[j];
		}
	} else {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}

//!# Solving L*y=b.
	for (j = 0; j < n; j++) {
		for (i = (j + 1); i < n; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}

//!# Solving U*x=y.
	for (j = (n - 1); j >= 0; j--) {
		w = lu[(n * j) + j];
		if (w != 0.0f) {
			x[j] = x[j] / w;
		}
		for (i = 0; i < j; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}
	return 0;
}

MC_TARGET_FUNC int mc_lusolvenxnff(int n, const float * restrict lu, const float * restrict d, const float * restrict p, const int * pvi, const float * restrict b, double * restrict x) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1], x[m x 1] and b[m x 1] where m=n.
//!# d, p and pvi can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int i = 0, j;
	double w;

	mc_cast(void, d);

//!# Computing x=b[pvi[i]] according to permutation matrix or pivot indeces vector.
	if (wantpvi) {
		x[i] = b[pvi[i]];
	} else if (wantp) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (p[n * i + j] != 0.0f) {
					break;
				}
			}
			x[i] = mc_cast(double, b[j]);
		}
	} else {
		for (i = 0; i < n; i++) {
			x[i] = mc_cast(double, b[i]);
		}
	}

//!# Solving L*y=b.
	for (j = 0; j < n; j++) {
		for (i = (j + 1); i < n; i++) {
			x[i] = x[i] - (x[j] * mc_cast(double, lu[(n * i) + j]));
		}
	}

//!# Solving U*x=y.
	for (j = (n - 1); j >= 0; j--) {
		w = mc_cast(double, lu[(n * j) + j]);
		if (w != 0.0) {
			x[j] = x[j] / w;
		}
		for (i = 0; i < j; i++) {
			x[i] = x[i] - (x[j] * mc_cast(double, lu[(n * i) + j]));
		}
	}
	return 0;
}

MC_TARGET_FUNC int mc_lusolvenxn(int n, const double * restrict lu, const double * restrict d, const double * restrict p, const int * pvi, const double * restrict b, double * restrict x) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1], x[m x 1] and b[m x 1] where m=n.
//!# d, p and pvi can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int i = 0, j;
	double w;

	mc_cast(void, d);

//!# Computing x=b[pvi[i]] according to permutation matrix or pivot indeces vector.
	if (wantpvi) {
		x[i] = b[pvi[i]];
	} else if (wantp) {
		for (i = 0; i < n; i++) {
			for (j = 0; i < n; i++) {
				if (p[n * i + j] != 0.0) {
					break;
				}
			}
			x[i] = b[j];
		}
	} else {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}

//!# Solving L*y=b.
	for (j = 0; j < n; j++) {
		for (i = (j + 1); i < n; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}

//!# Solving U*x=y.
	for (j = (n - 1); j >= 0; j--) {
		w = lu[(n * j) + j];
		if (w != 0.0) {
			x[j] = x[j] / w;
		}
		for (i = 0; i < j; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}
	return 0;
}

MC_TARGET_FUNC int mc_lusolvenxnl(int n, const long double * restrict lu, const long double * restrict d, const long double * restrict p, const int * pvi, const long double * restrict b, long double * restrict x) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1], x[m x 1] and b[m x 1] where m=n.
//!# d, p and pvi can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int i = 0, j;
	long double w;

	mc_cast(void, d);

//!# Computing x=b[pvi[i]] according to permutation matrix or pivot indeces vector.
	if (wantpvi) {
		x[i] = b[pvi[i]];
	} else if (wantp) {
		for (i = 0; i < n; i++) {
			for (j = 0; i < n; i++) {
				if (p[n * i + j] != 0.0L) {
					break;
				}
			}
			x[i] = b[j];
		}
	} else {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}

//!# Solving L*y=b.
	for (j = 0; j < n; j++) {
		for (i = (j + 1); i < n; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}

//!# Solving U*x=y.
	for (j = (n - 1); j >= 0; j--) {
		w = lu[(n * j) + j];
		if (w != 0.0L) {
			x[j] = x[j] / w;
		}
		for (i = 0; i < j; i++) {
			x[i] = x[i] - (x[j] * lu[(n * i) + j]);
		}
	}
	return 0;
}

#endif /* !MC_LUSOLVENXN_H */

/* EOF */
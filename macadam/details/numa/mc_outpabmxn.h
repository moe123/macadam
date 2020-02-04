//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_outpabmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zerosmxn.h>

#ifndef MC_OUTPABMXN_H
#define MC_OUTPABMXN_H

#pragma mark - mc_outpabmxn -

MC_TARGET_FUNC void mc_outpabmxnf(int m, int n, int p, int q, int j, int k, float * restrict c, const float * a, const float * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	float v, e, w;
	for (; l < n; l++) {
		w = b[(q * l) + k];
		for (i = 0; i < m; i++) {
			mc_twoproductf(a[(p * i) + j], w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpabmxnff(int m, int n, int p, int q, int j, int k, double * restrict c, const float * a, const float * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	double v, e, w;
	for (; l < n; l++) {
		w = mc_cast(double, b[(q * l) + k]);
		for (i = 0; i < m; i++) {
			mc_twoproduct(mc_cast(double, a[(p * i) + j]), w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpabmxnfd(int m, int n, int p, int q, int j, int k, double * restrict c, const float * a, const double * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	double v, e, w;
	for (; l < n; l++) {
		w = b[(q * l) + k];
		for (i = 0; i < m; i++) {
			mc_twoproduct(mc_cast(double, a[(p * i) + j]), w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpabmxndf(int m, int n, int p, int q, int j, int k, double * restrict c, const double * a, const float * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	double v, e, w;
	for (; l < n; l++) {
		w = mc_cast(double, b[(q * l) + k]);
		for (i = 0; i < m; i++) {
			mc_twoproduct(a[(p * i) + j], w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpabmxn(int m, int n, int p, int q, int j, int k, double * restrict c, const double * a, const double * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	double v, e, w;
	for (; l < n; l++) {
		w = b[(q * l) + k];
		for (i = 0; i < m; i++) {
			mc_twoproduct(a[(p * i) + j], w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpabmxnl(int m, int n, int p, int q, int j, int k, long double * restrict c, const long double * a, const long double * b)
{
//!# Requires c[m x n], a[m x p] and b[n x q].
//!# c=ai*bi' i.e outer product of two column-vectors.
	int l = 0, i;
	long double v, e, w;
	for (; l < n; l++) {
		w = b[(q * l) + k];
		for (i = 0; i < m; i++) {
			mc_twoproductl(a[(p * i) + j], w, &v, &e);
			c[(n * i) + l] = v + e;
		}
	}
}

#endif /* !MC_OUTPABMXN_H */

/* EOF */
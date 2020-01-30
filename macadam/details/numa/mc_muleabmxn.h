//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_muleabmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_MULEABMXN_H
#define MC_MULEABMXN_H

#pragma mark - mc_muleabmxn -

MC_TARGET_FUNC void mc_muleabmxnf(int m, int n, float * restrict c, const float * a, const float * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	float v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproductf(a[(n * i) + j], b[(n * i) + j], &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_muleabmxnff(int m, int n, double * restrict c, const float * a, const float * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	double v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproduct(mc_cast(double, a[(n * i) + j]), mc_cast(double, b[(n * i) + j]), &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_muleabmxnfd(int m, int n, double * restrict c, const float * a, const double * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	double v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproduct(a[(n * i) + j], mc_cast(double, b[(n * i) + j]), &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_muleabmxndf(int m, int n, double * restrict c, const double * a, const float * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	double v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproduct(a[(n * i) + j], mc_cast(double, b[(n * i) + j]), &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_muleabmxn(int m, int n, double * restrict c, const double * a, const double * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	double v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproduct(a[(n * i) + j], b[(n * i) + j], &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_muleabmxnl(int m, int n, long double * restrict c, const long double * a, const long double * b)
{
//!# Requires c[m x n], a[m x n] and b[m x n].
//!# c=a.*b i.e Hadamard product.
	int i = 0, j;
	long double v, e;
	for (; i < m; i++) {
		for (j = 0; j < n; j++) {
			mc_twoproductl(a[(n * i) + j], b[(n * i) + j], &v, &e);
			c[(n * i) + j] = v + e;
		}
	}
}

#endif /* !MC_MULEABMXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rotl1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gcd.h>

#ifndef MC_ROTL1XN_H
#define MC_ROTL1XN_H

#pragma mark - mc_rotl1xn -

MC_TARGET_FUNC void mc_rotl1xnf(int n, int p, float * y, const float * x)
{
//!# Requires y[n] and x[n] where 1 < n. Y and X may be the same.
//!# Left rotate elements of vector X by p times and store the
//!# result into vector Y.
	int i = 0, j, k; 
	float w;
	if (x != y) {
		mc_copy1xnf(n, y ,x);
	}
	for (; i < mc_igcd(p, n); i++) {
		j = i;
		w = y[j];
		while (!(k == i)) { 
			k    = ((j + p) >= n) ? ((j + p) - n) : (j + p);
			y[j] = y[k]; 
			j    = k; 
		}
		y[j] = w; 
	}
}

MC_TARGET_FUNC void mc_rotl1xnff(int n, int p, double * y, const float * x)
{
//!# Requires y[n] and x[n] where 1 < n. Left rotate elements of
//!# vector X by p times and store the result into vector Y.
	int i = 0, j, k; 
	double w;
	mc_copy1xnff(n, y ,x);
	for (; i < mc_igcd(p, n); i++) {
		j = i;
		w = y[j];
		while (!(k == i)) { 
			k    = ((j + p) >= n) ? ((j + p) - n) : (j + p);
			y[j] = y[k]; 
			j    = k; 
		}
		y[j] = w; 
	}
}

MC_TARGET_FUNC void mc_rotl1xn(int n, int p, double * y, const double * x)
{
//!# Requires y[n] and x[n] where 1 < n. Y and X may be the same.
//!# Left rotate elements of vector X by p times and store the
//!# result into vector Y.
	int i = 0, j, k; 
	double w;
	if (x != y) {
		mc_copy1xn(n, y ,x);
	}
	for (; i < mc_igcd(p, n); i++) {
		j = i;
		w = y[j];
		while (!(k == i)) { 
			k    = ((j + p) >= n) ? ((j + p) - n) : (j + p);
			y[j] = y[k]; 
			j    = k; 
		}
		y[j] = w; 
	}
}

MC_TARGET_FUNC void mc_rotl1xnl(int n, int p, long double * y, const long double * x)
{
//!# Requires y[n] and x[n] where 1 < n. Y and X may be the same.
//!# Left rotate elements of vector X by p times and store the
//!# result into vector Y.
	int i = 0, j, k; 
	long double w;
	if (x != y) {
		mc_copy1xnl(n, y ,x);
	}
	for (; i < mc_igcd(p, n); i++) {
		j = i;
		w = y[j];
		while (!(k == i)) { 
			k    = ((j + p) >= n) ? ((j + p) - n) : (j + p);
			y[j] = y[k]; 
			j    = k; 
		}
		y[j] = w; 
	}
}

#endif /* !MC_ROTLR1XN_H */

/* EOF */
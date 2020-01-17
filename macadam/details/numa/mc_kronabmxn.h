//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_kronabmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_KRONABMXN_H
#define MC_KRONABMXN_H

#pragma mark - mc_kronabmxn -

MC_TARGET_FUNC void mc_kronabmxnf(int m, int n, int p, int q, float * restrict c, const float * a, const float * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = a[(n * i) + j] * b[(q * k) + l];
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_kronabmxnff(int m, int n, int p, int q, double * restrict c, const float * a, const float * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = mc_cast(double, a[(n * i) + j]) * mc_cast(double, b[(q * k) + l]);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_kronabmxnfd(int m, int n, int p, int q, double * restrict c, const float * a, const double * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = mc_cast(double, a[(n * i) + j]) * b[(q * k) + l];
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_kronabmxndf(int m, int n, int p, int q, double * restrict c, const double * a, const float * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = a[(n * i) + j] * mc_cast(double, b[(q * k) + l]);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_kronabmxn(int m, int n, int p, int q, double * restrict c, const double * a, const double * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = a[(n * i) + j] * b[(q * k) + l];
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_kronabmxnl(int m, int n, int p, int q, long double * restrict c, const long double * a, const long double * b)
{
//!# Requires c[(p * m) * (q * n)], a[m x n] and b[p x q].
//!# Computing the Kronecker product of two matrices.
	int i = 0, j, k, l;	
	for(; i < m; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < p; k++) {
				for(l = 0; l < q; l++){
					c[((q * n) * ((i * p) + k)) + ((j * q) + l)] = a[(n * i) + j] * b[(q * k) + l];
				}
			}
		}
	}
}

#endif /* !MC_KRONABMXN_H */

/* EOF */
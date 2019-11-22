//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotpmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_DOTPMXN_H
#define MC_DOTPMXN_H

#pragma mark - mc_dotpmxn -

MC_TARGET_FUNC void mc_dotpmxnf(int m, int n, int p, float * restrict c, const float * a, const float * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb.
	int i = 0, j, k;
	float s;
	for (; i < m; i++) {
	 	for (j = 0; j < p; j++) {
			s = 0.0f;
			for (k = 0; k < n; k++) {
				s = s + (a[(n * i) + k] * b[(p * k) + j]);
			}
			c[(p * i) + j] = s;
		}
	}
}

MC_TARGET_FUNC void mc_dotpmxnff(int m, int n, int p, double * c, const float * a, const float * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb.
	int i = 0, j, k;
	double s;
	for (; i < m; i++) {
	 	for (j = 0; j < p; j++) {
			s = 0.0;
			for (k = 0; k < n; k++) {
				s = s + (mc_cast(double, a[(n * i) + k]) * mc_cast(double, b[(p * k) + j]));
			}
			c[(p * i) + j] = s;
		}
	}
}

MC_TARGET_FUNC void mc_dotpmxn(int m, int n, int p, double * restrict c, const double * a, const double * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb.
	int i = 0, j, k;
	double s;
	for (; i < m; i++) {
	 	for (j = 0; j < p; j++) {
			s = 0.0;
			for (k = 0; k < n; k++) {
				s = s + (a[(n * i) + k] * b[(p * k) + j]);
			}
			c[(p * i) + j] = s;
		}
	}
}

MC_TARGET_FUNC void mc_dotpmxnl(int m, int n, int p, long double * restrict c, const long double * a, const long double * b)
{
//!# Returns c[m x p]=a[m x n]*b[n x p] where m=ma, n=na=mb and p=nb.
	int i = 0, j, k;
	long double s;
	for (; i < m; i++) {
	 	for (j = 0; j < p; j++) {
			s = 0.0L;
			for (k = 0; k < n; k++) {
				s = s + (a[(n * i) + k] * b[(p * k) + j]);
			}
			c[(p * i) + j] = s;
		}
	}
}

#endif /* !MC_DOTPMXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulab2x2.h>
#include <macadam/details/numa/mc_mulab3x3.h>

#ifndef MC_MULABMXN_H
#define MC_MULABMXN_H

#pragma mark - mc_mulabmxn -

MC_TARGET_FUNC void mc_mulabmxnf(int m, int n, int p, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0f;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] += a[(n * i) + k] * b[(p * k) + j];
			}
		}
	}
}

MC_TARGET_FUNC void mc_mulabmxn(int m, int n, int p, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] += a[(n * i) + k] * b[(p * k) + j];
			}
		}
	}
}

MC_TARGET_FUNC void mc_mulabmxnl(int m, int n, int p, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0L;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] += a[(n * i) + k] * b[(p * k) + j];
			}
		}
	}
}

#endif /* !MC_MULABMXN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_MULABNXN_H
#define MC_MULABNXN_H

#pragma mark - mc_mulabnxn -

MC_TARGET_FUNC void mc_mulabnxnf(int n, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a*b
	int i = 0, j, k;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = 0.0f;
			for (k = 0; k < n; k++) {
				c[(n * i) + j] = c[(n * i) + j] + (a[(n * i) + k] * b[(n * k) + j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_mulabnxn(int n, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a*b
	int i = 0, j, k;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = 0.0;
			for (k = 0; k < n; k++) {
				c[(n * i) + j] = c[(n * i) + j] + (a[(n * i) + k] * b[(n * k) + j]);
			}
		}
	}
}

MC_TARGET_FUNC void mc_mulabnxnl(int n, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a*b
	int i = 0, j, k;
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = 0.0L;
			for (k = 0; k < n; k++) {
				c[(n * i) + j] = c[(n * i) + j] + (a[(n * i) + k] * b[(n * k) + j]);
			}
		}
	}
}

#endif /* !MC_MULABNXN_H */

/* EOF */
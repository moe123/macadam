//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulab2x2.h>
#include <macadam/details/numa/mc_mulab3x3.h>

#ifndef MC_MULABNXN_H
#define MC_MULABNXN_H

#pragma mark - mc_mulabnxn -

MC_TARGET_FUNC void mc_mulabnxnf(int n, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2f(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3f(c, a, b);
	} else {
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
}

MC_TARGET_FUNC void mc_mulabnxn(int n, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3(c, a, b);
	} else {
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
}

MC_TARGET_FUNC void mc_mulabnxnl(int n, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2l(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3l(c, a, b);
	} else {
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
}

#endif /* !MC_MULABNXN_H */

/* EOF */
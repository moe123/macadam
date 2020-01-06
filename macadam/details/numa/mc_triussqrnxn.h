//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_triussqrnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>

#ifndef MC_TRIUSSQRNXN_H
#define MC_TRIUSSQRNXN_H

#pragma mark - mc_triussqrnxn -

MC_TARGET_FUNC void mc_triussqrnxnf(int n, const float * a, float * sumsq, float * scale, int f)
{
//!# Computing the sum of squares of the upper-triangle of A.
//!# f=0: including main diagonal.
//!# f=1: excluding main diagonal.
	int i = 0, j;
	float t;

	*scale = 0.0f;
	*sumsq = 1.0f;

	if (n > 0) {
		for (; i < ((f == 1) ? (n - 1) : n); i++) {
			for (j = (i + ((f == 1) ? 0 : 1)); j < n; j++) {
				if (0.0f != (t = mc_fabsf(a[(n * i) + j]))) {
					if (*scale < t) {
						*sumsq = 1.0f + *sumsq * mc_raise2f(*scale / t);
						*scale = t;
					} else {
						*sumsq = *sumsq + mc_raise2f(t / *scale);
					}
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_triussqrnxnff(int n, const float * a, double * sumsq, double * scale, int f)
{
//!# Computing the sum of squares of the upper-triangle of A.
//!# f=0: including main diagonal.
//!# f=1: excluding main diagonal.
	int i = 0, j;
	double t;

	*scale = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		for (; i < ((f == 1) ? (n - 1) : n); i++) {
			for (j = (i + ((f == 1) ? 0 : 1)); j < n; j++) {
				if (0.0 != (t = mc_fabs(mc_cast(double, a[(n * i) + j])))) {
					if (*scale < t) {
						*sumsq = 1.0 + *sumsq * mc_raise2(*scale / t);
						*scale = t;
					} else {
						*sumsq = *sumsq + mc_raise2(t / *scale);
					}
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_triussqrnxn(int n, const double * a, double * sumsq, double * scale, int f)
{
//!# Computing the sum of squares of the upper-triangle of A.
//!# f=0: including main diagonal.
//!# f=1: excluding main diagonal.
	int i = 0, j;
	double t;

	*scale = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		for (; i < ((f == 1) ? (n - 1) : n); i++) {
			for (j = (i + ((f == 1) ? 0 : 1)); j < n; j++) {
				if (0.0 != (t = mc_fabs(a[(n * i) + j]))) {
					if (*scale < t) {
						*sumsq = 1.0 + *sumsq * mc_raise2(*scale / t);
						*scale = t;
					} else {
						*sumsq = *sumsq + mc_raise2(t / *scale);
					}
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_triussqrnxnl(int n, const long double * a, long double * sumsq, long double * scale, int f)
{
//!# Computing the sum of squares of the upper-triangle of A.
//!# f=0: including main diagonal.
//!# f=1: excluding main diagonal.
	int i = 0, j;
	long double t;

	*scale = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		for (; i < ((f == 1) ? (n - 1) : n); i++) {
			for (j = (i + ((f == 1) ? 0 : 1)); j < n; j++) {
				if (0.0L != (t = mc_fabsl(a[(n * i) + j]))) {
					if (*scale < t) {
						*sumsq = 1.0L + *sumsq * mc_raise2l(*scale / t);
						*scale = t;
					} else {
						*sumsq = *sumsq + mc_raise2l(t / *scale);
					}
				}
			}
		}
	}
}

#endif /* !MC_TRIUSSQRNXN_H */

/* EOF */
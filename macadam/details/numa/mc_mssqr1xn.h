//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mssqr1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/numa/mc_mean1xn.h>

#ifndef MC_MSSQR1XN_H
#define MC_MSSQR1XN_H

#pragma mark - mc_mssqr1xn -

MC_TARGET_FUNC void mc_mssqr1xnf(int n, const float * x, float * mean, float * sumsq, float * scale)
{
	int i;
	float t;

	*scale = 0.0f;
	*mean  = 0.0f;
	*sumsq = 1.0f;

	if (n > 0) {
		if (n == 1) {
			*mean = x[0];
		} else {
			*mean = mc_mean1xnf(n, x, 0, 1);
			for (i = 0; i < n; i++) {
				if (0.0f != (t = mc_fabsf(*mean - x[0]))) {
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

MC_TARGET_FUNC void mc_mssqr1xnff(int n, const float * x, double * mean, double * sumsq, double * scale)
{
	int i;
	double t;

	*scale = 0.0;
	*mean  = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		if (n == 1) {
			*mean = x[0];
		} else {
			*mean = mc_mean1xnff(n, x, 0, 1);
			for (i = 0; i < n; i++) {
				if (0.0f != (t = mc_fabs(*mean - mc_cast(double, x[0])))) {
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

MC_TARGET_FUNC void mc_mssqr1xn(int n, const double * x, double * mean, double * sumsq, double * scale)
{
	int i;
	double t;

	*scale = 0.0;
	*mean  = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		if (n == 1) {
			*mean = x[0];
		} else {
			*mean = mc_mean1xn(n, x, 0, 1);
			for (i = 0; i < n; i++) {
				if (0.0f != (t = mc_fabs(*mean - x[0]))) {
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

MC_TARGET_FUNC void mc_mssqr1xnl(int n, const long double * x, long double * mean, long double * sumsq, long double * scale)
{
	int i;
	long double t;

	*scale = 0.0;
	*mean  = 0.0;
	*sumsq = 1.0;

	if (n > 0) {
		if (n == 1) {
			*mean = x[0];
		} else {
			*mean = mc_mean1xnl(n, x, 0, 1);
			for (i = 0; i < n; i++) {
				if (0.0f != (t = mc_fabsl(*mean - x[0]))) {
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

#endif /* !MC_MSSQR1XN_H */

/* EOF */
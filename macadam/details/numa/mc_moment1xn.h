//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_moment1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqr1xn.h>

#ifndef MC_MOMENT1XN_H
#define MC_MOMENT1XN_H

#pragma mark - mc_moment1xn -

MC_TARGET_FUNC void mc_moment1xnf(int n, const float * x, float * m1, float * m2, float * m3, float * m4, float * skewness, float * kurtosis)
{
	float q, d, scale, sumsq;
	int i = 1;

	*m1       = 0.0f;
	*m2       = 0.0f;
	*m3       = 0.0f;
	*m4       = 0.0f;
	*skewness = 0.0f;
	*kurtosis = 0.0f;

	if (n > 0) {
		mc_mssqr1xnf(n, x, m1, &sumsq, &scale);
		*m2 = mc_raise2f(scale) * (sumsq / n);
		if (n > 1) {
			q = scale * mc_sqrtf(sumsq / n);
			for (; i <= n; i++) {
				 d  = x[i - 1] - *m1;
				*m3 = *m3 + (mc_raise2f(d) * d - *m3) / mc_cast(float, i);
				*m4 = *m4 + (mc_raise2f(d * d) - *m4) / mc_cast(float, i);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2f(d) * d - *skewness) / mc_cast(float, i);
					*kurtosis = *kurtosis + (mc_raise2f(d * d) - *kurtosis) / mc_cast(float, i);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_moment1xnff(int n, const float * x, double * m1, double * m2, double * m3, double * m4, double * skewness, double * kurtosis)
{
	double q, d, scale, sumsq;
	int i = 1;

	*m1       = 0.0;
	*m2       = 0.0;
	*m3       = 0.0;
	*m4       = 0.0;
	*skewness = 0.0;
	*kurtosis = 0.0;

	if (n > 0) {
		mc_mssqr1xnff(n, x, m1, &sumsq, &scale);
		*m2 = mc_raise2(scale) * (sumsq / n);
		if (n > 1) {
			q = scale * mc_sqrt(sumsq / n);
			for (; i <= n; i++) {
				 d  = mc_cast(double, x[i - 1]) - *m1;
				*m3 = *m3 + (mc_raise2(d) * d - *m3) / mc_cast(double, i);
				*m4 = *m4 + (mc_raise2(d * d) - *m4) / mc_cast(double, i);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2(d) * d - *skewness) / mc_cast(double, i);
					*kurtosis = *kurtosis + (mc_raise2(d * d) - *kurtosis) / mc_cast(double, i);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_moment1xn(int n, const double * x, double * m1, double * m2, double * m3, double * m4, double * skewness, double * kurtosis)
{
	double q, d, scale, sumsq;
	int i = 1;

	*m1       = 0.0;
	*m2       = 0.0;
	*m3       = 0.0;
	*m4       = 0.0;
	*skewness = 0.0;
	*kurtosis = 0.0;

	if (n > 0) {
		mc_mssqr1xn(n, x, m1, &sumsq, &scale);
		*m2 = mc_raise2(scale) * (sumsq / n);
		if (n > 1) {
			q = scale * mc_sqrt(sumsq / n);
			for (; i <= n; i++) {
				 d  = x[i - 1] - *m1;
				*m3 = *m3 + (mc_raise2(d) * d - *m3) / mc_cast(double, i);
				*m4 = *m4 + (mc_raise2(d * d) - *m4) / mc_cast(double, i);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2(d) * d - *skewness) / mc_cast(double, i);
					*kurtosis = *kurtosis + (mc_raise2(d * d) - *kurtosis) / mc_cast(double, i);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_moment1xnl(int n, const long double * x, long double * m1, long double * m2, long double * m3, long double * m4, long double * skewness, long double * kurtosis)
{
	long double q, d, scale, sumsq;
	int i = 1;

	*m1       = 0.0L;
	*m2       = 0.0L;
	*m3       = 0.0L;
	*m4       = 0.0L;
	*skewness = 0.0L;
	*kurtosis = 0.0L;

	if (n > 0) {
		mc_mssqr1xnl(n, x, m1, &sumsq, &scale);
		*m2 = mc_raise2l(scale) * (sumsq / n);
		if (n > 1) {
			q = scale * mc_sqrtl(sumsq / n);
			for (; i <= n; i++) {
				 d  = x[i - 1] - *m1;
				*m3 = *m3 + (mc_raise2l(d) * d - *m3) / mc_cast(long double, i);
				*m4 = *m4 + (mc_raise2l(d * d) - *m4) / mc_cast(long double, i);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2l(d) * d - *skewness) / mc_cast(long double, i);
					*kurtosis = *kurtosis + (mc_raise2l(d * d) - *kurtosis) / mc_cast(long double, i);
				}
			}
		}
	}
}

#endif /* !MC_MOMENT1XN_H */

/* EOF */
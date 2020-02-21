//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_momentmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mssqrmx1.h>

#ifndef MC_MOMENTMX1_H
#define MC_MOMENTMX1_H

#pragma mark - mc_momentmx1 -

MC_TARGET_FUNC void mc_momentmx1f(int m, int n, int j, const float * a, float * m1, float * m2, float * m3, float * m4, float * skewness, float * kurtosis)
{
	float q, d, scale, sumsq;
	int k = 1;

	*m1       = 0.0f;
	*m2       = 0.0f;
	*m3       = 0.0f;
	*m4       = 0.0f;
	*skewness = 0.0f;
	*kurtosis = 0.0f;

	if (m > 0 && n > 0) {
		mc_mssqrmx1f(m, n, j, a, 0, m1, &sumsq, &scale);
		*m2 = mc_raise2f(scale) * (sumsq / mc_cast(float, m));
		if (m > 1) {
			q = scale * mc_sqrtf(sumsq / mc_cast(float, m));
			for (; k <= m; k++) {
				 d  = a[(n * (k - 1)) + j] - *m1;
				*m3 = *m3 + (mc_raise2f(d) * d - *m3) / mc_cast(float, k);
				*m4 = *m4 + (mc_raise2f(d * d) - *m4) / mc_cast(float, k);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2f(d) * d - *skewness) / mc_cast(float, k);
					*kurtosis = *kurtosis + (mc_raise2f(d * d) - *kurtosis) / mc_cast(float, k);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_momentmx1ff(int m, int n, int j, const float * a, double * m1, double * m2, double * m3, double * m4, double * skewness, double * kurtosis)
{
	double q, d, scale, sumsq;
	int k = 1;

	*m1       = 0.0;
	*m2       = 0.0;
	*m3       = 0.0;
	*m4       = 0.0;
	*skewness = 0.0;
	*kurtosis = 0.0;

	if (m > 0 && n > 0) {
		mc_mssqrmx1ff(m, n, j, a, 0, m1, &sumsq, &scale);
		*m2 = mc_raise2(scale) * (sumsq / mc_cast(double, m));
		if (m > 1) {
			q = scale * mc_sqrt(sumsq / mc_cast(double, m));
			for (; k <= m; k++) {
				 d  = mc_cast(double, a[(n * (k - 1)) + j]) - *m1;
				*m3 = *m3 + (mc_raise2(d) * d - *m3) / mc_cast(double, k);
				*m4 = *m4 + (mc_raise2(d * d) - *m4) / mc_cast(double, k);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2(d) * d - *skewness) / mc_cast(double, k);
					*kurtosis = *kurtosis + (mc_raise2(d * d) - *kurtosis) / mc_cast(double, k);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_momentmx1(int m, int n, int j, const double * a, double * m1, double * m2, double * m3, double * m4, double * skewness, double * kurtosis)
{
	double q, d, scale, sumsq;
	int k = 1;

	*m1       = 0.0;
	*m2       = 0.0;
	*m3       = 0.0;
	*m4       = 0.0;
	*skewness = 0.0;
	*kurtosis = 0.0;

	if (m > 0 && n > 0) {
		mc_mssqrmx1(m, n, j, a, 0, m1, &sumsq, &scale);
		*m2 = mc_raise2(scale) * (sumsq / mc_cast(double, m));
		if (m > 1) {
			q = scale * mc_sqrt(sumsq / mc_cast(double, m));
			for (; k <= m; k++) {
				 d  = a[(n * (k - 1)) + j] - *m1;
				*m3 = *m3 + (mc_raise2(d) * d - *m3) / mc_cast(double, k);
				*m4 = *m4 + (mc_raise2(d * d) - *m4) / mc_cast(double, k);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2(d) * d - *skewness) / mc_cast(double, k);
					*kurtosis = *kurtosis + (mc_raise2(d * d) - *kurtosis) / mc_cast(double, k);
				}
			}
		}
	}
}

MC_TARGET_FUNC void mc_momentmx1l(int m, int n, int j, const long double * a, long double * m1, long double * m2, long double * m3, long double * m4, long double * skewness, long double * kurtosis)
{
	long double q, d, scale, sumsq;
	int k = 1;

	*m1       = 0.0L;
	*m2       = 0.0L;
	*m3       = 0.0L;
	*m4       = 0.0L;
	*skewness = 0.0L;
	*kurtosis = 0.0L;

	if (m > 0 && n > 0) {
		mc_mssqrmx1l(m, n, j, a, 0, m1, &sumsq, &scale);
		*m2 = mc_raise2l(scale) * (sumsq / mc_cast(long double, m));
		if (m > 1) {
			q = scale * mc_sqrtl(sumsq / mc_cast(long double, m));
			for (; k <= m; k++) {
				 d  = a[(n * (k - 1)) + j] - *m1;
				*m3 = *m3 + (mc_raise2l(d) * d - *m3) / mc_cast(long double, k);
				*m4 = *m4 + (mc_raise2l(d * d) - *m4) / mc_cast(long double, k);
				if (q != 0.0f) {
					 d        = d / q;
					*skewness = *skewness + (mc_raise2l(d) * d - *skewness) / mc_cast(long double, k);
					*kurtosis = *kurtosis + (mc_raise2l(d * d) - *kurtosis) / mc_cast(long double, k);
				}
			}
		}
	}
}

#endif /* !MC_MOMENTMX1_H */

/* EOF */
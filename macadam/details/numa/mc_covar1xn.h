//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_covar1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_sumtwo1xn.h>
#include <macadam/details/numa/mc_var1xn.h>

#ifndef MC_COVAR1XN_H
#define MC_COVAR1XN_H

#pragma mark - mc_covar1xn -

MC_TARGET_FUNC float mc_covar1xnf(int n, const float * x, const float * y, int b)
{
	float s = 0.0f;
	if (x == y) {
		mc_var1xnf(n, x, b, &s);
	} else {
		int i;
		if (n > 1) {
			const float mux = mc_sumtwo1xnf(n, x) / mc_cast(float, (b ? n - 1 : n));
			const float muy = mc_sumtwo1xnf(n, y) / mc_cast(float, (b ? n - 1 : n));
			for (i = 0; i < n; i++) {
				s = s + (x[i] - mux) * (y[i] - muy);
			}
			s = s / mc_cast(float, (b ? n - 1 : n));
		}
	}
	return s;
}

MC_TARGET_FUNC double mc_covar1xnff(int n, const float * x, const float * y, int b)
{
	double s = 0.0;
	if (x == y) {
		mc_var1xnff(n, x, b, &s);
	} else {
		int i;
		if (n > 1) {
			const double mux = mc_sumtwo1xnff(n, x) / mc_cast(double, (b ? n - 1 : n));
			const double muy = mc_sumtwo1xnff(n, y) / mc_cast(double, (b ? n - 1 : n));
			for (i = 0; i < n; i++) {
				s = s + (x[i] - mux) * (y[i] - muy);
			}
			s = s / mc_cast(double, (b ? n - 1 : n));
		}
	}
	return s;
}

MC_TARGET_FUNC double mc_covar1xn(int n, const double * x, const double * y, int b)
{
	double s = 0.0;
	if (x == y) {
		mc_var1xn(n, x, b, &s);
	} else {
		int i;
		if (n > 1) {
			const double mux = mc_sumtwo1xn(n, x) / mc_cast(double, (b ? n - 1 : n));
			const double muy = mc_sumtwo1xn(n, y) / mc_cast(double, (b ? n - 1 : n));
			for (i = 0; i < n; i++) {
				s = s + (x[i] - mux) * (y[i] - muy);
			}
			s = s / mc_cast(double, (b ? n - 1 : n));
		}
	}
	return s;
}

MC_TARGET_FUNC long double mc_covar1xnl(int n, const long double * x, const long double * y, int b)
{
	long double s = 0.0L;
	if (x == y) {
		mc_var1xnl(n, x, b, &s);
	} else {
		int i;
		if (n > 1) {
			const long double mux = mc_sumtwo1xnl(n, x) / mc_cast(long double, (b ? n - 1 : n));
			const long double muy = mc_sumtwo1xnl(n, y) / mc_cast(long double, (b ? n - 1 : n));
			for (i = 0; i < n; i++) {
				s = s + (x[i] - mux) * (y[i] - muy);
			}
			s = s / mc_cast(long double, (b ? n - 1 : n));
		}
	}
	return s;
}

#endif /* !MC_COVAR1XN_H */

/* EOF */
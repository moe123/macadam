//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sum1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/numa/mc_kahan1xn.h>
#include <macadam/details/numa/mc_klein1xn.h>
#include <macadam/details/numa/mc_neumaier1xn.h>

#ifndef MC_SUM1XN_H
#define MC_SUM1XN_H

#pragma mark - mc_sum1xn -

MC_TARGET_FUNC float mc_sum1xnf(int n, const float * x, int f)
{
	switch (f) {
		case 0:
		{
			int i   = 0;
			float s = 0.0f;
			for (; i < n; i++) {
				s = s + x[i];
			}
			return s;
		}
		case 1:
			return mc_kahan1xnf(n, x);
		break;
		case 2:
			return mc_neumaier1xnf(n, x);
		case 3:
			return mc_klein1xnf(n, x);
		case 4:
		{
			int i   = 0;
			float s = 0.0f;
			for (; i < n; i++) {
				s = s + mc_fabsf(x[i]);
			}
			return s;
		}
	}
	return 0.0f;
}

MC_TARGET_FUNC double mc_sum1xnff(int n, const float * x, int f)
{
	switch (f) {
		case 0:
		{
			int i    = 0;
			double s = 0.0;
			for (; i < n; i++) {
				s = s + mc_cast(float, x[i]);
			}
			return s;
		}
		case 1:
			return mc_kahan1xnff(n, x);
		break;
		case 2:
			return mc_neumaier1xnff(n, x);
		case 3:
			return mc_klein1xnff(n, x);
		case 4:
		{
			int i    = 0;
			double s = 0.0;
			for (; i < n; i++) {
				s = s + mc_fabs(mc_cast(float, x[i]));
			}
			return s;
		}
	}
	return 0.0;
}

MC_TARGET_FUNC double mc_sum1xn(int n, const double * x, int f)
{
	switch (f) {
		case 0:
		{
			int i    = 0;
			double s = 0.0;
			for (; i < n; i++) {
				s = s + x[i];
			}
			return s;
		}
		case 1:
			return mc_kahan1xn(n, x);
		break;
		case 2:
			return mc_neumaier1xn(n, x);
		case 3:
			return mc_klein1xn(n, x);
		case 4:
		{
			int i    = 0;
			double s = 0.0;
			for (; i < n; i++) {
				s = s + mc_fabs(x[i]);
			}
			return s;
		}
	}
	return 0.0;
}

MC_TARGET_FUNC long double mc_sum1xnl(int n, const long double * x, int f)
{
	
	switch (f) {
		case 0:
		{
			int i         = 0;
			long double s = 0.0L;
			for (; i < n; i++) {
				s = s + x[i];
			}
			return s;
		}
		case 1:
			return mc_kahan1xnl(n, x);
		break;
		case 2:
			return mc_neumaier1xnl(n, x);
		case 3:
			return mc_klein1xnl(n, x);
		case 4:
		{
			int i         = 0;
			long double s = 0.0L;
			for (; i < n; i++) {
				s = s + mc_fabsl(x[i]);
			}
			return s;
		}
	}
	return 0.0L;
}

#endif /* !MC_SUM1XN_H */

/* EOF */
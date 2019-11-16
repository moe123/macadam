//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sum1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

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
		{ //!# Kahan summation.
			int i   = 0;
			float s = 0.0f, c = 0.0f;
			for (; i < n; i++) {
				const float u = x[i] - c;
				const float w = s + u;
				c             = (w - s) - u;
				s             = w;
			}
			return s;
		}
		case 2:
		{ //!# Neumaier summation.
			int i   = 0;
			float s = 0.0f, c = 0.0f, u, w;
			for (; i < n; i++) {
				w = x[i];
				u = s + w;
				c = c + (mc_fabsf(s) >= mc_fabsf(w) ? (s - u) + w :  (w - u) + s);
				s = u;
			}
			return s + c;
		}
		case 3:
		{ //!# Klein summation.
			int i   = 0;
			float s = 0.0f, c = 0.0f, cs = 0.0f, ccs = 0.0f, cc, t, w;
			for (; i < n; i++) {
				w = x[i];
				t = s + w;
				if (mc_fabsf(s) >= mc_fabsf(w)) {
					c = (s - t) + w;
				} else {
					c = (w - t) + s;
				}
				s = t;
				t = cs + c;
				if (mc_fabsf(cs) >= mc_fabsf(c)) {
					cc = (cs - t) + c;
				} else {
					cc = (c - t) + cs;
				}
				cs  = t;
				ccs = ccs + cc;
			}
			return s + cs + ccs;
		}
		case 4:
		{//!# Absolute summation.
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
		{ //!# Kahan summation.
			int i    = 0;
			double s = 0.0, c = 0.0;
			for (; i < n; i++) {
				const double u = mc_cast(double, x[i]) - c;
				const double w = s + u;
				c              = (w - s) - u;
				s              = w;
			}
			return s;
		}
		case 2:
		{ //!# Neumaier summation.
			int i    = 0;
			double s = 0.0, c = 0.0, u, w;
			for (; i < n; i++) {
				w = mc_cast(double, x[i]);
				u = s + w;
				c = c + (mc_fabs(s) >= mc_fabs(w) ? (s - u) + w :  (w - u) + s);
				s = u;
			}
			return s + c;
		}
		case 3:
		{ //!# Klein summation.
			int i    = 0;
			double s = 0.0, c = 0.0, cs = 0.0, ccs = 0.0, cc, t, w;
			for (; i < n; i++) {
				w = mc_cast(double, x[i]);
				t = s + w;
				if (mc_fabs(s) >= mc_fabs(w)) {
					c = (s - t) + w;
				} else {
					c = (w - t) + s;
				}
				s = t;
				t = cs + c;
				if (mc_fabs(cs) >= mc_fabs(c)) {
					cc = (cs - t) + c;
				} else {
					cc = (c - t) + cs;
				}
				cs  = t;
				ccs = ccs + cc;
			}
			return s + cs + ccs;
		}
		case 4:
		{//!# Absolute summation.
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
		{ //!# Kahan summation.
			int i    = 0;
			double s = 0.0, c = 0.0;
			for (; i < n; i++) {
				const double u = x[i] - c;
				const double w = s + u;
				c              = (w - s) - u;
				s              = w;
			}
			return s;
		}
		case 2:
		{ //!# Neumaier summation.
			int i    = 0;
			double s = 0.0, c = 0.0, u, w;
			for (; i < n; i++) {
				w = x[i];
				u = s + w;
				c = c + (mc_fabs(s) >= mc_fabs(w) ? (s - u) + w :  (w - u) + s);
				s = u;
			}
			return s + c;
		}
		case 3:
		{ //!# Klein summation.
			int i    = 0;
			double s = 0.0, c = 0.0, cs = 0.0, ccs = 0.0, cc, t, w;
			for (; i < n; i++) {
				w = x[i];
				t = s + w;
				if (mc_fabs(s) >= mc_fabs(w)) {
					c = (s - t) + w;
				} else {
					c = (w - t) + s;
				}
				s = t;
				t = cs + c;
				if (mc_fabs(cs) >= mc_fabs(c)) {
					cc = (cs - t) + c;
				} else {
					cc = (c - t) + cs;
				}
				cs  = t;
				ccs = ccs + cc;
			}
			return s + cs + ccs;
		}
		case 4:
		{//!# Absolute summation.
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
		{ //!# Kahan summation.
			int i         = 0;
			long double s = 0.0L, c = 0.0L;
			for (; i < n; i++) {
				const long double u = x[i] - c;
				const long double w = s + u;
				c                   = (w - s) - u;
				s                   = w;
			}
			return s;
		}
		case 2:
		{ //!# Neumaier summation.
			int i         = 0;
			long double s = 0.0L, c = 0.0L, u, w;
			for (; i < n; i++) {
				w = x[i];
				u = s + w;
				c = c + (mc_fabsl(s) >= mc_fabsl(w) ? (s - u) + w :  (w - u) + s);
				s = u;
			}
			return s + c;
		}
		case 3:
		{ //!# Klein summation.
			int i         = 0;
			long double s = 0.0L, c = 0.0L, cs = 0.0L, ccs = 0.0L, cc, t, w;
			for (; i < n; i++) {
				w = x[i];
				t = s + w;
				if (mc_fabsl(s) >= mc_fabsl(w)) {
					c = (s - t) + w;
				} else {
					c = (w - t) + s;
				}
				s = t;
				t = cs + c;
				if (mc_fabsl(cs) >= mc_fabsl(c)) {
					cc = (cs - t) + c;
				} else {
					cc = (c - t) + cs;
				}
				cs  = t;
				ccs = ccs + cc;
			}
			return s + cs + ccs;
		}
		case 4:
		{//!# Absolute summation.
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
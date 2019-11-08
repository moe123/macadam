//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_klein1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_SUM_KLEIN1XN_H
#define MC_SUM_KLEIN1XN_H

#pragma mark - mc_klein1xn -

MC_TARGET_FUNC float mc_klein1xnf(int n, const float * x)
{
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

MC_TARGET_FUNC double mc_klein1xnff(int n, const float * x)
{
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

MC_TARGET_FUNC double mc_klein1xn(int n, const double * x)
{
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

MC_TARGET_FUNC long double mc_klein1xnl(int n, const long double * x)
{
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

#endif /* !MC_SUM_KLEIN1XN_H */

/* EOF */
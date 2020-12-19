//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_histce1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log2.h>
#include <macadam/details/math/mc_logbase.h>

#ifndef MC_HISTCE1XN_H
#define MC_HISTCE1XN_H

#pragma mark - mc_histce1xn -

MC_TARGET_FUNC float mc_histce1xnf(int npts, int binw, int b, const int * h)
{
//!# Requires h[npts] where 1 < n and 0 < binw and 0 < b. Computing the entropy
//!# of a given `counted` histogram (frequency) @see mc_histc1xn or mc_histcg1xn.
//!#     npts  - Size of histogram i.e h[npts].
//!#     binw  - The original bin width.
//!#     b     - The logarithm base, if b is `one`, loge is used i.e nat use base2 for bit unit.

	int i       = 0;
	const int c = binw < 1 ? 1 : binw;
	float e     = 0.0f;

	if (npts > 1 && b > 0) {
		for (; i < npts; i++) {
			const float p  = mc_cast(float, h[i]) / c;
			e             -= p > 0.0f ? p * mc_logbasef(p, b) : 0.0f;
		}
	}
	return e;
}

MC_TARGET_FUNC double mc_histce1xn(int npts, int binw, int b, const int * h)
{
//!# Requires h[npts] where 1 < n and 0 < binw and 0 < b. Computing the entropy
//!# of a given `counted` histogram (frequency) @see mc_histc1xn or mc_histcg1xn.
//!#     npts  - Size of histogram i.e h[npts].
//!#     binw  - The original bin width.
//!#     b     - The logarithm base, if b is `one`, loge is used i.e nat use base2 for bit unit.

	int i       = 0;
	const int c = binw < 1 ? 1 : binw;
	double e    = 0.0f;

	if (npts > 1 && b > 0) {
		for (; i < npts; i++) {
			const double p  = mc_cast(double, h[i]) / c;
			e              -= p > 0.0 ? p * mc_logbase(p, b) : 0.0;
		}
	}
	return e;
}

MC_TARGET_FUNC long double mc_histce1xnl(int npts, int binw, int b, const int * h)
{
//!# Requires h[npts] where 1 < n and 0 < binw and 0 < b. Computing the entropy
//!# of a given `counted` histogram (frequency) @see mc_histc1xn or mc_histcg1xn.
//!#     npts  - Size of histogram i.e h[npts].
//!#     binw  - The original bin width.
//!#     b     - The logarithm base, if b is `one`, loge is used i.e nat use base2 for bit unit.

	int i         = 0;
	const int c   = binw < 1 ? 1 : binw;
	long double e = 0.0f;

	if (npts > 1 && b > 0) {
		for (; i < npts; i++) {
			const long double p  = mc_cast(long double, h[i]) / c;
			e                   -= p > 0.0L ? p * mc_logbasel(p, b) : 0.0L;
		}
	}
	return e;
}

#endif /* !MC_HISTCE1XN_H */

/* EOF */
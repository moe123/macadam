//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hentropy21xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log2.h>

#ifndef MC_HENTROPY21XN_H
#define MC_HENTROPY21XN_H

#pragma mark - mc_hentropy21xn -

MC_TARGET_FUNC float mc_hentropy21xnf(int npts, int nbins, const int * h)
{
	int i       = 0;
	const int c = nbins - 1;
	float e     = 0.0f;
	if (nbins > 1 && npts > 1) {
		for (;i < npts; i++) {
			const float p  = mc_cast(float, h[i]) / c;
			e             -= p * mc_log2f(p);
		}
	}
	return e;
}

MC_TARGET_FUNC double mc_hentropy21xn(int npts, int nbins, const int * h)
{
	int i       = 0;
	const int c = nbins - 1;
	double e    = 0.0f;
	if (nbins > 1 && npts > 1) {
		for (;i < npts; i++) {
			const double p  = mc_cast(double, h[i]) / c;
			e              -= p * mc_log2(p);
		}
	}
	return e;
}

MC_TARGET_FUNC long double mc_hentropy21xnl(int npts, int nbins, const int * h)
{
	int i         = 0;
	const int c   = nbins - 1;
	long double e = 0.0f;
	if (nbins > 1 && npts > 1) {
		for (;i < npts; i++) {
			const long double p  = mc_cast(long double, h[i]) / c;
			e                   -= p * mc_log2l(p);
		}
	}
	return e;
}

#endif /* !MC_HENTROPY21XN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hentropyb1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_logbase.h>

#ifndef MC_HENTROPYB1XN_H
#define MC_HENTROPYB1XN_H

#pragma mark - mc_hentropyb1xn -

MC_TARGET_FUNC float mc_hentropyb1xnf(int npts, int nbins, int b, const int * h)
{
	int i       = 0;
	const int c = nbins - 1;
	float e     = 0.0f;
	if (nbins > 1 && npts > 1 && b > 1) {
		for (;i < npts; i++) {
			const float p  = mc_cast(float, h[i]) / c;
			e             -= p * mc_logbasef(p, b);
		}
	}
	return e;
}

MC_TARGET_FUNC double mc_hentropyb1xn(int npts, int nbins, int b, const int * h)
{
	int i       = 0;
	const int c = nbins - 1;
	double e    = 0.0f;
	if (nbins > 1 && npts > 1 && b > 1) {
		for (;i < npts; i++) {
			const double p  = mc_cast(double, h[i]) / c;
			e              -= p * mc_logbase(p, b);
		}
	}
	return e;
}

MC_TARGET_FUNC long double mc_hentropyb1xnl(int npts, int nbins, int b, const int * h)
{
	int i         = 0;
	const int c   = nbins - 1;
	long double e = 0.0f;
	if (nbins > 1 && npts > 1 && b > 1) {
		for (;i < npts; i++) {
			const long double p  = mc_cast(long double, h[i]) / c;
			e                   -= p * mc_logbasel(p, b);
		}
	}
	return e;
}

#endif /* !MC_HENTROPYB1XN_H */

/* EOF */
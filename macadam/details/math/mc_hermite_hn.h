//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hermite_hn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_HERMITE_HN_H
#define MC_HERMITE_HN_H

#pragma mark - mc_hermite_hn -

static MC_TARGET_INLINE float mc_hermite_hnf(unsigned int n, float x)
{
//!# nth physicists' Hermite polynomial.
	float hi       = 0.0f;
	float h0       = 0.0f;
	float h1       = 0.0f;
	unsigned int i = 2;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0f;
		h1 = 2.0f * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(float, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0f * hi;
		}
	}
	return h1;
}

static MC_TARGET_INLINE double mc_hermite_hn(unsigned int n, double x)
{
//!# nth physicists' Hermite polynomial.
	double hi      = 0.0;
	double h0      = 0.0;
	double h1      = 0.0;
	unsigned int i = 2;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0;
		h1 = 2.0 * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(double, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0 * hi;
		}
	}
	return h1;
}

static MC_TARGET_INLINE long double mc_hermite_hnl(unsigned int n, long double x)
{
//!# nth physicists' Hermite polynomial.
	long double hi = 0.0L;
	long double h0 = 0.0L;
	long double h1 = 0.0L;
	unsigned int i = 2;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0L;
		h1 = 2.0L * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(long double, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0L * hi;
		}
	}
	return h1;
}

#endif /* !MC_HERMITE_HN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nthroot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fhrt.h>

#ifndef MC_NTHROOT_H
#define MC_NTHROOT_H

#pragma mark - mc_nthroot -

static MC_TARGET_INLINE float mc_nthrootf(float x, unsigned int n)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
#	if MC_TARGET_CPP98
			return ::sqrtf(x);
#	else
			return sqrtf(x);
#	endif
		}
		if (n == 3) {
#	if MC_TARGET_CPP98
			return ::cbrtf(x);
#	else
			return cbrtf(x);
#	endif
		}
		if (n == 4) {
			return mc_fhrtf(x);
		}
		if (x < 0.0f && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const float r = 1.0f / mc_cast(float, n);
#	if MC_TARGET_CPP98
		return ::powf(x, r);
#	else
		return powf(x, r);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE double mc_nthroot(double x, unsigned int n)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
#	if MC_TARGET_CPP98
			return ::sqrt(x);
#	else
			return sqrt(x);
#	endif
		}
		if (n == 3) {
#	if MC_TARGET_CPP98
			return ::cbrt(x);
#	else
			return cbrt(x);
#	endif
		}
		if (n == 4) {
			return mc_fhrt(x);
		}
		if (x < 0.0 && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const double r = 1.0 / mc_cast(double, n);
#	if MC_TARGET_CPP98
		return ::pow(x, r);
#	else
		return pow(x, r);
#	endif
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE long double mc_nthrootl(long double x, unsigned int n)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
#	if MC_TARGET_CPP98
			return ::sqrtl(x);
#	else
			return sqrtl(x);
#	endif
		}
		if (n == 3) {
#	if MC_TARGET_CPP98
			return ::cbrtl(x);
#	else
			return cbrtl(x);
#	endif
		}
		if (n == 4) {
			return mc_fhrtl(x);
		}
		if (x < 0.0L && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const long double r = 1.0L / mc_cast(long double, n);
#	if MC_TARGET_CPP98
		return ::powl(x, r);
#	else
		return powl(x, r);
#	endif
	}
	return MCK_NAN;
}

#endif /* !MC_NTHROOT_H */

/* EOF */
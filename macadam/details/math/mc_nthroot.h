//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nthroot.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cbrt.h>
#include <macadam/details/math/mc_fhrt.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_NTHROOT_H
#define MC_NTHROOT_H

#pragma mark - mc_nthroot -

MC_TARGET_PROC float mc_nthrootf(unsigned int n, float x)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
			return mc_sqrtf(x);
		}
		if (n == 3) {
			return mc_cbrtf(x);
		}
		if (n == 4) {
			return mc_fhrtf(x);
		}
		if (x < 0.0f && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const float r = 1.0f / mc_cast(float, n);
		return mc_powf(x, r);
	}
	return MCK_NAN;
}

MC_TARGET_PROC double mc_nthroot(unsigned int n, double x)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
			return mc_sqrt(x);
		}
		if (n == 3) {
			return mc_cbrt(x);
		}
		if (n == 4) {
			return mc_fhrt(x);
		}
		if (x < 0.0 && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const double r = 1.0 / mc_cast(double, n);
		return mc_pow(x, r);
	}
	return MCK_NAN;
}

MC_TARGET_PROC long double mc_nthrootl(unsigned int n, long double x)
{
	if (n > 0 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			return x;
		}
		if (n == 2) {
			return mc_sqrtl(x);
		}
		if (n == 3) {
			return mc_cbrtl(x);
		}
		if (n == 4) {
			return mc_fhrtl(x);
		}
		if (x < 0.0L && ((n % 2) == 0)) {
			return MCK_NAN;
		}
		const long double r = 1.0L / mc_cast(long double, n);
		return mc_powl(x, r);
	}
	return MCK_NAN;
}

#endif /* !MC_NTHROOT_H */

/* EOF */
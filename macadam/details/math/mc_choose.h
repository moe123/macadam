//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_choose.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_factorial.h>
#include <macadam/details/math/mc_beta.h>

#ifndef MC_CHOOSE_H
#define MC_CHOOSE_H

#pragma mark - mc_choose -

static MC_TARGET_INLINE float mc_choosef(unsigned int n, unsigned int k)
{
	float r                 = MCLIMITS_MAXF;
	const int max_factorial = 35;
	if (n < MCLIMITS_UIMAX && k < MCLIMITS_UIMAX) {
		if(k > n) {
			return MCLIMITS_MAXF;
		} else if((k == 0) || (k == n)) {
			return mc_cast(float, 1);
		} else if((k == 1) || (k == n - 1)) {
			return mc_cast(float, n);
		}
		if(n < max_factorial) {
			r  = mc_factorialf(n);
			r /= mc_factorialf(n - k);
			r /= mc_factorialf(k);
#	if MC_TARGET_CPP98
			r  = ::ceilf(r - 0.5f);
#	else
			r  = ceilf(r - 0.5f);
#	endif
		} else {
			r = (k < (n - k))
				? (k - 0) * mc_betaf(mc_cast(float, (k + 0)), mc_cast(float, (n - k + 1)))
				: (n - k) * mc_betaf(mc_cast(float, (k + 1)), mc_cast(float, (n - k + 0)))
			;
			if(r != 0) {
				r = 1.0f / r;
#	if MC_TARGET_CPP98
				r = ::ceilf(r - 0.5f);
#	else
				r = ceilf(r - 0.5f);
#	endif
			} else {
				r = MCLIMITS_MAXF;
			}
		}
	}
	return r;
}

static MC_TARGET_INLINE double mc_choose(unsigned int n, unsigned int k)
{
	double r                = MCLIMITS_MAX;
	const int max_factorial = 171;
	if (n < MCLIMITS_UIMAX && k < MCLIMITS_UIMAX) {
		if(k > n) {
			return MCLIMITS_MAX;
		} else if((k == 0) || (k == n)) {
			return mc_cast(double, 1);
		} else if((k == 1) || (k == n - 1)) {
			return mc_cast(double, n);
		}
		if(n < max_factorial) {
			r  = mc_factorial(n);
			r /= mc_factorial(n - k);
			r /= mc_factorial(k);
#	if MC_TARGET_CPP98
			r  = ::ceil(r - 0.5);
#	else
			r  = ceil(r - 0.5);
#	endif
		} else {
			r = (k < (n - k))
				? (k - 0) * mc_beta(mc_cast(double, (k + 0)), mc_cast(double, (n - k + 1)))
				: (n - k) * mc_beta(mc_cast(double, (k + 1)), mc_cast(double, (n - k + 0)))
			;
			if(r != 0) {
				r = 1.0f / r;
#	if MC_TARGET_CPP98
				r = ::ceil(r - 0.5);
#	else
				r = ceil(r - 0.5);
#	endif
			} else {
				r = MCLIMITS_MAX;
			}
		}
	}
	return r;
}

static MC_TARGET_INLINE double mc_choosel(unsigned int n, unsigned int k)
{
	long double r = MCLIMITS_MAXL;
#	if MC_TARGET_MSVC_CPP
	const int max_factorial = 171;
#	else
	const int max_factorial = 1755;
#	endif
	if (n < MCLIMITS_UIMAX && k < MCLIMITS_UIMAX) {
		if(k > n) {
			return MCLIMITS_MAXL;
		} else if((k == 0) || (k == n)) {
			return mc_cast(long double, 1);
		} else if((k == 1) || (k == n - 1)) {
			return mc_cast(long double, n);
		}
		if(n < max_factorial) {
			r  = mc_cast(long double, mc_factoriall(n));
			r /= mc_cast(long double, mc_factoriall(n - k));
			r /= mc_cast(long double, mc_factoriall(k));
#	if MC_TARGET_CPP98
			r  = ::ceill(r - 0.5L);
#	else
			r  = ceill(r - 0.5L);
#	endif
		} else {
			r = (k < (n - k))
				? (k - 0) * mc_betal(mc_cast(long double, (k + 0)), mc_cast(long double, (n - k + 1)))
				: (n - k) * mc_betal(mc_cast(long double, (k + 1)), mc_cast(long double, (n - k + 0)))
			;
			if(r != 0) {
				r = 1.0f / r;
#	if MC_TARGET_CPP98
				r = ::ceill(r - 0.5L);
#	else
				r = ceill(r - 0.5L);
#	endif
			} else {
				r = MCLIMITS_MAXL;
			}
		}
	}
	return r;
}

#endif /* !MC_CHOOSE_H */

/* EOF */
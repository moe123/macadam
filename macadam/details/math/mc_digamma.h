//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_digamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_DIGAMMA_H
#define MC_DIGAMMA_H

#pragma mark - mc_digamma -

static MC_TARGET_INLINE float mc_digammaf(float x)
{
	if (x <= 1E-5) {
		return -MCK_KF(MCK_G) - (1.0f / x);
	}
	if (x < 8.5f) {
		return mc_digammaf(1.0f + x) - 1.0f / x;
	}
#	if MC_TARGET_CPP98
	const float p = ::powf(x, -2.0f);
	return (
		::logf(x) - 0.5f / x
		+ MCK_KF(MCK_ZETA_N1)  * p
		+ MCK_KF(MCK_ZETA_N3)  * ::powf(p, 2)
		+ MCK_KF(MCK_ZETA_N5)  * ::powf(p, 3)
		+ MCK_KF(MCK_ZETA_N7)  * ::powf(p, 4)
		+ MCK_KF(MCK_ZETA_N9)  * ::powf(p, 5)
		+ MCK_KF(MCK_ZETA_N11) * ::powf(p, 6)
	);
#	else
	const float p = powf(x, -2.0f);
	return (
		logf(x) - 0.5f / x
		+ MCK_KF(MCK_ZETA_N1)  * p
		+ MCK_KF(MCK_ZETA_N3)  * powf(p, 2)
		+ MCK_KF(MCK_ZETA_N5)  * powf(p, 3)
		+ MCK_KF(MCK_ZETA_N7)  * powf(p, 4)
		+ MCK_KF(MCK_ZETA_N9)  * powf(p, 5)
		+ MCK_KF(MCK_ZETA_N11) * powf(p, 6)
	);
#	endif
}

static MC_TARGET_INLINE double mc_digamma(double x)
{
	if (x <= 1E-5) {
		return -MCK_K(MCK_G) - (1.0 / x);
	}
	if (x < 8.5) {
		return mc_digamma(1.0 + x) - 1.0 / x;
	}
#	if MC_TARGET_CPP98
	const double p = ::pow(x, -2.0);
	return (
		::log(x) - 0.5 / x
		+ MCK_K(MCK_ZETA_N1)  * p
		+ MCK_K(MCK_ZETA_N3)  * ::pow(p, 2)
		+ MCK_K(MCK_ZETA_N5)  * ::pow(p, 3)
		+ MCK_K(MCK_ZETA_N7)  * ::pow(p, 4)
		+ MCK_K(MCK_ZETA_N9)  * ::pow(p, 5)
		+ MCK_K(MCK_ZETA_N11) * ::pow(p, 6)
	);
#	else
	const double p = pow(x, -2.0);
	return (
		log(x) - 0.5 / x
		+ MCK_K(MCK_ZETA_N1)  * p
		+ MCK_K(MCK_ZETA_N3)  * pow(p, 2)
		+ MCK_K(MCK_ZETA_N5)  * pow(p, 3)
		+ MCK_K(MCK_ZETA_N7)  * pow(p, 4)
		+ MCK_K(MCK_ZETA_N9)  * pow(p, 5)
		+ MCK_K(MCK_ZETA_N11) * pow(p, 6)
	);
#	endif
}

static MC_TARGET_INLINE long double mc_digammal(long double x)
{
	if (x <= 1E-5) {
		return -MCK_KL(MCK_G) - (1.0L / x);
	}
	if (x < 8.5L) {
		return mc_digammal(1.0L + x) - 1.0L / x;
	}
#	if MC_TARGET_CPP98
	const long double p = ::powl(x, -2.0L);
	return (
		::logl(x) - 0.5L / x
		+ MCK_KL(MCK_ZETA_N1)  * p
		+ MCK_KL(MCK_ZETA_N3)  * ::powl(p, 2)
		+ MCK_KL(MCK_ZETA_N5)  * ::powl(p, 3)
		+ MCK_KL(MCK_ZETA_N7)  * ::powl(p, 4)
		+ MCK_KL(MCK_ZETA_N9)  * ::powl(p, 5)
		+ MCK_KL(MCK_ZETA_N11) * ::powl(p, 6)
	);
#	else
	const long double p = powl(x, -2.0L);
	return (
		logl(x) - 0.5L / x
		+ MCK_KL(MCK_ZETA_N1)  * p
		+ MCK_KL(MCK_ZETA_N3)  * powl(p, 2)
		+ MCK_KL(MCK_ZETA_N5)  * powl(p, 3)
		+ MCK_KL(MCK_ZETA_N7)  * powl(p, 4)
		+ MCK_KL(MCK_ZETA_N9)  * powl(p, 5)
		+ MCK_KL(MCK_ZETA_N11) * powl(p, 6)
	);
#	endif
}

#endif /* !MC_DIGAMMA_H */

/* EOF */
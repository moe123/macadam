//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_digamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>

#ifndef MC_DIGAMMA_H
#define MC_DIGAMMA_H

#pragma mark - mc_digamma -

MC_TARGET_FUNC float mc_digammaf(float x)
{
	if (x <= 1E-5) {
		return -MCK_KF(MCK_G) - (1.0f / x);
	}
	if (x < 8.5f) {
		return mc_digammaf(1.0f + x) - 1.0f / x;
	}
	const float p = mc_powf(x, -2.0f);
	return (
		mc_logf(x) - 0.5f / x
		+ MCK_KF(MCK_ZETA_N1)  * p
		+ MCK_KF(MCK_ZETA_N3)  * mc_powf(p, 2)
		+ MCK_KF(MCK_ZETA_N5)  * mc_powf(p, 3)
		+ MCK_KF(MCK_ZETA_N7)  * mc_powf(p, 4)
		+ MCK_KF(MCK_ZETA_N9)  * mc_powf(p, 5)
		+ MCK_KF(MCK_ZETA_N11) * mc_powf(p, 6)
	);
}

MC_TARGET_FUNC double mc_digamma(double x)
{
	if (x <= 1E-5) {
		return -MCK_K(MCK_G) - (1.0 / x);
	}
	if (x < 8.5) {
		return mc_digamma(1.0 + x) - 1.0 / x;
	}
	const double p = mc_pow(x, -2.0);
	return (
		mc_log(x) - 0.5 / x
		+ MCK_K(MCK_ZETA_N1)  * p
		+ MCK_K(MCK_ZETA_N3)  * mc_pow(p, 2)
		+ MCK_K(MCK_ZETA_N5)  * mc_pow(p, 3)
		+ MCK_K(MCK_ZETA_N7)  * mc_pow(p, 4)
		+ MCK_K(MCK_ZETA_N9)  * mc_pow(p, 5)
		+ MCK_K(MCK_ZETA_N11) * mc_pow(p, 6)
	);
}

MC_TARGET_FUNC long double mc_digammal(long double x)
{
	if (x <= 1E-5) {
		return -MCK_KL(MCK_G) - (1.0L / x);
	}
	if (x < 8.5L) {
		return mc_digammal(1.0L + x) - 1.0L / x;
	}
	const long double p = mc_powl(x, -2.0L);
	return (
		mc_logl(x) - 0.5L / x
		+ MCK_KL(MCK_ZETA_N1)  * p
		+ MCK_KL(MCK_ZETA_N3)  * mc_powl(p, 2)
		+ MCK_KL(MCK_ZETA_N5)  * mc_powl(p, 3)
		+ MCK_KL(MCK_ZETA_N7)  * mc_powl(p, 4)
		+ MCK_KL(MCK_ZETA_N9)  * mc_powl(p, 5)
		+ MCK_KL(MCK_ZETA_N11) * mc_powl(p, 6)
	);
}

#endif /* !MC_DIGAMMA_H */

/* EOF */
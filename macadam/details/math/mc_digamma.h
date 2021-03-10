//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_digamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>

#ifndef MC_DIGAMMA_H
#define MC_DIGAMMA_H

#pragma mark - mc_digamma_approx0 -

MC_TARGET_PROC float mc_digammaf_approx0(const float x)
{
//!# Returns psi0(x) by generalized power series expansion.
	if (x <= 1E-5) {
		return -MCK_KF(MCK_G) - (1.0f / x);
	}
	if (x < 8.5f) {
		return mc_digammaf_approx0(1.0f + x) - 1.0f / x;
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

MC_TARGET_PROC double mc_digamma_approx0(const double x)
{
//!# Returns psi0(x) by generalized power series expansion.
	if (x <= 1E-5) {
		return -MCK_K(MCK_G) - (1.0 / x);
	}
	if (x < 8.5) {
		return mc_digamma_approx0(1.0 + x) - 1.0 / x;
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

MC_TARGET_PROC long double mc_digammal_approx0(const long double x)
{
#	if MC_TARGET_HAVE_LONG_DOUBLE
//!# Returns psi0(x) by generalized power series expansion.
	if (x <= 1E-5) {
		return -MCK_KL(MCK_G) - (1.0L / x);
	}
	if (x < 8.5L) {
		return mc_digammal_approx0(1.0L + x) - 1.0L / x;
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
#	else
	return mc_cast(long double, mc_digamma_approx0(mc_cast(const double, x)));
#	endif
}

#pragma mark - mc_digamma_approx1 -

MC_TARGET_PROC float mc_digammaf_approx1(const float x)
{
//!# Returns psi0(x) by Taylor series expansion.
	const float c1 = -8.33333333333333290000000000000000000000E-02f;
	const float c2 = +8.33333333333333320000000000000000000000E-03f;
	const float c3 = -3.96825396825396800000000000000000000000E-03f;
	const float c4 = +4.16666666666666660000000000000000000000E-03f;
	const float c5 = -7.57575757575757600000000000000000000000E-03f;
	const float c6 = +2.10927960927960940000000000000000000000E-02f;
	const float c7 = -8.33333333333333290000000000000000000000E-02f;

	float r = 0.0f, y, w = x;

	do {
		r = r - (1.0f / w);
		w = w + 1.0f;
	} while (w < 10.0f);

	y = mc_raise2f(w);
	r = r + (mc_logf(w) - 0.5f / w);
	w = y;

	r = r + (c1 * (1.0f / w));
	w = w * y;
	r = r + (c2 * (1.0f / w));
	w = w * y;
	r = r + (c3 * (1.0f / w));
	w = w * y;
	r = r + (c4 * (1.0f / w));
	w = w * y;
	r = r + (c5 * (1.0f / w));
	w = w * y;
	r = r + (c6 * (1.0f / w));
	w = w * y;
	r = r + (c7 * (1.0f / w));

	return r;
}

MC_TARGET_PROC double mc_digamma_approx1(const double x)
{
//!# Returns psi0(x) by Taylor series expansion.
	const double c1 = -8.3333333333333329000000000000000000000000E-02;
	const double c2 = +8.3333333333333332000000000000000000000000E-03;
	const double c3 = -3.9682539682539680000000000000000000000000E-03;
	const double c4 = +4.1666666666666666000000000000000000000000E-03;
	const double c5 = -7.5757575757575760000000000000000000000000E-03;
	const double c6 = +2.1092796092796094000000000000000000000000E-02;
	const double c7 = -8.3333333333333329000000000000000000000000E-02;

	double r = 0.0, y, w = x;

	do {
		r = r - (1.0 / w);
		w = w + 1.0;
	} while (w < 10.0);

	y = mc_raise2(w);
	r = r + (mc_log(w) - 0.5 / w);
	w = y;

	r = r + (c1 * (1.0 / w));
	w = w * y;
	r = r + (c2 * (1.0 / w));
	w = w * y;
	r = r + (c3 * (1.0 / w));
	w = w * y;
	r = r + (c4 * (1.0 / w));
	w = w * y;
	r = r + (c5 * (1.0 / w));
	w = w * y;
	r = r + (c6 * (1.0 / w));
	w = w * y;
	r = r + (c7 * (1.0 / w));

	return r;
}

MC_TARGET_PROC long double mc_digammal_approx1(const long double x)
{
#	if MC_TARGET_HAVE_LONG_DOUBLE
//!# Returns psi0(x) by Taylor series expansion.
	const long double c1 = -8.333333333333332900000000000000000000000000000000000000000000000E-02L;
	const long double c2 = +8.333333333333333200000000000000000000000000000000000000000000000E-03L;
	const long double c3 = -3.968253968253968000000000000000000000000000000000000000000000000E-03L;
	const long double c4 = +4.166666666666666600000000000000000000000000000000000000000000000E-03L;
	const long double c5 = -7.575757575757576000000000000000000000000000000000000000000000000E-03L;
	const long double c6 = +2.109279609279609400000000000000000000000000000000000000000000000E-02L;
	const long double c7 = -8.333333333333332900000000000000000000000000000000000000000000000E-02L;

	long double r = 0.0L, y, w = x;

	do {
		r = r - (1.0L / w);
		w = w + 1.0L;
	} while (w < 10.0L);

	y = mc_raise2l(w);
	r = r + (mc_logl(w) - 0.5L / w);
	w = y;

	r = r + (c1 * (1.0L / w));
	w = w * y;
	r = r + (c2 * (1.0L / w));
	w = w * y;
	r = r + (c3 * (1.0L / w));
	w = w * y;
	r = r + (c4 * (1.0L / w));
	w = w * y;
	r = r + (c5 * (1.0L / w));
	w = w * y;
	r = r + (c6 * (1.0L / w));
	w = w * y;
	r = r + (c7 * (1.0L / w));

	return r;
#	else
	return mc_cast(long double, mc_digamma_approx1(mc_cast(const double, x)));
#	endif
}

#pragma mark - mc_digamma -

MC_TARGET_FUNC float mc_digammaf(const float x)
{
	return mc_digammaf_approx1(x);
}

MC_TARGET_FUNC double mc_digamma(const double x)
{
	return mc_digamma_approx1(x);
}

MC_TARGET_FUNC long double mc_digammal(const long double x)
{
	return mc_digammal_approx1(x);
}

#endif /* !MC_DIGAMMA_H */

/* EOF */
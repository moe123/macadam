//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_GAMMA_H
#define MC_GAMMA_H

#pragma mark - mc_gamma_approx0 -

MC_TARGET_PROC float mc_gammaf_approx0(float x)
{
//!# Stirling's formula formula for x >= 13.
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x * MCK_KF(MCK_1_E);
	return mc_sqrtf(a) * mc_powf(b, x);
}

MC_TARGET_PROC double mc_gamma_approx0(double x)
{
//!# Stirling's formula formula for x >= 13.
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x * MCK_K(MCK_1_E);
	return mc_sqrt(a) * mc_pow(b, x);
}

MC_TARGET_PROC long double mc_gammal_approx0(long double x)
{
//!# Stirling's formula formula for x >= 13.
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x * MCK_KL(MCK_1_E);
	return mc_sqrtl(a) * mc_powl(b, x);
}

#pragma mark - mc_gamma_approx1 -

MC_TARGET_PROC float mc_gammaf_approx1(float x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
	const float r = mc_lgammaf_approx1(x);
	return mc_expf(r);
}

MC_TARGET_PROC double mc_gamma_approx1(double x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
	const double r = mc_lgamma_approx1(x);
	return mc_exp(r);
}

MC_TARGET_PROC long double mc_gammal_approx1(long double x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
	const long double r = mc_lgammal_approx1(x);
	return mc_expl(r);
}

#pragma mark - mc_gamma -

MC_TARGET_FUNC float mc_gammaf(float x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
#	if MC_TARGET_EMBEDDED
	return mc_expf(mc_lgammaf(x));
#	else
#	if MC_TARGET_CPP98
	return ::tgammaf(x);
#	else
	return tgammaf(x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_gamma(double x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
#	if MC_TARGET_EMBEDDED
	return mc_exp(mc_lgamma(x));
#	else
#	if MC_TARGET_CPP98
	return ::tgamma(x);
#	else
	return tgamma(x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_gammal(long double x)
{
	if (isnan(x) || isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
#	if MC_TARGET_EMBEDDED
	return mc_expl(mc_lgammal(x));
#	else
#	if MC_TARGET_CPP98
	return ::tgammal(x);
#	else
	return tgammal(x);
#	endif
#	endif
}

#endif /* !MC_GAMMA_H */

/* EOF */
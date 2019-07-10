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

static MC_TARGET_INLINE double mc_gammaf_approx0(float x)
{
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x * MCK_KF(MCK_1_E);
	return mc_sqrtf(a) * mc_powf(b, x);
}

static MC_TARGET_INLINE double mc_gamma_approx0(double x)
{
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x * MCK_K(MCK_1_E);
	return mc_sqrt(a) * mc_pow(b, x);
}

static MC_TARGET_INLINE long double mc_gammal_approx0(long double x)
{
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x * MCK_KL(MCK_1_E);
	return mc_sqrtl(a) * mc_powl(b, x);
}

#pragma mark - mc_gamma -

static MC_TARGET_INLINE
float mc_gammaf(float x)
{
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

static MC_TARGET_INLINE
double mc_gamma(double x)
{
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

static MC_TARGET_INLINE
long double mc_gammal(long double x)
{
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
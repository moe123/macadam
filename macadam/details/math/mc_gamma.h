//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>

#ifndef MC_GAMMA_H
#define MC_GAMMA_H

#pragma mark - mc_gamma_approx0 -

static MC_TARGET_INLINE double mc_gammaf_approx0(float x)
{
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x / MCK_KF(MCK_E);
#	if MC_TARGET_CPP98
	return ::sqrtf(a) * ::powf(b, x);
#	else
	return sqrtf(a) * powf(b, x);
#	endif
}

static MC_TARGET_INLINE double mc_gamma_approx0(double x)
{
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x / MCK_K(MCK_E);
#	if MC_TARGET_CPP98
	return ::sqrt(a) * ::pow(b, x);
#	else
	return sqrt(a) * pow(b, x);
#	endif
}

static MC_TARGET_INLINE long double mc_gammal_approx0(long double x)
{
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x / MCK_KL(MCK_E);
#	if MC_TARGET_CPP98
	return ::sqrtl(a) * ::powl(b, x);
#	else
	return sqrtl(a) * powl(b, x);
#	endif
}

#pragma mark - mc_gamma -

static MC_TARGET_INLINE
float mc_gammaf(float x)
{
#	if MC_TARGET_EMBEDDED
#	if MC_TARGET_CPP98
	return ::expf(mc_lgammaf(x));
#	else
	return expf(mc_lgammaf(x));
#	endif
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
#	if MC_TARGET_CPP98
	return ::exp(mc_lgamma(x));
#	else
	return exp(mc_lgamma(x));
#	endif
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
#	if MC_TARGET_CPP98
	return ::expl(mc_lgammal(x));
#	else
	return expl(mc_lgammal(x));
#	endif
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
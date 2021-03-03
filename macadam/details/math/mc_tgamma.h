//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tgamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gamma.h>

#ifndef MC_TGAMMA_H
#define MC_TGAMMA_H

#pragma mark - mc_tgamma -

MC_TARGET_FUNC float mc_tgammaf(const float x)
{
//!# Computes exp(log(|gamma(x)|)).
#	if MC_TARGET_EMBEDDED
	return mc_gammaf(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgammaf(x);
#	else
	return tgammaf(x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_tgamma(const double x)
{
//!# Computes exp(log(|gamma(x)|)).
#	if MC_TARGET_EMBEDDED
	return mc_gamma(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgamma(x);
#	else
	return tgamma(x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_tgammal(const long double x)
{
//!# Computes exp(log(|gamma(x)|)).
#	if MC_TARGET_EMBEDDED
	return mc_gammal(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgammal(x);
#	else
	return tgammal(x);
#	endif
#	endif
}

#endif /* !MC_TGAMMA_H */

/* EOF */
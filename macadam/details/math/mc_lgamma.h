//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lgamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gammaln.h>

#ifndef MC_LGAMMA_H
#define MC_LGAMMA_H

#pragma mark - mc_lgamma -

MC_TARGET_FUNC float mc_lgammaf(const float x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	return mc_gammalnf(x);
#	else
#	if MC_TARGET_CPP98
	return ::lgammaf(x);
#	else
	return lgammaf(x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_lgamma(const double x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	return mc_gammaln(x);
#	else
#	if MC_TARGET_CPP98
	return ::lgamma(x);
#	else
	return lgamma(x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_lgammal(const long double x)
{
//!# Computes log(|gamma(x)|).
#	if MC_TARGET_EMBEDDED
	return mc_gammalnl(x);
#	else
#	if MC_TARGET_CPP98
	return ::lgammal(x);
#	else
	return lgammal(x);
#	endif
#	endif
}

#endif /* !MC_LGAMMA_H */

/* EOF */
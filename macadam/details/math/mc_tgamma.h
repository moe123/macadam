//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tgamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gamma.h>

#ifndef MC_TGAMMA_H
#define MC_TGAMMA_H

#pragma mark - mc_tgamma -

static MC_TARGET_INLINE
float mc_tgammaf(float x)
{
	return mc_gammaf(x);
}

static MC_TARGET_INLINE
double mc_tgamma(double x)
{
	return mc_gamma(x);
}

static MC_TARGET_INLINE
long double mc_tgammal(long double x)
{
	return mc_gammal(x);
}

#endif /* !MC_TGAMMA_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gamma_r.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_gamma.h>

#ifndef MC_GAMMA_R_H
#define MC_GAMMA_R_H

#pragma mark - mc_gamma -

MC_TARGET_FUNC float mc_gammaf_r(const float x, int * sign)
{
	return mc_gammaf_approx1(x, sign);
}

MC_TARGET_FUNC double mc_gamma_r(const double x, int * sign)
{
	return mc_gamma_approx1(x, sign);
}

MC_TARGET_FUNC long double mc_gammal_r(const long double x, int * sign)
{
	return mc_gammal_approx1(x, sign);
}

#endif /* !MC_GAMMA_R_H */

/* EOF */
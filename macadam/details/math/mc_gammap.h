//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammap.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_igamma.h>

#ifndef MC_GAMMAP_H
#define MC_GAMMAP_H

#pragma mark - mc_gammap -

MC_TARGET_FUNC float mc_gammapf(float a, float z)
{
	return mc_igammapf_approx2(a, z);
}

MC_TARGET_FUNC double mc_gammap(double a, double z)
{
	return mc_igammap_approx2(a, z);
}

MC_TARGET_FUNC long double mc_gammapl(long double a, long double z)
{
	return mc_igammapl_approx2(a, z);
}

#endif /* !MC_GAMMAP_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammaq.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_erf.h>
#include <macadam/details/math/mc_erfc.h>
#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fisint.h>
#include <macadam/details/math/mc_igamma.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_GAMMAQ_H
#define MC_GAMMAQ_H

#pragma mark - mc_gammaq -

MC_TARGET_FUNC float mc_gammaqf(float a, float z)
{
	return mc_igammaqf_approx2(a, z);
}

MC_TARGET_FUNC double mc_gammaq(double a, double z)
{
	return mc_igammaq_approx2(a, z);
}

MC_TARGET_FUNC long double mc_gammaql(long double a, long double z)
{
	return mc_igammaql_approx2(a, z);
}

#endif /* !MC_GAMMAQ_H */

/* EOF */
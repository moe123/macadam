//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gamma_q.h
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

#pragma mark - mc_gamma_q -

MC_TARGET_FUNC float mc_gamma_qf(const float a, const float z)
{
	return mc_igamma_qf_approx2(a, z);
}

MC_TARGET_FUNC double mc_gamma_q(const double a, const double z)
{
	return mc_igamma_q_approx2(a, z);
}

MC_TARGET_FUNC long double mc_gamma_ql(const long double a, const long double z)
{
	return mc_igamma_ql_approx2(a, z);
}

#endif /* !MC_GAMMAQ_H */

/* EOF */
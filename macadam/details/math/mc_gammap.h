//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammap.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_igammac.h>
#include <macadam/details/math/mc_igammad.h>

#ifndef MC_GAMMAP_H
#define MC_GAMMAP_H

#pragma mark - mc_gammap -

static MC_TARGET_INLINE float mc_gammapf(float a, float z)
{
	float p = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 0.0f;
		}
		const float y = a * mc_logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			const float w = y - mc_lgammaf(a);
			if (z < a + 1.0f) {
				p = mc_gamma_pseriesf_approx0(a, z) * mc_expf(w);
			} else {
				p = 1.0f - mc_gamma_cfracf_approx0(a, z) * mc_expf(w);
			}
		} else {
			p = 0.0f;
		}
	}
	return p;
}

static MC_TARGET_INLINE double mc_gammap(double a, double z)
{
	double p = MCK_NAN;
	if (a > 0.0 && z >= 0.0) {
		if (z <=  0.0) {
			return 0.0;
		}
		const double y = a * mc_log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			const double w = y - mc_lgamma(a);
			if (z < a + 1.0) {
				p = mc_gamma_pseries_approx0(a, z) * mc_exp(w);
			} else {
				p = 1.0 - mc_gamma_cfrac_approx0(a, z) * mc_exp(w);
			}
		} else {
			p = 0.0;
		}
	}
	return p;
}

static MC_TARGET_INLINE long double mc_gammapl(long double a, long double z)
{
	long double p = MCK_NAN;
	if (a > 0.0L && z >= 0.0L) {
		if (z <=  0.0L) {
			return 0.0L;
		}
		const long double y = a * mc_logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			const long double w = y - mc_lgammal(a);
			if (z < a + 1.0L) {
				p = mc_gamma_pseriesl_approx0(a, z) * mc_expl(w);
			} else {
				p = 1.0L - mc_gamma_cfracl_approx0(a, z) * mc_expl(w);
			}
		} else {
			p = 0.0L;
		}
	}
	return p;
}

#endif /* !MC_GAMMAP_H */

/* EOF */
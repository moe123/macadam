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

static MC_TARGET_INLINE float mc_gammapf(float a, float z)
{
	float p = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 0.0f;
		}
#	if MC_TARGET_CPP98
		const float y = a * ::logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			if (z < a + 1.0f) {
				p = mc_gamma_pseriesf_approx0(a, z) * ::expf(y - mc_lgammaf(a));
			} else {
				p = 1.0f - mc_gamma_cfracf_approx0(a, z) * ::expf(y - mc_lgammaf(a));
			}
		} else {
			p = 0.0f;
		}
#	else
		const float y = a * logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			if (z < a + 1.0f) {
				p = mc_gamma_pseriesf_approx0(a, z) * expf(y - mc_lgammaf(a));
			} else {
				p = 1.0f - mc_gamma_cfracf_approx0(a, z) * expf(y - mc_lgammaf(a));
			}
		} else {
			p = 0.0f;
		}
#	endif
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
#	if MC_TARGET_CPP98
		const double y = a * ::log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			if (z < a + 1.0) {
				p = mc_gamma_cfrac_approx0(a, z) * ::exp(y - mc_lgamma(a));
			} else {
				p = 1.0 - mc_gamma_cfrac_approx0(a, z) * ::exp(y - mc_lgamma(a));
			}
		} else {
			p = 0.0;
		}
#	else
		const double y = a * log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			if (z < a + 1.0) {
				p = mc_gamma_cfrac_approx0(a, z) * exp(y - mc_lgamma(a));
			} else {
				p = 1.0 - mc_gamma_cfrac_approx0(a, z) * exp(y - mc_lgamma(a));
			}
		} else {
			p = 0.0;
		}
#	endif
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
#	if MC_TARGET_CPP98
		const long double y = a * ::logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			if (z < a + 1.0L) {
				p = mc_gamma_pseriesl_approx0(a, z) * ::expl(y - mc_lgammal(a));
			} else {
				p = 1.0L - mc_gamma_cfracl_approx0(a, z) * ::expl(y - mc_lgammal(a));
			}
		} else {
			p = 0.0L;
		}
#	else
		const long double y = a * logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			if (z < a + 1.0L) {
				p = mc_gamma_pseriesl_approx0(a, z) * expl(y - mc_lgammal(a));
			} else {
				p = 1.0L - mc_gamma_cfracl_approx0(a, z) * expl(y - mc_lgammal(a));
			}
		} else {
			p = 0.0L;
		}
#	endif
	}
	return p;
}

#endif /* !MC_GAMMAP_H */

/* EOF */
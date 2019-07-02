//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammaq.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_igammac.h>
#include <macadam/details/math/mc_igammad.h>

#ifndef MC_GAMMAQ_H
#define MC_GAMMAQ_H

static MC_TARGET_INLINE float mc_gammaqf(float a, float z)
{
	float q = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 1.0f;
		}
#	if MC_TARGET_CPP98
		const float y = a * ::logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			if (z >= a + 1.0f) {
				const float w = y - mc_lgammaf(a);
				q             = mc_gamma_cfracf_approx0(a, z) * ::expf(w);
			} else {
				const float w = y - mc_lgammaf(a);
				q             = 1.0f - mc_gamma_pseriesf_approx0(a, z) * ::expf(w);
			}
		} else {
			q = 1.0f;
		}
#	else
		const float y = a * logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			if (z >= a + 1.0f) {
				const float w = y - mc_lgammaf(a);
				q             = mc_gamma_cfracf_approx0(a, z) * expf(w);
			} else {
				const float w = y - mc_lgammaf(a);
				q             = 1.0f - mc_gamma_pseriesf_approx0(a, z) * expf(w);
			}
		} else {
			q = 1.0f;
		}
#	endif
	}
	return q;
}

static MC_TARGET_INLINE double mc_gammaq(double a, double z)
{
	double q = MCK_NAN;
	if (a > 0.0 && z >= 0.0) {
		if (z <=  0.0) {
			return 1.0;
		}
#	if MC_TARGET_CPP98
		const double y = a * ::log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			if (z >= a + 1.0) {
				const double w = y - mc_lgamma(a);
				q              = mc_gamma_cfrac_approx0(a, z) * ::exp(w);
			} else {
				const double w = y - mc_lgamma(a);
				q              = 1.0 - mc_gamma_pseries_approx0(a, z) * ::exp(w);
			}
		} else {
			q = 1.0;
		}
#	else
		const double y = a * log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			if (z >= a + 1.0) {
				const double w = y - mc_lgamma(a);
				q              = mc_gamma_cfrac_approx0(a, z) * exp(w);
			} else {
				const double w = y - mc_lgamma(a);
				q              = 1.0 - mc_gamma_pseries_approx0(a, z) * exp(w);
			}
		} else {
			q = 1.0;
		}
#	endif
	}
	return q;
}

static MC_TARGET_INLINE long double mc_gammaql(long double a, long double z)
{
	long double q = MCK_NAN;
	if (a > 0.0L && z >= 0.0L) {
		if (z <=  0.0L) {
			return 1.0L;
		}
#	if MC_TARGET_CPP98
		const long double y = a * ::logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			if (z >= a + 1.0L) {
				const long double w = y - mc_lgammal(a);
				q                   = mc_gamma_cfracl_approx0(a, z) * ::expl(w);
			} else {
				const long double w = y - mc_lgammal(a);
				q                   = 1.0L - mc_gamma_pseriesl_approx0(a, z) * ::expl(w);
			}
		} else {
			q = 1.0L;
		}
#	else
		const long double y = a * logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			if (z >= a + 1.0L) {
				const long double w = y - mc_lgammal(a);
				q                   = mc_gamma_cfracl_approx0(a, z) * expl(w);
			} else {
				const long double w = y - mc_lgammal(a);
				q                   = 1.0L - mc_gamma_pseriesl_approx0(a, z) * expl(w);
			}
		} else {
			q = 1.0L;
		}
#	endif
	}
	return q;
}

#endif /* !MC_GAMMAQ_H */

/* EOF */
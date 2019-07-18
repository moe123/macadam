//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammap.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_erf.h>
#include <macadam/details/math/mc_erfc.h>
#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fisint.h>
#include <macadam/details/math/mc_igamma.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_GAMMAP_H
#define MC_GAMMAP_H

#pragma mark - mc_gammap -

MC_TARGET_FUNCTION float mc_gammapf(float a, float z)
{
	float p = MCK_INFP;
	if (z <= 0.0f || a < 0.0f) {
		p = MCK_NAN;
	} else if (a == 0.0f && z == 0.0f) {
		p = 0.5f;
	} else if (z == 0.0f) {
		p = 0.0f;
	} else if (a == 0.0f) {
		p = 1.0f;
	} else {
		if (mc_fisintf(2.0f * a)) {
			if (a == 0.5f) {
				z = mc_sqrtf(z);
				return z < 1.0f ? mc_erff(z) : 1.0f - mc_erfcf(z);
			} else if (a == 1.0f) {
				return -mc_expm1f(-z);
			} else if (a < 30.0f && a < (z + 1.0f)) {
				if (mc_fisintf(a) && z > 0.6f) {
					return 1.0f - mc_igammaqif (a, z);
				} else if (z > 0.2f) {
					return 1.0f - mc_igammaqhf(a, z);
				}
			}
		}
		p = mc_igammapf_approx1(a, z);
	}
	return p;
}

MC_TARGET_FUNCTION double mc_gammap(double a, double z)
{
	double p = MCK_INFP;
	if (z <= 0.0 || a < 0.0) {
		p = MCK_NAN;
	} else if (a == 0.0 && z == 0.0) {
		p = 0.5;
	} else if (z == 0.0) {
		p = 0.0;
	} else if (a == 0.0) {
		p = 1.0;
	} else {
		if (mc_fisint(2.0 * a)) {
			if (a == 0.5) {
				z = mc_sqrt(z);
				return z < 1.0 ? mc_erf(z) : 1.0 - mc_erfc(z);
			} else if (a == 1.0) {
				return -mc_expm1(-z);
			} else if (a < 30.0 && a < (z + 1.0)) {
				if (mc_fisint(a) && z > 0.6) {
					return 1.0 - mc_igammaqi(a, z);
				} else if (z > 0.2) {
					return 1.0 - mc_igammaqh(a, z);
				}
			}
		}
		p = mc_igammap_approx1(a, z);
	}
	return p;
}

MC_TARGET_FUNCTION long double mc_gammapl(long double a, long double z)
{
	long double p = MCK_INFP;
	if (z <= 0.0L || a < 0.0L) {
		p = MCK_NAN;
	} else if (a == 0.0L && z == 0.0L) {
		p = 0.5L;
	} else if (z == 0.0L) {
		p = 0.0L;
	} else if (a == 0.0L) {
		p = 1.0L;
	} else {
		if (mc_fisintl(2.0L * a)) {
			if (a == 0.5L) {
				z = mc_sqrtl(z);
				return z < 1.0L ? mc_erfl(z) : 1.0L - mc_erfcl(z);
			} else if (a == 1.0L) {
				return -mc_expm1l(-z);
			} else if (a < 30.0L && a < (z + 1.0L)) {
				if (mc_fisintl(a) && z > 0.6L) {
					return 1.0L - mc_igammaqil(a, z);
				} else if (z > 0.2L) {
					return 1.0L - mc_igammaqhl(a, z);
				}
			}
		}
		p = mc_igammapl_approx1(a, z);
	}
	return p;
}

#endif /* !MC_GAMMAP_H */

/* EOF */
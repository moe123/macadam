//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammaq.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_erfc.h>
#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fisint.h>
#include <macadam/details/math/mc_igammac.h>
#include <macadam/details/math/mc_igammad.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_GAMMAQ_H
#define MC_GAMMAQ_H

#pragma mark - mc_gammaq_approx0 -

static MC_TARGET_INLINE float mc_gammaqf_approx0(float a, float z)
{
	float q = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 1.0f;
		}
		const float y = a * mc_logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			const float w = y - mc_lgammaf(a);
			if (z >= a + 1.0f) {
				q = mc_gamma_cfracf_approx0(a, z) * mc_expf(w);
			} else {
				q = 1.0f - mc_gamma_pseriesf_approx0(a, z) * mc_expf(w);
			}
		} else {
			q = 1.0f;
		}
	}
	return q;
}

static MC_TARGET_INLINE double mc_gammaq_approx0(double a, double z)
{
	double q = MCK_NAN;
	if (a > 0.0 && z >= 0.0) {
		if (z <=  0.0) {
			return 1.0;
		}
		const double y = a * mc_log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			const double w = y - mc_lgamma(a);
			if (z >= a + 1.0) {
				q = mc_gamma_cfrac_approx0(a, z) * mc_exp(w);
			} else {
				q = 1.0 - mc_gamma_pseries_approx0(a, z) * mc_exp(w);
			}
		} else {
			q = 1.0;
		}
	}
	return q;
}

static MC_TARGET_INLINE long double mc_gammaql_approx0(long double a, long double z)
{
	long double q = MCK_NAN;
	if (a > 0.0L && z >= 0.0L) {
		if (z <=  0.0L) {
			return 1.0L;
		}
		const long double y = a * mc_logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			const long double w = y - mc_lgammal(a);
			if (z >= a + 1.0L) {
				q = mc_gamma_cfracl_approx0(a, z) * mc_expl(w);
			} else {
				q = 1.0L - mc_gamma_pseriesl_approx0(a, z) * mc_expl(w);
			}
		} else {
			q = 1.0L;
		}
	}
	return q;
}

#pragma mark - mc_gammaqi -

static MC_TARGET_INLINE float mc_gammaqif(float a, float z)
{
	float q = mc_expf(-z), w, n;
	if (q > 0.0f && a >= 2.0f) {
		w = q;
		n = 1.0f;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0f;
		} while (n < a);
	}
	return q;
}

static MC_TARGET_INLINE double mc_gammaqi(double a, double z)
{
	double q = mc_exp(-z), w, n;
	if (q > 0.0 && a >= 2.0) {
		w = q;
		n = 1.0;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0;
		} while (n < a);
	}
	return q;
}

static MC_TARGET_INLINE long double mc_gammaqil(long double a, long double z)
{
	long double q = mc_expl(-z), w, n;
	if (q > 0.0L && a >= 2.0L) {
		w = q;
		n = 1.0L;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0L;
		} while (n < a);
	}
	return q;
}

#pragma mark - mc_gammqh -

static MC_TARGET_INLINE float mc_gammaqhf(float a, float z)
{
	float q = mc_erfcf(mc_sqrtf(z)), s, w, n;
	if (q != 0.0f && a > 1.0f) {
		w = 2.0f * mc_expf(-z) * mc_sqrtf(z / MCK_KF(MCK_PI));
		s = w;
		n = 2.0f;
		do {
			w = (w / (n - 0.5f)) * z;
			s = s + w;
			n = n + 1.0f;
		} while (n < a);
		q = q + s;
	}
	return q;
}

static MC_TARGET_INLINE double mc_gammaqh(double a, double z)
{
	double q = mc_erfc(mc_sqrt(z)), s, w, n;
	if (q != 0.0 && a > 1.0) {
		w = 2.0 * mc_exp(-z) * mc_sqrt(z / MCK_K(MCK_PI));
		s = w;
		n = 2.0;
		do {
			w = (w / (n - 0.5)) * z;
			s = s + w;
			n = n + 1.0;
		} while (n < a);
		q = q + s;
	}
	return q;
}

static MC_TARGET_INLINE long double mc_gammaqhl(long double a, long double z)
{
	double q = mc_erfcl(mc_sqrt(z)), s, w, n;
	if (q != 0.0L && a > 1.0L) {
		w = 2.0L * mc_expl(-z) * mc_sqrtl(z / MCK_KL(MCK_PI));
		s = w;
		n = 2.0L;
		do {
			w = (w / (n - 0.5L)) * z;
			s = s + w;
			n = n + 1.0L;
		} while (n < a);
		q = q + s;
	}
	return q;
}

#pragma mark - mc_gammaq -

static MC_TARGET_INLINE float mc_gammaqf(float a, float z)
{
	float q = MCK_NAN;
	if (a == 0.0f  && z == 0.0f) {
		q = 0.5f;
	} else if (z == 0.0f) {
		q = 1.0f;
	} else if (a == 0.0f) {
		q = 0.0f;
	} else {
		if (mc_fisintf(2.0f * a)) {
			if (a == 0.5f) {
				z = mc_sqrtf(z);
				return z < 1.0f ? 1.0f - mc_erfcf(z) : mc_erfcf(z);
			} else if (a == 1.0f) {
				return mc_expf(-z);
			} else if (a < 30.0f && a < (z + 1.0f)) {
				if (mc_fisintf(a) && z > 0.6f) {
					return mc_gammaqif(a, z);
				} else if (z > 0.2f) {
					return mc_gammaqhf(a, z);
				}
			}
		}
		q = mc_gammaqf_approx0(a, z);
	}
	return q;
}

static MC_TARGET_INLINE double mc_gammaq(double a, double z)
{
	double q = MCK_NAN;
	if (a == 0.0  && z == 0.0) {
		q = 0.5;
	} else if (z == 0.0) {
		q = 1.0;
	} else if (a == 0.0) {
		q = 0.0;
	} else {
		if (mc_fisint(2.0 * a)) {
			if (a == 0.5) {
				z = mc_sqrt(z);
				return z < 1.0 ? 1.0 - mc_erfc(z) : mc_erfc(z);
			} else if (a == 1.0) {
				return mc_exp(-z);
			} else if (a < 30.0 && a < (z + 1.0)) {
				if (mc_fisint(a) && z > 0.6) {
					return mc_gammaqi(a, z);
				} else if (z > 0.2) {
					return mc_gammaqh(a, z);
				}
			}
		}
		q = mc_gammaq_approx0(a, z);
	}
	return q;
}

static MC_TARGET_INLINE long double mc_gammaql(long double a, long double z)
{
	long double q = MCK_NAN;
	if (a == 0.0L  && z == 0.0L) {
		q = 0.5L;
	} else if (z == 0.0L) {
		q = 1.0L;
	} else if (a == 0.0L) {
		q = 0.0L;
	} else {
		if (mc_fisintl(2.0L * a)) {
			if (a == 0.5L) {
				z = mc_sqrtl(z);
				return z < 1.0L ? 1.0L - mc_erfcl(z) : mc_erfcl(z);
			} else if (a == 1.0L) {
				return mc_expl(-z);
			} else if (a < 30.0L && a < (z + 1.0L)) {
				if (mc_fisintl(a) && z > 0.6L) {
					return mc_gammaqil(a, z);
				} else if (z > 0.2L) {
					return mc_gammaqhl(a, z);
				}
			}
		}
		q = mc_gammaql_approx0(a, z);
	}
	return q;
}

#endif /* !MC_GAMMAQ_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hzeta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zeta.h>
#include <macadam/details/math/mc_exp2m1.h>
#include <macadam/details/math/mc_lchoose.h>

#ifndef MC_HZETA_H
#define MC_HZETA_H

#pragma mark - mc_hzeta -

static MC_TARGET_INLINE float mc_hzetaf(float s, float q)
{
	float r = 0.0f, c, term, sign;
	unsigned int i = 0, j;
#	if MC_TARGET_CPP98
	if ((::isnan(s) || ::isinf(s)) || (::isnan(q) || ::isinf(q)) || (s == 1.0f || q <= 0.0f)) {
		return MCK_NAN;
	}
#	else
	if ((isnan(s) || isinf(s)) || (isnan(q) || isinf(q)) || (s == 1.0f || q <= 0.0f)) {
		return MCK_NAN;
	}
#	endif
	if (s == 0.0f) {
		return 0.5f - q;
	}
	if (q == 0.5f && s < 16384.0f) {
		return mc_exp2m1f(s) * mc_zetaf(s);
	}
	if (q == 1.0f) {
		return mc_zetaf(s);
	}

	for (; i < 10000; ++i) {
		sign = 1.0f;
		term = 0.0f;
		for (j = 0; j <= i; ++j) {
			if ((MCK_KF(FLT_MAX_10_EXP) * MCK_KF(MCK_LOG10)) < (c = mc_lchoosef(mc_cast(float, i), mc_cast(float, j)))) {
#	if MC_TARGET_CPP98
				c     = sign * ::expf(c);
#	else
				c     = sign * expf(c);
#	endif
				sign *= -1.0f;
#	if MC_TARGET_CPP98
				term += c * ::powf(q + mc_cast(float, j), -s);
#	else
				term += c * powf(q + mc_cast(float, j), -s);
#	endif
				continue;
			}
			goto hurwitz_end;
		}
		term *= 1.0f / mc_cast(float, (i + 1));
#	if MC_TARGET_CPP98
		if (::fabsf(term * (1.0f / r)) < MCLIMITS_EPSILONF) {
			goto hurwitz_end;
		}
#	else
		if (fabsf(term * (1.0f / r)) < MCLIMITS_EPSILONF) {
			goto hurwitz_end;
		}
#	endif
		r += term;
	}
hurwitz_end:
	return r / (s - 1.0f);
}

static MC_TARGET_INLINE double mc_hzeta(double s, double q)
{
	double r = 0.0, c, term, sign;
	unsigned int i = 0, j;
#	if MC_TARGET_CPP98
	if ((::isnan(s) || ::isinf(s)) || (::isnan(q) || ::isinf(q)) || (s == 1.0 || q <= 0.0)) {
		return MCK_NAN;
	}
#	else
	if ((isnan(s) || isinf(s)) || (isnan(q) || isinf(q)) || (s == 1.0 || q <= 0.0)) {
		return MCK_NAN;
	}
#	endif
	if (s == 0.0) {
		return 0.5 - q;
	}
	if (q == 0.5 && s < 16384.0) {
		return mc_exp2m1(s) * mc_zeta(s);
	}
	if (q == 1.0) {
		return mc_zeta(s);
	}
	for (; i < 10000; ++i) {
		sign = 1.0;
		term = 0.0;
		for (j = 0; j <= i; ++j) {
			if ((MCK_K(DBL_MAX_10_EXP) * MCK_K(MCK_LOG10)) < (c = mc_lchoose(mc_cast(double, i), mc_cast(double, j)))) {
#	if MC_TARGET_CPP98
				c     = sign * ::exp(c);
#	else
				c     = sign * exp(c);
#	endif
				sign *= -1.0;
#	if MC_TARGET_CPP98
				term += c * ::pow(q + mc_cast(double, j), -s);
#	else
				term += c * pow(q + mc_cast(double, j), -s);
#	endif
				continue;
			}
			goto hurwitz_end;
		}
		term *= 1.0 / mc_cast(double, (i + 1));
#	if MC_TARGET_CPP98
		if (::fabs(term * (1.0 / r)) < MCLIMITS_EPSILON) {
			goto hurwitz_end;
		}
#	else
		if (fabs(term * (1.0 / r)) < MCLIMITS_EPSILON) {
			goto hurwitz_end;
		}
#	endif
		r += term;
	}
hurwitz_end:
	return r / (s - 1.0);
}

static MC_TARGET_INLINE long double mc_hzetal(long double s, long double q)
{
	long double r = 0.0L, c, term, sign;
	unsigned int i = 0, j;
#	if MC_TARGET_CPP98
	if ((::isnan(s) || ::isinf(s)) || (::isnan(q) || ::isinf(q)) || (s == 1.0L || q <= 0.0L)) {
		return MCK_NAN;
	}
#	else
	if ((isnan(s) || isinf(s)) || (isnan(q) || isinf(q)) || (s == 1.0L || q <= 0.0L)) {
		return MCK_NAN;
	}
#	endif
	if (s == 0.0L) {
		return 0.5L - q;
	}
	if (q == 0.5L && s < 16384.0L) {
		return mc_exp2m1l(s) * mc_zetal(s);
	}
	if (q == 1.0L) {
		return mc_zetal(s);
	}
	for (; i < 10000; ++i) {
		sign = 1.0L;
		term = 0.0L;
		for (j = 0; j <= i; ++j) {
			if ((MCK_KL(LDBL_MAX_10_EXP) * MCK_KL(MCK_LOG10)) < (c = mc_lchoosel(mc_cast(long double, i), mc_cast(long double, j)))) {
#	if MC_TARGET_CPP98
				c     = sign * ::expl(c);
#	else
				c     = sign * expl(c);
#	endif
				sign *= -1.0L;
#	if MC_TARGET_CPP98
				term += c * ::powl(q + mc_cast(long double, j), -s);
#	else
				term += c * powl(q + mc_cast(long double, j), -s);
#	endif
				continue;
			}
			goto hurwitz_end;
		}
		term *= 1.0L / mc_cast(long double, (i + 1));
#	if MC_TARGET_CPP98
		if (::fabsl(term * (1.0L / r)) < MCLIMITS_EPSILONL) {
			goto hurwitz_end;
		}
#	else
		if (fabsl(term * (1.0L / r)) < MCLIMITS_EPSILONL) {
			goto hurwitz_end;
		}
#	endif
		r += term;
	}
hurwitz_end:
	return r / (s - 1.0L);
}

#endif /* !MC_HZETA_H */

/* EOF */
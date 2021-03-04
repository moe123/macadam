//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_poisson.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_floor.h>
#include <macadam/details/math/mc_gammaln.h>
#include <macadam/details/math/mc_itrunc32.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/math/mc_tan.h>
#include <macadam/details/rand/mc_randu.h>

#ifndef MC_RAND_POISSON_H
#define MC_RAND_POISSON_H

#pragma mark - mc_rand_poisson -

MC_TARGET_FUNC int rand_poissonf(const float l)
{
	float r, m = 0.0f, p = 1.0f;

	if (l < 60.0f) {
		r = mc_expf(-l);
		do {
			m = m + 1.0f;
			p = p * mc_randuf();
		} while (p > r);
		m = m - 1.0f;
	} else {
		const float w = mc_sqrtf(l);
		const float g = mc_logf(l);
		float x       = -1.0f, f;
		do {
			while (x < 0.0f) {
				x = l + w * mc_tanf(MCK_KF(MCK_PI) * (mc_randuf() - 1.0f * 0.5f));
			}
			p = w / (MCK_KF(MCK_PI) * ((x - l) * (x - l) + l));
			m = mc_floorf(x);
			f = mc_expf(m * g - l - mc_gammalnf(m + 1));
			r = f / p / 2.4f;
		} while (mc_randuf() > r);
	}
	return mc_itrunc32f(m);
}

MC_TARGET_FUNC int rand_poisson(const double l)
{
	double r, m = 0.0, p = 1.0;

	if (l < 60.0) {
		r = mc_exp(-l);
		do {
			m = m + 1.0;
			p = p * mc_randu();
		} while (p > r);
		m = m - 1.0;
	} else {
		const double w = mc_sqrt(l);
		const double g = mc_log(l);
		double x       = -1.0, f;
		do {
			while (x < 0.0) {
				x = l + w * mc_tan(MCK_K(MCK_PI) * (mc_randu() - 1.0 * 0.5));
			}
			p = w / (MCK_K(MCK_PI) * ((x - l) * (x - l) + l));
			m = mc_floor(x);
			f = mc_exp(m * g - l - mc_gammaln(m + 1));
			r = f / p / 2.4;
		} while (mc_randu() > r);
	}
	return mc_itrunc32(m);
}

MC_TARGET_FUNC int rand_poissonl(const long double l)
{
	long double r, m = 0.0L, p = 1.0L;

	if (l < 60.0L) {
		r = mc_expl(-l);
		do {
			m = m + 1.0L;
			p = p * mc_randul();
		} while (p > r);
		m = m - 1.0;
	} else {
		const long double w = mc_sqrtl(l);
		const long double g = mc_logl(l);
		long double x       = -1.0L, f;
		do {
			while (x < 0.0L) {
				x = l + w * mc_tanl(MCK_KL(MCK_PI) * (mc_randul() - 1.0L * 0.5L));
			}
			p = w / (MCK_KL(MCK_PI) * ((x - l) * (x - l) + l));
			m = mc_floorl(x);
			f = mc_expl(m * g - l - mc_gammalnl(m + 1));
			r = f / p / 2.4L;
		} while (mc_randul() > r);
	}
	return mc_itrunc32l(m);
}

#endif /* !MC_RAND_POISSON_H */

/* EOF */
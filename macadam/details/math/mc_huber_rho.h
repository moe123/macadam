//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_huber_rho.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>

#ifndef MC_HUBER_RHO_H
#define MC_HUBER_RHO_H

#pragma mark - mc_huber_rho -

MC_TARGET_FUNC float mc_huber_rhof(float r)
{
	const float c = 1.345f;
	if (mc_fabsf(r) <= c) {
		return 0.5f * mc_raise2f(r);
	}
	return c * mc_fabsf(r) - 0.5f * mc_raise2f(c);
}

MC_TARGET_FUNC double mc_huber_rho(double r)
{
	const double c = 1.345;
	if (mc_fabs(r) <= c) {
		return 0.5 * mc_raise2(r);
	}
	return c * mc_fabs(r) - 0.5 * mc_raise2(c);
}

MC_TARGET_FUNC long double mc_huber_rhol(long double r)
{
	const long double c = 1.345L;
	if (mc_fabsl(r) <= c) {
		return 0.5L * mc_raise2l(r);
	}
	return c * mc_fabsl(r) - 0.5L * mc_raise2l(c);
}

#endif /* !MC_HUBER_RHO_H */

/* EOF */
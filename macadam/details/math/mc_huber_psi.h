//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_huber_psi.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_HUBER_PSI_H
#define MC_HUBER_PSI_H

#pragma mark - mc_huber_psic -

MC_TARGET_FUNC float mc_huber_psicf(float r, float c)
{
	if (r > c) {
		return r;
	}
	if (mc_fabsf(r) <= c) {
		return r;
	}
	return -c;
}

MC_TARGET_FUNC double mc_huber_psic(double r, double c)
{
	if (r > c) {
		return r;
	}
	if (mc_fabs(r) <= c) {
		return r;
	}
	return -c;
}

MC_TARGET_FUNC long double mc_huber_psicl(long double r, long double c)
{
	if (r > c) {
		return r;
	}
	if (mc_fabsl(r) <= c) {
		return r;
	}
	return -c;
}

#pragma mark - mc_huber_psi -

MC_TARGET_FUNC float mc_huber_psif(float r)
{
	const float c = 1.345f;
	return mc_huber_psicf(r, c);
}

MC_TARGET_FUNC double mc_huber_psi(double r)
{
	const double c = 1.345;
	return mc_huber_psic(r, c);
}

MC_TARGET_FUNC long double mc_huber_psil(long double r)
{
	const long double c = 1.345L;
	return mc_huber_psicl(r, c);
}

#endif /* !MC_HUBER_PSI_H */

/* EOF */
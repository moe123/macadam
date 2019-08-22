//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_huber_psi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>

#ifndef MC_HUBER_PSI_H
#define MC_HUBER_PSI_H

#pragma mark - mc_huber_psi -

MC_TARGET_FUNC float mc_huber_psif(float r)
{
	const float c = 1.345f;
	if (r > c) {
		return r;
	}
	if (mc_fabsf(r) <= c) {
		return r;
	}
	return -c;
}

MC_TARGET_FUNC double mc_huber_psi(double r)
{
	const double c = 1.345;
	if (r > c) {
		return r;
	}
	if (mc_fabs(r) <= c) {
		return r;
	}
	return -c;
}

MC_TARGET_FUNC long double mc_huber_psil(long double r)
{
	const long double c = 1.345L;
	if (r > c) {
		return r;
	}
	if (mc_fabsl(r) <= c) {
		return r;
	}
	return -c;
}

#endif /* !MC_HUBER_PSI_H */

/* EOF */
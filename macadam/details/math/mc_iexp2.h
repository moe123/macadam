//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_iexp2.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_absmag.h>

#ifndef MC_IEXP2_H
#define MC_IEXP2_H

#pragma mark - mc_iexp2 -

MC_TARGET_FUNC float mc_iexp2f(int e)
{
	float r       = 1.0f;
	const float s = e >= 0 ? 2.0f : 0.5f;
	for (int i = 0; i < mc_iabs(e); i++) {
		r = r * s;
	}
	return r;
}

MC_TARGET_FUNC double mc_iexp2(int e)
{
	double r       = 1.0;
	const double s = e >= 0 ? 2.0 : 0.5;
	for (int i = 0; i < mc_iabs(e); i++) {
		r = r * s;
	}
	return r;
}

MC_TARGET_FUNC long double mc_iexp2l(int e)
{
	long double r       = 1.0L;
	const long double s = e >= 0 ? 2.0L : 0.5L;
	for (int i = 0; i < mc_iabs(e); i++) {
		r = r * s;
	}
	return r;
}

#endif /* !MC_IEXP2_H */

/* EOF */
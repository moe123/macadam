//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eigsyq3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_tredql3x3.h>
#include <macadam/details/numa/mc_tredsy3x3.h>

#ifndef MC_EIGSYQ3X3_H
#define MC_EIGSYQ3X3_H

#pragma mark - mc_eigsyq3x3f -

MC_TARGET_PROC int mc_eigsyq3x3f(const float a[9], float e[3], float * v)
{
	int r;
	float w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3f(a, v, e, w))) {
		r = mc_tredql3x3f(v, e, w);
	}
	return r;
}

MC_TARGET_PROC int mc_eigsyq3x3(const double a[9], double e[3], double * v)
{
	int r;
	double w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3(a, v, e, w))) {
		r = mc_tredql3x3(v, e, w);
	}
	return r;
}

MC_TARGET_PROC int mc_eigsyq3x3l(const long double a[9], long double e[3], long double * v)
{
	int r;
	long double w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3l(a, v, e, w))) {
		r = mc_tredql3x3l(v, e, w);
	}
	return r;
}

#endif /* !MC_EIGSYQ3X3_H */

/* EOF */
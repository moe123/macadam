//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zdiv.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ZDIV_H
#define MC_ZDIV_H

#pragma mark - mc_zdiv -

MC_TARGET_PROC void mc_zdivf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b_r, float b_i
) {
	float w = b_r * b_r + b_i * b_i;
	if (w != 0.0f) {
		w = 1.0f / w;
		*c_r = (a_r * b_r + a_i * b_i) * w;
		*c_i = (a_i * b_r - a_r * b_i) * w;
	} else {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	}
}

MC_TARGET_PROC void mc_zdiv(double * c_r, double * c_i
	, double a_r, double a_i
	, double b_r, double b_i
) {
	double w = b_r * b_r + b_i * b_i;
	if (w != 0.0) {
		w = 1.0 / w;
		*c_r = (a_r * b_r + a_i * b_i) * w;
		*c_i = (a_i * b_r - a_r * b_i) * w;
	} else {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	}
}

MC_TARGET_PROC void mc_zdivl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b_r, long double b_i
) {
	long double w = b_r * b_r + b_i * b_i;
	if (w != 0.0L) {
		w = 1.0L / w;
		*c_r = (a_r * b_r + a_i * b_i) * w;
		*c_i = (a_i * b_r - a_r * b_i) * w;
	} else {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	}
}

#endif /* !MC_ZDIV_H */

/* EOF */
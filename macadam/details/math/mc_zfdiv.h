//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zfdiv.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>

#ifndef MC_ZFDIV_H
#define MC_ZFDIV_H

#pragma mark - mc_zfdiv -

MC_TARGET_PROC void mc_zfdivf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b
) {
	if (mc_isinf(b)) {
		*c_r = b;
		*c_i = MCK_INF;
	} else if (mc_isnan(b)) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else if (b == 0.0f) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else {
		*c_r = a_r * (1.0f / b);
		*c_i = a_i * (1.0f / b);
	}
}

MC_TARGET_PROC void mc_zfdiv(double * c_r, double * c_i
	, double a_r, double a_i
	, double b
) {
	if (mc_isinf(b)) {
		*c_r = b;
		*c_i = MCK_INF;
	} else if (mc_isnan(b)) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else if (b == 0.0) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else {
		*c_r = a_r * (1.0 / b);
		*c_i = a_i * (1.0 / b);
	}
}

MC_TARGET_PROC void mc_zfdivl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b
) {
	if (mc_isinf(b)) {
		*c_r = b;
		*c_i = MCK_INF;
	} else if (mc_isnan(b)) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else if (b == 0.0L) {
		*c_r = MCK_NAN;
		*c_i = MCK_NAN;
	} else {
		*c_r = a_r * (1.0L / b);
		*c_i = a_i * (1.0L / b);
	}
}

#endif /* !MC_ZFDIV_H */

/* EOF */
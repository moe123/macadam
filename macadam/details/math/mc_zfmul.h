//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zfmul.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>

#ifndef MC_ZFMUL_H
#define MC_ZFMUL_H

#pragma mark - mc_zfmul -

MC_TARGET_PROC void mc_zfmulf(float * c_r, float * c_i
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
		*c_r = 0.0f;
		*c_i = 0.0f;
	} else {
		*c_r = a_r * b;
		*c_i = a_i * b;
	}
}

MC_TARGET_PROC void mc_zfmul(double * c_r, double * c_i
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
		*c_r = 0.0;
		*c_i = 0.0;
	} else {
		*c_r = a_r * b;
		*c_i = a_i * b;
	}
}

MC_TARGET_PROC void mc_zfmull(long double * c_r, long double * c_i
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
		*c_r = 0.0L;
		*c_i = 0.0L;
	} else {
		*c_r = a_r * b;
		*c_i = a_i * b;
	}
}

#endif /* !MC_ZFMUL_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zsqr.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>

#ifndef MC_ZSQR_H
#define MC_ZSQR_H

#pragma mark - mc_zsqr -

MC_TARGET_PROC void mc_zsqrf(float * c_r, float * c_i
	, float a_r, float a_i
) {
	*c_r = mc_raise2f(a_r) - mc_raise2f(a_i);
	*c_i = 2.0f * a_r * a_i;
}

MC_TARGET_PROC void mc_zsqr(double * c_r, double * c_i
	, double a_r, double a_i
) {
	*c_r = mc_raise2(a_r) - mc_raise2(a_i);
	*c_i = 2.0 * a_r * a_i;
}

MC_TARGET_PROC void mc_zsqrl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	*c_r = mc_raise2l(a_r) - mc_raise2l(a_i);
	*c_i = 2.0L * a_r * a_i;
}

#endif /* !MC_ZSQR_H */

/* EOF */
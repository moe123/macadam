//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zinv.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zdiv.h>

#ifndef MC_ZINV_H
#define MC_ZINV_H

#pragma mark - mc_zinv -

MC_TARGET_PROC void mc_zinvf(float * c_r, float * c_i
	, const float a_r, const float a_i
) {
	mc_zdivf(c_r, c_i, 1.0f, 0.0f,  a_r, a_i);
}

MC_TARGET_PROC void mc_zinv(double * c_r, double * c_i
	, const double a_r, const double a_i
) {
	mc_zdiv(c_r, c_i, 1.0, 0.0,  a_r, a_i);
}

MC_TARGET_PROC void mc_zinvl(long double * c_r, long double * c_i
	, const long double a_r, const long double a_i
) {
	mc_zdivl(c_r, c_i, 1.0L, 0.0L,  a_r, a_i);
}

#endif /* !MC_ZINV_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zexp10.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zpow.h>

#ifndef MC_ZEXP10_H
#define MC_ZEXP10_H

#pragma mark - mc_zexp10 -

MC_TARGET_PROC void mc_zexp10f(float * c_r, float * c_i
	, float a_r, float a_i
) {
	mc_zpowf(c_r, c_i, 10.0f, 0.0f, a_r, a_i);
}

MC_TARGET_PROC void mc_zexp10(double * c_r, double * c_i
	, double a_r, double a_i
) {
	mc_zpow(c_r, c_i, 10.0, 0.0, a_r, a_i);
}

MC_TARGET_PROC void mc_zexp10l(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	mc_zpowl(c_r, c_i, 10.0L, 0.0L, a_r, a_i);
}

#endif /* !MC_ZEXP10_H */

/* EOF */
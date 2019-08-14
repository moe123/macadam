//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zlog10.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zfmul.h>
#include <macadam/details/math/mc_zlog.h>

#ifndef MC_ZLOG10_H
#define MC_ZLOG10_H

#pragma mark - mc_zlog10 -

MC_TARGET_PROC void mc_zlog10f(float * c_r, float * c_i
	, float a_r, float a_i
) {
	mc_zlogf(c_r, c_i, a_r, a_i);
	mc_zfmulf(c_r, c_i, *c_r, *c_i, MCK_KF(MCK_1_LOG10));
}

MC_TARGET_PROC void mc_zlog10(double * c_r, double * c_i
	, double a_r, double a_i
) {
	mc_zlog(c_r, c_i, a_r, a_i);
	mc_zfmul(c_r, c_i, *c_r, *c_i, MCK_K(MCK_1_LOG10));
}

MC_TARGET_PROC void mc_zlog10l(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	mc_zlogl(c_r, c_i, a_r, a_i);
	mc_zfmull(c_r, c_i, *c_r, *c_i, MCK_KL(MCK_1_LOG10));
}

#endif /* !MC_ZLOG10_H */

/* EOF */
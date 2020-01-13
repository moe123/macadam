//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zdiv.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zconj.h>
#include <macadam/details/math/mc_zfmul.h>
#include <macadam/details/math/mc_zmod.h>
#include <macadam/details/math/mc_zmul.h>

#ifndef MC_ZDIV_H
#define MC_ZDIV_H

#pragma mark - mc_zdiv -

MC_TARGET_PROC void mc_zdivf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b_r, float b_i
) {
	mc_zconjf(c_r, c_i, b_r, b_i);
	mc_zmulf(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zfmulf(c_r, c_i, *c_r, *c_i, 1.0f / mc_raise2f(mc_zmodf(b_r, b_i)));
}

MC_TARGET_PROC void mc_zdiv(double * c_r, double * c_i
	, double a_r, double a_i
	, double b_r, double b_i
) {
	mc_zconj(c_r, c_i, b_r, b_i);
	mc_zmul(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zfmul(c_r, c_i, *c_r, *c_i, 1.0 / mc_raise2(mc_zmod(b_r, b_i)));
}

MC_TARGET_PROC void mc_zdivl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b_r, long double b_i
) {
	mc_zconjl(c_r, c_i, b_r, b_i);
	mc_zmull(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zfmull(c_r, c_i, *c_r, *c_i, 1.0L / mc_raise2l(mc_zmodl(b_r, b_i)));
}

#endif /* !MC_ZDIV_H */

/* EOF */
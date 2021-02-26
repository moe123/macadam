//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_clgamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_zlgamma.h>

#ifndef MC_CLGAMMA_H
#define MC_CLGAMMA_H

#pragma mark - mc_clgamma -

MC_TARGET_PROC mc_complex_float_t mc_clgammaf(const mc_complex_float_t c)
{
	float z_r, z_i;
	if (mc_cmplxif(c) != 0.0f) {
		mc_zlgammaf(&z_r, &z_i
			, mc_cmplxrf(c), mc_cmplxif(c)
		);
	} else {
	//!# Computing |log-gamma| (guess according to IEEE Std 1003.1-2001 actual).
		z_r = mc_lgammaf(mc_cmplxrf(c));
		z_i = 0.0f;
	}
	return mc_cmplxf(z_r, z_i);
}

MC_TARGET_PROC mc_complex_double_t mc_clgamma(const mc_complex_double_t c)
{
	double z_r, z_i;
	if (mc_cmplxi(c) != 0.0) {
		mc_zlgamma(&z_r, &z_i
			, mc_cmplxr(c), mc_cmplxi(c)
		);
	} else {
	//!# Computing |log-gamma| (guess according to IEEE Std 1003.1-2001 actual).
		z_r = mc_lgamma(mc_cmplxr(c));
		z_i = 0.0;
	}
	return mc_cmplx(z_r, z_i);
}

MC_TARGET_PROC mc_complex_long_double_t mc_clgammal(const mc_complex_long_double_t c)
{
	long double z_r, z_i;
	if (mc_cmplxil(c) != 0.0L) {
		mc_zlgammal(&z_r, &z_i
			, mc_cmplxrl(c), mc_cmplxil(c)
		);
	} else {
	//!# Computing |log-gamma| (guess according to IEEE Std 1003.1-2001 actual).
		z_r = mc_lgammal(mc_cmplxrl(c));
		z_i = 0.0L;
	}
	return mc_cmplxl(z_r, z_i);
}

#endif /* !MC_CLGAMMA_H */

/* EOF */
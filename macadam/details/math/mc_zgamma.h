//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zgamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cos.h>
#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_sin.h>
#include <macadam/details/math/mc_zlgamma.h>

#ifndef MC_ZGAMMA_H
#define MC_ZGAMMA_H

#pragma mark - mc_zgamma_approx0 -

MC_TARGET_PROC void mc_zgammaf_approx0(float * r_r, float * r_i, float x_r, float x_i)
{
	mc_zlgammaf_approx0(r_r, r_i, x_r, x_i);
	if (*r_r != 0.0f && *r_i  != 0.0f) {
	 	const float x = mc_expf(*r_r);
		*r_r          = x * mc_cosf(*r_i);
		*r_i          = x * mc_sinf(*r_i);
	}
}

MC_TARGET_PROC void mc_zgamma_approx0(double * r_r, double * r_i, double x_r, double x_i)
{
	mc_zlgamma_approx0(r_r, r_i, x_r, x_i);
	if (*r_r != 0.0 && *r_i  != 0.0) {
	 	const double x = mc_exp(*r_r);
		*r_r           = x * mc_cos(*r_i);
		*r_i           = x * mc_sin(*r_i);
	}
}

MC_TARGET_PROC void mc_zgammal_approx0(long double * r_r, long double * r_i, long double x_r, long double x_i)
{
	mc_zlgammal_approx0(r_r, r_i, x_r, x_i);
	if (*r_r != 0.0L && *r_i  != 0.0L) {
	 	const long double x = mc_expl(*r_r);
		*r_r                = x * mc_cosl(*r_i);
		*r_i                = x * mc_sinl(*r_i);
	}
}

#pragma mark - mc_zgamma -

MC_TARGET_PROC void mc_zgammaf(float * r_r, float * r_i, float x_r, float x_i)
{
	mc_zgammaf_approx0(r_r, r_i, x_r, x_i);
}

MC_TARGET_PROC void mc_zgamma(double * r_r, double * r_i, double x_r, double x_i)
{
	mc_zgamma_approx0(r_r, r_i, x_r, x_i);
}

MC_TARGET_PROC void mc_zgammal(long double * r_r, long double * r_i, long double x_r, long double x_i)
{
	mc_zgammal_approx0(r_r, r_i, x_r, x_i);
}

#endif /* !MC_ZLGAMMA_H */

/* EOF */
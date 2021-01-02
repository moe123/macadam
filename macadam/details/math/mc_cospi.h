//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cospi.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cos.h>
#include <macadam/details/math/mc_remzpi.h>
#include <macadam/details/math/mc_sin.h>

#ifndef MC_COSPI_H
#define MC_COSPI_H

#pragma mark - mc_cospi -

MC_TARGET_FUNC float mc_cospif(float x)
{
	float r   = 0.0f;
	int64_t i = mc_remzpif(x, &r) & 3;
	r         = MCK_KF(MCK_PI) * r;
	switch (i) {
		case 0:
			r =  mc_cosf(r);
		break;
		case 1:
			r = -mc_sinf(r);
		break;
		case 2:
			r = -mc_cosf(r);
		break;
		default:
			r =  mc_sinf(r);
	}
	return r;
}

MC_TARGET_FUNC double mc_cospi(double x)
{
	double r  = 0.0;
	int64_t i = mc_remzpi(x, &r) & 3;
	r         = MCK_K(MCK_PI) * r;
	switch (i) {
		case 0:
			r =  mc_cos(r);
		break;
		case 1:
			r = -mc_sin(r);
		break;
		case 2:
			r = -mc_cos(r);
		break;
		default:
			r =  mc_sin(r);
	}
	return r;
}

MC_TARGET_FUNC long double mc_cospil(long double x)
{
	long double r = 0.0;
	int64_t i     = mc_remzpil(x, &r) & 3;
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_PIl)
	r             = M_PIl * r;
#	else
	r             = MCK_KL(MCK_PI) * r;
#	endif
	switch (i) {
		case 0:
			r =  mc_cosl(r);
		break;
		case 1:
			r = -mc_sinl(r);
		break;
		case 2:
			r = -mc_cosl(r);
		break;
		default:
			r =  mc_sinl(r);
	}
	return r;
}

#endif /* !MC_COSPI_H */

/* EOF */
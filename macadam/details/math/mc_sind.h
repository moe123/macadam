//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sind.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cos.h>
#include <macadam/details/math/mc_remquo.h>
#include <macadam/details/math/mc_sin.h>

#ifndef MC_SIND_H
#define MC_SIND_H

#pragma mark - mc_sind -

MC_TARGET_FUNC float mc_sindf(const float x)
{
	int quo;
	float r       = 0.0f, a;
	const float s = x < 0.0f ? -1.0f : +1.0f;
	const float y = s * x;
	const float z = mc_remquof(y, 90.0f, &quo);
	a             = (z / 180.0f) * MCK_KF(MCK_PI);
	switch (quo % 4) {
		case 0:
			a =  a + 0.0f;
			r =  mc_sinf(a);
		break;
		case 1:
			r =  mc_cosf(a);
		break;
		case 2:
			a = -a + 0.0f;
			r =  mc_sinf(a);
		break;
		case 3:
			r = -mc_cosf(a);
		break;
	}
	return s * r;
}

MC_TARGET_FUNC double mc_sind(const double x)
{
	int quo;
	double r       = 0.0, a;
	const double s = x < 0.0 ? -1.0 : +1.0;
	const double y = s * x;
	const double z = mc_remquo(y, 90.0, &quo);
	a              = (z / 180.0) * MCK_K(MCK_PI);
	switch (quo % 4) {
		case 0:
			a =  a + 0.0;
			r =  mc_sin(a);
		break;
		case 1:
			r =  mc_cos(a);
		break;
		case 2:
			a = -a + 0.0;
			r =  mc_sin(a);
		break;
		case 3:
			r = -mc_cos(a);
		break;
	}
	return s * r;
}

MC_TARGET_FUNC long double mc_sindl(const long double x)
{
	int quo;
	long double r       = 0.0L, a;
	const long double s = x < 0.0L ? -1.0L : +1.0L;
	const long double y = s * x;
	const long double z = mc_remquol(y, 90.0L, &quo);
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_PIl)
	a                   = (z / 180.0L) * M_PIl;
#	else
	a                   = (z / 180.0L) * MCK_KL(MCK_PI);
#	endif
	switch (quo % 4) {
		case 0:
			a =  a + 0.0L;
			r =  mc_sinl(a);
		break;
		case 1:
			r =  mc_cosl(a);
		break;
		case 2:
			a = -a + 0.0L;
			r =  mc_sinl(a);
		break;
		case 3:
			r = -mc_cosl(a);
		break;
	}
	return s * r;
}

#endif /* !MC_SIND_H */

/* EOF */
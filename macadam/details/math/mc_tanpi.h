//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tanpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmod.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_tan.h>

#ifndef MC_TANPI_H
#define MC_TANPI_H

#pragma mark - mc_tanpi -

MC_TARGET_FUNCTION float mc_tanpif (float x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__mctanpif (x);
#	else
	return __mctanpif (x);
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmodf(mc_fabsf(x), 2.0f);
	if (mc_fmodf(x, 1.0f) == 0.5f) {
		return 0.0f;
	}
	if (x == 1.0f) {
		return -1.0f;
	}
	if (x == 0.0f) {
		return 1.0f;
	}
	const float pix = MCK_KF(MCK_PI) * x;
	return mc_tanf(pix);
#	endif
}

MC_TARGET_FUNCTION double mc_tanpi(double x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__mctanpi(x);
#	else
	return __mctanpi(x);
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmod(mc_fabs(x), 2.0);
	if (mc_fmod(x, 1.0) == 0.5) {
		return 0.0;
	}
	if (x == 1.0) {
		return -1.0;
	}
	if (x == 0.0) {
		return 1.0;
	}
	const double pix = MCK_K(MCK_PI) * x;
	return mc_tan(pix);
#	endif
}

MC_TARGET_FUNCTION long double mc_tanpil(long double x)
{
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::__mctanpi(xx));
#	else
	return mc_cast(long double, __mctanpi(xx));
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmodl(mc_fabsl(x), 2.0L);
	if (mc_fmodl(x, 1.0L) == 0.5L) {
		return 0.0L;
	}
	if (x == 1.0L) {
		return -1.0L;
	}
	if (x == 0.0L) {
		return 1.0L;
	}
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_PIl)
	const long double pix = M_PIl * x;
#	else
	const long double pix = MCK_KL(MCK_PI) * x;
#	endif
	return mc_tanl(pix);
#	endif
}

#endif /* !MC_TANPI_H */

/* EOF */
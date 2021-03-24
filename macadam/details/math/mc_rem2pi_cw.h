//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rem2pi_cw.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fisval.h>
#include <macadam/details/math/mc_rempio2_cw.h>

#ifndef MC_REM2PI_CW_H
#define MC_REM2PI_CW_H

MC_TARGET_PROC float mc_rem2pi_cwf(const float x)
{
//!# [+0, +2pi]. x mod 2pi.

	const float pi2h = +6.28318530717958600000000000000000000000E+00f;
	const float pi2m = MCK_KF(MCK_2PI) - pi2h;
	const float pi2l = +2.44929359829470640000000000000000000000E-16f;

	float z;

	//!# Cody-Waite reduction with cutoff at 2^20.
	if (mc_fisvalf(x) && mc_fabsf(x) <= 1048576.0f) {
		if (x == 0.0f || mc_fisnearf(x, MCK_KF(MCK_2PI), 2)) {
			return 0.0f;
		}
		// z = x / MCK_KF(MCK_2PI);
		// z = mc_floorf(z);
		// z = ((x - z * pi2h) - z * pi2m) - z * pi2l;
		// if (z > MCK_KF(MCK_2PI)) {
		// 	z = ((z - pi2h) - pi2m) - pi2l;
		// }
		// if (z < 0.0f) {
		// 	z = ((z + pi2h) + pi2m) + pi2l;
		// }
		mc_rempio2_cwf(x * 0.25f, &z);
		z = z < 0.0f ? z * 4.0f + MCK_KF(MCK_2PI) : z * 4.0f;
	} else {
		z = MCK_NAN;
	}
	return z;
}

MC_TARGET_PROC double mc_rem2pi_cw(const double x)
{
//!# [+0, +2pi]. x mod 2pi.

	const double pi2h = +6.28318530717958600000000000000000000000000E+00;
	const double pi2m = MCK_K(MCK_2PI) - pi2h;
	const double pi2l = +2.44929359829470640000000000000000000000000E-16;

	double z;

	//!# Cody-Waite reduction with cutoff at 2^31.
	if (mc_fisval(x) && mc_fabs(x) <= 2147483648.0) {
		if (x == 0.0 || mc_fisnear(x, MCK_K(MCK_2PI), 2)) {
			return 0.0;
		}
		z = x / MCK_K(MCK_2PI);
		z = mc_floor(z);
		z = ((x - z * pi2h) - z * pi2m) - z * pi2l;
		if (z > MCK_K(MCK_2PI)) {
			z = ((z - pi2h) - pi2m) - pi2l;
		}
		if (z < 0.0) {
			z = ((z + pi2h) + pi2m) + pi2l;
		}
		// mc_rempio2_cw(x * 0.25, &z);
		// z = z < 0.0 ? z * 4.0 + MCK_K(MCK_2PI) : z * 4.0;
	} else {
		z = MCK_NAN;
	}
	return z;
}

MC_TARGET_PROC long double mc_rem2pi_cwl(const long double x)
{
//!# [+0, +2pi]. x mod 2pi.
#	if MC_TARGET_HAVE_LONG_DOUBLE
	const long double pi2h = +6.283185307179586000000000000000000000000000000000000000000000000E+00L;
	const long double pi2m = MCK_KL(MCK_2PI) - pi2h;
	const long double pi2l = +2.449293598294706400000000000000000000000000000000000000000000000E-16L;

	long double z;

	//!# Cody-Waite reduction with cutoff at 2^39.
	if (mc_fisvall(x) && mc_fabsl(x) <= 549755813888.0L) {
		if (x == 0.0L || mc_fisnearl(x, MCK_KL(MCK_2PI), 2)) {
			return 0.0L;
		}
		z = x / MCK_KL(MCK_2PI);
		z = mc_floorl(z);
		z = ((x - z * pi2h) - z * pi2m) - z * pi2l;
		if (z > MCK_KL(MCK_2PI)) {
			z = ((z - pi2h) - pi2m) - pi2l;
		}
		if (z < 0.0) {
			z = ((z + pi2h) + pi2m) + pi2l;
		}
		//mc_rempio2_cwl(x * 0.25L, &z);
		//z = z < 0.0L ? z * 4.0L + MCK_KL(MCK_2PI) : z * 4.0L;
	} else {
		z = MCK_NAN;
	}
	return z;
#	else
	const double y = mc_cast(const double, x);
	return mc_cast(long double, mc_rem2pi_cw(y));
#	endif
}

#endif /* !MC_REM2PI_CW_H */

/* EOF */
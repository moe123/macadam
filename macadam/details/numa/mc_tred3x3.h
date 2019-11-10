//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tred3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_TRED3X3_H
#define MC_TRED3X3_H

#pragma mark - mc_tred3x3 -

MC_TARGET_FUNC int mc_tred3x3f(const float a[9], float t[9], float d[3], float u[2])
{
	const float tiny = MCLIMITS_TINYF;

	float mag, q, a12 = a[1], a13 = a[2];

	mc_eye3x3f(t);
	d[0] = a[0]; d[1] = a[4]; d[2] = a[8];
	u[0] = a12; u[1] = a[5];
	if (mc_fabsf(a13) >= tiny && !(a12 == 0.0f && a13 == 0.0f)) {
		mag = mc_sqrtf(mc_raise2f(a12) + mc_raise2f(a13));
		if (mag >= tiny) {
			a12  = a12 / mag;
			a13  = a13 / mag;
			q    = 2.0f * a12 * a[5] + a13 * (a[8] - a[4]);
			d[1] = a[4] + a13 * q; d[2] = a[8] - a13 * q;
			u[0] = mag; u[1] = a[5] - a12 * q;
			t[4] = a12; t[5] = a13;
			t[7] = a13; t[8] =-a12;
			return 0;
		}
	}
	return -1;
}

MC_TARGET_FUNC int mc_tred3x3(const double a[9], double t[9], double d[3], double u[2])
{
	const double tiny = MCLIMITS_TINY;

	double mag, q, a12 = a[1], a13 = a[2];

	mc_eye3x3(t);
	d[0] = a[0]; d[1] = a[4]; d[2] = a[8];
	u[0] = a12; u[1] = a[5];
	if (mc_fabs(a13) >= tiny && !(a12 == 0.0 && a13 == 0.0)) {
		mag = mc_sqrt(mc_raise2(a12) + mc_raise2(a13));
		if (mag >= tiny) {
			a12  = a12 / mag;
			a13  = a13 / mag;
			q    = 2.0f * a12 * a[5] + a13 * (a[8] - a[4]);
			d[1] = a[4] + a13 * q; d[2] = a[8] - a13 * q;
			u[0] = mag; u[1] = a[5] - a12 * q;
			t[4] = a12; t[5] = a13;
			t[7] = a13; t[8] =-a12;
			return 0;
		}
	}
	return -1;
}

MC_TARGET_FUNC int mc_tred3x3l(const long double a[9], long double t[9], long double d[3], long double u[2])
{
	const long double tiny = MCLIMITS_TINYL;

	long double mag, q, a12 = a[1], a13 = a[2];

	mc_eye3x3l(t);
	d[0] = a[0]; d[1] = a[4]; d[2] = a[8];
	u[0] = a12; u[1] = a[5];
	if (mc_fabsl(a13) >= tiny && !(a12 == 0.0L && a13 == 0.0L)) {
		mag = mc_sqrtl(mc_raise2l(a12) + mc_raise2l(a13));
		if (mag >= tiny) {
			a12  = a12 / mag;
			a13  = a13 / mag;
			q    = 2.0f * a12 * a[5] + a13 * (a[8] - a[4]);
			d[1] = a[4] + a13 * q; d[2] = a[8] - a13 * q;
			u[0] = mag; u[1] = a[5] - a12 * q;
			t[4] = a12; t[5] = a13;
			t[7] = a13; t[8] =-a12;
			return 0;
		}
	}
	return -1;
}

#endif /* !MC_TRED3X3_H */

/* EOF */
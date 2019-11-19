//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ldu3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_eye3x3.h>
#include <macadam/details/numa/mc_lu3x3.h>

#ifndef MC_LDU3X3_H
#define MC_LDU3X3_H

#pragma mark - mc_ldu3x3 -

MC_TARGET_FUNC int mc_ldu3x3f(const float a[9], float l[9], float d[9], float u[9])
{
//!# A and L may be the same. Using a closed-form expression.
	d[0] = 1.0f; d[1] = 1.0f; d[2] = 1.0f;
	if (0 == mc_lu3x3f(a, l, u)) {
		if (u[0] != 0.0f && u[4] != 0.0f) {
			d[0] = u[0]; d[1] = 0.0f; d[2] = 0.0f;
			d[3] = 0.0f; d[4] = u[4]; d[5] = 0.0f;
			d[6] = 0.0f; d[7] = 0.0f; d[8] = u[8];
//!# Updating U with REF of upper triangle.
			u[0] = 1.0f; u[1] = u[1] / d[0]; u[2] = u[2] / d[0];
			u[3] = 0.0f; u[4] = 1.0f;        u[5] = u[5] / d[4];
			u[6] = 0.0f; u[7] = 0.0f;        u[8] = 1.0f;
			return 0;
		}
		mc_eye3x3f(l);
		mc_eye3x3f(d);
		mc_eye3x3f(u);
	}
	return -1;
}

MC_TARGET_FUNC int mc_ldu3x3ff(const float a[9], double l[9], double d[9], double u[9])
{
//!# A and L may be the same. Using a closed-form expression.
	d[0] = 1.0; d[1] = 1.0; d[2] = 1.0;
	if (0 == mc_lu3x3ff(a, l, u)) {
		if (u[0] != 0.0 && u[4] != 0.0) {
			d[0] = u[0]; d[1] = 0.0;  d[2] = 0.0;
			d[3] = 0.0;  d[4] = u[4]; d[5] = 0.0;
			d[6] = 0.0;  d[7] = 0.0;  d[8] = u[8];
//!# Updating U with REF of upper triangle.
			u[0] = 1.0; u[1] = u[1] / d[0]; u[2] = u[2] / d[0];
			u[3] = 0.0; u[4] = 1.0;         u[5] = u[5] / d[4];
			u[6] = 0.0; u[7] = 0.0;         u[8] = 1.0;
			return 0;
		}
		mc_eye3x3(l);
		mc_eye3x3(d);
		mc_eye3x3(u);
	}
	return -1;
}

MC_TARGET_FUNC int mc_ldu3x3(const double a[9], double l[9], double d[9], double u[9])
{
//!# A and L may be the same. Using a closed-form expression.
	d[0] = 1.0; d[1] = 1.0; d[2] = 1.0;
	if (0 == mc_lu3x3(a, l, u)) {
		if (u[0] != 0.0 && u[4] != 0.0) {
			d[0] = u[0]; d[1] = 0.0;  d[2] = 0.0;
			d[3] = 0.0;  d[4] = u[4]; d[5] = 0.0;
			d[6] = 0.0;  d[7] = 0.0;  d[8] = u[8];
//!# Updating U with REF of upper triangle.
			u[0] = 1.0; u[1] = u[1] / d[0]; u[2] = u[2] / d[0];
			u[3] = 0.0; u[4] = 1.0;         u[5] = u[5] / d[4];
			u[6] = 0.0; u[7] = 0.0;         u[8] = 1.0;
			return 0;
		}
		mc_eye3x3(l);
		mc_eye3x3(d);
		mc_eye3x3(u);
	}
	return -1;
}

MC_TARGET_FUNC int mc_ldu3x3l(const long double a[9], long double l[9], long double d[9], long double u[9])
{
//!# A and L may be the same. Using a closed-form expression.
	d[0] = 1.0L; d[1] = 1.0L; d[2] = 1.0L;
	if (0 == mc_lu3x3l(a, l, u)) {
		if (u[0] != 0.0L && u[4] != 0.0L) {
			d[0] = u[0]; d[1] = 0.0L; d[2] = 0.0L;
			d[3] = 0.0L; d[4] = u[4]; d[5] = 0.0L;
			d[6] = 0.0L; d[7] = 0.0L; d[8] = u[8];
//!# Updating U with REF of upper triangle.
			u[0] = 1.0L; u[1] = u[1] / d[0]; u[2] = u[2] / d[0];
			u[3] = 0.0L; u[4] = 1.0L;        u[5] = u[5] / d[4];
			u[6] = 0.0L; u[7] = 0.0L;        u[8] = 1.0L;
			return 0;
		}
		mc_eye3x3l(l);
		mc_eye3x3l(d);
		mc_eye3x3l(u);
	}
	return -1;
}

#endif /* !MC_LDU3X3_H */

/* EOF */
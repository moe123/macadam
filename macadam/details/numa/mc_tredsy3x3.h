//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tredsy3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_eye3x3.h>

#ifndef MC_TREDSY3X3_H
#define MC_TREDSY3X3_H

#pragma mark - mc_tredsy3x3_approx0 -

MC_TARGET_PROC int mc_tredsy3x3f_approx0(const float a[9], float * q, float d[3], float e[2])
{
//!# Close-formish expression by rref.
	const float tiny = MCLIMITS_TINYF;

	int wantq = mc_nonnull(q);
	float mag, s;

	float a11 = a[0], a12 = a[1], a13 = a[2];
	float             a22 = a[4], a23 = a[5];
	float                         a33 = a[8];

	if (wantq) {
		mc_eye3x3f(q);
	}

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[0] = a12; e[1] = a23;
	if (mc_fabsf(a13) >= tiny && !(a12 == 0.0f && a13 == 0.0f)) {
		mag = mc_sqrtf(mc_raise2f(a12) + mc_raise2f(a13));
		if (mc_fabsf(mag) >= tiny) {
			if (a11 > 0.0f) {
				mag = -mag;
			}
			a12  = a12 / mag;
			a13  = a13 / mag;
			s    = (2.0f * a12 * a23) + a13 * (a33 - a22);
			d[1] = a22 + a13 * s; d[2] = a33 - a13 * s;
			e[0] = mag; e[1] = a23 - a12 * s;
			if (wantq) {
				q[4] = a12; q[5] = a13;
				q[7] = a13; q[8] =-a12;
			}
			return 0;
		}
	}
	return -1;
}

MC_TARGET_PROC int mc_tredsy3x3_approx0(const double a[9], double * q, double d[3], double e[2])
{
//!# Close-formish expression by rref.
	const double tiny = MCLIMITS_TINY;

	int wantq = mc_nonnull(q);
	double mag, s;

	double a11 = a[0], a12 = a[1], a13 = a[2];
	double             a22 = a[4], a23 = a[5];
	double                         a33 = a[8];

	if (wantq) {
		mc_eye3x3(q);
	}

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[0] = a12; e[1] = a23;
	if (mc_fabs(a13) >= tiny && !(a12 == 0.0 && a13 == 0.0)) {
		mag = mc_sqrt(mc_raise2(a12) + mc_raise2(a13));
		if (mc_fabs(mag) >= tiny) {
			if (a11 > 0.0) {
				mag = -mag;
			}
			a12  = a12 / mag;
			a13  = a13 / mag;
			s    = 2.0 * a12 * a23 + a13 * (a33 - a22);
			d[1] = a22 + a13 * s; d[2] = a33 - a13 * s;
			e[0] = mag; e[1] = a23 - a12 * s;
			if (wantq) {
				q[4] = a12; q[5] = a13;
				q[7] = a13; q[8] =-a12;
			}
			return 0;
		}
	}
	return -1;
}

MC_TARGET_PROC int mc_tredsy3x3l_approx0(const long double a[9], long double * q, long double d[3], long double e[2])
{
//!# Close-formish expression by rref.
	const long double tiny = MCLIMITS_TINYL;

	int wantq = mc_nonnull(q);
	long double mag, s;

	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double             a22 = a[4], a23 = a[5];
	long double                         a33 = a[8];

	if (wantq) {
		mc_eye3x3l(q);
	}

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[0] = a12; e[1] = a23;
	if (mc_fabsl(a13) >= tiny && !(a12 == 0.0L && a13 == 0.0L)) {
		mag = mc_sqrtl(mc_raise2l(a12) + mc_raise2l(a13));
		if (mc_fabsl(mag) >= tiny) {
			if (a11 > 0.0) {
				mag = -mag;
			}
			a12  = a12 / mag;
			a13  = a13 / mag;
			s    = 2.0L * a12 * a23 + a13 * (a33 - a22);
			d[1] = a22 + a13 * s; d[2] = a33 - a13 * s;
			e[0] = mag; e[1] = a23 - a12 * s;
			if (wantq) {
				q[4] = a12; q[5] = a13;
				q[7] = a13; q[8] =-a12;
			}
			return 0;
		}
	}
	return -1;
}

#pragma mark - mc_tredsy3x3_approx1 -

MC_TARGET_PROC int mc_tredsy3x3f_approx1(const float a[9], float * q, float d[3], float e[2])
{
//!# Full Householder transformation.
	int wantq     = mc_nonnull(q);
	float w, s, k = 0.0f, h, g, u1, u2, q1, q2;

	float a11 = a[0], a12 = a[1], a13 = a[2];
	float             a22 = a[4], a23 = a[5];
	float                         a33 = a[8];

	h    = mc_raise2f(a12) + mc_raise2f(a13);
	g    = a12 > 0.0f ? -mc_sqrtf(h) : mc_sqrtf(h);
	e[0] = g;
	s    = g * a12;
	u1   = a12 - g;
	u2   = a13;

	if (wantq) {
		mc_eye3x3f(q);
	}

	w = h - s;

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[1] = a23;

	if (w > 0.0f) {
		w    = 1.0f / w;

		s    = a22 * u1 + a23 * u2;
		q1   = w * s;
		k    = k + u1 * s;
		s    = a23 * u1 + a33 * u2;
		q2   = w * s;
		k    = k + u2 * s;

		k    = k * (0.5f * w * w);

		q1   = q1 - k * u1;
		q2   = q2 - k * u2;

		d[0] = a11;
		d[1] = a22 - 2.0f * q1 * u1;
		d[2] = a23 - 2.0f * q2 * u2;

		if (wantq) {
			s    = w * u1;
			q[4] = q[4] - s * u1;
			q[7] = q[7] - s * u2;
			s    = w * u2;
			q[5] = q[5] - s * u1;
			q[8] = q[8] - s * u2;
		}
		e[1] = a23 - q1 * u2 - u1 * q2;
		return 0;
	}
	return -1;
}

MC_TARGET_PROC int mc_tredsy3x3_approx1(const double a[9], double * q, double d[3], double e[2])
{
//!# Full Householder transformation.
	int wantq      = mc_nonnull(q);
	double w, s, k = 0.0, h, g, u1, u2, q1, q2;

	double a11 = a[0], a12 = a[1], a13 = a[2];
	double             a22 = a[4], a23 = a[5];
	double                         a33 = a[8];

	h    = mc_raise2(a12) + mc_raise2(a13);
	g    = a12 > 0.0 ? -mc_sqrt(h) : mc_sqrt(h);
	e[0] = g;
	s    = g * a12;
	u1   = a12 - g;
	u2   = a13;

	if (wantq) {
		mc_eye3x3(q);
	}

	w = h - s;

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[1] = a23;

	if (w > 0.0) {
		w = 1.0 / w;

		s    = a22 * u1 + a23 * u2;
		q1   = w * s;
		k    = k + u1 * s;
		s    = a23 * u1 + a33 * u2;
		q2   = w * s;
		k    = k + u2 * s;

		k    = k * (0.5 * w * w);

		q1   = q1 - k * u1;
		q2   = q2 - k * u2;

		d[0] = a11;
		d[1] = a22 - 2.0 * q1 * u1;
		d[2] = a23 - 2.0 * q2 * u2;

		if (wantq) {
			s    = w * u1;
			q[4] = q[4] - s * u1;
			q[7] = q[7] - s * u2;
			s    = w * u2;
			q[5] = q[5] - s * u1;
			q[8] = q[8] - s * u2;
		}
		e[1] = a23 - q1 * u2 - u1 * q2;
		return 0;
	}
	return -1;
}

MC_TARGET_PROC int mc_tredsy3x3l_approx1(const long double a[9], long double q[9], long double d[3], long double e[2])
{
//!# Full Householder transformation.
	int wantq           = mc_nonnull(q);
	long double w, s, k = 0.0L, h, g, u1, u2, q1, q2;

	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double             a22 = a[4], a23 = a[5];
	long double                         a33 = a[8];

	h    = mc_raise2l(a12) + mc_raise2l(a13);
	g    = a12 > 0.0L ? -mc_sqrtl(h) : mc_sqrtl(h);
	e[0] = g;
	s    = g * a12;
	u1   = a12 - g;
	u2   = a13;

	if (wantq) {
		mc_eye3x3l(q);
	}

	w = h - s;

	d[0] = a11; d[1] = a22; d[2] = a33;
	e[1] = a23;

	if (w > 0.0L) {
		w = 1.0L / w;

		s    = a22 * u1 + a23 * u2;
		q1   = w * s;
		k    = k + u1 * s;
		s    = a23 * u1 + a33 * u2;
		q2   = w * s;
		k    = k + u2 * s;

		k    = k * (0.5L * w * w);

		q1   = q1 - k * u1;
		q2   = q2 - k * u2;

		d[0] = a11;
		d[1] = a22 - 2.0L * q1 * u1;
		d[2] = a23 - 2.0L * q2 * u2;

		if (wantq) {
			s    = w * u1;
			q[4] = q[4] - s * u1;
			q[7] = q[7] - s * u2;
			s    = w * u2;
			q[5] = q[5] - s * u1;
			q[8] = q[8] - s * u2;
		}
		e[1] = a23 - q1 * u2 - u1 * q2;
		return 0;
	}
	return -1;
}

#pragma mark - mc_tredsy3x3 -

MC_TARGET_PROC int mc_tredsy3x3f(const float a[9], float * q, float d[3], float e[2])
{
	return mc_tredsy3x3f_approx1(a, q, d, e);
}

MC_TARGET_PROC int mc_tredsy3x3(const double a[9], double * q, double d[3], double e[2])
{
	return mc_tredsy3x3_approx1(a, q, d, e);
}

MC_TARGET_PROC int mc_tredsy3x3l(const long double a[9], long double * q, long double d[3], long double e[2])
{
	return mc_tredsy3x3l_approx1(a, q, d, e);
}

#endif /* !MC_TREDSY3X3_H */

/* EOF */
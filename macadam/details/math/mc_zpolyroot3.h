//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zpolyroot3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_acos.h>
#include <macadam/details/math/mc_cbrt.h>
#include <macadam/details/math/mc_cos.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_raise3.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_ZPOLYROOT3_H
#define MC_ZPOLYROOT3_H

#pragma mark - mc_zpolyroot3 -

MC_TARGET_PROC int mc_zpolyroot3f(float a, float b, float c, float d
	, float * r1
	, float * i1
	, float * r2
	, float * i2
	, float * r3
	, float * i3
) {
//!# Three roots of the cubic equation: ax^3+bx^2+cx+d=0.
//!# Returns 2 if roots are real and at least two are equal.
//!# Returns 3 if roots are real and distinct.
//!# Returns 5 if first root is real, the two others are conjugate.
	int r         = -1;
	const float e = 1E-05f;
	if (!(a == 0.0f || d == 0.0f)) {
		if (a != 1.0f) {
			a = 1.0f / a;
			b = b * a;
			c = c * a;
			d = d * a;
		}
		const float q = (3.0f * c - mc_raise2f(b)) / 9.0f;
		const float t = (9.0f * b * c - 27.0f * d - 2.0f * mc_raise2f(b) * b) / 54.0f;
		const float s = mc_raise3f(q) + mc_raise2f(t);

		if (mc_fabsf(s) < e) {
			const float m = t > 0.0f ? mc_cbrtf(t) : -mc_cbrtf(-t);
			*r1           = 2.0f * m - b / 3.0f;
			*i1           = 0.0f;
			*r2           = -m - b / 3.0f;
			*i2           = 0.0f;
			*r3           = *r2;
			*i3           = *i2;
			r             = 2;
		} else if (s < 0) {
			const float m = mc_sqrtf(-q);
			const float h = 2.0f * m;
			const float g = b / 3.0f;
			const float w = mc_acosf(t / (m * mc_fabsf(q)));
			*r1           = h * mc_cosf(w / 3.0f) - g;
			*i1           = 0.0f;
			*r2           = h * mc_cosf((w + MCK_KF(MCK_2PI)) / 3.0f) - g;
			*i2           = *i1;
			*r3           = h * mc_cosf((w + MCK_KF(MCK_4PI)) / 3.0f) - g;
			*i3           = *i2;
			r             = 3;
		} else if (s > 0) {
			float u, v, w, h, g;
			const float m = mc_sqrtf(s);
			u             = t + m;
			v             = t - m;
			u             = (u > 0.0f) ? mc_cbrtf(u) : -mc_cbrtf(-u);
			v             = (v > 0.0f) ? mc_cbrtf(v) : -mc_cbrtf(-v);
			w             = u + v;
			h             = MCK_KF(MCK_SQRT3) / 2.0f * (u - v);
			g             = b / 3.0f;
			*r1           = w - g;
			*i1           = 0.0f;
			*r2           = -0.5f * w - g;
			*i2           = h;
			*r3           = *r2;
			*i3           = -(*i2);
			r             = 5;
		}
	}
	return r;
}

MC_TARGET_PROC int mc_zpolyroot3(double a, double b, double c, double d
	, double * r1
	, double * i1
	, double * r2
	, double * i2
	, double * r3
	, double * i3
) {
//!# Three roots of the cubic equation: ax^3+bx^2+cx+d=0.
//!# Returns 2 if roots are real and at least two are equal.
//!# Returns 3 if roots are real and distinct.
//!# Returns 5 if first root is real, the two others are conjugate.
	int r          = -1;
	const double e = 1E-09;
	if (!(a == 0.0 || d == 0.0)) {
		if (a != 1.0) {
			a = 1.0 / a;
			b = b * a;
			c = c * a;
			d = d * a;
		}
		const double q = (3.0 * c - mc_raise2(b)) / 9.0;
		const double t = (9.0 * b * c - 27.0 * d - 2.0 * mc_raise2(b) * b) / 54.0;
		const double s = mc_raise3(q) + mc_raise2(t);

		if (mc_fabs(s) < e) {
			const double m = t > 0.0 ? mc_cbrt(t) : -mc_cbrt(-t);
			*r1            = 2.0 * m - b / 3.0;
			*i1            = 0.0;
			*r2            = -m - b / 3.0;
			*i2            = 0.0;
			*r3            = *r2;
			*i3            = *i2;
			r              = 2;
		} else if (s < 0) {
			const double m = mc_sqrt(-q);
			const double h = 2.0 * m;
			const double g = b / 3.0;
			const double w = mc_acos(t / (m * mc_fabs(q)));
			*r1            = h * mc_cos(w / 3.0) - g;
			*i1            = 0.0;
			*r2            = h * mc_cos((w + MCK_K(MCK_2PI)) / 3.0) - g;
			*i2            = *i1;
			*r3            = h * mc_cos((w + MCK_K(MCK_4PI)) / 3.0) - g;
			*i3            = *i2;
			r              = 3;
		} else if (s > 0) {
			double u, v, w, h, g;
			const double m = mc_sqrt(s);
			u              = t + m;
			v              = t - m;
			u              = (u > 0.0) ? mc_cbrt(u) : -mc_cbrt(-u);
			v              = (v > 0.0) ? mc_cbrt(v) : -mc_cbrt(-v);
			w              = u + v;
			h              = MCK_K(MCK_SQRT3) / 2.0 * (u - v);
			g              = b / 3.0;
			*r1            = w - g;
			*i1            = 0.0;
			*r2            = -0.5 * w - g;
			*i2            = h;
			*r3            = *r2;
			*i3            = -(*i2);
			r              = 5;
		}
	}
	return r;
}

MC_TARGET_PROC int mc_zpolyroot3l(long double a, long double b, long double c, long double d
	, long double * r1
	, long double * i1
	, long double * r2
	, long double * i2
	, long double * r3
	, long double * i3
) {
//!# Three roots of the cubic equation: ax^3+bx^2+cx+d=0.
//!# Returns 2 if roots are real and at least two are equal.
//!# Returns 3 if roots are real and distinct.
//!# Returns 5 if first root is real, the two others are conjugate.
	int r               = -1;
	const long double e = 1E-12L;
	if (!(a == 0.0L || d == 0.0L)) {
		if (a != 1.0L) {
			a = 1.0L / a;
			b = b * a;
			c = c * a;
			d = d * a;
		}
		const long double q = (3.0L * c - mc_raise2l(b)) / 9.0L;
		const long double t = (9.0L * b * c - 27.0L * d - 2.0L * mc_raise2l(b) * b) / 54.0L;
		const long double s = mc_raise3l(q) + mc_raise2l(t);

		if (mc_fabsl(s) < e) {
			const long double m = t > 0.0L ? mc_cbrtl(t) : -mc_cbrtl(-t);
			*r1                 = 2.0L * m - b / 3.0L;
			*i1                 = 0.0L;
			*r2                 = -m - b / 3.0L;
			*i2                 = 0.0L;
			*r3                 = *r2;
			*i3                 = *i2;
			r                   = 2;
		} else if (s < 0) {
			const long double m = mc_sqrtl(-q);
			const long double h = 2.0L * m;
			const long double g = b / 3.0L;
			const long double w = mc_acosl(t / (m * mc_fabsl(q)));
			*r1                 = h * mc_cosl(w / 3.0L) - g;
			*i1                 = 0.0L;
			*r2                 = h * mc_cosl((w + MCK_KL(MCK_2PI)) / 3.0L) - g;
			*i2                 = *i1;
			*r3                 = h * mc_cosl((w + MCK_KL(MCK_4PI)) / 3.0L) - g;
			*i3                 = *i2;
			r                   = 3;
		} else if (s > 0) {
			long double u, v, w, h, g;
			const long double m = mc_sqrtl(s);
			u                   = t + m;
			v                   = t - m;
			u                   = (u > 0.0L) ? mc_cbrtl(u) : -mc_cbrtl(-u);
			v                   = (v > 0.0L) ? mc_cbrtl(v) : -mc_cbrtl(-v);
			w                   = u + v;
			h                   = MCK_KL(MCK_SQRT3) / 2.0L * (u - v);
			g                   = b / 3.0L;
			*r1                 = w - g;
			*i1                 = 0.0L;
			*r2                 = -0.5L * w - g;
			*i2                 = h;
			*r3                 = *r2;
			*i3                 = -(*i2);
			r                   = 5;
		}
	}
	return r;
}

#endif /* !MC_ZPOLYROOT3_H */

/* EOF */
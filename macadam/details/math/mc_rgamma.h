//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rgamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_factorial.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_log.h>

#ifndef MC_RGAMMA_H
#define MC_RGAMMA_H

#pragma mark - mc_rgamma_r0 -

static MC_TARGET_INLINE float mc_rgammaf_r0(float a, float z)
{
	float r = 0.0f, p;
	if (a > 0.0f) {
		p = 1.0f;

		r = r + (p / mc_factorialf(0.0f))  / (0.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(1.0f))  / (1.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(2.0f))  / (2.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(3.0f))  / (3.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(4.0f))  / (4.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(5.0f))  / (5.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(6.0f))  / (6.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(7.0f))  / (7.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(8.0f))  / (8.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(9.0f))  / (9.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(10.0f)) / (10.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(11.0f)) / (11.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(12.0f)) / (12.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(13.0f)) / (13.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(14.0f)) / (14.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(15.0f)) / (15.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(16.0f)) / (16.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(17.0f)) / (17.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(18.0f)) / (18.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(19.0f)) / (19.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(20.0f)) / (20.0f + a);

		r = mc_expf(a * mc_logf(z) + mc_logf(r) - mc_lgammaf(a));
	}
	return r;
}

static MC_TARGET_INLINE double mc_rgamma_r0(double a, double z)
{
	double r = 0.0, p;
	if (a > 0.0) {
		p = 1.0;

		r = r + (p / mc_factorial(0.0))  / (0.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(1.0))  / (1.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(2.0))  / (2.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(3.0))  / (3.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(4.0))  / (4.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(5.0))  / (5.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(6.0))  / (6.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(7.0))  / (7.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(8.0))  / (8.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(9.0))  / (9.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(10.0)) / (10.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(11.0)) / (11.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(12.0)) / (12.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(13.0)) / (13.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(14.0)) / (14.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(15.0)) / (15.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(16.0)) / (16.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(17.0)) / (17.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(18.0)) / (18.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(19.0)) / (19.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(20.0)) / (20.0 + a);

		r = mc_exp(a * mc_log(z) + mc_log(r) - mc_lgamma(a));
	}
	return r;
}

static MC_TARGET_INLINE long double mc_rgammal_r0(long double a, long double z)
{
	long double r = 0.0L, p;
	if (a > 0.0L) {
		p = 1.0L;

		r = r + (p / mc_factoriall(0.0L))  / (0.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(1.0L))  / (1.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(2.0L))  / (2.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(3.0L))  / (3.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(4.0L))  / (4.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(5.0L))  / (5.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(6.0L))  / (6.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(7.0L))  / (7.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(8.0L))  / (8.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(9.0L))  / (9.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(10.0L)) / (10.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(11.0L)) / (11.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(12.0L)) / (12.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(13.0L)) / (13.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(14.0L)) / (14.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(15.0L)) / (15.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(16.0L)) / (16.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(17.0L)) / (17.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(18.0L)) / (18.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(19.0L)) / (19.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(20.0L)) / (20.0L + a);

		r = mc_expl(a * mc_logl(z) + mc_logl(r) - mc_lgammal(a));
	}
	return r;
}

#pragma mark - mc_rgamma_r1 -

static MC_TARGET_INLINE float mc_rgammaf_r1(float a, float z)
{
	float r = 0.0f;
	float p = 1.0f / a;
	float c = p;
	float s = p;
	float d = -s + c;
	float l = s;
	float m = 0.0f;
	float e = 0.0f;
	int k   = 1;
	if (a > 0.0f) {
		r = mc_expf(a * mc_logf(z) - z - mc_lgammaf(a));
		if (r > 0.0f) {
			e = 1.0E-10f / r;
		}
		if (e <= 0.0f) {
			e = 1.0E-10f;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0f / z) * (a + mc_cast(float, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0f / (m - l) * r);
		p = p * ((1.0f / z) * (a + mc_cast(float, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0f / z) * (a + mc_cast(float, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

static MC_TARGET_INLINE double mc_rgamma_r1(double a, double z)
{
	double r = 0.0;
	double p = 1.0 / a;
	double c = p;
	double s = p;
	double d = -s + c;
	double l = s;
	double m = 0.0;
	double e = 0.0;
	int k   = 1;
	if (a > 0.0) {
		r = mc_exp(a * mc_log(z) - z - mc_lgamma(a));
		if (r > 0.0) {
			e = 1.0E-15 / r;
		}
		if (e <= 0.0) {
			e = 1.0E-15;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0 / z) * (a + mc_cast(double, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0 / (m - l) * r);
		p = p * ((1.0 / z) * (a + mc_cast(double, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0 / z) * (a + mc_cast(double, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

static MC_TARGET_INLINE long double mc_rgammal_r1(long double a, long double z)
{
	long double r = 0.0L;
	long double p = 1.0L / a;
	long double c = p;
	long double s = p;
	long double d = -s + c;
	long double l = s;
	long double m = 0.0L;
	long double e = 0.0L;
	int k   = 1;
	if (a > 0.0L) {
		r = mc_expl(a * mc_logl(z) - z - mc_lgammal(a));
		if (r > 0.0L) {
			e = 1.0E-15L / r;
		}
		if (e <= 0.0L) {
			e = 1.0E-15L;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0L / (m - l) * r);
		p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

#pragma mark - mc_rgamma_r2 -

static MC_TARGET_INLINE float mc_rgammaf_r2(float a, float z)
{
	float r = 0.0f, p = 1.0f / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0f)) + 1;
	if (a > 0.0f && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0f / (z + mc_cast(float, k)));
			s = s + p;
		}
		r = mc_expf(mc_logf(s) + a * mc_logf(z) - z - mc_lgammaf(a)) + mc_rgammaf_r0(a + mc_cast(float, n), z);
	}
	return r;
}

static MC_TARGET_INLINE double mc_rgamma_r2(double a, double z)
{
	double r = 0.0, p = 1.0 / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0)) + 1;
	if (a > 0.0 && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0 / (z + mc_cast(double, k)));
			s = s + p;
		}
		r = mc_exp(mc_log(s) + a * mc_log(z) - z - mc_lgamma(a)) + mc_rgammaf_r0(a + mc_cast(double, n), z);
	}
	return r;
}

static MC_TARGET_INLINE long double mc_rgammal_r2(long double a, long double z)
{
	long double r = 0.0L, p = 1.0L / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0L)) + 1;
	if (a > 0.0L && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0L / (z + mc_cast(long double, k)));
			s = s + p;
		}
		r = mc_expl(mc_logl(s) + a * mc_logl(z) - z - mc_lgammal(a)) + mc_rgammaf_r0(a + mc_cast(long double, n), z);
	}
	return r;
}

#pragma mark - mc_rgamma -

static MC_TARGET_INLINE float mc_rgammaf(float z, float a)
{
	if (z == 0.0f || !(a > 0.0f)) {
		return 0.0f;
	}
	if (mc_fabsf(z) <= 1.0f) {
		return mc_rgamma_r0(a, z);
	}
	if (mc_fabsf(z) <= (a + 1.0f)) {
		return mc_rgammaf_r1(a, z);
	}
	return mc_rgammaf_r2(a, z);
}

static MC_TARGET_INLINE double mc_rgamma(double z, double a)
{
	if (z == 0.0 || !(a > 0.0)) {
		return 0.0;
	}
	if (mc_fabs(z) <= 1.0) {
		return mc_rgamma_r0(a, z);
	}
	if (mc_fabs(z) <= (a + 1.0)) {
		return mc_rgamma_r1(a, z);
	}
	return mc_rgamma_r2(a, z);
}

static MC_TARGET_INLINE long double mc_rgammal(long double z, long double a)
{
	if (z == 0.0L || !(a > 0.0L)) {
		return 0.0L;
	}
	if (mc_fabsl(z) <= 1.0L) {
		return mc_rgammal_r0(a, z);
	}
	if (mc_fabsl(z) <= (a + 1.0L)) {
		return mc_rgammal_r1(a, z);
	}
	return mc_rgammal_r2(a, z);
}

#endif /* !MC_RGAMMA_H */

/* EOF */
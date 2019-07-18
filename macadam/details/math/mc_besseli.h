//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_besseli.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_raise2.h>

#ifndef MC_BESSELI_H
#define MC_BESSELI_H

#pragma mark - mc_besseli0_approx0 -

MC_TARGET_PROC float mc_besseli0f_approx0(float x)
{
	float r  = 1;
	int   t  = 0;
	float i0 = 0;
	do {
		i0 += r; ++t; r *= mc_raise2f(x) / (4.0f * t * t);
	} while (r > MCLIMITS_EPSILONF * i0);
	return i0;
}

MC_TARGET_PROC double mc_besseli0_approx0(double x)
{
	double r  = 1;
	int    t  = 0;
	double i0 = 0;
	do {
		i0 += r; ++t; r *= mc_raise2(x) / (4.0 * t * t);
	} while (r > MCLIMITS_EPSILON * i0);
	return i0;
}

MC_TARGET_PROC long double mc_besseli0l_approx0(long double x)
{
	long double r  = 1;
	int         t  = 0;
	long double i0 = 0;
	do {
		i0 += r; ++t; r *= mc_raise2l(x) / (4.0L * t * t);
	} while (r > MCLIMITS_EPSILONL * i0);
	return i0;
}

#pragma mark - mc_besseli1_approx0 -

MC_TARGET_PROC float mc_besseli1f_approx0(float x)
{
	float r  = 0.5f * x;
	int   t  = 0;
	float i1 = 0;
	do {
		i1 += r; ++t; r *= mc_raise2f(x) / (4.0f * t * (t + 1));
	} while (r > MCLIMITS_EPSILONF * i1);
	return i1;
}

MC_TARGET_PROC double mc_besseli1_approx0(double x)
{
	double r  = 0.5 * x;
	int    t  = 0;
	double i1 = 0;
	do { 
		i1 += r; ++t; r *= mc_raise2(x) / (4.0 * t * (t + 1));
	} while (r > MCLIMITS_EPSILON * i1);
	return i1;
}

MC_TARGET_PROC long double mc_besseli1l_approx0(long double x)
{
	long double r  = 0.5L * x;
	int         t  = 0;
	long double i1 = 0;
	do {
		i1 += r; ++t; r *= mc_raise2l(x) / (4.0L * t * (t + 1));
	} while (r > MCLIMITS_EPSILONL * i1);
	return i1;
}

#pragma mark - mc_besselin_approx0 -

MC_TARGET_PROC double mc_besselinf_approx0(int n, float x)
{
	float i0 = mc_besseli0f_approx0(x);
	float i1 = mc_besseli1f_approx0(x);
	float in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0f / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

MC_TARGET_PROC double mc_besselin_approx0(int n, double x)
{
	double i0 = mc_besseli0_approx0(x);
	double i1 = mc_besseli1_approx0(x);
	double in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0 / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

MC_TARGET_PROC long double mc_besselinl_approx0(int n, long double x)
{
	long double i0 = mc_besseli0l_approx0(x);
	long double i1 = mc_besseli1l_approx0(x);
	long double in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0L / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

#pragma mark - mc_besseli0_approx1 -

MC_TARGET_PROC float mc_besseli0f_approx1(float x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	float a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	float b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5f) {
		a1 = +0.1682f;   a2 = +0.1472f;  a3 = +0.4450f;  a4 = +0.2382f;
		b1 = +0.7536f;   b2 = +0.9739f;  b3 = -0.715f;   b4 = +0.2343f;
	} else if (x < 20.0f) {
		a1 = +0.2667f;   a2 = +0.4916f;  a3 = +0.1110f;  a4 = +0.1304f;
		b1 = +0.4710f;   b2 = -163.4f;   b3 = +0.9852f;  b4 = +0.8554f;
	} else if (x < 37.25f) {
		a1 = +0.1121f;   a2 = 0.1055f;   a3 = -0.00018f; a4 = +0.00326f;
		b1 = +0.9807f;   b2 = 0.8672f;   b3 = +1.0795f;  b4 = +1.0385f;
	} else {
		a1 = +2.41E-9f;  a2 = +0.06745f; a3 = +0.05471f; a4 = +0.5686f;
		b1 = +1.144f;    b2 = +0.995f;   b3 = +0.5686f;  b4 = +0.946f;
	}
	return (a1 * mc_expf(x * b1) + a2 * mc_expf(x * b2) + a3 * mc_expf(x * b3) + a4 * mc_expf(x * b4));
}

#pragma mark - mc_besseli0_approx1 -

MC_TARGET_PROC double mc_besseli0_approx1(double x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5) {
		a1 = +0.1682;   a2 = +0.1472;  a3 = +0.4450;  a4 = +0.2382;
		b1 = +0.7536;   b2 = +0.9739;  b3 = -0.715;   b4 = +0.2343;
	} else if (x < 20.0) {
		a1 = +0.2667;   a2 = +0.4916;  a3 = +0.1110;  a4 = +0.1304;
		b1 = +0.4710;   b2 = -163.4;   b3 = +0.9852;  b4 = +0.8554;
	} else if (x < 37.25) {
		a1 = +0.1121;   a2 = 0.1055;   a3 = -0.00018; a4 = +0.00326;
		b1 = +0.9807;   b2 = 0.8672;   b3 = +1.0795;  b4 = +1.0385;
	} else {
		a1 = +2.41E-9;  a2 = +0.06745; a3 = +0.05471; a4 = +0.5686;
		b1 = +1.144;    b2 = +0.995;   b3 = +0.5686;  b4 = +0.946;
	}
	return (a1 * mc_exp(x * b1) + a2 * mc_exp(x * b2) + a3 * mc_exp(x * b3) + a4 * mc_exp(x * b4));
}

MC_TARGET_PROC long double mc_besseli0l_approx1(long double x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	long double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	long double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5L) {
		a1 = +0.1682L;   a2 = +0.1472L;  a3 = +0.4450L;  a4 = +0.2382L;
		b1 = +0.7536L;   b2 = +0.9739L;  b3 = -0.715L;   b4 = +0.2343L;
	} else if (x < 20.0L) {
		a1 = +0.2667L;   a2 = +0.4916L;  a3 = +0.1110L;  a4 = +0.1304L;
		b1 = +0.4710L;   b2 = -163.4L;   b3 = +0.9852L;  b4 = +0.8554L;
	} else if (x < 37.25L) {
		a1 = +0.1121L;   a2 = 0.1055L;   a3 = -0.00018L; a4 = +0.00326L;
		b1 = +0.9807L;   b2 = 0.8672L;   b3 = +1.0795L;  b4 = +1.0385L;
	} else {
		a1 = +2.41E-9L;  a2 = +0.06745L; a3 = +0.05471L; a4 = +0.5686L;
		b1 = +1.144L;    b2 = +0.995L;   b3 = +0.5686L;  b4 = +0.946L;
	}
	return (a1 * mc_expl(x * b1) + a2 * mc_expl(x * b2) + a3 * mc_expl(x * b3) + a4 * mc_expl(x * b4));
}

#pragma mark - mc_besseli1_approx1 -

MC_TARGET_PROC float mc_besseli1f_approx1(float x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	float a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	float b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5f) {
		a1 = +0.1682f;   a2 = +0.1472f;  a3 = +0.4450f;  a4 = +0.2382f;
		b1 = +0.7536f;   b2 = +0.9739f;  b3 = -0.715f;   b4 = +0.2343f;
	} else if (x < 20.0f) {
		a1 = +0.2667f;   a2 = +0.4916f;  a3 = +0.1110f;  a4 = +0.1304f;
		b1 = +0.4710f;   b2 = -163.4f;   b3 = +0.9852f;  b4 = +0.8554f;
	} else if (x < 37.25f) {
		a1 = +0.1121f;   a2 = 0.1055f;   a3 = -0.00018f; a4 = +0.00326f;
		b1 = +0.9807f;   b2 = 0.8672f;   b3 = +1.0795f;  b4 = +1.0385f;
	} else {
		a1 = +2.41E-9f;  a2 = +0.06745f; a3 = +0.05471f; a4 = +0.5686f;
		b1 = +1.144f;    b2 = +0.995f;   b3 = +0.5686f;  b4 = +0.946f;
	}
	return (a1 * b1 * mc_expf(x * b1) + a2 * b2 * mc_expf(x * b2) + a3 * b3 + mc_expf(x * b3) + a4 * b4 * mc_expf(x * b4));
}

MC_TARGET_PROC double mc_besseli1_approx1(double x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5) {
		a1 = +0.1682;   a2 = +0.1472;  a3 = +0.4450;  a4 = +0.2382;
		b1 = +0.7536;   b2 = +0.9739;  b3 = -0.715;   b4 = +0.2343;
	} else if (x < 20.0) {
		a1 = +0.2667;   a2 = +0.4916;  a3 = +0.1110;  a4 = +0.1304;
		b1 = +0.4710;   b2 = -163.4;   b3 = +0.9852;  b4 = +0.8554;
	} else if (x < 37.25) {
		a1 = +0.1121;   a2 = 0.1055;   a3 = -0.00018; a4 = +0.00326;
		b1 = +0.9807;   b2 = 0.8672;   b3 = +1.0795;  b4 = +1.0385;
	} else {
		a1 = +2.41E-9;  a2 = +0.06745; a3 = +0.05471; a4 = +0.5686;
		b1 = +1.144;    b2 = +0.995;   b3 = +0.5686;  b4 = +0.946;
	}
	return (a1 * b1 * mc_exp(x * b1) + a2 * b2 * mc_exp(x * b2) + a3 * b3 + mc_exp(x * b3) + a4 * b4 * mc_exp(x * b4));
}

MC_TARGET_PROC long double mc_besseli1l_approx1(long double x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	long double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	long double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5L) {
		a1 = +0.1682L;   a2 = +0.1472L;  a3 = +0.4450L;  a4 = +0.2382L;
		b1 = +0.7536L;   b2 = +0.9739L;  b3 = -0.715L;   b4 = +0.2343L;
	} else if (x < 20.0L) {
		a1 = +0.2667L;   a2 = +0.4916L;  a3 = +0.1110L;  a4 = +0.1304L;
		b1 = +0.4710L;   b2 = -163.4L;   b3 = +0.9852L;  b4 = +0.8554L;
	} else if (x < 37.25L) {
		a1 = +0.1121L;   a2 = 0.1055L;   a3 = -0.00018L; a4 = +0.00326L;
		b1 = +0.9807L;   b2 = 0.8672L;   b3 = +1.0795L;  b4 = +1.0385L;
	} else {
		a1 = +2.41E-9L;  a2 = +0.06745L; a3 = +0.05471L; a4 = +0.5686L;
		b1 = +1.144L;    b2 = +0.995L;   b3 = +0.5686L;  b4 = +0.946L;
	}
	return (a1 * b1 * mc_expl(x * b1) + a2 * b2 * mc_expl(x * b2) + a3 * b3 + mc_expl(x * b3) + a4 * b4 * mc_expl(x * b4));
}

#pragma mark - mc_besselin_approx1 -

MC_TARGET_PROC double mc_besselinf_approx1(int n, float x)
{
	float i0 = mc_besseli0f_approx1(x);
	float i1 = mc_besseli1f_approx1(x);
	float in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0f / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

MC_TARGET_PROC double mc_besselin_approx1(int n, double x)
{
	double i0 = mc_besseli0_approx1(x);
	double i1 = mc_besseli1_approx1(x);
	double in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0 / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

MC_TARGET_PROC long double mc_besselinl_approx1(int n, long double x)
{
	long double i0 = mc_besseli0l_approx1(x);
	long double i1 = mc_besseli1l_approx1(x);
	long double in = 0;
	int i     = 1;
	if (n == 0) {
		return i0;
	}
	if (n == 1) {
		return i1;
	}
	for(; i < n; i++){
		in = i0 - (2.0L / x) * i * i1;
		i0 = i1;
		i1 = in;
	}
	return in;
}

#pragma mark - mc_besseli0 -

MC_TARGET_FUNC float mc_besseli0f(float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli0f_approx1(x);
#	else
	return mc_besseli0f_approx0(x);
#	endif
}

MC_TARGET_FUNC double mc_besseli0(double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli0_approx1(x);
#	else
	return mc_besseli0_approx0(x);
#	endif
}

MC_TARGET_FUNC long double mc_besseli0l(long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli0l_approx1(x);
#	else
	return mc_besseli0l_approx0(x);
#	endif
}

#pragma mark - mc_besseli1 -

MC_TARGET_FUNC float mc_besseli1f(float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1f_approx1(x);
#	else
	return mc_besseli1f_approx0(x);
#	endif
}

MC_TARGET_FUNC double mc_besseli1(double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1_approx1(x);
#	else
	return mc_besseli1_approx0(x);
#	endif
}

MC_TARGET_FUNC long double mc_besseli1l(long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1l_approx1(x);
#	else
	return mc_besseli1l_approx0(x);
#	endif
}

#pragma mark - mc_besselin -

MC_TARGET_FUNC double mc_besselinf(int n, float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselinf_approx1(n, x);
#	else
	return mc_besselinf_approx0(n, x);
#	endif
}

MC_TARGET_FUNC double mc_besselin(int n, double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselin_approx1(n, x);
#	else
	return mc_besselin_approx0(n, x);
#	endif
}

MC_TARGET_FUNC long double mc_besselinl(int n, long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselinl_approx1(n, x);
#	else
	return mc_besselinl_approx0(n, x);
#	endif
}

#endif /* !MC_BESSELI_H */

/* EOF */
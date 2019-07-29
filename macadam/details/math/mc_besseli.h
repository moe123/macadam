//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_besseli.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_rsqrt.h>
#include <macadam/details/math/mc_sqr.h>
#include <macadam/details/math/mc_xchebevaln.h>

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

MC_TARGET_PROC float mc_besselinf_approx0(int n, float x)
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
		a1 = +1.68200001120567321777343750000000000000E-01f;
		a2 = +1.47200003266334533691406250000000000000E-01f;
		a3 = +4.44999992847442626953125000000000000000E-01f;
		a4 = +2.38199993968009948730468750000000000000E-01f;
		b1 = +7.53600001335144042968750000000000000000E-01f;
		b2 = +9.73900020122528076171875000000000000000E-01f;
		b3 = -7.14999973773956298828125000000000000000E-01f;
		b4 = +2.34300002455711364746093750000000000000E-01f;
	} else if (x < 20.0f) {
		a1 = +2.66699999570846557617187500000000000000E-01f;
		a2 = +4.91600006818771362304687500000000000000E-01f;
		a3 = +1.11000001430511474609375000000000000000E-01f;
		a4 = +1.30400002002716064453125000000000000000E-01f;
		b1 = +4.70999985933303833007812500000000000000E-01f;
		b2 = -1.63399993896484375000000000000000000000E+02f;
		b3 = +9.85199987888336181640625000000000000000E-01f;
		b4 = +8.55400025844573974609375000000000000000E-01f;
	} else if (x < 37.25f) {
		a1 = +1.12099997699260711669921875000000000000E-01f;
		a2 = +1.05499997735023498535156250000000000000E-01f;
		a3 = -1.80000002728775143623352050781250000000E-04f;
		a4 = +3.25999991036951541900634765625000000000E-03f;
		b1 = +9.80700016021728515625000000000000000000E-01f;
		b2 = +8.67200016975402832031250000000000000000E-01f;
		b3 = +1.07949995994567871093750000000000000000E+00f;
		b4 = +1.03849995136260986328125000000000000000E+00f;
	} else {
		a1 = +2.40999997735968918277649208903312683105E-09f;
		a2 = +6.74500018358230590820312500000000000000E-02f;
		a3 = +5.47100007534027099609375000000000000000E-02f;
		a4 = +5.68599998950958251953125000000000000000E-01f;
		b1 = +1.14400005340576171875000000000000000000E+00f;
		b2 = +9.95000004768371582031250000000000000000E-01f;
		b3 = +5.68599998950958251953125000000000000000E-01f;
		b4 = +9.45999979972839355468750000000000000000E-01f;
	}
	return (a1 * b1 * mc_expf(x * b1) + a2 * b2 * mc_expf(x * b2) + a3 * b3 + mc_expf(x * b3) + a4 * b4 * mc_expf(x * b4));
}

MC_TARGET_PROC double mc_besseli1_approx1(double x)
{
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5) {
		a1 = +1.6820000112056732177734375000000000000000E-01;
		a2 = +1.4720000326633453369140625000000000000000E-01;
		a3 = +4.4499999284744262695312500000000000000000E-01;
		a4 = +2.3819999396800994873046875000000000000000E-01;
		b1 = +7.5360000133514404296875000000000000000000E-01;
		b2 = +9.7390002012252807617187500000000000000000E-01;
		b3 = -7.1499997377395629882812500000000000000000E-01;
		b4 = +2.3430000245571136474609375000000000000000E-01;
	} else if (x < 20.0) {
		a1 = +2.6669999957084655761718750000000000000000E-01;
		a2 = +4.9160000681877136230468750000000000000000E-01;
		a3 = +1.1100000143051147460937500000000000000000E-01;
		a4 = +1.3040000200271606445312500000000000000000E-01;
		b1 = +4.7099998593330383300781250000000000000000E-01;
		b2 = -1.6339999389648437500000000000000000000000E+02;
		b3 = +9.8519998788833618164062500000000000000000E-01;
		b4 = +8.5540002584457397460937500000000000000000E-01;
	} else if (x < 37.25) {
		a1 = +1.1209999769926071166992187500000000000000E-01;
		a2 = +1.0549999773502349853515625000000000000000E-01;
		a3 = -1.8000000272877514362335205078125000000000E-04;
		a4 = +3.2599999103695154190063476562500000000000E-03;
		b1 = +9.8070001602172851562500000000000000000000E-01;
		b2 = +8.6720001697540283203125000000000000000000E-01;
		b3 = +1.0794999599456787109375000000000000000000E+00;
		b4 = +1.0384999513626098632812500000000000000000E+00;
	} else {
		a1 = +2.4099999773596891827764920890331268310547E-09;
		a2 = +6.7450001835823059082031250000000000000000E-02;
		a3 = +5.4710000753402709960937500000000000000000E-02;
		a4 = +5.6859999895095825195312500000000000000000E-01;
		b1 = +1.1440000534057617187500000000000000000000E+00;
		b2 = +9.9500000476837158203125000000000000000000E-01;
		b3 = +5.6859999895095825195312500000000000000000E-01;
		b4 = +9.4599997997283935546875000000000000000000E-01;
	}
	return (a1 * b1 * mc_exp(x * b1) + a2 * b2 * mc_exp(x * b2) + a3 * b3 + mc_exp(x * b3) + a4 * b4 * mc_exp(x * b4));
}

MC_TARGET_PROC long double mc_besseli1l_approx1(long double x)
{
#	if !MC_TARGET_MSVC_CPP
//!# DOI: 10.1109/IEEEGCC.2013.6705802
	long double a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	long double b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	if (x < 11.5L) {
		a1 = +1.682000011205673217773437500000000000000000000000000000000000000E-01L;
		a2 = +1.472000032663345336914062500000000000000000000000000000000000000E-01L;
		a3 = +4.449999928474426269531250000000000000000000000000000000000000000E-01L;
		a4 = +2.381999939680099487304687500000000000000000000000000000000000000E-01L;
		b1 = +7.536000013351440429687500000000000000000000000000000000000000000E-01L;
		b2 = +9.739000201225280761718750000000000000000000000000000000000000000E-01L;
		b3 = -7.149999737739562988281250000000000000000000000000000000000000000E-01L;
		b4 = +2.343000024557113647460937500000000000000000000000000000000000000E-01L;
	} else if (x < 20.0L) {
		a1 = +2.666999995708465576171875000000000000000000000000000000000000000E-01L;
		a2 = +4.916000068187713623046875000000000000000000000000000000000000000E-01L;
		a3 = +1.110000014305114746093750000000000000000000000000000000000000000E-01L;
		a4 = +1.304000020027160644531250000000000000000000000000000000000000000E-01L;
		b1 = +4.709999859333038330078125000000000000000000000000000000000000000E-01L;
		b2 = -1.633999938964843750000000000000000000000000000000000000000000000E+02L;
		b3 = +9.851999878883361816406250000000000000000000000000000000000000000E-01L;
		b4 = +8.554000258445739746093750000000000000000000000000000000000000000E-01L;
	} else if (x < 37.25L) {
		a1 = +1.120999976992607116699218750000000000000000000000000000000000000E-01L;
		a2 = +1.054999977350234985351562500000000000000000000000000000000000000E-01L;
		a3 = -1.800000027287751436233520507812500000000000000000000000000000000E-04L;
		a4 = +3.259999910369515419006347656250000000000000000000000000000000000E-03L;
		b1 = +9.807000160217285156250000000000000000000000000000000000000000000E-01L;
		b2 = +8.672000169754028320312500000000000000000000000000000000000000000E-01L;
		b3 = +1.079499959945678710937500000000000000000000000000000000000000000E+00L;
		b4 = +1.038499951362609863281250000000000000000000000000000000000000000E+00L;
	} else {
		a1 = +2.409999977359689182776492089033126831054687500000000000000000000E-09L;
		a2 = +6.745000183582305908203125000000000000000000000000000000000000000E-02L;
		a3 = +5.471000075340270996093750000000000000000000000000000000000000000E-02L;
		a4 = +5.685999989509582519531250000000000000000000000000000000000000000E-01L;
		b1 = +1.144000053405761718750000000000000000000000000000000000000000000E+00L;
		b2 = +9.950000047683715820312500000000000000000000000000000000000000000E-01L;
		b3 = +5.685999989509582519531250000000000000000000000000000000000000000E-01L;
		b4 = +9.459999799728393554687500000000000000000000000000000000000000000E-01L;
	}
	return (a1 * b1 * mc_expl(x * b1) + a2 * b2 * mc_expl(x * b2) + a3 * b3 + mc_expl(x * b3) + a4 * b4 * mc_expl(x * b4));
#	else
	return mc_cast(long double, mc_besseli1_approx1(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besselin_approx1 -

MC_TARGET_PROC float mc_besselinf_approx1(int n, float x)
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

#pragma mark - mc_besseli0_approx2 -

MC_TARGET_PROC float mc_besseli0f_approx2(float x)
{
	const float A[] =
	{
		  -1.3000250099862480421200000000000000000E-8f
		, +6.0469950225419189493200000000000000000E-8f
		, -2.6707938539406117339100000000000000000E-7f
		, +1.1173875391201037181500000000000000000E-6f
		, -4.4167383584587505635900000000000000000E-6f
		, +1.6448448070728897089300000000000000000E-5f
		, -5.7541950100821037039800000000000000000E-5f
		, +1.8850288509584165572900000000000000000E-4f
		, -5.7637557453858236588500000000000000000E-4f
		, +1.6394756169413357984200000000000000000E-3f
		, -4.3243099950505759443000000000000000000E-3f
		, +1.0546460394594998318300000000000000000E-2f
		, -2.3737414805899468815600000000000000000E-2f
		, +4.9305284239670708487800000000000000000E-2f
		, -9.4901097048047644421000000000000000000E-2f
		, +1.7162090152220877534900000000000000000E-1f
		, -3.0468267234319839868300000000000000000E-1f
		, +6.7679527440947608499500000000000000000E-1f
	};

	static float B[] =
	{
		  +3.3962320257083863451500000000000000000E-9f
		, +2.2666689904981780645900000000000000000E-8f
		, +2.0489185894690637418300000000000000000E-7f
		, +2.8913705208347564829700000000000000000E-6f
		, +6.8897583469168239842600000000000000000E-5f
		, +3.3691164782556940899000000000000000000E-3f
		, +8.0449041101410883160800000000000000000E-1f
	};

	float y = mc_fabsf(x), r = ((y <= 8.0f)
		? (mc_expf(y) * mc_xchebevalnf((0.5f * y) - 2.0f, A, 18))
		: (mc_expf(y) * mc_xchebevalnf(32.0f / y - 2.0f, B, 7)) * mc_rsqrtf(y)
	);
	return r;
}

MC_TARGET_PROC double mc_besseli0_approx2(double x)
{
	const double A[] =
	{
		  -4.41534164647933937950000000000000000000000E-18
		, +3.33079451882223809783000000000000000000000E-17
		, -2.43127984654795469359000000000000000000000E-16
		, +1.71539128555513303061000000000000000000000E-15
		, -1.16853328779934516808000000000000000000000E-14
		, +7.67618549860493561688000000000000000000000E-14
		, -4.85644678311192946090000000000000000000000E-13
		, +2.95505266312963983461000000000000000000000E-12
		, -1.72682629144155570723000000000000000000000E-11
		, +9.67580903537323691224000000000000000000000E-11
		, -5.18979560163526290666000000000000000000000E-10
		, +2.65982372468238665035000000000000000000000E-9
		, -1.30002500998624804212000000000000000000000E-8
		, +6.04699502254191894932000000000000000000000E-8
		, -2.67079385394061173391000000000000000000000E-7
		, +1.11738753912010371815000000000000000000000E-6
		, -4.41673835845875056359000000000000000000000E-6
		, +1.64484480707288970893000000000000000000000E-5
		, -5.75419501008210370398000000000000000000000E-5
		, +1.88502885095841655729000000000000000000000E-4
		, -5.76375574538582365885000000000000000000000E-4
		, +1.63947561694133579842000000000000000000000E-3
		, -4.32430999505057594430000000000000000000000E-3
		, +1.05464603945949983183000000000000000000000E-2
		, -2.37374148058994688156000000000000000000000E-2
		, +4.93052842396707084878000000000000000000000E-2
		, -9.49010970480476444210000000000000000000000E-2
		, +1.71620901522208775349000000000000000000000E-1
		, -3.04682672343198398683000000000000000000000E-1
		, +6.76795274409476084995000000000000000000000E-1
	};

	static double B[] =
	{
		  -7.23318048787475395456000000000000000000000E-18
		, -4.83050448594418207126000000000000000000000E-18
		, +4.46562142029675999901000000000000000000000E-17
		, +3.46122286769746109310000000000000000000000E-17
		, -2.82762398051658348494000000000000000000000E-16
		, -3.42548561967721913462000000000000000000000E-16
		, +1.77256013305652638360000000000000000000000E-15
		, +3.81168066935262242075000000000000000000000E-15
		, -9.55484669882830764870000000000000000000000E-15
		, -4.15056934728722208663000000000000000000000E-14
		, +1.54008621752140982691000000000000000000000E-14
		, +3.85277838274214270114000000000000000000000E-13
		, +7.18012445138366623367000000000000000000000E-13
		, -1.79417853150680611778000000000000000000000E-12
		, -1.32158118404477131188000000000000000000000E-11
		, -3.14991652796324136454000000000000000000000E-11
		, +1.18891471078464383424000000000000000000000E-11
		, +4.94060238822496958910000000000000000000000E-10
		, +3.39623202570838634515000000000000000000000E-9
		, +2.26666899049817806459000000000000000000000E-8
		, +2.04891858946906374183000000000000000000000E-7
		, +2.89137052083475648297000000000000000000000E-6
		, +6.88975834691682398426000000000000000000000E-5
		, +3.36911647825569408990000000000000000000000E-3
		, +8.04490411014108831608000000000000000000000E-1
	};

	double y = mc_fabs(x), r = ((y <= 8.0)
		? (mc_exp(y) * mc_xchebevaln((0.5 * y) - 2.0, A, 30))
		: (mc_exp(y) * mc_xchebevaln(32.0 / y - 2.0, B, 25)) * mc_rsqrt(y)
	);
	return r;
}

MC_TARGET_PROC long double mc_besseli0l_approx2(long double x)
{
#	if !MC_TARGET_MSVC_CPP
	const long double A[] =
	{
		  -4.415341646479339379500000000000000000000000000000000000000000000E-18L
		, +3.330794518822238097830000000000000000000000000000000000000000000E-17L
		, -2.431279846547954693590000000000000000000000000000000000000000000E-16L
		, +1.715391285555133030610000000000000000000000000000000000000000000E-15L
		, -1.168533287799345168080000000000000000000000000000000000000000000E-14L
		, +7.676185498604935616880000000000000000000000000000000000000000000E-14L
		, -4.856446783111929460900000000000000000000000000000000000000000000E-13L
		, +2.955052663129639834610000000000000000000000000000000000000000000E-12L
		, -1.726826291441555707230000000000000000000000000000000000000000000E-11L
		, +9.675809035373236912240000000000000000000000000000000000000000000E-11L
		, -5.189795601635262906660000000000000000000000000000000000000000000E-10L
		, +2.659823724682386650350000000000000000000000000000000000000000000E-9L
		, -1.300025009986248042120000000000000000000000000000000000000000000E-8L
		, +6.046995022541918949320000000000000000000000000000000000000000000E-8L
		, -2.670793853940611733910000000000000000000000000000000000000000000E-7L
		, +1.117387539120103718150000000000000000000000000000000000000000000E-6L
		, -4.416738358458750563590000000000000000000000000000000000000000000E-6L
		, +1.644844807072889708930000000000000000000000000000000000000000000E-5L
		, -5.754195010082103703980000000000000000000000000000000000000000000E-5L
		, +1.885028850958416557290000000000000000000000000000000000000000000E-4L
		, -5.763755745385823658850000000000000000000000000000000000000000000E-4L
		, +1.639475616941335798420000000000000000000000000000000000000000000E-3L
		, -4.324309995050575944300000000000000000000000000000000000000000000E-3L
		, +1.054646039459499831830000000000000000000000000000000000000000000E-2L
		, -2.373741480589946881560000000000000000000000000000000000000000000E-2L
		, +4.930528423967070848780000000000000000000000000000000000000000000E-2L
		, -9.490109704804764442100000000000000000000000000000000000000000000E-2L
		, +1.716209015222087753490000000000000000000000000000000000000000000E-1L
		, -3.046826723431983986830000000000000000000000000000000000000000000E-1L
		, +6.767952744094760849950000000000000000000000000000000000000000000E-1L
	};

	static long double B[] =
	{
		  -7.233180487874753954560000000000000000000000000000000000000000000E-18L
		, -4.830504485944182071260000000000000000000000000000000000000000000E-18L
		, +4.465621420296759999010000000000000000000000000000000000000000000E-17L
		, +3.461222867697461093100000000000000000000000000000000000000000000E-17L
		, -2.827623980516583484940000000000000000000000000000000000000000000E-16L
		, -3.425485619677219134620000000000000000000000000000000000000000000E-16L
		, +1.772560133056526383600000000000000000000000000000000000000000000E-15L
		, +3.811680669352622420750000000000000000000000000000000000000000000E-15L
		, -9.554846698828307648700000000000000000000000000000000000000000000E-15L
		, -4.150569347287222086630000000000000000000000000000000000000000000E-14L
		, +1.540086217521409826910000000000000000000000000000000000000000000E-14L
		, +3.852778382742142701140000000000000000000000000000000000000000000E-13L
		, +7.180124451383666233670000000000000000000000000000000000000000000E-13L
		, -1.794178531506806117780000000000000000000000000000000000000000000E-12L
		, -1.321581184044771311880000000000000000000000000000000000000000000E-11L
		, -3.149916527963241364540000000000000000000000000000000000000000000E-11L
		, +1.188914710784643834240000000000000000000000000000000000000000000E-11L
		, +4.940602388224969589100000000000000000000000000000000000000000000E-10L
		, +3.396232025708386345150000000000000000000000000000000000000000000E-9L
		, +2.266668990498178064590000000000000000000000000000000000000000000E-8L
		, +2.048918589469063741830000000000000000000000000000000000000000000E-7L
		, +2.891370520834756482970000000000000000000000000000000000000000000E-6L
		, +6.889758346916823984260000000000000000000000000000000000000000000E-5L
		, +3.369116478255694089900000000000000000000000000000000000000000000E-3L
		, +8.044904110141088316080000000000000000000000000000000000000000000E-1L
	};

	long double y = mc_fabsl(x), r = ((y <= 8.0L)
		? (mc_expl(y) * mc_xchebevalnl((0.5L * y) - 2.0L, A, 30))
		: (mc_expl(y) * mc_xchebevalnl(32.0L / y - 2.0L, B, 25)) * mc_rsqrtl(y)
	);
	return r;
#	else
	return mc_cast(long double, mc_besseli0_approx2(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besseli1_approx2 -

MC_TARGET_PROC float mc_besseli1f_approx2(float x)
{
	const float A[] =
	{
		  +9.3815373864957717838800000000000000000E-9f
		, -4.4450591287963280806500000000000000000E-8f
		, +2.0032947535521352622900000000000000000E-7f
		, -8.5687202646954547406600000000000000000E-7f
		, +3.4702513081376784767400000000000000000E-6f
		, -1.3273163656039435827900000000000000000E-5f
		, +4.7815651075500542263800000000000000000E-5f
		, -1.6176081582589674558800000000000000000E-4f
		, +5.1228595616857577289500000000000000000E-4f
		, -1.5135724506312531489900000000000000000E-3f
		, +4.1564229443128881566900000000000000000E-3f
		, -1.0564084894626198155800000000000000000E-2f
		, +2.4726449030626516828300000000000000000E-2f
		, -5.2945981208094991426900000000000000000E-2f
		, +1.0264365868984709538400000000000000000E-1f
		, -1.7641651835783405515300000000000000000E-1f
		, +2.5258718644363365482300000000000000000E-1f
	};

	static float B[] =
	{
		  -3.8353803859642370220500000000000000000E-9f
		, -2.6314688468895195068400000000000000000E-8f
		, -2.5122362378702089252900000000000000000E-7f
		, -3.8825648088776903934600000000000000000E-6f
		, -1.1058893876262371629100000000000000000E-4f
		, -9.7610974913614684077700000000000000000E-3f
		, +7.7857623501828012047400000000000000000E-1f
	};

	float y = mc_fabsf(x), r = ((y <= 8.0f)
		? (mc_xchebevalnf((0.5f * y) - 2.0f, A, 17) * y * mc_expf(y))
		: (mc_expf(y) * mc_xchebevalnf(32.0f / y - 2.0f, B, 7)) * mc_rsqrtf(y)
	);
	return x < 0.0f ? -r : r;
}

MC_TARGET_PROC double mc_besseli1_approx2(double x)
{
	const double A[] =
	{
		  +2.7779141127610463995900000000000000000000E-18
		, -2.1114212143581660811500000000000000000000E-17
		, +1.5536319577362004692100000000000000000000E-16
		, -1.1055969477353863080500000000000000000000E-15
		, +7.6006842947354069341000000000000000000000E-15
		, -5.0421855047279116871100000000000000000000E-14
		, +3.2237933659455747098100000000000000000000E-13
		, -1.9839743977649437152000000000000000000000E-12
		, +1.1736186298890901630800000000000000000000E-11
		, -6.6634897235020277422300000000000000000000E-11
		, +3.6255902815521170370100000000000000000000E-10
		, -1.8872497517228292879000000000000000000000E-9
		, +9.3815373864957717838800000000000000000000E-9
		, -4.4450591287963280806500000000000000000000E-8
		, +2.0032947535521352622900000000000000000000E-7
		, -8.5687202646954547406600000000000000000000E-7
		, +3.4702513081376784767400000000000000000000E-6
		, -1.3273163656039435827900000000000000000000E-5
		, +4.7815651075500542263800000000000000000000E-5
		, -1.6176081582589674558800000000000000000000E-4
		, +5.1228595616857577289500000000000000000000E-4
		, -1.5135724506312531489900000000000000000000E-3
		, +4.1564229443128881566900000000000000000000E-3
		, -1.0564084894626198155800000000000000000000E-2
		, +2.4726449030626516828300000000000000000000E-2
		, -5.2945981208094991426900000000000000000000E-2
		, +1.0264365868984709538400000000000000000000E-1
		, -1.7641651835783405515300000000000000000000E-1
		, +2.5258718644363365482300000000000000000000E-1
	};

	static double B[] =
	{
		  +7.5172963108421048135300000000000000000000E-18
		, +4.4143483230717079115100000000000000000000E-18
		, -4.6503053684893583215300000000000000000000E-17
		, -3.2095259219934239598000000000000000000000E-17
		, +2.9626289976459501387600000000000000000000E-16
		, +3.3082023109209282832400000000000000000000E-16
		, -1.8803547755107824485400000000000000000000E-15
		, -3.8144030724370078047800000000000000000000E-15
		, +1.0420276984128802764200000000000000000000E-14
		, +4.2724400167119513542900000000000000000000E-14
		, -2.1015418427726643130200000000000000000000E-14
		, -4.0835511110921973182300000000000000000000E-13
		, -7.1985517762459085120900000000000000000000E-13
		, +2.0356285441470895072200000000000000000000E-12
		, +1.4125807436613781331600000000000000000000E-11
		, +3.2526035830154882385600000000000000000000E-11
		, -1.8974958123505412345000000000000000000000E-11
		, -5.5897434621965838068700000000000000000000E-10
		, -3.8353803859642370220500000000000000000000E-9
		, -2.6314688468895195068400000000000000000000E-8
		, -2.5122362378702089252900000000000000000000E-7
		, -3.8825648088776903934600000000000000000000E-6
		, -1.1058893876262371629100000000000000000000E-4
		, -9.7610974913614684077700000000000000000000E-3
		, +7.7857623501828012047400000000000000000000E-1
	};

	double y = mc_fabs(x), r = ((y <= 8.0)
		? (mc_xchebevaln((0.5 * y) - 2.0, A, 29) * y * mc_exp(y))
		: (mc_exp(y) * mc_xchebevaln(32.0 / y - 2.0, B, 25)) * mc_rsqrt(y)
	);
	return x < 0.0 ? -r : r;
}

MC_TARGET_PROC long double mc_besseli1l_approx2(long double x)
{
#	if !MC_TARGET_MSVC_CPP
	const long double A[] =
	{
		  +2.777914112761046399590000000000000000000000000000000000000000000E-18L
		, -2.111421214358166081150000000000000000000000000000000000000000000E-17L
		, +1.553631957736200469210000000000000000000000000000000000000000000E-16L
		, -1.105596947735386308050000000000000000000000000000000000000000000E-15L
		, +7.600684294735406934100000000000000000000000000000000000000000000E-15L
		, -5.042185504727911687110000000000000000000000000000000000000000000E-14L
		, +3.223793365945574709810000000000000000000000000000000000000000000E-13L
		, -1.983974397764943715200000000000000000000000000000000000000000000E-12L
		, +1.173618629889090163080000000000000000000000000000000000000000000E-11L
		, -6.663489723502027742230000000000000000000000000000000000000000000E-11L
		, +3.625590281552117037010000000000000000000000000000000000000000000E-10L
		, -1.887249751722829287900000000000000000000000000000000000000000000E-9L
		, +9.381537386495771783880000000000000000000000000000000000000000000E-9L
		, -4.445059128796328080650000000000000000000000000000000000000000000E-8L
		, +2.003294753552135262290000000000000000000000000000000000000000000E-7L
		, -8.568720264695454740660000000000000000000000000000000000000000000E-7L
		, +3.470251308137678476740000000000000000000000000000000000000000000E-6L
		, -1.327316365603943582790000000000000000000000000000000000000000000E-5L
		, +4.781565107550054226380000000000000000000000000000000000000000000E-5L
		, -1.617608158258967455880000000000000000000000000000000000000000000E-4L
		, +5.122859561685757728950000000000000000000000000000000000000000000E-4L
		, -1.513572450631253148990000000000000000000000000000000000000000000E-3L
		, +4.156422944312888156690000000000000000000000000000000000000000000E-3L
		, -1.056408489462619815580000000000000000000000000000000000000000000E-2L
		, +2.472644903062651682830000000000000000000000000000000000000000000E-2L
		, -5.294598120809499142690000000000000000000000000000000000000000000E-2L
		, +1.026436586898470953840000000000000000000000000000000000000000000E-1L
		, -1.764165183578340551530000000000000000000000000000000000000000000E-1L
		, +2.525871864436336548230000000000000000000000000000000000000000000E-1L
	};

	static long double B[] =
	{
		  +7.517296310842104813530000000000000000000000000000000000000000000E-18L
		, +4.414348323071707911510000000000000000000000000000000000000000000E-18L
		, -4.650305368489358321530000000000000000000000000000000000000000000E-17L
		, -3.209525921993423959800000000000000000000000000000000000000000000E-17L
		, +2.962628997645950138760000000000000000000000000000000000000000000E-16L
		, +3.308202310920928283240000000000000000000000000000000000000000000E-16L
		, -1.880354775510782448540000000000000000000000000000000000000000000E-15L
		, -3.814403072437007804780000000000000000000000000000000000000000000E-15L
		, +1.042027698412880276420000000000000000000000000000000000000000000E-14L
		, +4.272440016711951354290000000000000000000000000000000000000000000E-14L
		, -2.101541842772664313020000000000000000000000000000000000000000000E-14L
		, -4.083551111092197318230000000000000000000000000000000000000000000E-13L
		, -7.198551776245908512090000000000000000000000000000000000000000000E-13L
		, +2.035628544147089507220000000000000000000000000000000000000000000E-12L
		, +1.412580743661378133160000000000000000000000000000000000000000000E-11L
		, +3.252603583015488238560000000000000000000000000000000000000000000E-11L
		, -1.897495812350541234500000000000000000000000000000000000000000000E-11L
		, -5.589743462196583806870000000000000000000000000000000000000000000E-10L
		, -3.835380385964237022050000000000000000000000000000000000000000000E-9L
		, -2.631468846889519506840000000000000000000000000000000000000000000E-8L
		, -2.512236237870208925290000000000000000000000000000000000000000000E-7L
		, -3.882564808877690393460000000000000000000000000000000000000000000E-6L
		, -1.105889387626237162910000000000000000000000000000000000000000000E-4L
		, -9.761097491361468407770000000000000000000000000000000000000000000E-3L
		, +7.785762350182801204740000000000000000000000000000000000000000000E-1L
	};

	long double y = mc_fabsl(x), r = ((y <= 8.0L)
		? (mc_xchebevalnl((0.5L * y) - 2.0L, A, 29) * y * mc_expl(y))
		: (mc_expl(y) * mc_xchebevalnl(32.0L / y - 2.0L, B, 25)) * mc_rsqrtl(y)
	);
	return x < 0.0L ? -r : r;
#	else
	return mc_cast(long double, mc_besseli1_approx2(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besselin_approx2 -

MC_TARGET_PROC float mc_besselinf_approx2(int n, float x)
{
	float i0 = mc_besseli0f_approx2(x);
	float i1 = mc_besseli1f_approx2(x);
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

MC_TARGET_PROC double mc_besselin_approx2(int n, double x)
{
	double i0 = mc_besseli0_approx2(x);
	double i1 = mc_besseli1_approx2(x);
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

MC_TARGET_PROC long double mc_besselinl_approx2(int n, long double x)
{
	long double i0 = mc_besseli0l_approx2(x);
	long double i1 = mc_besseli1l_approx2(x);
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
	return mc_besseli0f_approx2(x);
#	endif
}

MC_TARGET_FUNC double mc_besseli0(double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli0_approx1(x);
#	else
	return mc_besseli0_approx2(x);
#	endif
}

MC_TARGET_FUNC long double mc_besseli0l(long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli0l_approx1(x);
#	else
	return mc_besseli0l_approx2(x);
#	endif
}

#pragma mark - mc_besseli1 -

MC_TARGET_FUNC float mc_besseli1f(float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1f_approx1(x);
#	else
	return mc_besseli1f_approx2(x);
#	endif
}

MC_TARGET_FUNC double mc_besseli1(double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1_approx1(x);
#	else
	return mc_besseli1_approx2(x);
#	endif
}

MC_TARGET_FUNC long double mc_besseli1l(long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besseli1l_approx1(x);
#	else
	return mc_besseli1l_approx2(x);
#	endif
}

#pragma mark - mc_besselin -

MC_TARGET_FUNC float mc_besselinf(int n, float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselinf_approx1(n, x);
#	else
	return mc_besselinf_approx2(n, x);
#	endif
}

MC_TARGET_FUNC double mc_besselin(int n, double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselin_approx1(n, x);
#	else
	return mc_besselin_approx2(n, x);
#	endif
}

MC_TARGET_FUNC long double mc_besselinl(int n, long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_besselinl_approx1(n, x);
#	else
	return mc_besselinl_approx2(n, x);
#	endif
}

#endif /* !MC_BESSELI_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zetap.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_xpolyevaln.h>

#ifndef MC_ZETAP_H
#define MC_ZETAP_H

#pragma mark - mc_rzetap_approx0 -

static MC_TARGET_INLINE float mc_rzetapf_approx0(float x)
{
	float z = 0, k = 1;
	unsigned int i = 1;
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1.0f;
	} else if (x < 0 && ::fmodf(x, 2) == 0) {
		return 0.0F;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1.0F;
	} else if (x < 0 && fmodf(x, 2) == 0) {
		return 0.0f;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
	do {
#	if MC_TARGET_CPP98
		k = (1.0f / ::powf(mc_cast(float, i), x)); z += k; i++;
#	else
		k = (1.0f / powf(mc_cast(float, i), x)); z += k; i++;
#	endif
	} while (k > 1E-10f);
	return z;
}

static MC_TARGET_INLINE double mc_rzetap_approx0(double x)
{
	double z = 0, k = 1;
	unsigned int i = 1;
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1.0;
	} else if (x < 0 && ::fmod(x, 2) == 0) {
		return 0.0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1.0;
	} else if (x < 0 && fmod(x, 2) == 0) {
		return 0.0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
	do {
#	if MC_TARGET_CPP98
		k = (1.0 / ::pow(mc_cast(double, i), x)); z += k; i++;
#	else
		k = (1.0 / pow(mc_cast(double, i), x)); z += k; i++;
#	endif
	} while (k > 1E-10);
	return z;
}

static MC_TARGET_INLINE long double mc_rzetapl_approx0(long double x)
{
	long double z = 0, k = 1;
	unsigned int i = 1;
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1.0L;
	} else if (x < 0 && ::fmodl(x, 2) == 0) {
		return 0.0L;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1.0L;
	} else if (x < 0 && fmodl(x, 2) == 0) {
		return 0.0L;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
	do {
#	if MC_TARGET_CPP98
		k = (1.0L / ::powl(mc_cast(long double, i), x)); z += k; i++;
#	else
		k = (1.0L / powl(mc_cast(long double, i), x)); z += k; i++;
#	endif
	} while (k > 1E-10);
	return z;
}

#pragma mark - mc_rzetap_approx1 -

static MC_TARGET_INLINE float mc_rzetapf_approx1(float x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1;
	} else if (x < 0 && ::fmodf(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1;
	} else if (x < 0 && fmodf(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
#	if MC_TARGET_CPP98
		return 1.0f + (((x + 3.0f) / (x - 1.0f)) * (1.0f / ::powf(2.0f, x + 1.0f)));
#	else
		return 1.0f + (((x + 3.0f) / (x - 1.0f)) * (1.0f / powf(2.0f, x + 1.0f)));
#	endif
}

static MC_TARGET_INLINE double mc_rzetap_approx1(double x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1;
	} else if (x < 0 && ::fmod(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1;
	} else if (x < 0 && fmod(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
#	if MC_TARGET_CPP98
	return 1.0 + (((x + 3.0) / (x - 1.0)) * (1.0 / ::pow(2.0, x + 1.0)));
#	else
	return 1.0 + (((x + 3.0) / (x - 1.0)) * (1.0 / pow(2.0, x + 1.0)));
#	endif
}

static MC_TARGET_INLINE long double mc_rzetapl_approx1(long double x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	} else if (::isinf(x)) {
		return 1;
	} else if (x < 0 && ::fmodl(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	} else if (isinf(x)) {
		return 1;
	} else if (x < 0 && fmodl(x, 2) == 0) {
		return 0;
	} else if (x == -1) {
		return -MCK_1_12;
	} else if (x == 0) {
		return -MCK_1_2;
	} else if (x == 1) {
		return MCK_INF;
	} else if (x == 2) {
		return MCK_PI2_6;
	} else if (x == 4) {
		return MCK_PI4_90;
	}
#	endif
#	if MC_TARGET_CPP98
	return 1.0L + (((x + 3.0L) / (x - 1.0L)) * (1.0L / ::powl(2.0L, x + 1.0L)));
#	else
	return 1.0L + (((x + 3.0L) / (x - 1.0L)) * (1.0L / powl(2.0L, x + 1.0L)));
#	endif
}

#pragma mark - mc_zetapsc -

static MC_TARGET_INLINE float       mc_zetapscf(float s, float sc);
static MC_TARGET_INLINE double      mc_zetapsc(double s, double sc);
static MC_TARGET_INLINE long double mc_zetapscl(long double s, long double sc);

static MC_TARGET_INLINE float mc_zetapscf(float s, float sc)
{
	const double x = mc_cast(double, s);
	const double y = mc_cast(double, sc);
	return mc_cast(float, mc_zetapsc(x, y));
}

static MC_TARGET_INLINE double mc_zetapsc(double s, double sc)
{
	double r = 1.0, y;
	const double P1[] = {
		  +0.2433929443359374999690000000000000000000E+00
		, -0.4968378068648656880820000000000000000000E+00
		, +0.0680008039723709987107000000000000000000E+00
		, -0.0051162041300661994211200000000000000000E+00
		, +0.0004553698992500530033350000000000000000E+00
		, -0.2794966852730337619270000000000000000000E-4
	};

	const double Q1[] = {
		  +1.0
		, -0.3042548006822579052200000000000000000000E+00
		, +0.0500527485803715987360000000000000000000E+00
		, -0.0051935567106470062786200000000000000000E+00
		, +0.0003606233857711983502570000000000000000E+00
		, -0.1596008830545509876330000000000000000000E-4
		, +0.3397702798124105860320000000000000000000E-6
	};

	const double P2[] = {
		  +0.5772156649015328606050000000000000000000E+00
		, +0.2225373689171621394450000000000000000000E+00
		, +0.0356286324033215682729000000000000000000E+00
		, +0.0030446529236635008144600000000000000000E+00
		, +0.0001781025116490694219040000000000000000E+00
		, +0.7008674702659836650420000000000000000000E-5
	};

	const double Q2[] = {
		  +1.0000000000000000000000000000000000000000E+00
		, +0.2593857591495310300850000000000000000000E+00
		, +0.0373974962106091316854000000000000000000E+00
		, +0.0033273515918333282061700000000000000000E+00
		, +0.0001886904207069986064690000000000000000E+00
		, +0.6359943779218619300710000000000000000000E-5
		, +0.2265839549783711994050000000000000000000E-7
	};

	const double P4[] = {
		  -0.0537258300023595010270000000000000000000E+00
		, +0.0470551187571475844778000000000000000000E+00
		, +0.0101339410415759517471000000000000000000E+00
		, +0.0010024032666609285452800000000000000000E+00
		, +0.6850271190981228148670000000000000000000E-4
		, +0.3909728202197659421170000000000000000000E-5
		, +0.5403197691135439344830000000000000000000E-7
	};

	const double Q4[] = {
		  +1.0
		, +0.2865777397265427304210000000000000000000E+00
		, +0.0447355811517733225843000000000000000000E+00
		, +0.0043012510761025236330200000000000000000E+00
		, +0.0002849569690897866620450000000000000000E+00
		, +0.1161881016098484113290000000000000000000E-4
		, +0.2780903181916572782040000000000000000000E-6
		, -0.1968362023322202847800000000000000000000E-8
	};

	const double P7[] = {
		  -2.4971019060225940706500000000000000000000E+00
		, -3.3666491324596062533400000000000000000000E+00
		, -1.7718002062377759545200000000000000000000E+00
		, -0.4647178852496543139330000000000000000000E+00
		, -0.0643694921293579472583000000000000000000E+00
		, -0.0046426538620280571548700000000000000000E+00
		, -0.0001655565797797043401660000000000000000E+00
		, -0.2528849707409940695820000000000000000000E-5
	};

	const double Q7[] = {
		  +1.0
		, +1.0130013139069045908500000000000000000000E+00
		, +0.3878981157586435038270000000000000000000E+00
		, +0.0695071490045701135188000000000000000000E+00
		, +0.0058690859525144283929100000000000000000E+00
		, +0.0002177529740646121886160000000000000000E+00
		, +0.3976265833494190117310000000000000000000E-5
		, -0.9278847392843597007640000000000000000000E-8
		, +0.1198105018056188943810000000000000000000E-9
	};

	const double P15[] = {
		  -4.7855802849513554808300000000000000000000E+00
		, -3.2387332223860935894700000000000000000000E+00
		, -0.8923385828810217999220000000000000000000E+00
		, -0.1313262962179659138090000000000000000000E+00
		, -0.0115651591773783712996000000000000000000E+00
		, -0.0006577289683626957752050000000000000000E+00
		, -0.2520513281294499730470000000000000000000E-4
		, -0.6265034453726417989250000000000000000000E-6
		, -0.8156963147908538934840000000000000000000E-8
	};

	const double Q15[] = {
		  +1.0
		, +0.5257656654001235150360000000000000000000E+00
		, +0.1085264175365712278700000000000000000000E+00
		, +0.0115669945375362045249000000000000000000E+00
		, +0.0007328965138582740919660000000000000000E+00
		, +0.3068395228242024844800000000000000000000E-4
		, +0.8196492146096331261190000000000000000000E-6
		, +0.1179575564723359681460000000000000000000E-7
		, -0.1934323009730176711370000000000000000000E-12
	};

	const double P42[] = {
		  -10.394895057330886178100000000000000000000E+00
		, -2.8264601277791395010800000000000000000000E+00
		, -0.3421443627395703336650000000000000000000E+00
		, -0.0249285145498722647472000000000000000000E+00
		, -0.0012249310884809711411800000000000000000E+00
		, -0.4230553711925928501960000000000000000000E-4
		, -0.1025215577185967488000000000000000000000E-5
		, -0.1650967626635094670610000000000000000000E-7
		, -0.1453925558730220443290000000000000000000E-9
	};

	const double Q42[] = {
		  +1.0000000000000000000000000000000000000000E+00
		, +0.2051359785852819880520000000000000000000E+00
		, +0.0192359357875879453602000000000000000000E+00
		, +0.0011149645202971551411900000000000000000E+00
		, +0.4349284490166939868570000000000000000000E-4
		, +0.1169110687266107258910000000000000000000E-5
		, +0.2067043422902352374750000000000000000000E-7
		, +0.2097728361008276474740000000000000000000E-9
		, -0.9397982499222347033840000000000000000000E-16
		, +0.2645840174212450802940000000000000000000E-18
	};

#	if MC_TARGET_CPP98
	if (::isnan(s) || ::isnan(sc)) {
		return MCK_NAN;
	} else if (::isinf(s) || ::isinf(sc)) {
		return MCK_INF;
	}
	if (s < 1.0) {
		const double c0 = 1.2433929443359375000000000000000000000000E+00;
		y               = mc_xpolyevaln(sc, P1, 6) / mc_xpolyevaln(sc, Q1, 7) - c0;
		r               = (y + sc) / sc;
	} else if (s <= 2.0) {
		s = -sc;
		y = mc_xpolyevaln(s, P2, 6) / mc_xpolyevaln(s, Q2, 7);
		r = y - 1.0 / sc;
	} else if (s <= 4.0) {
		const double c1 = 6.9865989685058593750000000000000000000000E-01;
		s               = s - 2.0;
		y               = mc_xpolyevaln(s, P4, 7) / mc_xpolyevaln(s, Q4, 8) + c1;
		r               = y - 1.0 / sc;
	} else if (s <= 7.0) {
		s = s - 4.0;
		y = mc_xpolyevaln(s, P7, 8) / mc_xpolyevaln(s, Q7, 9);
		r = 1.0 + ::exp(y);
	} else if (s < 15.0) {
		s = s - 7.0;
		y = mc_xpolyevaln(s, P15, 9) / mc_xpolyevaln(s, Q15, 9);
		r = 1.0 + ::exp(y);
	} else if (s < 42.0) {
		s = s - 15.0;
		y = mc_xpolyevaln(s, P42, 9) / mc_xpolyevaln(s, Q42, 10);
		r = 1.0 + ::exp(y);
	} else if (s < 63.0) {
		r = 1.0 + ::exp2(-s);
	}
#	else
	if (isnan(s) || isnan(sc)) {
		return MCK_NAN;
	} else if (isinf(s) || isinf(sc)) {
		return MCK_INF;
	}
	if (s < 1.0) {
		const double c0 = 1.2433929443359375000000000000000000000000E+00;
		y               = mc_xpolyevaln(sc, P1, 6) / mc_xpolyevaln(sc, Q1, 7) - c0;
		r               = (y + sc) / sc;
	} else if (s <= 2.0) {
		s = -sc;
		y = mc_xpolyevaln(s, P2, 6) / mc_xpolyevaln(s, Q2, 7);
		r = y - 1.0 / sc;
	} else if (s <= 4.0) {
		const double c1 = 6.9865989685058593750000000000000000000000E-01;
		s               = s - 2.0;
		y               = mc_xpolyevaln(s, P4, 7) / mc_xpolyevaln(s, Q4, 8) + c1;
		r               = y - 1.0 / sc;
	} else if (s <= 7.0) {
		s = s - 4.0;
		y = mc_xpolyevaln(s, P7, 8) / mc_xpolyevaln(s, Q7, 9);
		r = 1.0 + exp(y);
	} else if (s < 15.0) {
		s = s - 7.0;
		y = mc_xpolyevaln(s, P15, 9) / mc_xpolyevaln(s, Q15, 9);
		r = 1.0 + exp(y);
	} else if (s < 42.0) {
		s = s - 15.0;
		y = mc_xpolyevaln(s, P42, 9) / mc_xpolyevaln(s, Q42, 10);
		r = 1.0 + exp(y);
	} else if (s < 63.0) {
		r = 1.0 + exp2(-s);
	}
#	endif
	return r;
}

static MC_TARGET_INLINE long double mc_zetapscl(long double s, long double sc)
{
#	if MC_TARGET_MSVC_CPP
	const double x = mc_cast(double, s);
	const double y = mc_cast(double, sc);
	return mc_cast(long double, mc_zetapsc(x, y));
#	else
	const double x = mc_cast(double, s);
	const double y = mc_cast(double, sc);
	return mc_cast(long double, mc_zetapsc(x, y));
#	endif
}

#pragma mark - mc_izetap -

static MC_TARGET_INLINE float mc_izetapf(unsigned int s)
{
	const float Z[] = {
		  -5.00000000000000000000000000000000000000E-01f
		,  MCK_INF
		, +1.64493405818939208984375000000000000000E+00f
		, +1.20205688476562500000000000000000000000E+00f
		, +1.08232319355010986328125000000000000000E+00f
		, +1.03692770004272460937500000000000000000E+00f
		, +1.01734304428100585937500000000000000000E+00f
		, +1.00834929943084716796875000000000000000E+00f
		, +1.00407731533050537109375000000000000000E+00f
		, +1.00200843811035156250000000000000000000E+00f
		, +1.00099456310272216796875000000000000000E+00f
		, +1.00049424171447753906250000000000000000E+00f
		, +1.00024604797363281250000000000000000000E+00f
		, +1.00012266635894775390625000000000000000E+00f
		, +1.00006127357482910156250000000000000000E+00f
		, +1.00003063678741455078125000000000000000E+00f
		, +1.00001525878906250000000000000000000000E+00f
		, +1.00000762939453125000000000000000000000E+00f
		, +1.00000381469726562500000000000000000000E+00f
		, +1.00000190734863281250000000000000000000E+00f
		, +1.00000095367431640625000000000000000000E+00f
		, +1.00000047683715820312500000000000000000E+00f
		, +1.00000023841857910156250000000000000000E+00f
		, +1.00000011920928955078125000000000000000E+00f
		, +1.00000005960818905125947000000000000000E+00f
		, +1.00000002980350351465228000000000000000E+00f
		, +1.00000001490155482836504100000000000000E+00f
		, +1.00000000745071178983543000000000000000E+00f
	};
	if (s < 28) {
		return Z[s];
	}
	return 1.0;
}

static MC_TARGET_INLINE double mc_izetap(unsigned int s)
{
	const double Z[] = {
		  -5.0000000000000000000000000000000000000000E-01
		,  MCK_INF
		, +1.6449340668482264060656916626612655818462E+00
		, +1.2020569031595942366408280577161349356174E+00
		, +1.0823232337111381440308832679875195026398E+00
		, +1.0369277551433699890992556902347132563591E+00
		, +1.0173430619844492373005095942062325775623E+00
		, +1.0083492773819229260112706469953991472721E+00
		, +1.0040773561979443595504335462464950978756E+00
		, +1.0020083928260821171107863847282715141773E+00
		, +1.0009945751278179759680142524302937090397E+00
		, +1.0004941886041194276657506634364835917950E+00
		, +1.0002460865533080447420388736645691096783E+00
		, +1.0001227133475785180394268536474555730820E+00
		, +1.0000612481350588112150035158265382051468E+00
		, +1.0000305882363069720497605885611847043037E+00
		, +1.0000152822594086110541411471785977482796E+00
		, +1.0000076371976378553085851308424025774002E+00
		, +1.0000038172932650404334253835259005427361E+00
		, +1.0000019082127165059858953100047074258327E+00
		, +1.0000009539620338117060782678890973329544E+00
		, +1.0000004769329868814509154617553576827049E+00
		, +1.0000002384505026764571766761946491897106E+00
		, +1.0000001192199259314463688497198745608330E+00
		, +1.0000000596081890513744383497396484017372E+00
		, +1.0000000298035034429489087415277026593685E+00
		, +1.0000000149015548789321883305092342197895E+00
		, +1.0000000074507118252853388185030780732632E+00
		, +1.0000000037253340412490842936676926910877E+00
		, +1.0000000018626598041748820833163335919380E+00
		, +1.0000000009313274595967868663137778639793E+00
		, +1.0000000004656628416199737330316565930843E+00
		, +1.0000000002328310877430794789688661694527E+00
		, +1.0000000001164155438715397394844330847263E+00
		, +1.0000000000582076609134674072265625000000E+00
		, +1.0000000000291038304567337036132812500000E+00
		, +1.0000000000145519152283668518066406250000E+00
		, +1.0000000000072759576141834259033203125000E+00
		, +1.0000000000036379788070917129516601562500E+00
		, +1.0000000000018189894035458564758300781250E+00
		, +1.0000000000009094947017729282379150390625E+00
		, +1.0000000000004547473508864641189575195312E+00
		, +1.0000000000002273736754432320594787597656E+00
		, +1.0000000000001136868377216160297393798828E+00
		, +1.0000000000000568434188608080148696899414E+00
		, +1.0000000000000284217094304040074348449707E+00
		, +1.0000000000000142108547152020037174224854E+00
		, +1.0000000000000071054273576010018587112427E+00
		, +1.0000000000000035527136788005009293556213E+00
		, +1.0000000000000017763568394002504646778107E+00
		, +1.0000000000000008881784197001252323389053E+00
		, +1.0000000000000004440892098500626161694527E+00
		, +1.0000000000000002220446049250313080847263E+00
		, +1.0000000000000001110000000000000000000000E+00
		, +1.0000000000000000555000000000000000000000E+00
		, +1.0000000000000000278000000000000000000000E+00
		, +1.0000000000000000139000000000000000000000E+00
		, +1.0000000000000000069000000000000000000000E+00
		, +1.0000000000000000035000000000000000000000E+00
		, +1.0000000000000000017000000000000000000000E+00
		, +1.0000000000000000009000000000000000000000E+00
		, +1.0000000000000000004000000000000000000000E+00
		, +1.0000000000000000002000000000000000000000E+00
		, +1.0000000000000000001000000000000000000000E+00
	};
	if (s < 64) {
		return Z[s];
	}
	return 1.0;
}

static MC_TARGET_INLINE long double mc_izetapl(unsigned int s)
{
#	if MC_TARGET_MSVC_CPP
	const long double Z[] = {
		  -5.000000000000000000000000000000000000000000000000000000000000000E-01L
		,  MCK_INF
		, +1.644934066848226436640192926752490620856406167149543762207031250E+00L
		, +1.202056903159594285429925819563834465952822938561439514160156250E+00L
		, +1.082323233711138191735778857349714598967693746089935302734375000E+00L
		, +1.036927755143369926323949903324006527327583171427249908447265625E+00L
		, +1.017343061984449139939154505007934403693070635199546813964843750E+00L
		, +1.008349277381922826806771864571743435590178705751895904541015625E+00L
		, +1.004077356197944339709533789761763955539208836853504180908203125E+00L
		, +1.002008392826082214363721256678019244645838625729084014892578125E+00L
		, +1.000994575127818085689274107963342430593911558389663696289062500E+00L
		, +1.000494188604119464528624527943634348048362880945205688476562500E+00L
		, +1.000246086553308048753586911860935515505843795835971832275390625E+00L
		, +1.000122713347578489199649065533037628483725711703300476074218750E+00L
		, +1.000061248135058705180031046744204559217905625700950622558593750E+00L
		, +1.000030588236307020513597698663232904436881653964519500732421875E+00L
		, +1.000015282259408652470664136124867127364268526434898376464843750E+00L
		, +1.000007637197637899760874202748084371705772355198860168457031250E+00L
		, +1.000003817293265000534785436059337371261790394783020019531250000E+00L
		, +1.000001908212716553907631333864003408962162211537361145019531250E+00L
		, +1.000000953962033873505602099562850071379216387867927551269531250E+00L
		, +1.000000476932986787775847759007774584461003541946411132812500000E+00L
		, +1.000000238450502728498880955498862022068351507186889648437500000E+00L
		, +1.000000119219925965273476631267612901865504682064056396484375000E+00L
		, +1.000000059608189052133379870479501505542430095374584197998046875E+00L
		, +1.000000029803503514614672342819545747261145152151584625244140625E+00L
		, +1.000000014901554829275728830673131142248166725039482116699218750E+00L
		, +1.000000007450711789831927778227083081219461746513843536376953125E+00L
		, +1.000000003725334025853413444373529728181893005967140197753906250E+00L
		, +1.000000001862659723510240450394803701783530414104461669921875000E+00L
		, +1.000000000931327433467514509413121004399727098643779754638671875E+00L
		, +1.000000000465662906455263647664821746730012819170951843261718750E+00L
		, +1.000000000232831184562333481924412126318202354013919830322265625E+00L
		, +1.000000000116415501696075229798310601836419664323329925537109375E+00L
		, +1.000000000058207722170890152657563021421083249151706695556640625E+00L
		, +1.000000000029103850406053677346562835737131536006927490234375000E+00L
		, +1.000000000014551923359883145447923880055896006524562835693359375E+00L
		, +1.000000000007275959782587770874329180514905601739883422851562500E+00L
		, +1.000000000003637980867075840674118580864160321652889251708984375E+00L
		, +1.000000000001818989620386290972930964926490560173988342285156250E+00L
		, +1.000000000000909496328076186966171690073679201304912567138671875E+00L
		, +1.000000000000454747350886464118957519531250000000000000000000000E+00L
		, +1.000000000000227375193326273539184967376058921217918395996093750E+00L
		, +1.000000000000113686837721616029739379882812500000000000000000000E+00L
		, +1.000000000000056845045164066743126340952585451304912567138671875E+00L
		, +1.000000000000028421709430404007434844970703125000000000000000000E+00L
		, +1.000000000000014212589438677980524516897276043891906738281250000E+00L
		, +1.000000000000007105427357601001858711242675781250000000000000000E+00L
		, +1.000000000000003554556822493726286893434007652103900909423828125E+00L
		, +1.000000000000001776356839400250464677810668945312500000000000000E+00L
		, +1.000000000000000890129983610599140320118749514222145080566406250E+00L
		, +1.000000000000000444089209850062616169452667236328125000000000000E+00L
		, +1.000000000000000223996168835505216065939748659729957580566406250E+00L
		, +1.000000000000000111022302462515654042363166809082031250000000000E+00L
		, +1.000000000000000057571135358980285445795743726193904876708984375E+00L
		, +1.000000000000000027755575615628913510590791702270507812500000000E+00L
		, +1.000000000000000016046192152785465623310301452875137329101562500E+00L
		, +1.000000000000000006938893903907228377647697925567626953125000000E+00L
		, +1.000000000000000005637851296924623056838754564523696899414062500E+00L
		, +1.000000000000000001734723475976807094411924481391906738281250000E+00L
		, +1.000000000000000000867361738011993372834205506734295148791000000E+00L
		, +1.000000000000000000433680868994201773602981120347976684570312500E+00L
		, +1.000000000000000000216840434499721978501391016832098457616000000E+00L
		, +1.000000000000000000108420217248550443400745280086994171142578125E+00L
		, +1.000000000000000000054210108624566454109187004043886337151000000E+00L
		, +1.000000000000000000027105054312234688319546213119497764319000000E+00L
		, +1.000000000000000000013552527156101164581485233996826928329000000E+00L
		, +1.000000000000000000006776263578045189097995298741556686206000000E+00L
		, +1.000000000000000000003388131789020796818085703100450836834000000E+00L
		, +1.000000000000000000001694065894509799165406492747124861940000000E+00L
		, +1.000000000000000000000847032947254699834824699260918216752000000E+00L
		, +1.000000000000000000000423516473627283334786227048335793441000000E+00L
		, +1.000000000000000000000211758236813619473184420943981800259000000E+00L
		, +1.000000000000000000000105879118406802338522650015392383985000000E+00L
		, +1.000000000000000000000052939559203398703238139123029185056000000E+00L
	};
	if (s < 75) {
		return Z[s];
	}
	return 1.0;
#	else
	return mc_cast(long double, mc_izetap(s));
#	endif
}

#pragma mark - mc_zetap -

static MC_TARGET_INLINE float mc_zetapf(float s)
{
#	if MC_TARGET_EMBEDDED
	return mc_rzetapf_approx0(s);
#	else
#	if MC_TARGET_CPP98
	if (::isnan(s)) {
		return MCK_NAN;
	} else if (::isinf(s)) {
		return MCK_INF;
	}
	if (::truncf(s) == s && (s >= 0.0f && s < 28.0f)) {
		return mc_izetapf(mc_cast(unsigned int, s));
	}
#	else
	if (isnan(s)) {
		return MCK_NAN;
	} else if (isinf(s)) {
		return MCK_INF;
	}
	if (truncf(s) == s && (s >= 0.0f && s < 28.0f)) {
		return mc_izetapf(mc_cast(unsigned int, s));
	}
#	endif
	if (s > 0.0f && s <= 1.6E-10f) {
		return -0.5f - MCK_KF(MCK_LSQRT2PI) * s;
	}
	return mc_zetapscf(s, 1.0f - s);
#	endif
}

static MC_TARGET_INLINE double mc_zetap(double s)
{
#	if MC_TARGET_EMBEDDED
	return mc_rzetap_approx0(s);
#	else
#	if MC_TARGET_CPP98
	if (::isnan(s)) {
		return MCK_NAN;
	} else if (::isinf(s)) {
		return MCK_INF;
	}
	if (::trunc(s) == s && (s >= 0.0 && s < 64.0)) {
		return mc_izetap(mc_cast(unsigned int, s));
	}
#	else
	if (isnan(s)) {
		return MCK_NAN;
	} else if (isinf(s)) {
		return MCK_INF;
	}
	if (trunc(s) == s && (s >= 0.0 && s < 64.0)) {
		return mc_izetap(mc_cast(unsigned int, s));
	}
#	endif
	if (s > 0.0 && s <= 1.6E-10) {
		return -0.5 - MCK_K(MCK_LSQRT2PI) * s;
	}
	return mc_zetapsc(s, 1.0 - s);
#	endif
}

static MC_TARGET_INLINE long double mc_zetapl(long double s)
{
#	if MC_TARGET_EMBEDDED
	return mc_rzetapl_approx0(s);
#	else
#	if MC_TARGET_CPP98
	if (::isnan(s)) {
		return MCK_NAN;
	} else if (::isinf(s)) {
		return MCK_INF;
	}
#	if MC_TARGET_MSVC_CPP
	if (::truncl(s) == s && (s >= 0.0L && s < 75.0L)) {
		return mc_izetapl(mc_cast(unsigned int, s));
	}
#	else
	if (::truncl(s) == s && (s >= 0.0L && s < 64.0L)) {
		return mc_izetapl(mc_cast(unsigned int, s));
	}
#	endif
#	else
	if (isnan(s)) {
		return MCK_NAN;
	} else if (isinf(s)) {
		return MCK_INF;
	}
#	if MC_TARGET_MSVC_CPP
	if (truncl(s) == s && (s >= 0.0L && s < 75.0L)) {
		return mc_izetapl(mc_cast(unsigned int, s));
	}
#	else
	if (truncl(s) == s && (s >= 0.0L && s < 64.0L)) {
		return mc_izetapl(mc_cast(unsigned int, s));
	}
#	endif
#	endif
	if (s > 0.0L && s <= 1.6E-10L) {
		return -0.5L - MCK_KL(MCK_LSQRT2PI) * s;
	}
	return mc_zetapscl(s, 1.0L - s);
#	endif
}

#endif /* !MC_ZETAP_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gamma.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_GAMMA_H
#define MC_GAMMA_H

#pragma mark - mc_gamma_approx0 -

MC_TARGET_PROC float mc_gammaf_approx0(const float x)
{
//!# Stirling's formula formula for x >= 13.
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
	const float a = MCK_KF(MCK_2PI) / x;
	const float b = x * MCK_KF(MCK_1_E);
	return mc_sqrtf(a) * mc_powf(b, x);
}

MC_TARGET_PROC double mc_gamma_approx0(const double x)
{
//!# Stirling's formula formula for x >= 13.
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
	const double a = MCK_K(MCK_2PI) / x;
	const double b = x * MCK_K(MCK_1_E);
	return mc_sqrt(a) * mc_pow(b, x);
}

MC_TARGET_PROC long double mc_gammal_approx0(const long double x)
{
//!# Stirling's formula formula for x >= 13.
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
	const long double a = MCK_KL(MCK_2PI) / x;
	const long double b = x * MCK_KL(MCK_1_E);
	return mc_sqrtl(a) * mc_powl(b, x);
}

#pragma mark - mc_gamma_approx1 -

MC_TARGET_PROC float mc_gammaf_approx1(const float x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
	const float r = mc_lgammaf_approx2(x);
	return mc_expf(r);
}

MC_TARGET_PROC double mc_gamma_approx1(const double x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
	const double r = mc_lgamma_approx2(x);
	return mc_exp(r);
}

MC_TARGET_PROC long double mc_gammal_approx1(const long double x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
	const long double r = mc_lgammal_approx2(x);
	return mc_expl(r);
}

#pragma mark - mc_gamma_approx2 -

MC_TARGET_PROC float mc_gammaf_approx2(const float x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f;
	}
	if (x > 0.0f && x < 1.0f) {
		const float Y[] =
		{
			  +1.00000000000000000000000000000000000000E+00f
			, +5.77215671539306640625000000000000000000E-01f
			, -6.55878067016601562500000000000000000000E-01f
			, -4.20026332139968872070312500000000000000E-02f
			, +1.66538611054420471191406250000000000000E-01f
			, -4.21977341175079345703125000000000000000E-02f
			, -9.62197128683328628540039062500000000000E-03f
			, +7.21894344314932823181152343750000000000E-03f
			, -1.16516754496842622756958007812500000000E-03f
			, -2.15241670957766473293304443359375000000E-04f
			, +1.28050276543945074081420898437500000000E-04f
			, -2.01348539121681824326515197753906250000E-05f
			, -1.25049348298489348962903022766113281250E-06f
			, +1.13302724003006005659699440002441406250E-06f
			, -2.05633838845642458181828260421752929688E-07f
			, +6.11609518585964906378649175167083740234E-09f
			, +5.00200769693037727847695350646972656250E-09f
			, -1.18127452264360499611939303576946258545E-09f
			, +1.04342673390434015345817897468805313110E-10f
			, +7.78226354886113469433439604472368955612E-12f
			, -3.69680544856643145124053262406960129738E-12f
			, +5.10037053823991781698055092419963330030E-13f
			, -2.05832597602491340627040017352555878460E-14f
			, -5.34811986566802698150890904571497230791E-15f
			, +1.22678005212326860645655202119996829424E-15f
			, -1.18129994150942903459455823877988223103E-16f
			, +1.19000002039710864142193699755090108283E-18f
			, +1.40999997464143238655605826215033715698E-18f
			, -2.29999999163418719516790121593086126950E-19f
			, +1.99999993653104507779357749269744104481E-20f
		};
		return 1.0f / mc_xpolyevalnf(x - 1.0f, Y, 30);
	}
	return mc_gammaf_approx1(x);
}

MC_TARGET_PROC double mc_gamma_approx2(const double x)
{
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0;
	}
	if (x > 0.0 && x < 1.0) {
		const double Y[] =
		{
			  +1.0000000000000000000000000000000000000000E+00
			, +5.7721566490153286554942724251304753124714E-01
			, -6.5587807152025390244887148583075031638145E-01
			, -4.2002635034095237021034563440480269491673E-02
			, +1.6653861138229147931255624826007988303900E-01
			, -4.2197734555544333390209033041173825040460E-02
			, -9.6219715278769730321117847893219732213765E-03
			, +7.2189432466630999024603809743894089478999E-03
			, -1.1651675918590651687134496228281932417303E-03
			, -2.1524167411495097519159858112658412210294E-04
			, +1.2805028238811619551232312552713210607180E-04
			, -2.0134854780788238686178165393059202870063E-05
			, -1.2504934821426699954492398059180402469792E-06
			, +1.1330272319816999520029811993060420149959E-06
			, -2.0563384169775999265480600532163268923114E-07
			, +6.1160951044799999539996377166065771868730E-09
			, +5.0020076444699996680320884816142029682950E-09
			, -1.1812745704899999622212872904731574552617E-09
			, +1.0434267116999999692052651756343068477351E-10
			, +7.7822634399999994831376449332605764550724E-12
			, -3.6968056200000003359740855265755599600927E-12
			, +5.1003702999999995732415852765614332870684E-13
			, -2.0583259999999999123850822127860308453755E-14
			, -5.3481199999999998211395566681274152460215E-15
			, +1.2267799999999999880344587415804631339213E-15
			, -1.1813000000000000852064003157042843290243E-16
			, +1.1900000000000000235057264046085428673571E-18
			, +1.4100000000000000084301805864295926103376E-18
			, -2.2999999999999997986208858920556142889787E-19
			, +1.9999999999999998903065429084191433034590E-20
		};
		return 1.0 / mc_xpolyevaln(x - 1.0, Y, 30);
	}
	return mc_gamma_approx1(x);
}

MC_TARGET_PROC long double mc_gammal_approx2(const long double x)
{
	const long double Y[] =
	{
		  +1.000000000000000000000000000000000000000000000000000000000000000E+00L
		, +5.772156649015328606163073577040023565132287330925464630126953125E-01L
		, -6.558780715202538810900886878663129664346342906355857849121093750E-01L
		, -4.200263503409523553025657627291167273142491467297077178955078125E-02L
		, +1.665386113822914895040566696238215627090539783239364624023437500E-01L
		, -4.219773455554433675123576774623757046356331557035446166992187500E-02L
		, -9.621971527876973559813310928751084460941456200089305639266967773E-03L
		, +7.218943246663099539930279549548863826657907338812947273254394531E-03L
		, -1.165167591859065109950538907061107218865458889922592788934707642E-03L
		, -2.152416741149509700035217791939945453094651384162716567516326904E-04L
		, +1.280502823881161900066089683741799021277074643876403570175170898E-04L
		, -2.013485478078823999974097812726715056586002106087107677012681961E-05L
		, -1.250493482142669999998733174959692458771964851393931894563138485E-06L
		, +1.133027231981699999979456727381647157537614134525938425213098526E-06L
		, -2.056338416977599999960339417297533037148893342305200349073857069E-07L
		, +6.116095104480000000043871032546594245144812307390935757211991586E-09L
		, +5.002007644470000000035244496550115441096777402218975794312427752E-09L
		, -1.181274570489999999985636545213434603931968933099305729683692334E-09L
		, +1.043426711700000000002394915462607731008949814299757719027184066E-10L
		, +7.782263439999999999841537853023308999754642804793508537031243577E-12L
		, -3.696805619999999999919339902424530854696329575624635932484807199E-12L
		, +5.100370300000000000212550227434072966166492076500911523329051533E-13L
		, -2.058326000000000000053413281293006876483568884883096046858885764E-14L
		, -5.348119999999999999865855507262902409616235446153604052299534999E-15L
		, +1.226779999999999999975224396781325422868350231748814957270787840E-15L
		, -1.181299999999999999984000276569097831297320871197372528288091487E-16L
		, +1.189999999999999999995839388162792707982361952896077044550493486E-18L
		, +1.409999999999999999966621260509122552962714908665099123777326258E-18L
		, -2.300000000000000000100617622995693154820162614080188426072427082E-19L
		, +2.000000000000000000068327916450239360039781568701975060533327916E-20L
	};
	if (mc_isnan(x) || mc_isinf(x)) {
		return x;
	}
	if (x == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L;
	}
	if (x > 0.0L && x < 1.0L) {
		return 1.0L / mc_xpolyevalnl(x - 1.0L, Y, 30);
	}
	return mc_gammal_approx1(x);
}

#pragma mark - mc_gamma -

MC_TARGET_FUNC float mc_gammaf(const float x)
{
#	if MC_TARGET_EMBEDDED
	return mc_gammaf_approx2(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgammaf(x);
#	else
	return tgammaf(x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_gamma(const double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_gamma_approx2(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgamma(x);
#	else
	return tgamma(x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_gammal(const long double x)
{
#	if MC_TARGET_EMBEDDED
	return mc_gammal_approx2(x);
#	else
#	if MC_TARGET_CPP98
	return ::tgammal(x);
#	else
	return tgammal(x);
#	endif
#	endif
}

#endif /* !MC_GAMMA_H */

/* EOF */
// mc_bernoulli_b2n.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_BERNOULLI_B2N_H
#define MC_BERNOULLI_B2N_H

#pragma mark - mc_bernoulli_b2n -

MC_TARGET_FUNC float mc_bernoulli_b2nf(unsigned int n)
{
	const unsigned int max_b2n = 33;
	const float b2n[] = 
	{
		  MCK_KF(MCK_BN0)
		, MCK_KF(MCK_BN2)
		, MCK_KF(MCK_BN4)
		, MCK_KF(MCK_BN6)
		, MCK_KF(MCK_BN8)
		, MCK_KF(MCK_BN10)
		, MCK_KF(MCK_BN12)
		, MCK_KF(MCK_BN14)
		, MCK_KF(MCK_BN16)
		, MCK_KF(MCK_BN18)
		, MCK_KF(MCK_BN20)
		, MCK_KF(MCK_BN22)
		, MCK_KF(MCK_BN24)
		, MCK_KF(MCK_BN26)
		, MCK_KF(MCK_BN28)
		, MCK_KF(MCK_BN30)
		, MCK_KF(MCK_BN32)
		, MCK_KF(MCK_BN34)
		, MCK_KF(MCK_BN36)
		, MCK_KF(MCK_BN38)
		, MCK_KF(MCK_BN40)
		, MCK_KF(MCK_BN42)
		, MCK_KF(MCK_BN44)
		, MCK_KF(MCK_BN46)
		, MCK_KF(MCK_BN48)
		, MCK_KF(MCK_BN50)
		, MCK_KF(MCK_BN52)
		, MCK_KF(MCK_BN54)
		, MCK_KF(MCK_BN56)
		, MCK_KF(MCK_BN58)
		, MCK_KF(MCK_BN60)
		, MCK_KF(MCK_BN62)
		, MCK_KF(MCK_BN64)
	};
	float r = ((n % 2) == 0) ? MCK_INFP : MCK_INFN;
	if (n < max_b2n) {
		r = (n == 1) ? MCK_KF(MCK_BN1) : b2n[n / 2];
	}
	return r;
}

MC_TARGET_FUNC double mc_bernoulli_b2n(unsigned int n)
{
	const unsigned int max_b2n = 130;
	const double b2n[] = 
	{
		  MCK_K(MCK_BN0)
		, MCK_K(MCK_BN2)
		, MCK_K(MCK_BN4)
		, MCK_K(MCK_BN6)
		, MCK_K(MCK_BN8)
		, MCK_K(MCK_BN10)
		, MCK_K(MCK_BN12)
		, MCK_K(MCK_BN14)
		, MCK_K(MCK_BN16)
		, MCK_K(MCK_BN18)
		, MCK_K(MCK_BN20)
		, MCK_K(MCK_BN22)
		, MCK_K(MCK_BN24)
		, MCK_K(MCK_BN26)
		, MCK_K(MCK_BN28)
		, MCK_K(MCK_BN30)
		, MCK_K(MCK_BN32)
		, MCK_K(MCK_BN34)
		, MCK_K(MCK_BN36)
		, MCK_K(MCK_BN38)
		, MCK_K(MCK_BN40)
		, MCK_K(MCK_BN42)
		, MCK_K(MCK_BN44)
		, MCK_K(MCK_BN46)
		, MCK_K(MCK_BN48)
		, MCK_K(MCK_BN50)
		, MCK_K(MCK_BN52)
		, MCK_K(MCK_BN54)
		, MCK_K(MCK_BN56)
		, MCK_K(MCK_BN58)
		, MCK_K(MCK_BN60)
		, MCK_K(MCK_BN62)
		, MCK_K(MCK_BN64)
		, MCK_K(MCK_BN66)
		, MCK_K(MCK_BN68)
		, MCK_K(MCK_BN70)
		, MCK_K(MCK_BN72)
		, MCK_K(MCK_BN74)
		, MCK_K(MCK_BN76)
		, MCK_K(MCK_BN78)
		, MCK_K(MCK_BN80)
		, MCK_K(MCK_BN82)
		, MCK_K(MCK_BN84)
		, MCK_K(MCK_BN86)
		, MCK_K(MCK_BN88)
		, MCK_K(MCK_BN90)
		, MCK_K(MCK_BN92)
		, MCK_K(MCK_BN94)
		, MCK_K(MCK_BN96)
		, MCK_K(MCK_BN98)
		, MCK_K(MCK_BN100)
		, MCK_K(MCK_BN102)
		, MCK_K(MCK_BN104)
		, MCK_K(MCK_BN106)
		, MCK_K(MCK_BN108)
		, MCK_K(MCK_BN110)
		, MCK_K(MCK_BN112)
		, MCK_K(MCK_BN114)
		, MCK_K(MCK_BN116)
		, MCK_K(MCK_BN118)
		, MCK_K(MCK_BN120)
		, MCK_K(MCK_BN122)
		, MCK_K(MCK_BN124)
		, MCK_K(MCK_BN126)
		, MCK_K(MCK_BN128)
		, MCK_K(MCK_BN130)
		, MCK_K(MCK_BN132)
		, MCK_K(MCK_BN134)
		, MCK_K(MCK_BN136)
		, MCK_K(MCK_BN138)
		, MCK_K(MCK_BN140)
		, MCK_K(MCK_BN142)
		, MCK_K(MCK_BN144)
		, MCK_K(MCK_BN146)
		, MCK_K(MCK_BN148)
		, MCK_K(MCK_BN150)
		, MCK_K(MCK_BN152)
		, MCK_K(MCK_BN154)
		, MCK_K(MCK_BN156)
		, MCK_K(MCK_BN158)
		, MCK_K(MCK_BN160)
		, MCK_K(MCK_BN162)
		, MCK_K(MCK_BN164)
		, MCK_K(MCK_BN166)
		, MCK_K(MCK_BN168)
		, MCK_K(MCK_BN170)
		, MCK_K(MCK_BN172)
		, MCK_K(MCK_BN174)
		, MCK_K(MCK_BN176)
		, MCK_K(MCK_BN178)
		, MCK_K(MCK_BN180)
		, MCK_K(MCK_BN182)
		, MCK_K(MCK_BN184)
		, MCK_K(MCK_BN186)
		, MCK_K(MCK_BN188)
		, MCK_K(MCK_BN190)
		, MCK_K(MCK_BN192)
		, MCK_K(MCK_BN194)
		, MCK_K(MCK_BN196)
		, MCK_K(MCK_BN198)
		, MCK_K(MCK_BN200)
		, MCK_K(MCK_BN202)
		, MCK_K(MCK_BN204)
		, MCK_K(MCK_BN206)
		, MCK_K(MCK_BN208)
		, MCK_K(MCK_BN210)
		, MCK_K(MCK_BN212)
		, MCK_K(MCK_BN214)
		, MCK_K(MCK_BN216)
		, MCK_K(MCK_BN218)
		, MCK_K(MCK_BN220)
		, MCK_K(MCK_BN222)
		, MCK_K(MCK_BN224)
		, MCK_K(MCK_BN226)
		, MCK_K(MCK_BN228)
		, MCK_K(MCK_BN230)
		, MCK_K(MCK_BN232)
		, MCK_K(MCK_BN234)
		, MCK_K(MCK_BN236)
		, MCK_K(MCK_BN238)
		, MCK_K(MCK_BN240)
		, MCK_K(MCK_BN242)
		, MCK_K(MCK_BN244)
		, MCK_K(MCK_BN246)
		, MCK_K(MCK_BN248)
		, MCK_K(MCK_BN250)
		, MCK_K(MCK_BN252)
		, MCK_K(MCK_BN254)
		, MCK_K(MCK_BN256)
		, MCK_K(MCK_BN258)
	};
	double r = ((n % 2) == 0) ? MCK_INFP : MCK_INFN;
	if (n < max_b2n) {
		r = (n == 1) ? MCK_K(MCK_BN1) : b2n[n / 2];
	}
	return r;
}

MC_TARGET_FUNC long double mc_bernoulli_b2nl(unsigned int n)
{
//!# @TODO
	return mc_cast(long double, mc_bernoulli_b2n(n));
}

#endif /* !MC_BERNOULLI_B2N_H */

/* EOF */
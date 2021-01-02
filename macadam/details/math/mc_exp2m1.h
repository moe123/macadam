//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp2m1.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_expm1.h>

#ifndef MC_EXP2M1_H
#define MC_EXP2M1_H

#pragma mark - mc_exp2m1 -

MC_TARGET_FUNC float mc_exp2m1f(float x)
{
	const float y = x * MCK_KF(MCK_LOGE2);
	return mc_expm1f(y);
}

MC_TARGET_FUNC double mc_exp2m1(double x)
{
	const double y = x * MCK_K(MCK_LOGE2);
	return mc_expm1(y);
}

MC_TARGET_FUNC long double mc_exp2m1l(long double x)
{
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_LN2l)
	const long double y = x * M_LN2l;
#	else
	const long double y = x * MCK_KL(MCK_LOGE2);
#	endif
	return mc_expm1l(y);
}

#pragma mark - mc_uexp2m1 -

MC_TARGET_PROC unsigned int mc_uexp2m1(unsigned int x)
{
	return (1 << x) - 1;
}

#pragma mark - mc_exp2m1ul -

MC_TARGET_PROC unsigned long mc_exp2m1ul(unsigned long x)
{
	return (1 << x) - 1;
}

#pragma mark - mc_exp2m1ull -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
MC_TARGET_PROC unsigned long long mc_exp2m1ull(unsigned long long x)
{
	return (1 << x) - 1;
}
#	else
#	define mc_exp2m1ull mc_exp2m1ul
#	endif

#endif /* !MC_EXP2M1_H */

/* EOF */
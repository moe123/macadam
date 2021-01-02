//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_itrunc.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ITRUNC_H
#define MC_ITRUNC_H

#pragma mark - mc_itrunc -

MC_TARGET_PROC int mc_itruncf(float x)
{
	return mc_cast(int, x);
}

MC_TARGET_PROC int mc_itrunc(double x)
{
	return mc_cast(int, x);
}

MC_TARGET_PROC int mc_itruncl(long double x)
{
	return mc_cast(int, x);
}

#pragma mark - mc_ltrunc -

MC_TARGET_PROC long mc_ltruncf(float x)
{
	return mc_cast(long, x);
}

MC_TARGET_PROC long mc_ltrunc(double x)
{
	return mc_cast(long, x);
}

MC_TARGET_PROC long mc_ltruncl(long double x)
{
	return mc_cast(long, x);
}

#pragma mark - mc_lltrunc -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
MC_TARGET_PROC long long mc_lltruncf(float x)
{
	return mc_cast(long long, x);
}

MC_TARGET_PROC long long mc_lltrunc(double x)
{
	return mc_cast(long long, x);
}

MC_TARGET_PROC long long mc_lltruncl(long double x)
{
	return mc_cast(long long, x);
}
#	else
#	define mc_lltruncf mc_ltruncf
#	define mc_lltrunc  mc_ltrunc
#	define mc_lltruncl mc_ltruncl
#	endif

#endif /* !MC_ITRUNC_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_maxmag.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_MAXMAG_H
#define MC_MAXMAG_H

#pragma mark - mc_bmax -

static MC_TARGET_INLINE signed char mc_bmax(signed char a, signed char b)
{
	return a > b ? a : b;
}

#pragma mark - mc_smax -

static MC_TARGET_INLINE short mc_smax(short a, short b)
{
	return a > b ? a : b;
}

#pragma mark - mc_imax -

static MC_TARGET_INLINE int mc_imax(int a, int b)
{
	return a > b ? a : b;
}

#pragma mark - mc_lmax -

static MC_TARGET_INLINE long mc_lmax(long a, long b){
	return a > b ? a : b;
}

#pragma mark - mc_llmax -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE long long mc_llmax(long long a, long long b)
{
	return a > b ? a : b;
}
#	else
#	define mc_llmax mc_lmax
#	endif

#endif /* !MC_MAXMAG_H */

/* EOF */
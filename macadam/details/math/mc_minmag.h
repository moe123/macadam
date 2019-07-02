//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_minmag.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_MINMAG_H
#define MC_MINMAG_H

#pragma mark - mc_bmin -

static MC_TARGET_INLINE signed char mc_bmin(signed char a, signed char b)
{
	return a < b ? a : b;
}

#pragma mark - mc_smin -

static MC_TARGET_INLINE short mc_smin(short a, short b)
{
	return a < b ? a : b;
}

#pragma mark - mc_imin -

static MC_TARGET_INLINE int mc_imin(int a, int b)
{
	return a < b ? a : b;
}

#pragma mark - mc_lmin -

static MC_TARGET_INLINE long mc_lmin(long a, long b)
{
	return a < b ? a : b;
}

#pragma mark - mc_llmin -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE long long mc_llmin(long long a, long long b)
{
	return a < b ? a : b;
}
#	else
#	define mc_llmin mc_lmin
#	endif

#pragma mark - mc_ubmin -

static MC_TARGET_INLINE unsigned char mc_ubmin(unsigned char a, unsigned char b)
{
	return a < b ? a : b;
}

#pragma mark - mc_usmin -

static MC_TARGET_INLINE unsigned short mc_usmin(unsigned short a, unsigned short b)
{
	return a < b ? a : b;
}

#pragma mark - mc_uimin -

static MC_TARGET_INLINE unsigned int mc_uimin(unsigned int a, unsigned int b)
{
	return a < b ? a : b;
}

#pragma mark - mc_ulmin -

static MC_TARGET_INLINE unsigned long mc_ulmin(unsigned long a, unsigned long b)
{
	return a < b ? a : b;
}

#pragma mark - mc_ullmin -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE unsigned long long mc_ullmin(unsigned long long a, unsigned long long b)
{
	return a < b ? a : b;
}
#	else
#	define mc_ullmin mc_ulmin
#	endif

#endif /* !MC_MINMAG_H */

/* EOF */
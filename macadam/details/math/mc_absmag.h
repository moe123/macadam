//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_absmag.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ABSMAG_H
#define MC_ABSMAG_H

#pragma mark - mc_babs -

static MC_TARGET_INLINE signed char mc_babs(signed char x)
{
	return x < 0 ? -x : x;
}

#pragma mark - mc_sabs -

static MC_TARGET_INLINE short mc_sabs(short x)
{
	return x < 0 ? -x : x;
}

#pragma mark - mc_iabs -

static MC_TARGET_INLINE int mc_iabs(int x)
{
#	if MC_TARGET_CPP98
	return ::abs(x);
#	else
	return abs(x);
#	endif
}

#pragma mark - mc_ubabs -

static MC_TARGET_INLINE unsigned char mc_ubabs(unsigned char x)
{
	return x;
}

#pragma mark - mc_usabs -

static MC_TARGET_INLINE unsigned short mc_usabs(unsigned short x)
{
	return x;
}

#pragma mark - mc_uabs -

static MC_TARGET_INLINE unsigned int mc_uabs(unsigned int x)
{
	return x;
}

#pragma mark - mc_iabs8 -

static MC_TARGET_INLINE int8_t mc_iabs8(int8_t x)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	return x == INT8_MIN ? INT8_MAX : (x >= 0 ? x : -x);
#	else
	return x >= 0 ? x : -x;
#	endif
}

#pragma mark - mc_iabs16 -

static MC_TARGET_INLINE int16_t mc_iabs16(int16_t x)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	return x == INT16_MIN ? INT16_MAX : (x >= 0 ? x : -x);
#	else
	return x >= 0 ? x : -x;
#	endif
}

#pragma mark - mc_iabs32 -

static MC_TARGET_INLINE int32_t mc_iabs32(int32_t x)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	return x == INT32_MIN ? INT32_MAX : (x >= 0 ? x : -x);
#	else
	return x >= 0 ? x : -x;
#	endif
}

#pragma mark - mc_iabs64 -

static MC_TARGET_INLINE int64_t mc_iabs64(int64_t x)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	return x == INT64_MIN ? INT64_MIN : (x >= 0 ? x : -x);
#	else
	return x >= 0 ? x : -x;
#	endif
}

#pragma mark - mc_uabs8 -

static MC_TARGET_INLINE uint8_t mc_uabs8(uint8_t x)
{
	return x;
}

#pragma mark - mc_uabs16 -

static MC_TARGET_INLINE uint16_t mc_uabs16(uint16_t x)
{
	return x;
}

#pragma mark - mc_uabs32 -

static MC_TARGET_INLINE uint32_t mc_uabs32(uint32_t x)
{
	return x;
}

#pragma mark - mc_uabs64 -

static MC_TARGET_INLINE uint64_t mc_uabs64(uint64_t x)
{
	return x;
}

#pragma mark - mc_labs -

static MC_TARGET_INLINE long mc_labs(long x)
{
#	if MC_TARGET_CPP98
	return ::labs(x);
#	else
	return labs(x);
#	endif
}

#pragma mark - mc_llabs -

#	if MC_TARGET_CPP11
static MC_TARGET_INLINE long long mc_llabs(long long x)
{
	return ::llabs(x);
}
#	elif MC_TARGET_C99
static MC_TARGET_INLINE long long mc_llabs(long long x)
{
	return llabs(x);
}
#	else
#	define mc_llabs mc_labs
#	endif

#pragma mark - mc_luabs -

static MC_TARGET_INLINE unsigned long mc_luabs(unsigned long x)
{
	return x;
}

#pragma mark - mc_lluabs -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE unsigned long long mc_lluabs(unsigned long long x)
{
	return x;
}
#	else
#	define mc_lluabs mc_luabs
#	endif

#endif /* !MC_ABSMAG_H */

/* EOF */
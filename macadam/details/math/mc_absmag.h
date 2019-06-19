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

#endif /* !MC_ABSMAG_H */

/* EOF */
// mc_atanh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ATANH_H
#define MC_ATANH_H

#pragma mark - mc_atanh -

static MC_TARGET_INLINE float mc_atanhf(float x)
{
#	if MC_TARGET_CPP98
	return ::atanhf(x);
#	else
	return atanhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_atanh(double x)
{
#	if MC_TARGET_CPP98
	return ::atanh(x);
#	else
	return atanh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_atanhl(long double x)
{
#	if MC_TARGET_CPP98
	return ::atanhl(x);
#	else
	return atanhl(x);
#	endif
}

#endif /* !MC_ATANH_H */

/* EOF */

#ifndef MC_ATAN_H
#define MC_ATAN_H

#pragma mark - mc_atan -

static MC_TARGET_INLINE float mc_atanf(float x)
{
#	if MC_TARGET_CPP98
	return ::atanf(x);
#	else
	return atanf(x);
#	endif
}

static MC_TARGET_INLINE double mc_atan(double x)
{
#	if MC_TARGET_CPP98
	return ::atan(x);
#	else
	return atan(x);
#	endif
}

static MC_TARGET_INLINE long double mc_atanl(long double x)
{
#	if MC_TARGET_CPP98
	return ::atanl(x);
#	else
	return atanl(x);
#	endif
}

#endif /* !MC_ATAN_H */

/* EOF */
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
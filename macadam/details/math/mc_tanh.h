// mc_tanh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_TANH_H
#define MC_TANH_H

#pragma mark - mc_tanh -

static MC_TARGET_INLINE float mc_tanhf(float x)
{
#	if MC_TARGET_CPP98
	return ::tanhf(x);
#	else
	return tanhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_tanh(double x)
{
#	if MC_TARGET_CPP98
	return ::tanh(x);
#	else
	return tanh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_tanhl(long double x)
{
#	if MC_TARGET_CPP98
	return ::tanhl(x);
#	else
	return tanhl(x);
#	endif
}

#endif /* !MC_TANH_H */

/* EOF */
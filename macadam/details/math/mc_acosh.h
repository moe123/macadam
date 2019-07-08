//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acosh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ACOSH_H
#define MC_ACOSH_H

#pragma mark - mc_acosh -

static MC_TARGET_INLINE float mc_acoshf(float x)
{
#	if MC_TARGET_CPP98
	return ::acoshf(x);
#	else
	return acoshf(x);
#	endif
}

static MC_TARGET_INLINE double mc_acosh(double x)
{
#	if MC_TARGET_CPP98
	return ::acosh(x);
#	else
	return acosh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_acoshl(long double x)
{
#	if MC_TARGET_CPP98
	return ::acoshl(x);
#	else
	return acoshl(x);
#	endif
}

#endif /* !MC_ACOSH_H */

/* EOF */
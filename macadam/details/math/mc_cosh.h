//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cosh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_COSH_H
#define MC_COSH_H

#pragma mark - mc_cosh -

static MC_TARGET_INLINE float mc_coshf(float x)
{
#	if MC_TARGET_CPP98
	return ::coshf(x);
#	else
	return coshf(x);
#	endif
}

static MC_TARGET_INLINE double mc_cosh(double x)
{
#	if MC_TARGET_CPP98
	return ::cosh(x);
#	else
	return cosh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_coshl(long double x)
{
#	if MC_TARGET_CPP98
	return ::coshl(x);
#	else
	return coshl(x);
#	endif
}

#endif /* !MC_COSH_H */

/* EOF */
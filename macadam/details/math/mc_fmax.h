//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fmax.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FMAX_H
#define MC_FMAX_H

#pragma mark - mc_fmax -

MC_TARGET_FUNC float mc_fmaxf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::fmaxf(x, y);
#	else
	return fmaxf(x, y);
#	endif
}

MC_TARGET_FUNC double mc_fmax(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::fmax(x, y);
#	else
	return fmax(x, y);
#	endif
}

MC_TARGET_FUNC long double mc_fmaxl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::fmaxl(x, y);
#	else
	return fmaxl(x, y);
#	endif
}

#endif /* !MC_FMAX_H */

/* EOF */
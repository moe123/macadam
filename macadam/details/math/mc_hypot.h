//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hypot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_HYPOT_H
#define MC_HYPOT_H

#pragma mark - mc_hypot -

MC_TARGET_FUNCTION float mc_hypotf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::hypotf(x, y);
#	else
	return hypotf(x, y);
#	endif
}

MC_TARGET_FUNCTION double mc_hypot(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::hypot(x, y);
#	else
	return hypot(x, y);
#	endif
}

MC_TARGET_FUNCTION double mc_hypotl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::hypotl(x, y);
#	else
	return hypotl(x, y);
#	endif
}

#endif /* !MC_HYPOT_H */

/* EOF */
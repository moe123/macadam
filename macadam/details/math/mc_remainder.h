//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_remainder.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_REMAINDER_H
#define MC_REMAINDER_H

#pragma mark - mc_remainder -

MC_TARGET_FUNC float mc_remainderf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::remainderf(x, y);
#	else
	return remainderf(x, y);
#	endif
}

MC_TARGET_FUNC double mc_remainder(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::remainder(x, y);
#	else
	return remainder(x, y);
#	endif
}

MC_TARGET_FUNC long double mc_remainderl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::remainderl(x, y);
#	else
	return remainderl(x, y);
#	endif
}

#endif /* !MC_REMAINDER_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fmin.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FMIN_H
#define MC_FMIN_H

#pragma mark - mc_fmin -

MC_TARGET_FUNC float mc_fminf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::fminf(x, y);
#	else
	return fminf(x, y);
#	endif
}

MC_TARGET_FUNC double mc_fmin(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::fmin(x, y);
#	else
	return fmin(x, y);
#	endif
}

MC_TARGET_FUNC long double mc_fminl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::fminl(x, y);
#	else
	return fminl(x, y);
#	endif
}

#endif /* !MC_FMIN_H */

/* EOF */
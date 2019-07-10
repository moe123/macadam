//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_modf.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_MODF_H
#define MC_MODF_H

#pragma mark - mc_modf -

static MC_TARGET_INLINE float mc_modff(float x, float * y)
{
#	if MC_TARGET_CPP98
	return ::modff(x, y);
#	else
	return modff(x, y);
#	endif
}

static MC_TARGET_INLINE double mc_modf(double x, double * y)
{
#	if MC_TARGET_CPP98
	return ::modf(x, y);
#	else
	return modf(x, y);
#	endif
}

static MC_TARGET_INLINE long double mc_modfl(long double x, long double * y)
{
#	if MC_TARGET_CPP98
	return ::modfl(x, y);
#	else
	return modfl(x, y);
#	endif
}

#endif /* !MC_MODF_H */

/* EOF */
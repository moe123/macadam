//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fmod.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FMOD_H
#define MC_FMOD_H

#pragma mark - mc_fmod -

MC_TARGET_FUNCTION float mc_fmodf(float x, float y)
{
#	if MC_TARGET_CPP98
	return ::fmodf(x, y);
#	else
	return fmodf(x, y);
#	endif
}

MC_TARGET_FUNCTION double mc_fmod(double x, double y)
{
#	if MC_TARGET_CPP98
	return ::fmod(x, y);
#	else
	return fmod(x, y);
#	endif
}

MC_TARGET_FUNCTION long double mc_fmodl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ::fmodl(x, y);
#	else
	return fmodl(x, y);
#	endif
}

#endif /* !MC_FMOD_H */

/* EOF */
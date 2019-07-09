//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_erfc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ERFC_H
#define MC_ERFC_H

#pragma mark - mc_erfc -

static MC_TARGET_INLINE float mc_erfcf(float x)
{
#	if MC_TARGET_CPP98
	return ::erfcf(x);
#	else
	return erfcf(x);
#	endif
}

static MC_TARGET_INLINE double mc_erfc(double x)
{
#	if MC_TARGET_CPP98
	return ::erfc(x);
#	else
	return erfc(x);
#	endif
}

static MC_TARGET_INLINE long double mc_erfcl(long double x)
{
#	if MC_TARGET_CPP98
	return ::erfcl(x);
#	else
	return erfcl(x);
#	endif
}

#endif /* !MC_ERFC_H */

/* EOF */
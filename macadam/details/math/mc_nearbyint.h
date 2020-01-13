//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nearbyint.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_NEARBYINT_H
#define MC_NEARBYINT_H

#pragma mark - mc_nearbyint -

MC_TARGET_FUNC float mc_nearbyintf(float x)
{
#	if MC_TARGET_CPP98
	return ::nearbyintf(x);
#	else
	return nearbyintf(x);
#	endif
}

MC_TARGET_FUNC double mc_nearbyint(double x)
{
#	if MC_TARGET_CPP98
	return ::nearbyint(x);
#	else
	return nearbyint(x);
#	endif
}

MC_TARGET_FUNC long double mc_nearbyintl(long double x)
{
#	if MC_TARGET_CPP98
	return ::nearbyintl(x);
#	else
	return nearbyintl(x);
#	endif
}

#endif /* !MC_NEARBYINT_H */

/* EOF */
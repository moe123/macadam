//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acos.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ACOS_H
#define MC_ACOS_H

#pragma mark - mc_acos -

MC_TARGET_FUNCTION float mc_acosf(float x)
{
#	if MC_TARGET_CPP98
	return ::acosf(x);
#	else
	return acosf(x);
#	endif
}

MC_TARGET_FUNCTION double mc_acos(double x)
{
#	if MC_TARGET_CPP98
	return ::acos(x);
#	else
	return acos(x);
#	endif
}

MC_TARGET_FUNCTION long double mc_acosl(long double x)
{
#	if MC_TARGET_CPP98
	return ::acosl(x);
#	else
	return acosl(x);
#	endif
}

#endif /* !MC_ACOS_H */

/* EOF */
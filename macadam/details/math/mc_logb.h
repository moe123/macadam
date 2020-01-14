//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logb.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOGB_H
#define MC_LOGB_H

#pragma mark - mc_logb -

MC_TARGET_FUNC float mc_logbf(float x)
{
#	if MC_TARGET_CPP98
	return ::logbf(x);
#	else
	return logbf(x);
#	endif
}

MC_TARGET_FUNC double mc_logb(double x)
{
#	if MC_TARGET_CPP98
	return ::logb(x);
#	else
	return logb(x);
#	endif
}

MC_TARGET_FUNC long double mc_logbl(long double x)
{
#	if MC_TARGET_CPP98
	return ::logbl(x);
#	else
	return logbl(x);
#	endif
}

#endif /* !MC_LOGB_H */

/* EOF */
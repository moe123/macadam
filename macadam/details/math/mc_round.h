//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_round.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ROUND_H
#define MC_ROUND_H

#pragma mark - mc_round -

MC_TARGET_FUNC float mc_roundf(float x)
{
#	if MC_TARGET_CPP98
	return ::roundf(x);
#	else
	return roundf(x);
#	endif
}

MC_TARGET_FUNC double mc_round(double x)
{
#	if MC_TARGET_CPP98
	return ::round(x);
#	else
	return round(x);
#	endif
}

MC_TARGET_FUNC long double mc_roundl(long double x)
{
#	if MC_TARGET_CPP98
	return ::roundl(x);
#	else
	return roundl(x);
#	endif
}

#endif /* !MC_ROUND_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_remquo.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_REMQUO_H
#define MC_REMQUO_H

#pragma mark - mc_remquo -

MC_TARGET_PROC float mc_remquof(float x, float y, int * quo)
{
#	if MC_TARGET_CPP98
	return ::remquof(x, y, quo);
#	else
	return remquof(x, y, quo);
#	endif
}

MC_TARGET_PROC double mc_remquo(double x, double y, int * quo)
{
#	if MC_TARGET_CPP98
	return ::remquo(x, y, quo);
#	else
	return remquo(x, y, quo);
#	endif
}

MC_TARGET_PROC long double mc_remquol(long double x, long double y, int * quo)
{
#	if MC_TARGET_CPP98
	return ::remquol(x, y, quo);
#	else
	return remquol(x, y, quo);
#	endif
}

#endif /* !MC_REMQUO_H */

/* EOF */
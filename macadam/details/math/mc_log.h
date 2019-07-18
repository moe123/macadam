//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOG_H
#define MC_LOG_H

#pragma mark - mc_log -

MC_TARGET_FUNCTION float mc_logf(float x)
{
#	if MC_TARGET_CPP98
	return ::logf(x);
#	else
	return logf(x);
#	endif
}

MC_TARGET_FUNCTION double mc_log(double x)
{
#	if MC_TARGET_CPP98
	return ::log(x);
#	else
	return log(x);
#	endif
}

MC_TARGET_FUNCTION long double mc_logl(long double x)
{
#	if MC_TARGET_CPP98
	return ::logl(x);
#	else
	return logl(x);
#	endif
}

#endif /* !MC_LOG_H */

/* EOF */
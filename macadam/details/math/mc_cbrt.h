//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cbrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_pow.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_CBRT_H
#define MC_CBRT_H

#pragma mark - mc_cbrt -

MC_TARGET_FUNCTION float mc_cbrtf(float x)
{
#	if MC_TARGET_CPP98
	return ::cbrtf(x);
#	else
	return cbrtf(x);
#	endif
}

MC_TARGET_FUNCTION double mc_cbrt(double x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(x);
#	else
	return cbrt(x);
#	endif
}

MC_TARGET_FUNCTION long double mc_cbrtl(long double x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(x);
#	else
	return cbrtl(x);
#	endif
}

#endif /* !MC_CBRT_H */

/* EOF */
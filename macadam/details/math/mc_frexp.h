//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_frexp.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FREXP_H
#define MC_FREXP_H

#pragma mark - mc_frexp -

MC_TARGET_FUNC float mc_frexpf(float x, int * e)
{
#	if MC_TARGET_CPP98
	return ::frexpf(x, e);
#	else
	return frexpf(x, e);
#	endif
}

MC_TARGET_FUNC double mc_frexp(double x, int * e)
{
#	if MC_TARGET_CPP98
	return ::frexp(x, e);
#	else
	return frexp(x, e);
#	endif
}

MC_TARGET_FUNC long double mc_frexpl(long double x, int * e)
{
#	if MC_TARGET_CPP98
	return ::frexpl(x, e);
#	else
	return frexpl(x, e);
#	endif
}

#endif /* !MC_FREXP_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXP_H
#define MC_EXP_H

#pragma mark - mc_exp -

MC_TARGET_FUNCTION float mc_expf(float x)
{
#	if MC_TARGET_CPP98
	return ::expf(x);
#	else
	return expf(x);
#	endif
}

MC_TARGET_FUNCTION double mc_exp(double x)
{
#	if MC_TARGET_CPP98
	return ::exp(x);
#	else
	return exp(x);
#	endif
}

MC_TARGET_FUNCTION long double mc_expl(long double x)
{
#	if MC_TARGET_CPP98
	return ::expl(x);
#	else
	return expl(x);
#	endif
}

#endif /* !MC_EXP_H */

/* EOF */
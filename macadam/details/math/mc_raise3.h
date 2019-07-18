//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_raise3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RAISE3_H
#define MC_RAISE3_H

#pragma mark - mc_raise3 -

MC_TARGET_FUNC float mc_raise3f(float x)
{
	return x * x * x;
}

MC_TARGET_FUNC double mc_raise3(double x)
{
	return x * x * x;
}

MC_TARGET_FUNC long double mc_raise3l(long double x)
{
	return x * x * x;
}

#endif /* !MC_RAISE3_H */

/* EOF */
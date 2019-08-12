//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_raise6.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RAISE6_H
#define MC_RAISE6_H

#pragma mark - mc_raise6 -

MC_TARGET_PROC float mc_raise6f(float x)
{
	return x * x * x * x * x * x;
}

MC_TARGET_PROC double mc_raise6(double x)
{
	return x * x * x * x * x * x;
}

MC_TARGET_PROC long double mc_raise6l(long double x)
{
	return x * x * x * x * x * x;
}

#endif /* !MC_RAISE6_H */

/* EOF */
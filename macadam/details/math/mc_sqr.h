//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sqr.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SQR_H
#define MC_SQR_H

#pragma mark - mc_sqr -

MC_TARGET_FUNC float mc_sqrf(float x)
{
	return mc_raise2f(x);
}

MC_TARGET_FUNC double mc_sqr(double x)
{
	return mc_raise2(x);
}

MC_TARGET_FUNC long double mc_sqrl(long double x)
{
	return mc_raise2l(x);
}

#endif /* !MC_SQR_H */

/* EOF */
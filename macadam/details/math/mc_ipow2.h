//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ipow2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_IPOW2_H
#define MC_IPOW2_H

#pragma mark - mc_ipow2 -

MC_TARGET_FUNC float mc_ipow2f(int x)
{
	if (x < -1074) {
		return 0.0f;
	} else if (x < 0) {
		return 1.0f / mc_cast(float, (1 << x));
	} else if (x == 0) {
		return 1.0f;
	} else if (x == 1) {
		return 2.0f;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(float, (1 << x));
}

MC_TARGET_FUNC double mc_ipow2(int x)
{
	if (x < -1074) {
		return 0.0;
	} else if (x < 0) {
		return 1.0 / mc_cast(double, (1 << x));
	} else if (x == 0) {
		return 1.0;
	} else if (x == 1) {
		return 2.0;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(double, (1 << x));
}

MC_TARGET_FUNC long double mc_ipow2l(int x)
{
	if (x < -1074) {
		return 0.0L;
	} else if (x < 0) {
		return 1.0L / mc_cast(long double, (1 << x));
	} else if (x == 0) {
		return 1.0L;
	} else if (x == 1) {
		return 2.0L;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(long double, (1 << x));
}

#endif /* !MC_IPOW2_H */

/* EOF */
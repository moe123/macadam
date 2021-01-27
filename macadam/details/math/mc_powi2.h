//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_powi2.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_POWI2_H
#define MC_POWI2_H

#pragma mark - mc_powi2 -

MC_TARGET_FUNC float mc_powi2f(const int x)
{
	if (x < -1074) {
		return 0.0f;
	} else if (x < 0) {
		return 1.0f / mc_cast(float, (1 << (-x)));
	} else if (x == 0) {
		return 1.0f;
	} else if (x == 1) {
		return 2.0f;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(float, (1 << x));
}

MC_TARGET_FUNC double mc_powi2(const int x)
{
	if (x < -1074) {
		return 0.0;
	} else if (x < 0) {
		return 1.0 / mc_cast(double, (1 << (-x)));
	} else if (x == 0) {
		return 1.0;
	} else if (x == 1) {
		return 2.0;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(double, (1 << x));
}

MC_TARGET_FUNC long double mc_powi2l(const int x)
{
	if (x < -1074) {
		return 0.0L;
	} else if (x < 0) {
		return 1.0L / mc_cast(long double, (1 << (-x)));
	} else if (x == 0) {
		return 1.0L;
	} else if (x == 1) {
		return 2.0L;
	} else if (x > 1023) {
		return MCK_INFP;
	}
	return mc_cast(long double, (1 << x));
}

#endif /* !MC_POWI2_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_atan2pi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_atan2.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ATAN2PI_H
#define MC_ATAN2PI_H

#pragma mark - mc_atan2pi -

MC_TARGET_FUNC float mc_atan2pif(float y, float x)
{
	const float z = mc_atan2f(y, x);
	return z * MCK_KF(MCK_1_PI);
}

MC_TARGET_FUNC double mc_atan2pi(double y, double x)
{
	const double z = mc_atan2(y, x);
	return z * MCK_K(MCK_1_PI);
}

MC_TARGET_FUNC long double mc_atan2pil(long double y, long double x)
{
	const long double z = mc_atan2l(y, x);
	return z * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ATAN2PI_H */

/* EOF */
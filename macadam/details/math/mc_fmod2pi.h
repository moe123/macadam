//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fmod2pi.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fisnear.h>
#include <macadam/details/math/mc_fmod.h>

#ifndef MC_FMOD2PI_H
#define MC_FMOD2PI_H

#pragma mark - mc_fmod2pi -

MC_TARGET_FUNC float mc_fmod2pif(const float x)
{
//!# [+0, +2pi].
	const float p = MCK_KF(MCK_2PI);
	const float m = mc_fmodf(x, p);
	return m < 0.0f ? m + p : (mc_fisnearf(x, p, 2) ? 0.0f : m);
}

MC_TARGET_FUNC double mc_fmod2pi(const double x)
{
//!# [+0, +2pi].
	const double p = MCK_K(MCK_2PI);
	const double m = mc_fmod(x, p);
	return m < 0.0 ? m + p : (mc_fisnear(x, p, 2) ? 0.0 : m);
}

MC_TARGET_FUNC long double mc_fmod2pil(const long double x)
{
//!# [+0, +2pi].
	const long double p = MCK_KL(MCK_2PI);
	const long double m = mc_fmodl(x, p);
	return m < 0.0L ? m + p : (mc_fisnearl(x, p, 2) ? 0.0L : m);
}

#endif /* !MC_FMOD2PI_H */

/* EOF */
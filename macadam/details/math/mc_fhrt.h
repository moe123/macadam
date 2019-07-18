//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fhrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_pow.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FHRT_H
#define MC_FHRT_H

#pragma mark - mc_fhrt -

MC_TARGET_FUNC float mc_fhrtf(float x)
{
	if (x < 0.0f || x == -0.0f) {
		return -mc_powf(-x, 0.25f);
	}
	return mc_powf(x, 0.25f);
}

MC_TARGET_FUNC double mc_fhrt(double x)
{
	if (x < 0.0 || x == -0.0) {
		return -mc_pow(-x, 0.25);
	}
	return mc_pow(x, 0.25);
}

MC_TARGET_FUNC long double mc_fhrtl(long double x)
{
	if (x < 0.0L || x == -0.0L) {
		return -mc_powl(-x, 0.25L);
	}
	return mc_powl(x, 0.25L);
}

#endif /* !MC_FHRT_H */

/* EOF */
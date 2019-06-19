//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fhrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_FHRT_H
#define MC_FHRT_H

#pragma mark - mc_fhrt -

static MC_TARGET_INLINE float mc_fhrtf(float x)
{
#	if MC_TARGET_CPP98
	if (x < 0.0f || x == -0.0f) {
		return -(::powf(-x, 0.25f));
	}
	return ::powf(x, 0.25f);
#	else
	if (x < 0.0f || x == -0.0f) {
		return -powf(-x, 0.25f);
	}
	return powf(x, 0.25f);
#	endif
}

static MC_TARGET_INLINE double mc_fhrt(double x)
{
#	if MC_TARGET_CPP98
	if (x < 0.0 || x == -0.0) {
		return -(::pow(-x, 0.25));
	}
	return ::pow(x, 0.25);
#	else
	if (x < 0.0 || x == -0.0) {
		return -pow(-x, 0.25);
	}
	return pow(x, 0.25);
#	endif
}

static MC_TARGET_INLINE long double mc_fhrtl(long double x)
{
#	if MC_TARGET_CPP98
	if (x < 0.0L || x == -0.0L) {
		return -(::powl(-x, 0.25L));
	}
	return ::powl(x, 0.25L);
#	else
	if (x < 0.0L || x == -0.0L) {
		return -powl(-x, 0.25L);
	}
	return powl(x, 0.25L);
#	endif
}

#endif /* !MC_FHRT_H */

/* EOF */
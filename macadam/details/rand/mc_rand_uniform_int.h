//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_uniform_int.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randu.h>

#ifndef MC_RAND_UNIFORM_INT_H
#define MC_RAND_UNIFORM_INT_H

#pragma mark - mc_rand_uniform_int -

MC_TARGET_FUNC int mc_rand_uniform_int(int a, int b)
{
//!# Uniform int distribution generator.
	int r;
	if (!(a >= b)) {
		const float u = mc_randuf();
		const float c = mc_cast(float, a);
		const float d = mc_cast(float, b);
		r             = mc_cast(int, (c + (u * (d - (c + 1.0f)))));
		r             = r > b ? b : (r < a ? a : r);
	} else {
		r = a;
	}
	return r;
}

#pragma mark - mc_rand_uniform_int64 -

MC_TARGET_FUNC int64_t mc_rand_uniform_int64(int64_t a, int64_t b)
{
//!# Uniform int distribution generator.
	int64_t r;
	if (!(a >= b)) {
		const double u = mc_randu();
		const double c = mc_cast(double, a);
		const double d = mc_cast(double, b);
		r              = mc_cast(int64_t, (c + (u * (d - (c + 1.0)))));
		r              = r > b ? b : (r < a ? a : r);
	} else {
		r = a;
	}
	return r;
}

#endif /* !MC_RAND_UNIFORM_INT_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_uniform.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randu.h>

#ifndef MC_RAND_UNIFORM_H
#define MC_RAND_UNIFORM_H

#pragma mark - mc_rand_uniform -

MC_TARGET_FUNC float mc_rand_uniformf(float a, float b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const float u =  mc_randuf();
	return a * (1.0f - u) + b * u;
}

MC_TARGET_FUNC double mc_rand_uniform(double a, double b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const double u =  mc_randu();
	return a * (1.0 - u) + b * u;
}

MC_TARGET_FUNC long double mc_rand_uniforml(long double a, long double b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const long double u =  mc_randul();
	return a * (1.0L - u) + b * u;
}

#endif /* !MC_RAND_UNIFORM_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_randn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randg.h>

#ifndef MC_RANDN_H
#define MC_RANDN_H

#pragma mark - mc_randn -

MC_TARGET_FUNC float mc_randnf(float mu, float std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randgf();
}

MC_TARGET_FUNC double mc_randn(double mu, double std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randg();
}

MC_TARGET_FUNC long double mc_randnl(long double mu, long double std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randgl();
}

#endif /* !MC_RANDN_H */

/* EOF */
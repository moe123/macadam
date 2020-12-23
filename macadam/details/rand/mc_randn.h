//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_randn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randg.h>

#ifndef MC_RANDN_H
#define MC_RANDN_H

#pragma mark - mc_randn -

MC_TARGET_FUNC float mc_randnf(float mu, float stddev)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + stddev * mc_randgf();
}

MC_TARGET_FUNC double mc_randn(double mu, double stddev)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + stddev * mc_randg();
}

MC_TARGET_FUNC long double mc_randnl(long double mu, long double stddev)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + stddev * mc_randgl();
}

#endif /* !MC_RANDN_H */

/* EOF */
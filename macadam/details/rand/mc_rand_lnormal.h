//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_lnormal.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/rand/mc_randn.h>

#ifndef MC_RAND_LNORMAL_H
#define MC_RAND_LNORMAL_H

#pragma mark - mc_rand_lnormal -

MC_TARGET_FUNC float mc_rand_lnormalf(float mu, float stdd)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expf(mc_randnf(mu, stdd));
}

MC_TARGET_FUNC double mc_rand_lnormal(double mu, double stdd)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_exp(mc_randn(mu, stdd));
}

MC_TARGET_FUNC long double mc_rand_lnormall(long double mu, long double stdd)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expl(mc_randnl(mu, stdd));
}

#endif /* !MC_RAND_LNORMAL_H */

/* EOF */
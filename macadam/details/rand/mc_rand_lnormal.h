//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_lnormal.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/rand/mc_randn.h>

#ifndef MC_RAND_LNORMAL_H
#define MC_RAND_LNORMAL_H

#pragma mark - mc_rand_lnormal -

MC_TARGET_FUNC float mc_rand_lnormalf(float mu, float stddev)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expf(mc_randnf(mu, stddev));
}

MC_TARGET_FUNC double mc_rand_lnormal(double mu, double stddev)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_exp(mc_randn(mu, stddev));
}

MC_TARGET_FUNC long double mc_rand_lnormall(long double mu, long double stddev)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expl(mc_randnl(mu, stddev));
}

#endif /* !MC_RAND_LNORMAL_H */

/* EOF */
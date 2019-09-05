//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand_pareto.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/rand/mc_rand_exponential.h>

#ifndef MC_RAND_PARETO_H
#define MC_RAND_PARETO_H

#pragma mark - mc_rand_pareto -

MC_TARGET_FUNC float mc_rand_paretof(float a)
{
//!# Pareto distribution generator.
	const float x = mc_rand_exponentialf(1.0f) / a;
	return mc_expf(x) - 1.0f;
}

MC_TARGET_FUNC double mc_rand_pareto(double a)
{
//!# Pareto distribution generator.
	const double x = mc_rand_exponential(1.0) / a;
	return mc_exp(x) - 1.0;
}

MC_TARGET_FUNC long double mc_rand_paretol(long double a)
{
//!# Pareto distribution generator.
	const long double x = mc_rand_exponentiall(1.0L) / a;
	return mc_expl(x) - 1.0L;
}

#endif /* !MC_RAND_PARETO_H */

/* EOF */
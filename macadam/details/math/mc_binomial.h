//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_binomial.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_choose.h>

#ifndef MC_BINOMIAL_H
#define MC_BINOMIAL_H

MC_TARGET_FUNC float mc_binomialf(unsigned int n, unsigned int k)
{
	return mc_choosef(n, k);
}

MC_TARGET_FUNC double mc_binomial(unsigned int n, unsigned int k)
{
	return mc_choose(n, k);
}

MC_TARGET_FUNC long double mc_binomiall(unsigned int n, unsigned int k)
{
	return mc_choosel(n, k);
}

#endif /* !MC_BINOMIAL_H */

/* EOF */
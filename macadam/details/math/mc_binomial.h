//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_binomial.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_choose.h>

#ifndef MC_BINOMIAL_H
#define MC_BINOMIAL_H

#	define mc_binomialf(n, k) mc_choosef(n, k)
#	define mc_binomial(n, k)  mc_choose(n, k)
#	define mc_binomiall(n, k) mc_choosel(n, k)

#endif /* !MC_BINOMIAL_H */

/* EOF */
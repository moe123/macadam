//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logradix.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>

#ifndef MC_LOGRADIX_H
#define MC_LOGRADIX_H

#pragma mark - mc_logradix -

MC_TARGET_FUNC float mc_logradixf(unsigned int n, float x)
{
	return mc_logf(x) / mc_logf(mc_cast(float, n));
}

MC_TARGET_FUNC double mc_logradix(unsigned int n, double x)
{
	return mc_log(x) / mc_log(mc_cast(double, n));
}

MC_TARGET_FUNC long double mc_logradixl(unsigned int n, long double x)
{
	return mc_logl(x) / mc_logl(mc_cast(long double, n));
}

#endif /* !MC_LOGRADIX_H */

/* EOF */
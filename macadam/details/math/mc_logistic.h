//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logistic.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>

#ifndef MC_LOGISTIC_H
#define MC_LOGISTIC_H

#pragma mark - mc_logistic -

MC_TARGET_FUNCTION float mc_logisticf(float x, float lambda)
{
	return 1.0f / (mc_expf(-lambda * x) + 1.0f);
}

MC_TARGET_FUNCTION double mc_logistic(double x, double lambda)
{
	return 1.0 / (mc_exp(-lambda * x) + 1.0);
}

MC_TARGET_FUNCTION long double mc_logisticl(long double x, long double lambda)
{
	return 1.0L / (mc_expl(-lambda * x) + 1.0L);
}

#endif /* !MC_LOGISTIC_H */

/* EOF */
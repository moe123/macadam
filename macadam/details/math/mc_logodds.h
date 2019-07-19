//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logodds.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>

#ifndef MC_LOGODDS_H
#define MC_LOGODDS_H

#pragma mark - mc_logodds -

MC_TARGET_FUNC float mc_logoddsf(float x, float l)
{

	const float a = 1.0f / x - 1.0f;
	const float b = 1.0f / l;
	return -mc_logf(a) * b;
}

MC_TARGET_FUNC double mc_logodds(double x, double l)
{
	const double a = 1.0 / x - 1.0;
	const double b = 1.0 / l;
	return -mc_log(a) * b;
}

MC_TARGET_FUNC long double mc_logoddsl(long double x, long double l)
{
	const long double a = 1.0L / x - 1.0L;
	const long double b = 1.0L / l;
	return -mc_logl(a) * b;
}
#endif /* !MC_LOGODDS_H */

/* EOF */
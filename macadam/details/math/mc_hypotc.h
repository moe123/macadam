//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hypotc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_HYPOTC_H
#define MC_HYPOTC_H

#pragma mark - mc_hypotc -

MC_TARGET_FUNC float mc_hypotcf(float x, float y, float z)
{
	return mc_sqrtf((x * x) + (y * y) + (z * z));
}

MC_TARGET_FUNC double mc_hypotc(double x, double y, double z)
{
	return mc_sqrt((x * x) + (y * y) + (z * z));
}

MC_TARGET_FUNC long double mc_hypotcl(long double x, long double y, long double z)
{
	return mc_sqrtl((x * x) + (y * y) + (z * z));
}

#endif /* !MC_HYPOTC_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_huberweight.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_huberloss.h>

#ifndef MC_HUBERWEIGHT_H
#define MC_HUBERWEIGHT_H

#pragma mark - mc_huberweight -

MC_TARGET_FUNC float mc_huberweightf(float r)
{
	const float c = 1.345f;
	const float s = 1.0f;
	return mc_huberlossf(r, c, s, 0);
}

MC_TARGET_FUNC double mc_huberweight(double r)
{
	const double c = 1.345;
	const double s = 1.0;
	return mc_huberloss(r, c, s, 0);
}

MC_TARGET_FUNC long double mc_huberweightl(long double r)
{
	const long double c = 1.345L;
	const long double s = 1.0L;
	return mc_huberlossl(r, c, s, 0);
}

#endif /* !MC_HUBERWEIGHT_H */

/* EOF */
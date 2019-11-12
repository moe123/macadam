//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unit1x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_l2norm1x2.h>

#ifndef MC_UNIT1X2_H
#define MC_UNIT1X2_H

#pragma mark - mc_unit1x2 -

MC_TARGET_FUNC void mc_unit1x2f(float x[2])
{
	const float scale = 1.0f / mc_l2norm1x2f(x);
	x[0] = x[0] * scale;
	x[1] = x[1] * scale;
}

MC_TARGET_FUNC void mc_unit1x2(double x[2])
{
	const double scale = 1.0 / mc_l2norm1x2(x);
	x[0] = x[0] * scale;
	x[1] = x[1] * scale;
}

MC_TARGET_FUNC void mc_unit1x2l(long double x[2])
{
	const long double scale = 1.0L / mc_l2norm1x2l(x);
	x[0] = x[0] * scale;
	x[1] = x[1] * scale;
}

#endif /* !MC_UNIT1X2_H */

/* EOF */
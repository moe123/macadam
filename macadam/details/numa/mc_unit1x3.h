//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unit1x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_norm1x3.h>

#ifndef MC_UNIT1X3_H
#define MC_UNIT1X3_H

#pragma mark - mc_unit1x3 -

MC_TARGET_FUNC void mc_unit1x3f(float x[MC_TARGET_NONNULL 3])
{
	const float scale = 1.0f / mc_norm1x3f(x);
	x[0]              = x[0] * scale;
	x[1]              = x[1] * scale;
	x[2]              = x[2] * scale;
}

MC_TARGET_FUNC void mc_unit1x3(double x[MC_TARGET_NONNULL 3])
{
	const double scale = 1.0 / mc_norm1x3(x);
	x[0]               = x[0] * scale;
	x[1]               = x[1] * scale;
	x[2]               = x[2] * scale;
}

MC_TARGET_FUNC void mc_unit1x3l(long double x[MC_TARGET_NONNULL 3])
{
	const long double scale = 1.0L / mc_norm1x3l(x);
	x[0]                    = x[0] * scale;
	x[1]                    = x[1] * scale;
	x[2]                    = x[2] * scale;
}

#endif /* !MC_UNIT1X3_H */

/* EOF */
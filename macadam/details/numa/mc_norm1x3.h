//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_norm1x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_NORM1X3_H
#define MC_NORM1X3_H

#pragma mark - mc_norm1x3 -

MC_TARGET_PROC float mc_norm1x3f(const float x[MC_TARGET_NONNULL 3])
{
	return mc_sqrtf(mc_raise2f(x[0]) + mc_raise2f(x[1]) + mc_raise2f(x[2]));
}

MC_TARGET_PROC double mc_norm1x3(const double x[MC_TARGET_NONNULL 3])
{
	return mc_sqrt(mc_raise2(x[0]) + mc_raise2(x[1]) + mc_raise2(x[2]));
}

MC_TARGET_PROC long double mc_norm1x3l(const long double x[MC_TARGET_NONNULL 3])
{
	return mc_sqrtl(mc_raise2l(x[0]) + mc_raise2l(x[1]) + mc_raise2l(x[2]));
}

#endif /* !MC_NORM1X3_H */

/* EOF */
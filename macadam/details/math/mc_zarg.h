//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zarg.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_atan2.h>

#ifndef MC_ZARG_H
#define MC_ZARG_H

#pragma mark - mc_zarg -

MC_TARGET_PROC float mc_zargf(float z_r, float z_i)
{
	return mc_atan2f(z_i, z_r);
}

MC_TARGET_PROC double mc_zarg(double z_r, double z_i)
{
	return mc_atan2(z_i, z_r);
}

MC_TARGET_PROC long double mc_zargl(long double z_r, long double z_i)
{
	return mc_atan2l(z_i, z_r);
}

#endif /* !MC_ZARG_H */

/* EOF */
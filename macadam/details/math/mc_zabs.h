//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zabs.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_hypot.h>

#ifndef MC_ZABS_H
#define MC_ZABS_H

#pragma mark - mc_zabs -

MC_TARGET_PROC float mc_zabsf(float z_r, float z_i)
{
	return mc_hypotf(z_i, z_r);
}

MC_TARGET_PROC double mc_zabs(double z_r, double z_i)
{
	return mc_hypot(z_i, z_r);
}

MC_TARGET_PROC long double mc_zabsl(long double z_r, long double z_i)
{
	return mc_hypotl(z_i, z_r);
}

#endif /* !MC_ZABS_H */

/* EOF */
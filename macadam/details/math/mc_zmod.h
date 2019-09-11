//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zmod.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/math/mc_znorm.h>

#ifndef MC_ZMOD_H
#define MC_ZMOD_H

#pragma mark - mc_zmod -

MC_TARGET_PROC float mc_zmodf(float z_r, float z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return mc_sqrtf(mc_znormf(z_r, z_i));
}

MC_TARGET_PROC double mc_zmod(double z_r, double z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return mc_sqrt(mc_znorm(z_r, z_i));
}

MC_TARGET_PROC long double mc_zmodl(long double z_r, long double z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return mc_sqrtl(mc_znorml(z_r, z_i));
}

#endif /* !MC_ZMOD_H */

/* EOF */
// mc_znorm.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>

#ifndef MC_ZNORM_H
#define MC_ZNORM_H

#pragma mark - mc_znorm -

MC_TARGET_PROC float mc_znormf(float z_r, float z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return z_r * z_r + z_i * z_i;
}

MC_TARGET_PROC double mc_znorm(double z_r, double z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return z_r * z_r + z_i * z_i;
}

MC_TARGET_PROC long double mc_znorml(long double z_r, long double z_i)
{
	if (mc_isinf(z_r)) {
		return MCK_INFP;
	}
	if (mc_isinf(z_i)) {
		return MCK_INFP;
	}
	return z_r * z_r + z_i * z_i;
}

#endif /* !MC_ZNORM_H */

/* EOF */
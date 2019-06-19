//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sinc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SINC_H
#define MC_SINC_H

#pragma mark - mc_sinc -

static MC_TARGET_INLINE float mc_sincf(float x)
{
	//!# \note: f(0)=1, i.e removable singularity.
	const float pix = MCK_KF(MCK_PI) * x;
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0f : ::sinf(pix) / pix;
#	else
	return x == 0 ? 1.0f : sinf(pix) / pix;
#	endif
}

static MC_TARGET_INLINE double mc_sinc(double x)
{
	//!# \note: f(0)=1, i.e removable singularity.
	const double pix = MCK_K(MCK_PI) * x;
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0 : ::sin(pix) / pix;
#	else
	return x == 0 ? 1.0 : sin(pix) / pix;
#	endif
}

static MC_TARGET_INLINE long double mc_sincl(long double x)
{
	//!# \note: f(0)=1, i.e removable singularity.
#	if MC_TARGET_C99 && defined(M_PIl)
	const long double pix = M_PIl * x;
#	else
	const long double pix = MCK_KL(MCK_PI) * x;
#	endif
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0L : ::sinl(pix) / pix;
#	else
	return x == 0 ? 1.0L : sinl(pix) / pix;
#	endif
}

#pragma mark - mc_unnsinc -

static MC_TARGET_INLINE float mc_unnsincf(float x)
{
	//!# \note: f(0)=1, i.e removable singularity.
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0f : ::sinf(x) / x;
#	else
	return x == 0 ? 1.0f : sinf(x) / x;
#	endif
}

static MC_TARGET_INLINE double mc_unnsinc(double x)
{
	//!# \note: f(0)=1, i.e removable singularity.
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0 : ::sin(x) / x;
#	else
	return x == 0 ? 1.0 : sin(x) / x;
#	endif
}

static MC_TARGET_INLINE long double mc_unnsincl(long double x)
{
	//!# \note: f(0)=1, i.e removable singularity.
#	if MC_TARGET_CPP98
	return x == 0 ? 1.0L : ::sinl(x) / x;
#	else
	return x == 0 ? 1.0L : sinl(x) / x;
#	endif
}

#endif /* !MC_SINC_H */

/* EOF */
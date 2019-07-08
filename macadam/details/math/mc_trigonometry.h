//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trigonometry.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_TRIGONOMETRY_H
#define MC_TRIGONOMETRY_H

#pragma mark - mc_sec -

static MC_TARGET_INLINE float mc_secf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::cosf(x);
#	else
	return 1.0f / cosf(x);
#	endif
}

static MC_TARGET_INLINE double mc_sec(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::cos(x);
#	else
	return 1.0 / cos(x);
#	endif
}

static MC_TARGET_INLINE long double mc_secl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::cosl(x);
#	else
	return 1.0L / cosl(x);
#	endif
}

#pragma mark - mc_csc -

static MC_TARGET_INLINE float mc_cscf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::sinf(x);
#	else
	return 1.0f / sinf(x);
#	endif
}

static MC_TARGET_INLINE double mc_csc(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::sin(x);
#	else
	return 1.0 / sin(x);
#	endif
}

static MC_TARGET_INLINE long double mc_cscl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::sinl(x);
#	else
	return 1.0L / sinl(x);
#	endif
}

#pragma mark - mc_sech -

static MC_TARGET_INLINE float mc_sechf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::coshf(x);
#	else
	return 1.0f / coshf(x);
#	endif
}

static MC_TARGET_INLINE double mc_sech(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::cosh(x);
#	else
	return 1.0 / cosh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_sechl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::coshl(x);
#	else
	return 1.0L / coshl(x);
#	endif
}

#pragma mark - mc_csch -

static MC_TARGET_INLINE float mc_cschf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::sinhf(x);
#	else
	return 1.0f / sinhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_csch(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::sinh(x);
#	else
	return 1.0 / sinh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_cschl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::sinhl(x);
#	else
	return 1.0L / sinhl(x);
#	endif
}

#endif /* !MC_TRIGONOMETRY_H */

/* EOF */
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

#pragma mark - mc_cot -

static MC_TARGET_INLINE float mc_cotf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::tanf(x);
#	else
	return 1.0f / tanf(x);
#	endif
}

static MC_TARGET_INLINE double mc_cot(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::tan(x);
#	else
	return 1.0 / tan(x);
#	endif
}

static MC_TARGET_INLINE long double mc_cotl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::tanl(x);
#	else
	return 1.0L / tanl(x);
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

#pragma mark - mc_coth -

static MC_TARGET_INLINE float mc_cothf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::tanhf(x);
#	else
	return 1.0f / tanhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_coth(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::tanh(x);
#	else
	return 1.0 / tanh(x);
#	endif
}

static MC_TARGET_INLINE double mc_cothl(double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::tanhl(x);
#	else
	return 1.0L / tanhl(x);
#	endif
}

#pragma mark - mc_acsc -

static MC_TARGET_INLINE float mc_acscf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::asinf(x);
#	else
	return 1.0f / asinf(x);
#	endif
}

static MC_TARGET_INLINE double mc_acsc(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::asin(x);
#	else
	return 1.0 / asin(x);
#	endif
}

static MC_TARGET_INLINE long double mc_acscl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::asinl(x);
#	else
	return 1.0L / asinl(x);
#	endif
}

#pragma mark - mc_asec -

static MC_TARGET_INLINE float mc_asecf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::acosf(x);
#	else
	return 1.0f / acosf(x);
#	endif
}

static MC_TARGET_INLINE double mc_asec(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::acos(x);
#	else
	return 1.0 / acos(x);
#	endif
}

static MC_TARGET_INLINE long double mc_asecl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::acosl(x);
#	else
	return 1.0L / acosl(x);
#	endif
}

#pragma mark - mc_acot -

static MC_TARGET_INLINE float mc_acotf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::atan(x);
#	else
	return 1.0f / atan(x);
#	endif
}

static MC_TARGET_INLINE double mc_acot(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::atan(x);
#	else
	return 1.0 / atan(x);
#	endif
}

static MC_TARGET_INLINE long double mc_acotl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::atan(x);
#	else
	return 1.0L / atan(x);
#	endif
}

#pragma mark - mc_asech -

static MC_TARGET_INLINE float mc_asechf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::acoshf(x);
#	else
	return 1.0f / acoshf(x);
#	endif
}

static MC_TARGET_INLINE double mc_asech(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::acosh(x);
#	else
	return 1.0 / acosh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_asechl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::acoshl(x);
#	else
	return 1.0L / acoshl(x);
#	endif
}

#pragma mark - mc_acsch -

static MC_TARGET_INLINE float mc_acschf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::asinhf(x);
#	else
	return 1.0f / asinhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_acsch(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::asinh(x);
#	else
	return 1.0 / asinh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_acschl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::asinhl(x);
#	else
	return 1.0L / asinhl(x);
#	endif
}

#pragma mark - mc_acoth -

static MC_TARGET_INLINE float mc_acothf(float x)
{
#	if MC_TARGET_CPP98
	return 1.0f / ::atanhf(x);
#	else
	return 1.0f / atanhf(x);
#	endif
}

static MC_TARGET_INLINE double mc_acoth(double x)
{
#	if MC_TARGET_CPP98
	return 1.0 / ::atanh(x);
#	else
	return 1.0 / atanh(x);
#	endif
}

static MC_TARGET_INLINE long double mc_acothl(long double x)
{
#	if MC_TARGET_CPP98
	return 1.0L / ::atanhl(x);
#	else
	return 1.0L / atanhl(x);
#	endif
}

#endif /* !MC_TRIGONOMETRY_H */

/* EOF */
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
	return ::asinf(1.0f / x);
#	else
	return asinf(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_acsc(double x)
{
#	if MC_TARGET_CPP98
	return ::asin(1.0 / x);
#	else
	return asin(1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_acscl(long double x)
{
#	if MC_TARGET_CPP98
	return ::asinl(1.0L / x);
#	else
	return asinl(1.0L / x);
#	endif
}

#pragma mark - mc_asec -

static MC_TARGET_INLINE float mc_asecf(float x)
{
#	if MC_TARGET_CPP98
	return ::acosf(1.0f / x);
#	else
	return acosf(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_asec(double x)
{
#	if MC_TARGET_CPP98
	return ::acos(1.0 / x);
#	else
	return acos(1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_asecl(long double x)
{
#	if MC_TARGET_CPP98
	return ::acosl(1.0L / x);
#	else
	return acosl(1.0L / x);
#	endif
}

#pragma mark - mc_acot -

static MC_TARGET_INLINE float mc_acotf(float x)
{
#	if MC_TARGET_CPP98
	return ::atan(1.0f / x);
#	else
	return atan(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_acot(double x)
{
#	if MC_TARGET_CPP98
	return ::atan(1.0 / x);
#	else
	return atan(1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_acotl(long double x)
{
#	if MC_TARGET_CPP98
	return ::atan(1.0L / x);
#	else
	return atan(1.0L / x);
#	endif
}

#pragma mark - mc_asech -

static MC_TARGET_INLINE float mc_asechf(float x)
{
#	if MC_TARGET_CPP98
	return ::acoshf(1.0f / x);
#	else
	return acoshf(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_asech(double x)
{
#	if MC_TARGET_CPP98
	return ::acosh(1.0 / x);
#	else
	return acosh(1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_asechl(long double x)
{
#	if MC_TARGET_CPP98
	return ::acoshl(1.0L / x);
#	else
	return acoshl(1.0L / x);
#	endif
}

#pragma mark - mc_acsch -

static MC_TARGET_INLINE float mc_acschf(float x)
{
#	if MC_TARGET_CPP98
	return ::asinhf(1.0f / x);
#	else
	return asinhf(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_acsch(double x)
{
#	if MC_TARGET_CPP98
	return ::asinh(1.0 / x);
#	else
	return asinh(1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_acschl(long double x)
{
#	if MC_TARGET_CPP98
	return ::asinhl(1.0L / x);
#	else
	return asinhl(1.0L / x);
#	endif
}

#pragma mark - mc_acoth -

static MC_TARGET_INLINE float mc_acothf(float x)
{
#	if MC_TARGET_CPP98
	return ::atanhf(1.0f / x);
#	else
	return atanhf(1.0f / x);
#	endif
}

static MC_TARGET_INLINE double mc_acoth(double x)
{
#	if MC_TARGET_CPP98
	return ::atanh(1.0 / x);
#	else
	return atanh( 1.0 / x);
#	endif
}

static MC_TARGET_INLINE long double mc_acothl(long double x)
{
#	if MC_TARGET_CPP98
	return ::atanhl(1.0L / x);
#	else
	return atanhl(1.0L / x);
#	endif
}

#endif /* !MC_TRIGONOMETRY_H */

/* EOF */
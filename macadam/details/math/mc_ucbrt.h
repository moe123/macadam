//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ucbrt.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_UCBRT_H
#define MC_UCBRT_H

#pragma mark - mc_ucbrt -

MC_TARGET_FUNC float mc_ucbrtf(const unsigned int x)
{
#	if MC_TARGET_CPP98
	return x < 0x1000001U ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return x < 0x1000001U  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_ucbrt(const unsigned int x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_ucbrtl(const unsigned int x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}

#pragma mark - mc_ulcbrt -

MC_TARGET_FUNC float mc_ulcbrtf(const unsigned long x)
{
#	if MC_TARGET_CPP98
	return x < 0x1000001 ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return x < 0x1000001  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_ulcbrt(const unsigned long x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_ulcbrtl(const unsigned long x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}

#pragma mark - mc_ullcbrt -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
MC_TARGET_FUNC float mc_ullcbrtf(const unsigned long long x)
{
#	if MC_TARGET_CPP98
	return x < 0x1000001 ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return x < 0x1000001  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_ullcbrt(const unsigned long long x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_ullcbrtl(const unsigned long long x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}
#	else
#	define mc_ullcbrtf mc_ulcbrtf
#	define mc_ullcbrt  mc_ulcbrt
#	define mc_ullcbrtl mc_ullcbrt
#	endif

#endif /* !MC_UCBRT_H */

/* EOF */
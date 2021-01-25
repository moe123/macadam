//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_icbrt.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_absmag.h>

#ifndef MC_ICBRT_H
#define MC_ICBRT_H

#pragma mark - mc_icbrt -

MC_TARGET_FUNC float mc_icbrtf(const int x)
{
#	if MC_TARGET_CPP98
	return mc_iabs(x) < 0x1000001 ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return mc_iabs(x) < 0x1000001  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_icbrt(const int x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_icbrtl(const int x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}

#pragma mark - mc_lcbrt -

MC_TARGET_FUNC float mc_lcbrtf(const long x)
{
#	if MC_TARGET_CPP98
	return mc_labs(x) < 0x1000001 ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return mc_labs(x) < 0x1000001  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_lcbrt(const long x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_lcbrtl(const long x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}

#pragma mark - mc_llcbrt -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
MC_TARGET_FUNC float mc_llcbrtf(const long long x)
{
#	if MC_TARGET_CPP98
	return mc_llabs(x) < 0x1000001 ? (::cbrtf(mc_cast(float, x))) : mc_cast_expr(float, ::cbrt(mc_cast(double, x)));
#	else
	return mc_llabs(x) < 0x1000001  ? (cbrtf(mc_cast(float, x)))  : mc_cast(float, cbrt(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_llcbrt(const long long x)
{
#	if MC_TARGET_CPP98
	return ::cbrt(mc_cast(double, x));
#	else
	return cbrt(mc_cast(double, x));
#	endif
}

MC_TARGET_FUNC long double mc_llcbrtl(const long long x)
{
#	if MC_TARGET_CPP98
	return ::cbrtl(mc_cast(long double, x));
#	else
	return cbrtl(mc_cast(long double, x));
#	endif
}
#	else
#	define mc_llcbrtf mc_lcbrtf
#	define mc_llcbrt  mc_lcbrt
#	define mc_llcbrtl mc_llcbrt
#	endif

#endif /* !MC_ICBRT_H */

/* EOF */
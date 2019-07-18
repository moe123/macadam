//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_besselj.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_BESSELJ_H
#define MC_BESSELJ_H

#	if MC_TARGET_MSVC_CPP
#		define j0 _j0
#		define j1 _j1
#		define jn _jn
#	endif

#pragma mark - mc_besselj0 -

MC_TARGET_FUNC float mc_besselj0f(float x)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::j0(mc_cast(double, x)));
#	else
	return mc_cast(float, j0(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_besselj0(double x)
{
#	if MC_TARGET_CPP98
	return ::j0(x);
#	else
	return j0(x);
#	endif
}

MC_TARGET_FUNC long double mc_besselj0l(long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::j0(mc_cast(double, x)));
#	else
	return mc_cast(long double, j0(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besselj1 -

MC_TARGET_FUNC float mc_besselj1f(float x)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::j1(mc_cast(double, x)));
#	else
	return mc_cast(float, j1(mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_besselj1(double x)
{
#	if MC_TARGET_CPP98
	return ::j1(x);
#	else
	return j1(x);
#	endif
}

MC_TARGET_FUNC long double mc_besselj1l(long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::j1(mc_cast(double, x)));
#	else
	return mc_cast(long double, j1(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besseljn -

MC_TARGET_FUNC float mc_besseljnf(int n, float x)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::jn(n, mc_cast(double, x)));
#	else
	return mc_cast(float, jn(n, mc_cast(double, x)));
#	endif
}

MC_TARGET_FUNC double mc_besseljn(int n, double x)
{
#	if MC_TARGET_CPP98
	return ::jn(n, x);
#	else
	return jn(n, x);
#	endif
}

MC_TARGET_FUNC long double mc_besseljnl(int n, long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::jn(n, mc_cast(double, x)));
#	else
	return mc_cast(long double, jn(n, mc_cast(double, x)));
#	endif
}

#endif /* !MC_BESSELJ_H */

/* EOF */
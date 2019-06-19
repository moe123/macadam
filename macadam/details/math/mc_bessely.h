//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_bessely.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_BESSELY_H
#define MC_BESSELY_H

#	if MC_TARGET_MSVC_CPP
#		define y0 _y0
#		define y1 _y1
#		define yn _yn
#	endif

#pragma mark - mc_bessely0 -

static MC_TARGET_INLINE float mc_bessely0f(float x)
{
#	if MC_TARGET_MSVC_CPP
	
#	endif
#	if MC_TARGET_CPP98
	return mc_cast(float, ::y0(mc_cast(double, x)));
#	else
	return mc_cast(float, y0(mc_cast(double, x)));
#	endif
}

static MC_TARGET_INLINE double mc_bessely0(double x)
{
#	if MC_TARGET_CPP98
	return ::y0(x);
#	else
	return y0(x);
#	endif
}

static MC_TARGET_INLINE long double mc_bessely0l(long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::y0(mc_cast(double, x)));
#	else
	return mc_cast(long double, y0(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_bessely1 -

static MC_TARGET_INLINE float mc_bessely1f(float x)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::y1(mc_cast(double, x)));
#	else
	return mc_cast(float, y1(mc_cast(double, x)));
#	endif
}

static MC_TARGET_INLINE double mc_bessely1(double x)
{
#	if MC_TARGET_CPP98
	return ::y1(x);
#	else
	return y1(x);
#	endif
}

static MC_TARGET_INLINE long double mc_bessely1l(long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::y1(mc_cast(double, x)));
#	else
	return mc_cast(long double, y1(mc_cast(double, x)));
#	endif
}

#pragma mark - mc_besselyn -

static MC_TARGET_INLINE float mc_besselynf(int n, float x)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::yn(n, mc_cast(double, x)));
#	else
	return mc_cast(float, yn(n, mc_cast(double, x)));
#	endif
}

static MC_TARGET_INLINE double mc_besselyn(int n, double x)
{
#	if MC_TARGET_CPP98
	return ::yn(n, x);
#	else
	return yn(n, x);
#	endif
}

static MC_TARGET_INLINE long double mc_besselynl(int n, long double x)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::yn(n, mc_cast(double, x)));
#	else
	return mc_cast(long double, yn(n, mc_cast(double, x)));
#	endif
}

#endif /* !MC_BESSELY_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_scalb.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SCALB_H
#define MC_SCALB_H

#pragma mark - mc_scalb -

#	if MC_TARGET_MSVC_CPP

MC_TARGET_FUNC float mc_scalbf(float x, float y)
{ return ::_scalbf(mc_cast(float, x), mc_cast(long, y)); }

MC_TARGET_FUNC double mc_scalb(double x, double y)
{ return ::_scalb(mc_cast(double, x), mc_cast(long, y)); }

MC_TARGET_FUNC long double mc_scalbl(long double x, long double y)
{ return mc_cast(long double, ::_scalb(mc_cast(double, x), mc_cast(long, y))); }

#	elif defined(__APPLE__) && defined(__MACH__)
MC_TARGET_FUNC float mc_scalbf(float x, float y)
{
#	if MC_TARGET_CPP98
	return mc_cast(float, ::scalb(mc_cast(double, x), mc_cast(double, y)));
#	else
	return mc_cast(float, scalb(mc_cast(double, x), mc_cast(double, y)));
#	endif
}

#	define mc_scalb scalb

MC_TARGET_FUNC long double mc_scalbl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::scalb(mc_cast(double, x), mc_cast(double, y)));
#	else
	return mc_cast(long double, scalb(mc_cast(double, x), mc_cast(double, y)));
#	endif
}
#	else
#	define mc_scalbf scalbf
#	define mc_scalb  scalb
#	define mc_scalbl scalbl
#	endif

#endif /* !MC_SCALB_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sinhcosh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SINHCOSH_H
#define MC_SINHCOSH_H

#pragma mark - mc_sinhcosh -

static MC_TARGET_INLINE void mc_sinhcoshf(float x, float * sinhp, float * coshp)
{
#	if MC_TARGET_CPP98
	*sinhp = ::sinhf(x);
	*coshp = ::coshf(x);
#	else
	*sinhp = sinhf(x);
	*coshp = coshf(x);
#	endif
}

static MC_TARGET_INLINE void mc_sinhcosh(double x, double * sinhp, double * coshp)
{
#	if MC_TARGET_CPP98
	*sinhp = ::sinh(x);
	*coshp = ::cosh(x);
#	else
	*sinhp = sinh(x);
	*coshp = cosh(x);
#	endif
}

static MC_TARGET_INLINE void mc_sinhcoshl(long double x, long double * sinhp, long double * coshp)
{
#	if MC_TARGET_CPP98
	*sinhp = ::sinhl(x);
	*coshp = ::coshl(x);
#	else
	*sinhp = sinhl(x);
	*coshp = coshl(x);
#	endif
}

#endif /* !MC_SINHCOSH_H */

/* EOF */
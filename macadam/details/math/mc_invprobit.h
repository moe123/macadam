//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_invprobit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_INVPROBIT_H
#define MC_INVPROBIT_H

#pragma mark - mc_invprobit -

static MC_TARGET_INLINE float mc_invprobitf(float x)
{
#	if MC_TARGET_CPP98
	return 0.5f * ::erfcf(-x * MCK_KF(MCK_1SQRT2));
#	else
	return 0.5f * erfcf(-x * MCK_KF(MCK_1SQRT2));
#	endif
}

static MC_TARGET_INLINE double mc_invprobit(double x)
{
#	if MC_TARGET_CPP98
	return 0.5 * ::erfc(-x * MCK_K(MCK_1SQRT2));
#	else
	return 0.5 * erfc(-x * MCK_K(MCK_1SQRT2));
#	endif
}

static MC_TARGET_INLINE long double mc_invprobitl(long double x)
{
#	if MC_TARGET_CPP98
	return 0.5L * ::erfcl(-x * MCK_KL(MCK_1SQRT2));
#	else
	return 0.5L * erfcl(-x * MCK_KL(MCK_1SQRT2));
#	endif
}

#endif /* !MC_INVPROBIT_H */

/* EOF */
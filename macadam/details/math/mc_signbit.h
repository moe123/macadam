//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_signbit.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SIGNBIT_H
#define MC_SIGNBIT_H

#pragma mark - mc_signbit -

#	if MC_TARGET_CPP98
#	define mc_signbit(x) ::signbit(x)
#	else
#	define mc_signbit(x) signbit(x)
#	endif

#endif /* !MC_SIGNBIT_H */

/* EOF */
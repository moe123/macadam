//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_isinf.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ISINF_H
#define MC_ISINF_H

#pragma mark - mc_isinf -

#	if MC_TARGET_CPP98
#	define mc_isinf(x) (::isinf(x) ? 1 : 0)
#	else
#	define mc_isinf(x) (isinf(x) ? 1 : 0)
#	endif

#endif /* !MC_ISINF_H */

/* EOF */
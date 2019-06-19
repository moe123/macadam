//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_invlogit.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_expit.h>

#ifndef MC_INVLOGIT_H
#define MC_INVLOGIT_H

#pragma mark - mc_invlogit -

#	define mc_invlogitf(x) mc_expitf(x)
#	define mc_invlogit(x)  mc_expit(x)
#	define mc_invlogitl(x) mc_expitl(x)

#endif /* !MC_INVLOGIT_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_lsame.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_BLAS_LSAME_H
#define MC_BLAS_LSAME_H

MC_TARGET_FUNC int mc_blas_lsame(const char ca, const char cb)
{
	return (ca == cb) ? 1 : toupper(ca) == toupper(cb) ? 1 : 0;
}

#endif /* !MC_BLAS_LSAME_H */

/* EOF */
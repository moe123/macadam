//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rootn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_nthroot.h>

#ifndef MC_ROOTN_H
#define MC_ROOTN_H

#pragma mark - mc_rootn -

MC_TARGET_FUNC float mc_rootnf(unsigned int n, float x)
{
	return mc_nthrootf(n, x);
}

MC_TARGET_FUNC double mc_rootn(unsigned int n, double x)
{
	return mc_nthroot(n, x);
}

MC_TARGET_FUNC long double mc_rootnl(unsigned int n, long double x)
{
	return mc_nthrootl(n, x);
}

#endif /* !MC_ROOTN_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nchoosek.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_NCHOOSEK_H
#define MC_NCHOOSEK_H

#pragma mark - mc_nchoosek -

MC_TARGET_FUNCTION unsigned int mc_nchoosek(unsigned int n, unsigned int k)
{
	if (n < MCLIMITS_UIMAX && k < MCLIMITS_UIMAX) {
		if (k > n) {
			return MCLIMITS_UIMAX;
		} else if ((k == 0) || (k == n)) {
			return 1;
		} else if ((k == 1) || (k == n - 1)) {
			return n;
		}
		return (n * mc_nchoosek(n - 1, k - 1)) / k;
	}
	return MCLIMITS_UIMAX;
}

#endif /* !MC_NCHOOSEK_H */

/* EOF */
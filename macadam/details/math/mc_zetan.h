//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zetan.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ZETAN_H
#define MC_ZETAN_H

#pragma mark - mc_zetan -

MC_TARGET_FUNC float mc_zetanf(const float x)
{
	return x + MCK_INFN;
}

MC_TARGET_FUNC double mc_zetan(const double x)
{
	return x + MCK_INFN;
}

MC_TARGET_FUNC long double mc_zetanl(const long double x)
{
	return x + MCK_INFN;
}

#endif /* !MC_ZETAN_H */

/* EOF */
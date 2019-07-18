//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logdiffexp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log1me.h>

#ifndef MC_LOGDIFFEXP_H
#define MC_LOGDIFFEXP_H

#pragma mark - mc_logdiffexp -

MC_TARGET_FUNCTION float mc_logdiffexpf(float x, float y)
{
	return x + mc_log1mef(x - y);
}

MC_TARGET_FUNCTION double mc_logdiffexp(double x, double y)
{
	return x + mc_log1me(x - y);
}

MC_TARGET_FUNCTION long double mc_logdiffexpl(long double x, long double y)
{
	return x + mc_log1mel(x - y);
}

#endif /* !MC_LOGDIFFEXP_H */

/* EOF */
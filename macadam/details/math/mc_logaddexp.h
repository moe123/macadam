//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_logaddexp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log1p.h>

#ifndef MC_LOGADDEXP_H
#define MC_LOGADDEXP_H

#pragma mark - mc_logaddexp -

static MC_TARGET_INLINE float mc_logaddexpf(float x, float y)
{
#	if MC_TARGET_CPP98
		return ((x == y)
			? (x + MCK_KF(MCK_LOG2))
			: ((x - y) > 0 ? (x + mc_log1pf(::expf(-(x - y)))) : y + mc_log1pf(::expf((x - y))))
		);
#	else
		return ((x == y)
			? (x + MCK_KF(MCK_LOG2))
			: ((x - y) > 0 ? x + mc_log1pf(expf(-(x - y))) : y + mc_log1pf(expf((x - y))))
		);
#	endif
}

static MC_TARGET_INLINE double mc_logaddexp(double x, double y)
{
#	if MC_TARGET_CPP98
		return ((x == y)
			? (x + MCK_K(MCK_LOG2))
			: ((x - y) > 0 ? (x + mc_log1p(::exp(-(x - y)))) : y + mc_log1p(::exp((x - y))))
		);
#	else
		return ((x == y)
			? (x + MCK_K(MCK_LOG2))
			: ((x - y) > 0 ? x + mc_log1p(exp(-(x - y))) : y + mc_log1p(exp((x - y))))
		);
#	endif
}

static MC_TARGET_INLINE long double mc_logaddexpl(long double x, long double y)
{
#	if MC_TARGET_CPP98
	return ((x == y)
		? (x + MCK_KL(MCK_LOG2))
		: ((x - y) > 0 ? (x + mc_log1pl(::expl(-(x - y)))) : y + mc_log1pl(::expl((x - y))))
	);
#	else
#	if MC_TARGET_C99 && defined(M_LN2l)
		return ((x == y)
			? (x + M_LN2l)
			: ((x - y) > 0 ? x + mc_log1pl(expl(-(x - y))) : y + mc_log1pl(expl((x - y))))
		);
#	else
		return ((x == y)
			? (x + MCK_K(MCK_LOG2))
			: ((x - y) > 0 ? x + mc_log1pl(expl(-(x - y))) : y + mc_log1pl(expl((x - y))))
		);
#	endif
#	endif
}

#endif /* !MC_LOGADDEXP_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_bessel.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_besseli.h>
#include <macadam/details/math/mc_besselj.h>
#include <macadam/details/math/mc_bessely.h>

#ifndef MC_BESSEL_H
#define MC_BESSEL_H

#	if MC_TARGET_EMBEDDED
#	define mc_i0f(x)    mc_besseli0f_v1(x)
#	define mc_i0(x)     mc_besseli0_v1(x)
#	define mc_i0l(x)    mc_besseli0l_v1(x)
#	else
#	define mc_i0f(x)    mc_besseli0f_v0(x)
#	define mc_i0(x)     mc_besseli0_v0(x)
#	define mc_i0l(x)    mc_besseli0l_v0(x)
#	endif

#	if MC_TARGET_EMBEDDED
#	define mc_i1f(x)    mc_besseli1f_v1(x)
#	define mc_i1(x)     mc_besseli1_v1(x)
#	define mc_i1l(x)    mc_besseli1l_v1(x)
#	else
#	define mc_i1f(x)    mc_besseli1f_v0(x)
#	define mc_i1(x)     mc_besseli1_v0(x)
#	define mc_i1l(x)    mc_besseli1l_v0(x)
#	endif

#	if MC_TARGET_EMBEDDED
#	define mc_inf(n, x) mc_besselinf_v1(n, x)
#	define mc_in(n, x)  mc_besselin_v1(n, x)
#	define mc_inl(n, x) mc_besselinl_v1(n, x)
#	else
#	define mc_inf(n, x) mc_besselinf_v0(n, x)
#	define mc_in(n, x)  mc_besselin_v0(n, x)
#	define mc_inl(n, x) mc_besselinl_v0(n, x)
#	endif

#	define mc_j0f(x)    mc_besselj0f(x)
#	define mc_j0(x)     mc_besselj0(x)
#	define mc_j0l(x)    mc_besselj0l(x)

#	define mc_j1f(x)    mc_besselj1f(x)
#	define mc_j1(x)     mc_besselj1(x)
#	define mc_j1l(x)    mc_besselj1l(x)

#	define mc_jnf(n, x) mc_besseljnf(n, x) 
#	define mc_jn(n, x)  mc_besseljn(n, x)
#	define mc_jnl(n, x) mc_besseljnl(n, x)

#	define mc_y0f(x)    mc_bessely0f(x)
#	define mc_y0(x)     mc_bessely0(x)
#	define mc_y0l(x)    mc_bessely0l(x)

#	define mc_y1f(x)    mc_bessely1f(x)
#	define mc_y1(x)     mc_bessely1(x)
#	define mc_y1l(x)    mc_bessely1l(x)

#	define mc_ynf(n, x) mc_besselynf(n, x) 
#	define mc_yn(n, x)  mc_besselyn(n, x)
#	define mc_ynl(n, x) mc_besselynl(n, x)

#endif /* !MC_BESSEL_H */

/* EOF */
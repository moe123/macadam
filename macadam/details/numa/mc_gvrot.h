//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gvrot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_hypot2.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmax.h>

#ifndef MC_GVROT_H
#define MC_GVROT_H

#pragma mark - mc_gvrot -

MC_TARGET_FUNC void mc_gvrotf(float a1, float a2, float tol, float * ch, float * sh)
{
//!# Givens rotation.
	float w;

//!# Sanity check.
	 w  = mc_hypot2f(a1, a2);
	*sh = w > tol ? a2 : 0.0f;
	*ch = mc_fabsf(a1) + mc_fmaxf(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0f ? *ch : *sh;
	*ch =  a1 < 0.0f ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0f /  mc_hypot2f(*ch, *sh);
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_FUNC void mc_gvrotff(float a1, float a2, float tol, double * ch, double * sh)
{
//!# Givens rotation.
	double w, a1d, a2d, told;

	a1d  = mc_cast(double, a1);
	a2d  = mc_cast(double, a2);
	told = mc_cast(double, tol);

//!# Sanity check.
	 w  = mc_hypot2(a1d, a2d);
	*sh = w > told ? a2d : 0.0;
	*ch = mc_fabs(a1d) + mc_fmax(w, told);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1d < 0.0 ? *ch : *sh;
	*ch =  a1d < 0.0 ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0 / mc_hypot2(*ch, *sh);
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_FUNC void mc_gvrot(double a1, double a2, double tol, double * ch, double * sh)
{
//!# Givens rotation.
	double w;

//!# Sanity check.
	 w  = mc_hypot2(a1, a2);
	*sh = w > tol ? a2 : 0.0;
	*ch = mc_fabs(a1) + mc_fmax(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0 ? *ch : *sh;
	*ch =  a1 < 0.0 ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0 / mc_hypot2(*ch, *sh);
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_FUNC void mc_gvrotl(long double a1, long double a2, long double tol, long double * ch, long double * sh)
{
//!# Givens rotation.
	long double w;

//!# Sanity check.
	 w  = mc_hypot2l(a1, a2);
	*sh = w > tol ? a2 : 0.0L;
	*ch = mc_fabsl(a1) + mc_fmaxl(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0L ? *ch : *sh;
	*ch =  a1 < 0.0L ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0L / mc_hypot2l(*ch, *sh);
	*ch = *ch * w;
	*sh = *sh * w;
}

#endif /* !MC_GVROT_H */

/* EOF */
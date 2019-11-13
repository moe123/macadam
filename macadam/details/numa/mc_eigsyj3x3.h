//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eigsyj3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_eye3x3.h>
#include <macadam/mcswap.h>

#ifndef MC_EIGSYJ3X3_H
#define MC_EIGSYJ3X3_H

#pragma mark - mc_eigsyj3x3 -

MC_TARGET_FUNC int mc_eigsyj3x3f(const float a[9], float e[3], float * v)
{
	int wantv     = mc_nonnull(v);
//!# Number of Jacobi iterations.
	int i         = 0;
//!# Too low values guard.
	const float m = MCLIMITS_TINYF;
//!# Max number of iteration for convergence.
	const int j   = 90;

//!# Copying upper triangle of the given symmetric system.
	float a11 = a[0], a12 = a[1], a13 = a[2];
	float             a22 = a[4], a23 = a[5];
	float                         a33 = a[8];

//!# Absolute values of off-diagonal items.
	float aa12 = mc_fabsf(a12);
	float aa13 = mc_fabsf(a13);
	float aa23 = mc_fabsf(a23);

//!# Working vectors. 
	float v11 = 1.0f, v12 = 0.0f, v13 = 0.0f;
	float v21 = 0.0f, v22 = 1.0f, v23 = 0.0f;
	float v31 = 0.0f, v32 = 0.0f, v33 = 1.0f;

//!# Jacobi rotation variables.
	float c, r, s, t, u;
	float apr, aqr, vpr, vqr;

//!# Applying Jacobi rotations until all off-diagonal items are 0.
	for (; aa12 + aa13 + aa23 > 0.0f; ++i) {
		if (i >= j) {
			e[0] = 1.0f, e[1] = 1.0f, e[2] = 1.0f;
			if (wantv) {
				mc_eye3x3f(v);
			}
			break;
		}
		if (aa12 >= aa13 && aa12 >= aa23) {
			u = a22 - a11;
			if (mc_fabsf(a12) < m * mc_fabsf(u)) {
				t = a12 / u;
			} else {
				r = 0.5f * u / a12;
				t = ((r >= 0.0f) ? 1.0f / (r + mc_sqrtf(1.0f + mc_raise2f(r))) : 1.0f / (r - mc_sqrtf(1.0f + mc_raise2f(r))));
			}
			c   = 1.0f / mc_sqrtf(1.0f + t * t);
			s   = t * c;
			u   = s/(1.0f + c);
			r   = t * a12;
			a11 = a11 - r;
			a22 = a22 + r;
			a12 = 0.0f;
			apr = a13;
			aqr = a23;
			a13 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v12;
			v11 = vpr - s * (vqr + vpr * u);
			v12 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v22;
			v21 = vpr - s * (vqr + vpr * u);
			v22 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v32;
			v31 = vpr - s * (vqr + vpr * u);
			v32 = vqr + s * (vpr - vqr * u);
		} else if (aa13 >= aa12 && aa13 >= aa23) {
			u = a33 - a11;
			if (mc_fabsf(a13) < m * mc_fabsf(u)) {
				t = a13 / u;
			} else {
				r = 0.5f * u / a13;
				t = ((r >= 0.0f) ? 1.0f / (r + mc_sqrtf(1.0f + mc_raise2f(r))) : 1.0f / (r - mc_sqrtf(1.0f + mc_raise2f(r))));
			}
			c   = 1.0f / mc_sqrtf(1.0f + t * t);
			s   = t * c;
			u   = s / (1.0f + c);
			r   = t * a13;
			a11 = a11 - r;
			a33 = a33 + r;
			a13 = 0.0f;
			apr = a12;
			aqr = a23;
			a12 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v13;
			v11 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v23;
			v21 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v33;
			v31 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		} else {
			u = a33 - a22;
			if (mc_fabsf(a23) < m * mc_fabsf(u)) {
				t = a23 / u;
			} else {
				r = 0.5f * u / a23;
				t = ((r >= 0.0f) ? 1.0f / (r + mc_sqrtf(1.0f + mc_raise2f(r))) : 1.0f / (r - mc_sqrtf(1.0f + mc_raise2f(r))));
			}
			c   = 1.0f / mc_sqrtf(1.0f + t * t);
			s   = t * c;
			u   = s / (1.0f + c);
			r   = t * a23;
			a22 = a22 - r;
			a33 = a33 + r;
			a23 = 0.0f;
			apr = a12;
			aqr = a13;
			a12 = apr - s * (aqr + apr * u);
			a13 = aqr + s * (apr - aqr * u);
			vpr = v12;
			vqr = v13;
			v12 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v22;
			vqr = v23;
			v22 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v32;
			vqr = v33;
			v32 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		}
		aa12 = mc_fabsf(a12);
		aa13 = mc_fabsf(a13);
		aa23 = mc_fabsf(a23);
	}
	if (i < j) {
//!# Reordering eigenvalues and eigenvectors (ascending i.e smaller first).
		if (mc_fabsf(a11) > mc_fabsf(a22)) {
			mcswap_var(t, a11, a22);
			if (wantv) {
				mcswap_var(t, v11, v12);
				mcswap_var(t, v21, v22);
				mcswap_var(t, v31, v32);
			}
		}
		if (mc_fabsf(a11) > mc_fabsf(a33)) {
			mcswap_var(t, a11, a33);
			if (wantv) {
				mcswap_var(t, v11, v13);
				mcswap_var(t, v21, v23);
				mcswap_var(t, v31, v33);
			}
		}
		if (mc_fabsf(a22) > mc_fabsf(a33)) {
			mcswap_var(t, a22, a33);
			if (wantv) {
				mcswap_var(t, v12, v13);
				mcswap_var(t, v22, v23);
				mcswap_var(t, v32, v33);
			}
		}
		e[0] = a11; e[1] = a22; e[2] = a33;
		if (wantv) {
			v[0] = v11; v[1] = v12; v[2] = v13;
			v[3] = v21; v[4] = v22; v[5] = v23;
			v[6] = v31; v[7] = v32; v[8] = v33;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_eigsyj3x3(const double a[9], double e[3], double * v)
{
	int wantv      = mc_nonnull(v);
//!# Number of Jacobi iterations.
	int i          = 0;
//!# Too low values guard.
	const double m = MCLIMITS_TINYF;
//!# Max number of iteration for convergence.
	const int j    = 90;

//!# Copying upper triangle of the given symmetric system.
	double a11 = a[0], a12 = a[1], a13 = a[2];
	double             a22 = a[4], a23 = a[5];
	double                         a33 = a[8];

//!# Absolute values of off-diagonal items.
	double aa12 = mc_fabs(a12);
	double aa13 = mc_fabs(a13);
	double aa23 = mc_fabs(a23);

//!# Working vectors. 
	double v11 = 1.0, v12 = 0.0, v13 = 0.0;
	double v21 = 0.0, v22 = 1.0, v23 = 0.0;
	double v31 = 0.0, v32 = 0.0, v33 = 1.0;

//!# Jacobi rotation variables.
	double c, r, s, t, u;
	double apr, aqr, vpr, vqr;

//!# Applying Jacobi rotations until all off-diagonal items are 0.
	for (; aa12 + aa13 + aa23 > 0.0; ++i) {
		if (i >= j) {
			e[0] = 1.0, e[1] = 1.0, e[2] = 1.0;
			if (wantv) {
				mc_eye3x3(v);
			}
			break;
		}
		if (aa12 >= aa13 && aa12 >= aa23) {
			u = a22 - a11;
			if (mc_fabs(a12) < m * mc_fabs(u)) {
				t = a12 / u;
			} else {
				r = 0.5 * u / a12;
				t = ((r >= 0.0) ? 1.0 / (r + mc_sqrt(1.0 + mc_raise2(r))) : 1.0 / (r - mc_sqrt(1.0 + mc_raise2(r))));
			}
			c   = 1.0 / mc_sqrt(1.0 + t * t);
			s   = t * c;
			u   = s/(1.0 + c);
			r   = t * a12;
			a11 = a11 - r;
			a22 = a22 + r;
			a12 = 0.0;
			apr = a13;
			aqr = a23;
			a13 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v12;
			v11 = vpr - s * (vqr + vpr * u);
			v12 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v22;
			v21 = vpr - s * (vqr + vpr * u);
			v22 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v32;
			v31 = vpr - s * (vqr + vpr * u);
			v32 = vqr + s * (vpr - vqr * u);
		} else if (aa13 >= aa12 && aa13 >= aa23) {
			u = a33 - a11;
			if (mc_fabs(a13) < m * mc_fabs(u)) {
				t = a13 / u;
			} else {
				r = 0.5 * u / a13;
				t = ((r >= 0.0) ? 1.0 / (r + mc_sqrt(1.0 + mc_raise2(r))) : 1.0 / (r - mc_sqrt(1.0 + mc_raise2(r))));
			}
			c   = 1.0 / mc_sqrt(1.0 + t * t);
			s   = t * c;
			u   = s / (1.0 + c);
			r   = t * a13;
			a11 = a11 - r;
			a33 = a33 + r;
			a13 = 0.0;
			apr = a12;
			aqr = a23;
			a12 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v13;
			v11 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v23;
			v21 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v33;
			v31 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		} else {
			u = a33 - a22;
			if (mc_fabs(a23) < m * mc_fabs(u)) {
				t = a23 / u;
			} else {
				r = 0.5 * u / a23;
				t = ((r >= 0.0) ? 1.0 / (r + mc_sqrt(1.0 + mc_raise2(r))) : 1.0 / (r - mc_sqrt(1.0 + mc_raise2(r))));
			}
			c   = 1.0 / mc_sqrt(1.0 + t * t);
			s   = t * c;
			u   = s / (1.0 + c);
			r   = t * a23;
			a22 = a22 - r;
			a33 = a33 + r;
			a23 = 0.0;
			apr = a12;
			aqr = a13;
			a12 = apr - s * (aqr + apr * u);
			a13 = aqr + s * (apr - aqr * u);
			vpr = v12;
			vqr = v13;
			v12 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v22;
			vqr = v23;
			v22 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v32;
			vqr = v33;
			v32 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		}
		aa12 = mc_fabs(a12);
		aa13 = mc_fabs(a13);
		aa23 = mc_fabs(a23);
	}
	if (i < j) {
//!# Reordering eigenvalues and eigenvectors (ascending i.e smaller first).
		if (mc_fabs(a11) > mc_fabs(a22)) {
			mcswap_var(t, a11, a22);
			if (wantv) {
				mcswap_var(t, v11, v12);
				mcswap_var(t, v21, v22);
				mcswap_var(t, v31, v32);
			}
		}
		if (mc_fabs(a11) > mc_fabs(a33)) {
			mcswap_var(t, a11, a33);
			if (wantv) {
				mcswap_var(t, v11, v13);
				mcswap_var(t, v21, v23);
				mcswap_var(t, v31, v33);
			}
		}
		if (mc_fabs(a22) > mc_fabs(a33)) {
			mcswap_var(t, a22, a33);
			if (wantv) {
				mcswap_var(t, v12, v13);
				mcswap_var(t, v22, v23);
				mcswap_var(t, v32, v33);
			}
		}
		e[0] = a11; e[1] = a22; e[2] = a33;
		if (wantv) {
			v[0] = v11; v[1] = v12; v[2] = v13;
			v[3] = v21; v[4] = v22; v[5] = v23;
			v[6] = v31; v[7] = v32; v[8] = v33;
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_eigsyj3x3l(const long double a[9], long double e[3], long double * v)
{
	int wantv           = mc_nonnull(v);
//!# Number of Jacobi iterations.
	int i               = 0;
//!# Too low values guard.
	const long double m = MCLIMITS_TINYF;
//!# Max number of iteration for convergence.
	const int j         = 90;

//!# Copying upper triangle of the given symmetric system.
	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double             a22 = a[4], a23 = a[5];
	long double                         a33 = a[8];

//!# Absolute values of off-diagonal items.
	long double aa12 = mc_fabsl(a12);
	long double aa13 = mc_fabsl(a13);
	long double aa23 = mc_fabsl(a23);

//!# Working vectors. 
	long double v11 = 1.0L, v12 = 0.0L, v13 = 0.0L;
	long double v21 = 0.0L, v22 = 1.0L, v23 = 0.0L;
	long double v31 = 0.0L, v32 = 0.0L, v33 = 1.0L;

//!# Jacobi rotation variables.
	long double c, r, s, t, u;
	long double apr, aqr, vpr, vqr;

//!# Applying Jacobi rotations until all off-diagonal items are 0.
	for (; aa12 + aa13 + aa23 > 0.0L; ++i) {
		if (i >= j) {
			e[0] = 1.0L, e[1] = 1.0L, e[2] = 1.0L;
			if (wantv) {
				mc_eye3x3l(v);
			}
			break;
		}
		if (aa12 >= aa13 && aa12 >= aa23) {
			u = a22 - a11;
			if (mc_fabsl(a12) < m * mc_fabsl(u)) {
				t = a12 / u;
			} else {
				r = 0.5L * u / a12;
				t = ((r >= 0.0L) ? 1.0L / (r + mc_sqrtl(1.0L + mc_raise2l(r))) : 1.0L / (r - mc_sqrtl(1.0L + mc_raise2l(r))));
			}
			c   = 1.0L / mc_sqrtl(1.0L + t * t);
			s   = t * c;
			u   = s/(1.0L + c);
			r   = t * a12;
			a11 = a11 - r;
			a22 = a22 + r;
			a12 = 0.0L;
			apr = a13;
			aqr = a23;
			a13 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v12;
			v11 = vpr - s * (vqr + vpr * u);
			v12 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v22;
			v21 = vpr - s * (vqr + vpr * u);
			v22 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v32;
			v31 = vpr - s * (vqr + vpr * u);
			v32 = vqr + s * (vpr - vqr * u);
		} else if (aa13 >= aa12 && aa13 >= aa23) {
			u = a33 - a11;
			if (mc_fabsl(a13) < m * mc_fabsl(u)) {
				t = a13 / u;
			} else {
				r = 0.5L * u / a13;
				t = ((r >= 0.0L) ? 1.0L / (r + mc_sqrtl(1.0L + mc_raise2l(r))) : 1.0L / (r - mc_sqrtl(1.0L + mc_raise2l(r))));
			}
			c   = 1.0L / mc_sqrtl(1.0L + t * t);
			s   = t * c;
			u   = s / (1.0L + c);
			r   = t * a13;
			a11 = a11 - r;
			a33 = a33 + r;
			a13 = 0.0L;
			apr = a12;
			aqr = a23;
			a12 = apr - s * (aqr + apr * u);
			a23 = aqr + s * (apr - aqr * u);
			vpr = v11;
			vqr = v13;
			v11 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v21;
			vqr = v23;
			v21 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v31;
			vqr = v33;
			v31 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		} else {
			u = a33 - a22;
			if (mc_fabsl(a23) < m * mc_fabsl(u)) {
				t = a23 / u;
			} else {
				r = 0.5L * u / a23;
				t = ((r >= 0.0L) ? 1.0L / (r + mc_sqrtl(1.0L + mc_raise2l(r))) : 1.0L / (r - mc_sqrtl(1.0L + mc_raise2l(r))));
			}
			c   = 1.0L / mc_sqrtl(1.0L + t * t);
			s   = t * c;
			u   = s / (1.0L + c);
			r   = t * a23;
			a22 = a22 - r;
			a33 = a33 + r;
			a23 = 0.0L;
			apr = a12;
			aqr = a13;
			a12 = apr - s * (aqr + apr * u);
			a13 = aqr + s * (apr - aqr * u);
			vpr = v12;
			vqr = v13;
			v12 = vpr - s * (vqr + vpr * u);
			v13 = vqr + s * (vpr - vqr * u);
			vpr = v22;
			vqr = v23;
			v22 = vpr - s * (vqr + vpr * u);
			v23 = vqr + s * (vpr - vqr * u);
			vpr = v32;
			vqr = v33;
			v32 = vpr - s * (vqr + vpr * u);
			v33 = vqr + s * (vpr - vqr * u);
		}
		aa12 = mc_fabsl(a12);
		aa13 = mc_fabsl(a13);
		aa23 = mc_fabsl(a23);
	}
	if (i < j) {
//!# Reordering eigenvalues and eigenvectors (ascending i.e smaller first).
		if (mc_fabsl(a11) > mc_fabsl(a22)) {
			mcswap_var(t, a11, a22);
			if (wantv) {
				mcswap_var(t, v11, v12);
				mcswap_var(t, v21, v22);
				mcswap_var(t, v31, v32);
			}
		}
		if (mc_fabsl(a11) > mc_fabsl(a33)) {
			mcswap_var(t, a11, a33);
			if (wantv) {
				mcswap_var(t, v11, v13);
				mcswap_var(t, v21, v23);
				mcswap_var(t, v31, v33);
			}
		}
		if (mc_fabsl(a22) > mc_fabsl(a33)) {
			mcswap_var(t, a22, a33);
			if (wantv) {
				mcswap_var(t, v12, v13);
				mcswap_var(t, v22, v23);
				mcswap_var(t, v32, v33);
			}
		}
		e[0] = a11; e[1] = a22; e[2] = a33;
		if (wantv) {
			v[0] = v11; v[1] = v12; v[2] = v13;
			v[3] = v21; v[4] = v22; v[5] = v23;
			v[6] = v31; v[7] = v32; v[8] = v33;
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_EIGSYJ3X3_H */

/* EOF */
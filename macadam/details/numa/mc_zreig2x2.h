//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zreig2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmax.h>
#include <macadam/details/math/mc_fmin.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/math/mc_zadd.h>
#include <macadam/details/math/mc_zmul.h>
#include <macadam/details/math/mc_zsqrt.h>
#include <macadam/details/math/mc_zsub.h>
#include <macadam/details/numa/mc_det2x2.h>
#include <macadam/details/numa/mc_trace2x2.h>
#include <macadam/details/numa/mc_zeye2x2.h>
#include <macadam/details/numa/mc_zunit1x2.h>

#ifndef MC_ZREIG2X2_H
#define MC_ZREIG2X2_H

#pragma mark - mc_zreig2x2_approx0 -

MC_TARGET_PROC int mc_zreig2x2f_approx0(
	  const float a[4]
	, float * e0_r
	, float * e0_i
	, float * e1_r
	, float * e1_i
	, int wantv
	, float * v0_r, float * v0_i, float * v1_r, float * v1_i
	, float * v2_r, float * v2_i, float * v3_r, float * v3_i
) {
	float t0 = 0.0f, t1, t2, t3, t4;
	if (a[1] != a[2]) {
//!# Solving 2x2 non-symmetric.
		const float trc = mc_trace2x2f(a);
		t1              = (a[0] - a[3]) * (a[0] - a[3]) + 4.0f * a[1] * a[2];
		if (t1 >= 0.0f) {
			t1 = mc_sqrtf(t1);
		} else {
			mc_zsqrtf(&t0, &t1, t1, 0.0f);
		}
		if (t0 != 0.0f) {
//!# Handling complex conjugate solution such as:
//!# e0=(trc + sqrt(disc))/2 and e1=(trc - sqrt(disc))/2.
			mc_zaddf(e0_r, e0_i, trc, 0.0f, 0.0f, t1);
			mc_zmulf(e0_r, e0_i, 0.5f, 0.0f, *e0_r, *e0_i);
			mc_zsubf(e1_r, e1_i, trc, 0.0f, 0.0f, t1);
			mc_zmulf(e1_r, e1_i, 0.5f, 0.0f, *e1_r, *e1_i);

			if (wantv) {
				if (a[1] != 0.0f && mc_fabsf(a[1]) > mc_fabsf(a[2])) {
//!# Assigning left-side vector v0=a[1] and v2=e0 - a[0].
					*v0_r = a[1]; *v0_i = 0.0f;
					mc_zsubf(v2_r, v2_i, *e0_r, *e0_i,  a[0], 0.0f);

//!# Scaling to obtain a unit vector.
					mc_zunit1x2f(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else if (a[2] != 0.0f) {
//!# Assigning left-side vector v0=e1 - a[3] and v2=a[2].
					mc_zsubf(v0_r, v0_i, *e0_r, *e0_i, a[3], 0.0f);
					*v2_r = a[2]; *v2_i = 0.0f;

//!# Scaling to obtain a unit vector.
					mc_zunit1x2f(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else {
					mc_zeye2x2f(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
			}
			return 0;
		} else {
			*e0_r = 0.5f * (trc + t1);
			*e0_i = 0.0f;
			*e1_r = 0.5f * (trc - t1);
			*e1_i = 0.0f;

			if (mc_fabsf(*e0_r) < MCLIMITS_EPSILONF || mc_fabsf(*e1_r) < MCLIMITS_EPSILONF) {
				*e0_r = 1.0f;
				*e1_r = 1.0f;
				if (wantv) {
					mc_zeye2x2f(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -9;
			}

			if (wantv) {
				t0 = 4.0f * a[1] * a[1] + 4.0f * a[1] * a[2] + 2.0f * (a[3] - a[0]) * (a[3] - a[0]);
				t1 = (a[3] - a[0]) * (a[3] - a[0]) + 4.0f * a[1] * a[2];
				t2 = 2.0f * (a[3] - a[0]);
				if (t1 >= 0.0f) {
					t1 = mc_sqrtf(t1);
				} else {
					mc_zsqrtf(&t0, &t1, t1, 0.0f);
					if (t0 != 0.0f) {
						mc_zeye2x2f(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -8;
					}
				}
	
				t3 = t0 + t2 * t1;
				if (t3 >= 0.0f) {
					t3 = mc_sqrtf(t3);
				} else {
					mc_zsqrtf(&t0, &t3, t3, 0.0f);
					if (t0 != 0.0f) {
						mc_zeye2x2f(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -7;
					}
				}

				t4 = t0 - t2 * t1;
				if (t4 >= 0.0f) {
					t4 = mc_sqrtf(t4);
				} else {
					mc_zsqrtf(&t0, &t4, t4, 0.0f);
					if (t0 != 0.0f) {
						mc_zeye2x2f(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -6;
					}
				}
				if (t3 == 0.0f || t4 == 0.0f) {
					mc_zeye2x2f(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
					return -5;
				}
				*v0_r = 2.0f * a[1] / t3;          *v0_i = 0.0f; *v1_r = 2.0f * a[1] / t4;          *v1_i = 0.0f;
				*v2_r = ((a[3] - a[0]) + t1) / t3; *v2_i = 0.0f; *v3_r = ((a[3] - a[0]) - t1) / t4; *v3_i = 0.0f;

				if (mc_fabsf( *e0_r) > mc_fabsf(*e1_r)) {
					t0 = *e0_r; *e0_r = *e1_r; *e1_r = t0;
					t0 = *v0_r; *v0_r = *v1_r; *v1_r = t0;
					t0 = *v2_r; *v2_r = *v3_r; *v3_r = t0;
				}
			} else {
				if (mc_fabsf(*e0_r) > mc_fabsf(*e1_r)) {
					t0   = *e0_r; *e0_r = *e1_r; *e1_r = t0;
				}
			}
			return 1;
		}
	} else {
//!# Solving 2x2 symmetric.
		if (mc_fabsf(a[2]) == 0.0f) {
			*e0_r = mc_fminf(a[0], a[3]); *e0_i = 0.0f;
			*e1_r = mc_fmaxf(a[0], a[3]); *e1_i = 0.0f;
			if (wantv) {
				mc_zeye2x2f(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
			return 3;
		} else {
			const float trc = mc_trace2x2f(a);
			const float det = mc_det2x2f(a);
			t1              = mc_raise2f(trc) - 4.0f * det;

			if (t1 >= 0.0f) {
				t1 = mc_sqrtf(t1);
			} else {
				mc_zsqrtf(&t0, &t1, t1, 0.0f);
			}
			 t0 = -trc;
			 t0 = -0.5f * (t0 + (t0 > 0.0f ? 1.0f : -1.0f) * t1);
			 t1 = det / t0;

			if (mc_fabsf(t0) > mc_fabsf(t1)) {
				t2 = t0;
				t0 = t1;
				t1 = t2;
			}

			if (mc_fabsf(t0) < MCLIMITS_EPSILONF || mc_fabsf(t1) < MCLIMITS_EPSILONF) {
				*e0_r = 1.0f; *e0_i = 0.0f;
				*e1_r = 1.0f; *e1_i = 0.0f;
				if (wantv) {
					mc_zeye2x2f(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -3;
			}

			*e0_r = t0; *e0_i = 0.0f;
			*e1_r = t1; *e1_i = 0.0f;

			if (wantv) {
				t0 =  a[3] - t0;
				t1 = -a[2];

				t2 = mc_sqrtf(mc_raise2f(t0) + mc_raise2f(t1));
				t0 = t0 / t2;
				t1 = t1 / t2;

				*v0_r = t0; *v0_i = 0.0f; *v1_r =  t1; *v1_i = 0.0f;
				*v2_r = t1; *v2_i = 0.0f; *v3_r = -t0; *v3_i = 0.0f;
			}
			return 2;
		}
	}
	return -1;
}

MC_TARGET_PROC int mc_zreig2x2_approx0(
	  const double a[4]
	, double * e0_r
	, double * e0_i
	, double * e1_r
	, double * e1_i
	, int wantv
	, double * v0_r, double * v0_i, double * v1_r, double * v1_i
	, double * v2_r, double * v2_i, double * v3_r, double * v3_i
) {
	double t0 = 0.0, t1, t2, t3, t4;
	if (a[1] != a[2]) {
//!# Solving 2x2 non-symmetric.
		const double trc = mc_trace2x2(a);
		t1              = (a[0] - a[3]) * (a[0] - a[3]) + 4.0 * a[1] * a[2];
		if (t1 >= 0.0) {
			t1 = mc_sqrt(t1);
		} else {
			mc_zsqrt(&t0, &t1, t1, 0.0);
		}
		if (t0 != 0.0) {
//!# Handling complex conjugate solution such as:
//!# e0=(trc + sqrt(disc))/2 and e1=(trc - sqrt(disc))/2.
			mc_zadd(e0_r, e0_i, trc, 0.0, 0.0, t1);
			mc_zmul(e0_r, e0_i, 0.5, 0.0, *e0_r, *e0_i);
			mc_zsub(e1_r, e1_i, trc, 0.0, 0.0, t1);
			mc_zmul(e1_r, e1_i, 0.5, 0.0, *e1_r, *e1_i);

			if (wantv) {
				if (a[1] != 0.0 && mc_fabs(a[1]) > mc_fabs(a[2])) {
//!# Assigning left-side vector v0=a[1] and v2=e0 - a[0].
					*v0_r = a[1]; *v0_i = 0.0;
					mc_zsub(v2_r, v2_i, *e0_r, *e0_i,  a[0], 0.0);

//!# Scaling to obtain a unit vector.
					mc_zunit1x2(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else if (a[2] != 0.0) {
//!# Assigning left-side vector v0=e1 - a[3] and v2=a[2].
					mc_zsub(v0_r, v0_i, *e0_r, *e0_i, a[3], 0.0);
					*v2_r = a[2]; *v2_i = 0.0;

//!# Scaling to obtain a unit vector.
					mc_zunit1x2(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else {
					mc_zeye2x2(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
			}
			return 0;
		} else {
			*e0_r = 0.5 * (trc + t1);
			*e0_i = 0.0;
			*e1_r = 0.5 * (trc - t1);
			*e1_i = 0.0;

			if (mc_fabs(*e0_r) < MCLIMITS_EPSILON || mc_fabs(*e1_r) < MCLIMITS_EPSILON) {
				*e0_r = 1.0;
				*e1_r = 1.0;
				if (wantv) {
					mc_zeye2x2(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -9;
			}

			if (wantv) {
				t0 = 4.0 * a[1] * a[1] + 4.0 * a[1] * a[2] + 2.0 * (a[3] - a[0]) * (a[3] - a[0]);
				t1 = (a[3] - a[0]) * (a[3] - a[0]) + 4.0 * a[1] * a[2];
				t2 = 2.0 * (a[3] - a[0]);
				if (t1 >= 0.0) {
					t1 = mc_sqrt(t1);
				} else {
					mc_zsqrt(&t0, &t1, t1, 0.0);
					if (t0 != 0.0) {
						mc_zeye2x2(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -8;
					}
				}
	
				t3 = t0 + t2 * t1;
				if (t3 >= 0.0) {
					t3 = mc_sqrt(t3);
				} else {
					mc_zsqrt(&t0, &t3, t3, 0.0);
					if (t0 != 0.0) {
						mc_zeye2x2(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -7;
					}
				}

				t4 = t0 - t2 * t1;
				if (t4 >= 0.0) {
					t4 = mc_sqrt(t4);
				} else {
					mc_zsqrt(&t0, &t4, t4, 0.0);
					if (t0 != 0.0) {
						mc_zeye2x2(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -6;
					}
				}
				if (t3 == 0.0 || t4 == 0.0) {
					mc_zeye2x2(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
					return -5;
				}
				*v0_r = 2.0 * a[1] / t3;          *v0_i = 0.0; *v1_r = 2.0 * a[1] / t4;          *v1_i = 0.0;
				*v2_r = ((a[3] - a[0]) + t1) / t3; *v2_i = 0.0; *v3_r = ((a[3] - a[0]) - t1) / t4; *v3_i = 0.0;

				if (mc_fabs( *e0_r) > mc_fabs(*e1_r)) {
					t0 = *e0_r; *e0_r = *e1_r; *e1_r = t0;
					t0 = *v0_r; *v0_r = *v1_r; *v1_r = t0;
					t0 = *v2_r; *v2_r = *v3_r; *v3_r = t0;
				}
			} else {
				if (mc_fabs(*e0_r) > mc_fabs(*e1_r)) {
					t0   = *e0_r; *e0_r = *e1_r; *e1_r = t0;
				}
			}
			return 1;
		}
	} else {
//!# Solving 2x2 symmetric.
		if (mc_fabs(a[2]) == 0.0) {
			*e0_r = mc_fmin(a[0], a[3]); *e0_i = 0.0;
			*e1_r = mc_fmax(a[0], a[3]); *e1_i = 0.0;
			if (wantv) {
				mc_zeye2x2(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
			return 3;
		} else {
			const double trc = mc_trace2x2(a);
			const double det = mc_det2x2(a);
			t1              = mc_raise2(trc) - 4.0 * det;

			if (t1 >= 0.0) {
				t1 = mc_sqrt(t1);
			} else {
				mc_zsqrt(&t0, &t1, t1, 0.0);
			}
			 t0 = -trc;
			 t0 = -0.5 * (t0 + (t0 > 0.0 ? 1.0 : -1.0) * t1);
			 t1 = det / t0;

			if (mc_fabs(t0) > mc_fabs(t1)) {
				t2 = t0;
				t0 = t1;
				t1 = t2;
			}

			if (mc_fabs(t0) < MCLIMITS_EPSILON || mc_fabs(t1) < MCLIMITS_EPSILON) {
				*e0_r = 1.0; *e0_i = 0.0;
				*e1_r = 1.0; *e1_i = 0.0;
				if (wantv) {
					mc_zeye2x2(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -3;
			}

			*e0_r = t0; *e0_i = 0.0;
			*e1_r = t1; *e1_i = 0.0;

			if (wantv) {
				t0 =  a[3] - t0;
				t1 = -a[2];

				t2 = mc_sqrt(mc_raise2(t0) + mc_raise2(t1));
				t0 = t0 / t2;
				t1 = t1 / t2;

				*v0_r = t0; *v0_i = 0.0; *v1_r =  t1; *v1_i = 0.0;
				*v2_r = t1; *v2_i = 0.0; *v3_r = -t0; *v3_i = 0.0;
			}
			return 2;
		}
	}
	return -1;
}

MC_TARGET_PROC int mc_zreig2x2l_approx0(
	  const long double a[4]
	, long double * e0_r
	, long double * e0_i
	, long double * e1_r
	, long double * e1_i
	, int wantv
	, long double * v0_r, long double * v0_i, long double * v1_r, long double * v1_i
	, long double * v2_r, long double * v2_i, long double * v3_r, long double * v3_i
) {
	long double t0 = 0.0L, t1, t2, t3, t4;
	if (a[1] != a[2]) {
//!# Solving 2x2 non-symmetric.
		const long double trc = mc_trace2x2l(a);
		t1              = (a[0] - a[3]) * (a[0] - a[3]) + 4.0L * a[1] * a[2];
		if (t1 >= 0.0L) {
			t1 = mc_sqrtl(t1);
		} else {
			mc_zsqrtl(&t0, &t1, t1, 0.0L);
		}
		if (t0 != 0.0L) {
//!# Handling complex conjugate solution such as:
//!# e0=(trc + sqrt(disc))/2 and e1=(trc - sqrt(disc))/2.
			mc_zaddl(e0_r, e0_i, trc, 0.0L, 0.0L, t1);
			mc_zmull(e0_r, e0_i, 0.5L, 0.0L, *e0_r, *e0_i);
			mc_zsubl(e1_r, e1_i, trc, 0.0L, 0.0L, t1);
			mc_zmull(e1_r, e1_i, 0.5L, 0.0L, *e1_r, *e1_i);

			if (wantv) {
				if (a[1] != 0.0L && mc_fabsl(a[1]) > mc_fabsl(a[2])) {
//!# Assigning left-side vector v0=a[1] and v2=e0 - a[0].
					*v0_r = a[1]; *v0_i = 0.0L;
					mc_zsubl(v2_r, v2_i, *e0_r, *e0_i,  a[0], 0.0L);

//!# Scaling to obtain a unit vector.
					mc_zunit1x2l(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else if (a[2] != 0.0L) {
//!# Assigning left-side vector v0=e1 - a[3] and v2=a[2].
					mc_zsubl(v0_r, v0_i, *e0_r, *e0_i, a[3], 0.0L);
					*v2_r = a[2]; *v2_i = 0.0L;

//!# Scaling to obtain a unit vector.
					mc_zunit1x2l(v0_r, v0_i, v2_r, v2_i);

//!# Assigning conjugate to the right-side vector.
					*v1_r = *v0_r; *v1_i = -(*v0_i);
					*v3_r = *v2_r; *v3_i = -(*v2_i);
				} else {
					mc_zeye2x2l(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
			}
			return 0;
		} else {
			*e0_r = 0.5L * (trc + t1);
			*e0_i = 0.0L;
			*e1_r = 0.5L * (trc - t1);
			*e1_i = 0.0L;

			if (mc_fabsl(*e0_r) < MCLIMITS_EPSILONL || mc_fabsl(*e1_r) < MCLIMITS_EPSILONL) {
				*e0_r = 1.0L;
				*e1_r = 1.0L;
				if (wantv) {
					mc_zeye2x2l(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -9;
			}

			if (wantv) {
				t0 = 4.0L * a[1] * a[1] + 4.0L * a[1] * a[2] + 2.0L * (a[3] - a[0]) * (a[3] - a[0]);
				t1 = (a[3] - a[0]) * (a[3] - a[0]) + 4.0L * a[1] * a[2];
				t2 = 2.0L * (a[3] - a[0]);
				if (t1 >= 0.0L) {
					t1 = mc_sqrtl(t1);
				} else {
					mc_zsqrtl(&t0, &t1, t1, 0.0L);
					if (t0 != 0.0L) {
						mc_zeye2x2l(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -8;
					}
				}
	
				t3 = t0 + t2 * t1;
				if (t3 >= 0.0L) {
					t3 = mc_sqrtl(t3);
				} else {
					mc_zsqrtl(&t0, &t3, t3, 0.0L);
					if (t0 != 0.0L) {
						mc_zeye2x2l(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -7;
					}
				}

				t4 = t0 - t2 * t1;
				if (t4 >= 0.0L) {
					t4 = mc_sqrtl(t4);
				} else {
					mc_zsqrtl(&t0, &t4, t4, 0.0L);
					if (t0 != 0.0L) {
						mc_zeye2x2l(
							  v0_r, v0_i, v1_r, v1_i
							, v2_r, v2_i, v3_r, v3_i
						);
						return -6;
					}
				}
				if (t3 == 0.0L || t4 == 0.0L) {
					mc_zeye2x2l(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
					return -5;
				}
				*v0_r = 2.0L * a[1] / t3;          *v0_i = 0.0L; *v1_r = 2.0L * a[1] / t4;          *v1_i = 0.0L;
				*v2_r = ((a[3] - a[0]) + t1) / t3; *v2_i = 0.0L; *v3_r = ((a[3] - a[0]) - t1) / t4; *v3_i = 0.0L;

				if (mc_fabsl( *e0_r) > mc_fabsl(*e1_r)) {
					t0 = *e0_r; *e0_r = *e1_r; *e1_r = t0;
					t0 = *v0_r; *v0_r = *v1_r; *v1_r = t0;
					t0 = *v2_r; *v2_r = *v3_r; *v3_r = t0;
				}
			} else {
				if (mc_fabsl(*e0_r) > mc_fabsl(*e1_r)) {
					t0   = *e0_r; *e0_r = *e1_r; *e1_r = t0;
				}
			}
			return 1;
		}
	} else {
//!# Solving 2x2 symmetric.
		if (mc_fabsl(a[2]) == 0.0L) {
			*e0_r = mc_fminl(a[0], a[3]); *e0_i = 0.0L;
			*e1_r = mc_fmaxl(a[0], a[3]); *e1_i = 0.0L;
			if (wantv) {
				mc_zeye2x2l(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
			return 3;
		} else {
			const long double trc = mc_trace2x2l(a);
			const long double det = mc_det2x2l(a);
			t1              = mc_raise2l(trc) - 4.0L * det;

			if (t1 >= 0.0L) {
				t1 = mc_sqrtl(t1);
			} else {
				mc_zsqrtl(&t0, &t1, t1, 0.0L);
			}
			 t0 = -trc;
			 t0 = -0.5L * (t0 + (t0 > 0.0L ? 1.0L : -1.0L) * t1);
			 t1 = det / t0;

			if (mc_fabsl(t0) > mc_fabsl(t1)) {
				t2 = t0;
				t0 = t1;
				t1 = t2;
			}

			if (mc_fabsl(t0) < MCLIMITS_EPSILONL || mc_fabsl(t1) < MCLIMITS_EPSILONL) {
				*e0_r = 1.0L; *e0_i = 0.0L;
				*e1_r = 1.0L; *e1_i = 0.0L;
				if (wantv) {
					mc_zeye2x2l(
						  v0_r, v0_i, v1_r, v1_i
						, v2_r, v2_i, v3_r, v3_i
					);
				}
				return -3;
			}

			*e0_r = t0; *e0_i = 0.0L;
			*e1_r = t1; *e1_i = 0.0L;

			if (wantv) {
				t0 =  a[3] - t0;
				t1 = -a[2];

				t2 = mc_sqrtl(mc_raise2l(t0) + mc_raise2l(t1));
				t0 = t0 / t2;
				t1 = t1 / t2;

				*v0_r = t0; *v0_i = 0.0L; *v1_r =  t1; *v1_i = 0.0L;
				*v2_r = t1; *v2_i = 0.0L; *v3_r = -t0; *v3_i = 0.0L;
			}
			return 2;
		}
	}
	return -1;
}

#pragma mark - mc_zreig2x2_approx1 -

MC_TARGET_PROC int mc_zreig2x2f_approx1(
	  const float a[4]
	, float * e0_r
	, float * e0_i
	, float * e1_r
	, float * e1_i
	, int wantv
	, float * v0_r, float * v0_i, float * v1_r, float * v1_i
	, float * v2_r, float * v2_i, float * v3_r, float * v3_i
) {
	float t0, t1, t2;
	if (a[2] == 0.0f && a[1] == 0.0f) {
		*e0_r = mc_fminf(a[0], a[3]); *e0_i = 0.0f;
		*e1_r = mc_fmaxf(a[0], a[3]); *e1_i = 0.0f;
		if (wantv) {
			mc_zeye2x2f(
				  v0_r, v0_i, v1_r, v1_i
				, v2_r, v2_i, v3_r, v3_i
			);
		}
		return 2;
	} else {
		const float t = mc_trace2x2f(a);
		const float d = mc_det2x2f(a);

		mc_zsqrtf(&t0, &t1, mc_raise2f(t) / 4.0f - d, 0.0f);
		t2 = t0;

		mc_zaddf(e0_r, e0_i, t * 0.5f, 0.0f, 0.0f, t1);
		mc_zsubf(e1_r, e1_i, t * 0.5f, 0.0f, 0.0f, t1);

		if (wantv) {
			if (a[2] != 0.0f && mc_fabsf(a[2]) > mc_fabsf(a[1])) {
				mc_zsubf(&t0, &t1, *e0_r, *e0_i, a[3], 0.0f);
				*v0_r = t0; *v0_i = t1;

				mc_zsubf(&t0, &t1, *e1_r, *e1_i, a[3], 0.0f);
				*v1_r = t0; *v1_i = t1;

				*v2_r = a[2]; *v2_i = 0.0f; *v3_r = a[2]; *v3_i = 0.0f;
				
				mc_zunit1x2f(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2f(v1_r, v1_i, v3_r, v3_i);

			} else if (a[1] != 0.0f) {
				*v0_r = a[1]; *v0_i = 0.0f; *v1_r = a[1]; *v1_i = 0.0f;

				mc_zsubf(&t0, &t1, *e0_r, *e0_i, a[0], 0.0f);
				*v2_r = t0; *v2_i = t1;

				mc_zsubf(&t0, &t1, *e1_r, *e1_i, a[0], 0.0f);
				*v3_r = t0; *v3_i = t1;

				mc_zunit1x2f(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2f(v1_r, v1_i, v3_r, v3_i);
			} else {
				mc_zeye2x2f(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
		}
		return a[2] == a[1] ? 1 : (t2 > 0.0f ? 0 : 1);
	}
	return -1;
}

MC_TARGET_PROC int mc_zreig2x2_approx1(
	  const double a[4]
	, double * e0_r
	, double * e0_i
	, double * e1_r
	, double * e1_i
	, int wantv
	, double * v0_r, double * v0_i, double * v1_r, double * v1_i
	, double * v2_r, double * v2_i, double * v3_r, double * v3_i
) {
	double t0, t1, t2;
	if (a[2] == 0.0 && a[1] == 0.0) {
		*e0_r = mc_fmin(a[0], a[3]); *e0_i = 0.0;
		*e1_r = mc_fmax(a[0], a[3]); *e1_i = 0.0;
		if (wantv) {
			mc_zeye2x2(
				  v0_r, v0_i, v1_r, v1_i
				, v2_r, v2_i, v3_r, v3_i
			);
		}
		return 2;
	} else {
		const double t = mc_trace2x2(a);
		const double d = mc_det2x2(a);

		mc_zsqrt(&t0, &t1, mc_raise2(t) / 4.0 - d, 0.0);
		t2 = t0;

		mc_zadd(e0_r, e0_i, t * 0.5, 0.0, 0.0, t1);
		mc_zsub(e1_r, e1_i, t * 0.5, 0.0, 0.0, t1);

		if (wantv) {
			if (a[2] != 0.0 && mc_fabs(a[2]) > mc_fabs(a[1])) {
				mc_zsub(&t0, &t1, *e0_r, *e0_i, a[3], 0.0);
				*v0_r = t0; *v0_i = t1;

				mc_zsub(&t0, &t1, *e1_r, *e1_i, a[3], 0.0);
				*v1_r = t0; *v1_i = t1;

				*v2_r = a[2]; *v2_i = 0.0; *v3_r = a[2]; *v3_i = 0.0;
				
				mc_zunit1x2(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2(v1_r, v1_i, v3_r, v3_i);

			} else if (a[1] != 0.0) {
				*v0_r = a[1]; *v0_i = 0.0; *v1_r = a[1]; *v1_i = 0.0;

				mc_zsub(&t0, &t1, *e0_r, *e0_i, a[0], 0.0);
				*v2_r = t0; *v2_i = t1;

				mc_zsub(&t0, &t1, *e1_r, *e1_i, a[0], 0.0);
				*v3_r = t0; *v3_i = t1;

				mc_zunit1x2(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2(v1_r, v1_i, v3_r, v3_i);
			} else {
				mc_zeye2x2(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
		}
		return a[2] == a[1] ? 1 : (t2 > 0.0 ? 0 : 1);
	}
	return -1;
}

MC_TARGET_PROC int mc_zreig2x2l_approx1(
	  const long double a[4]
	, long double * e0_r
	, long double * e0_i
	, long double * e1_r
	, long double * e1_i
	, int wantv
	, long double * v0_r, long double * v0_i, long double * v1_r, long double * v1_i
	, long double * v2_r, long double * v2_i, long double * v3_r, long double * v3_i
) {
	long double t0, t1, t2;
	if (a[2] == 0.0L && a[1] == 0.0L) {
		*e0_r = mc_fminl(a[0], a[3]); *e0_i = 0.0L;
		*e1_r = mc_fmaxl(a[0], a[3]); *e1_i = 0.0L;
		if (wantv) {
			mc_zeye2x2l(
				  v0_r, v0_i, v1_r, v1_i
				, v2_r, v2_i, v3_r, v3_i
			);
		}
		return 2;
	} else {
		const long double t = mc_trace2x2l(a);
		const long double d = mc_det2x2l(a);

		mc_zsqrtl(&t0, &t1, mc_raise2l(t) / 4.0L - d, 0.0L);
		t2 = t0;

		mc_zaddl(e0_r, e0_i, t * 0.5L, 0.0L, 0.0L, t1);
		mc_zsubl(e1_r, e1_i, t * 0.5L, 0.0L, 0.0L, t1);

		if (wantv) {
			if (a[2] != 0.0L && mc_fabsl(a[2]) > mc_fabsl(a[1])) {
				mc_zsubl(&t0, &t1, *e0_r, *e0_i, a[3], 0.0L);
				*v0_r = t0; *v0_i = t1;

				mc_zsubl(&t0, &t1, *e1_r, *e1_i, a[3], 0.0L);
				*v1_r = t0; *v1_i = t1;

				*v2_r = a[2]; *v2_i = 0.0L; *v3_r = a[2]; *v3_i = 0.0L;
				
				mc_zunit1x2l(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2l(v1_r, v1_i, v3_r, v3_i);

			} else if (a[1] != 0.0L) {
				*v0_r = a[1]; *v0_i = 0.0L; *v1_r = a[1]; *v1_i = 0.0L;

				mc_zsubl(&t0, &t1, *e0_r, *e0_i, a[0], 0.0L);
				*v2_r = t0; *v2_i = t1;

				mc_zsubl(&t0, &t1, *e1_r, *e1_i, a[0], 0.0L);
				*v3_r = t0; *v3_i = t1;

				mc_zunit1x2l(v0_r, v0_i, v2_r, v2_i);
				mc_zunit1x2l(v1_r, v1_i, v3_r, v3_i);
			} else {
				mc_zeye2x2l(
					  v0_r, v0_i, v1_r, v1_i
					, v2_r, v2_i, v3_r, v3_i
				);
			}
		}
		return a[2] == a[1] ? 1 : (t2 > 0.0L ? 0 : 1);
	}
	return -1;
}

#pragma mark - mc_zreig2x2 -

MC_TARGET_PROC int mc_zreig2x2f(
	  const float a[4]
	, float * e0_r
	, float * e0_i
	, float * e1_r
	, float * e1_i
	, int wantv
	, float * v0_r, float * v0_i, float * v1_r, float * v1_i
	, float * v2_r, float * v2_i, float * v3_r, float * v3_i
) {
	return mc_zreig2x2f_approx1(a, e0_r, e0_i, e1_r, e1_i
		, wantv
		, v0_r, v0_i, v1_r, v1_i
		, v2_r, v2_i, v3_r, v3_i
	);
}

MC_TARGET_PROC int mc_zreig2x2(
	  const double a[4]
	, double * e0_r
	, double * e0_i
	, double * e1_r
	, double * e1_i
	, int wantv
	, double * v0_r, double * v0_i, double * v1_r, double * v1_i
	, double * v2_r, double * v2_i, double * v3_r, double * v3_i
) {
	return mc_zreig2x2_approx1(a, e0_r, e0_i, e1_r, e1_i
		, wantv
		, v0_r, v0_i, v1_r, v1_i
		, v2_r, v2_i, v3_r, v3_i
	);
}

MC_TARGET_PROC int mc_zreig2x2l(
	  const long double a[4]
	, long double * e0_r
	, long double * e0_i
	, long double * e1_r
	, long double * e1_i
	, int wantv
	, long double * v0_r, long double * v0_i, long double * v1_r, long double * v1_i
	, long double * v2_r, long double * v2_i, long double * v3_r, long double * v3_i
) {
	return mc_zreig2x2l_approx1(a, e0_r, e0_i, e1_r, e1_i
		, wantv
		, v0_r, v0_i, v1_r, v1_i
		, v2_r, v2_i, v3_r, v3_i
	);
}

#endif /* !MC_ZREIG2X2_H */

/* EOF */
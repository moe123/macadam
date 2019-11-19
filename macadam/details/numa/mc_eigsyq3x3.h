//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eigsyq3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_tredsy3x3.h>
#include <macadam/mcswap.h>

#ifndef MC_EIGSYQ3X3_H
#define MC_EIGSYQ3X3_H

#pragma mark - mc_tredql3x3 -

MC_TARGET_PROC int mc_tredql3x3f(float * v, float d[3], float e[3])
{
	int z = 0, wantv = mc_nonnull(v);
	float b, c, f, h, p, r, s, t;
	int i, j, k, n;

	for (k = 0; k < 2; k++) {
		n = 0;
		do {
			for (j = k; j <= 1; j++) {
				h = mc_fabsf(d[j]) + mc_fabsf(d[j + 1]);
				if (mc_fabsf(e[j]) + h == h) {
					break;
				}
			}

			if (j == k) {
				break;
			}
			z = !z;

			h = (d[k + 1] - d[k]) / (e[k] + e[k]);
			r = mc_sqrtf(mc_raise2f(h) + 1.0f);
			h = h > 0.0f ? (d[j] - d[k] + e[k] / (h + r)) : (d[j] - d[k] + e[k] / (h - r));

			c = 1.0f;
			s = 1.0f;
			p = 0.0f;

			for (i = (j - 1); i >= k; i--) {
				f = s * e[i];
				b = c * e[i];
				if (mc_fabsf(f) > mc_fabsf(h)) {
					c        = h / f;
					r        = mc_sqrtf(mc_raise2f(c) + 1.0f);
					e[i + 1] = f * r;
					s        = 1.0f / r;
					c        = c * s;
				} else {
					s        = f / h;
					r        = mc_sqrtf(mc_raise2f(s) + 1.0f);
					e[i + 1] = h * r;
					c        = 1.0f / r;
					s        = s * c;
				}

				h        = d[i + 1] - p;
				r        = (d[i] - h) * s + 2.0f * c * b;
				p        = s * r;
				d[i + 1] = h + p;
				h        = c * r - b;

				if (wantv) {
					t            = v[i + 1];
					v[i + 1    ] = s * v[i] + c * t;
					v[i        ] = c * v[i] - s * t;

					t            = v[3 + i + 1];
					v[3 + i + 1] = s * v[3 + i] + c * t;
					v[3 + i    ] = c * v[3 + i] - s * t;

					t            = v[6 + i + 1];
					v[6 + i + 1] = s * v[6 + i] + c * t;
					v[6 + i    ] = c * v[6 + i] - s * t;
				}
			}
			d[k] = d[k] - p;
			e[k] = h;
			e[j] = 0.0f;
		} while (++n <= 30);
		if (n >= 30) {
			return -1;
		}
	}
	if (mc_fabsf(d[0]) > mc_fabsf(d[1])) {
		mcswap_var(e[0], d[0], d[1]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[1]);
			mcswap_var(e[0], v[3], v[4]);
			mcswap_var(e[0], v[6], v[7]);
		}
	}
	if (mc_fabsf(d[0]) > mc_fabsf(d[2])) {
		mcswap_var(e[0], d[0], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[2]);
			mcswap_var(e[0], v[3], v[5]);
			mcswap_var(e[0], v[6], v[8]);
		}
	}
	if (mc_fabsf(d[1]) > mc_fabsf(d[2])) {
		mcswap_var(e[0], d[1], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[1], v[2]);
			mcswap_var(e[0], v[4], v[5]);
			mcswap_var(e[0], v[7], v[8]);
		}
	}
	if (z && wantv) {
		v[2] = -v[2];
		v[5] = -v[5];
		v[8] = -v[8];
	}
	return 0;
}

MC_TARGET_PROC int mc_tredql3x3(double * v, double d[3], double e[3])
{
	int z = 0, wantv = mc_nonnull(v);
	double b, c, f, h, p, r, s, t;
	int i, j, k, n;

	for (k = 0; k < 2; k++) {
		n = 0;
		do {
			for (j = k; j <= 1; j++) {
				h = mc_fabs(d[j]) + mc_fabs(d[j + 1]);
				if (mc_fabs(e[j]) + h == h) {
					break;
				}
			}

			if (j == k) {
				break;
			}
			z = !z;

			h = (d[k + 1] - d[k]) / (e[k] + e[k]);
			r = mc_sqrt(mc_raise2(h) + 1.0);
			h = h > 0.0 ? (d[j] - d[k] + e[k] / (h + r)) : (d[j] - d[k] + e[k] / (h - r));

			c = 1.0;
			s = 1.0;
			p = 0.0;

			for (i = (j - 1); i >= k; i--) {
				f = s * e[i];
				b = c * e[i];
				if (mc_fabs(f) > mc_fabs(h)) {
					c        = h / f;
					r        = mc_sqrt(mc_raise2(c) + 1.0);
					e[i + 1] = f * r;
					s        = 1.0 / r;
					c        = c * s;
				} else {
					s        = f / h;
					r        = mc_sqrt(mc_raise2(s) + 1.0);
					e[i + 1] = h * r;
					c        = 1.0 / r;
					s        = s * c;
				}

				h        = d[i + 1] - p;
				r        = (d[i] - h) * s + 2.0 * c * b;
				p        = s * r;
				d[i + 1] = h + p;
				h        = c * r - b;

				if (wantv) {
					t            = v[i + 1];
					v[i + 1    ] = s * v[i] + c * t;
					v[i        ] = c * v[i] - s * t;

					t            = v[3 + i + 1];
					v[3 + i + 1] = s * v[3 + i] + c * t;
					v[3 + i    ] = c * v[3 + i] - s * t;

					t            = v[6 + i + 1];
					v[6 + i + 1] = s * v[6 + i] + c * t;
					v[6 + i    ] = c * v[6 + i] - s * t;
				}
			}
			d[k] = d[k] - p;
			e[k] = h;
			e[j] = 0.0;
		} while (++n <= 90);
		if (n >= 90) {
			return -1;
		}
	}
	fprintf(stderr, "z=%d\n", z);
	if (mc_fabs(d[0]) > mc_fabs(d[1])) {
		mcswap_var(e[0], d[0], d[1]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[1]);
			mcswap_var(e[0], v[3], v[4]);
			mcswap_var(e[0], v[6], v[7]);
		}
	}
	if (mc_fabs(d[0]) > mc_fabs(d[2])) {
		mcswap_var(e[0], d[0], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[2]);
			mcswap_var(e[0], v[3], v[5]);
			mcswap_var(e[0], v[6], v[8]);
		}
	}
	if (mc_fabs(d[1]) > mc_fabs(d[2])) {
		mcswap_var(e[0], d[1], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[1], v[2]);
			mcswap_var(e[0], v[4], v[5]);
			mcswap_var(e[0], v[7], v[8]);
		}
	}
	if (z && wantv) {
		v[2] = -v[2];
		v[5] = -v[5];
		v[8] = -v[8];
	}
	return 0;
}

MC_TARGET_PROC int mc_tredql3x3l(long double * v, long double d[3], long double e[3])
{
	int z = 0, wantv = mc_nonnull(v);
	long double b, c, f, h, p, r, s, t;
	int i, j, k, n;

	for (k = 0; k < 2; k++) {
		n = 0;
		do {
			for (j = k; j <= 1; j++) {
				h = mc_fabsl(d[j]) + mc_fabsl(d[j + 1]);
				if (mc_fabsl(e[j]) + h == h) {
					break;
				}
			}

			if (j == k) {
				break;
			}
			z = !z;

			h = (d[k + 1] - d[k]) / (e[k] + e[k]);
			r = mc_sqrtl(mc_raise2l(h) + 1.0L);
			h = h > 0.0L ? (d[j] - d[k] + e[k] / (h + r)) : (d[j] - d[k] + e[k] / (h - r));

			c = 1.0L;
			s = 1.0L;
			p = 0.0L;

			for (i = (j - 1); i >= k; i--) {
				f = s * e[i];
				b = c * e[i];
				if (mc_fabsl(f) > mc_fabsl(h)) {
					c        = h / f;
					r        = mc_sqrtl(mc_raise2l(c) + 1.0L);
					e[i + 1] = f * r;
					s        = 1.0L / r;
					c        = c * s;
				} else {
					s        = f / h;
					r        = mc_sqrtl(mc_raise2l(s) + 1.0L);
					e[i + 1] = h * r;
					c        = 1.0L / r;
					s        = s * c;
				}

				h        = d[i + 1] - p;
				r        = (d[i] - h) * s + 2.0L * c * b;
				p        = s * r;
				d[i + 1] = h + p;
				h        = c * r - b;

				if (wantv) {
					t            = v[i + 1];
					v[i + 1    ] = s * v[i] + c * t;
					v[i        ] = c * v[i] - s * t;

					t            = v[3 + i + 1];
					v[3 + i + 1] = s * v[3 + i] + c * t;
					v[3 + i    ] = c * v[3 + i] - s * t;

					t            = v[6 + i + 1];
					v[6 + i + 1] = s * v[6 + i] + c * t;
					v[6 + i    ] = c * v[6 + i] - s * t;
				}
			}
			d[k] = d[k] - p;
			e[k] = h;
			e[j] = 0.0L;
		} while (++n <= 120);
		if (n >= 120) {
			return -1;
		}
	}
	if (mc_fabsl(d[0]) > mc_fabsl(d[1])) {
		mcswap_var(e[0], d[0], d[1]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[1]);
			mcswap_var(e[0], v[3], v[4]);
			mcswap_var(e[0], v[6], v[7]);
		}
	}
	if (mc_fabsl(d[0]) > mc_fabsl(d[2])) {
		mcswap_var(e[0], d[0], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[0], v[2]);
			mcswap_var(e[0], v[3], v[5]);
			mcswap_var(e[0], v[6], v[8]);
		}
	}
	if (mc_fabsl(d[1]) > mc_fabsl(d[2])) {
		mcswap_var(e[0], d[1], d[2]);
		if (wantv) {
			mcswap_var(e[0], v[1], v[2]);
			mcswap_var(e[0], v[4], v[5]);
			mcswap_var(e[0], v[7], v[8]);
		}
	}
	if (z && wantv) {
		v[2] = -v[2];
		v[5] = -v[5];
		v[8] = -v[8];
	}
	return 0;
}

#pragma mark - mc_eigsyq3x3 -

MC_TARGET_FUNC int mc_eigsyq3x3f(const float a[9], float e[3], float * v)
{
	int r;
	float w[3]   = { 0 };
	if (0 == (r = mc_tredsy3x3f(a, v, e, w))) {
		r = mc_tredql3x3f(v, e, w);
	}
	return r;
}

MC_TARGET_FUNC int mc_eigsyq3x3(const double a[9], double e[3], double * v)
{
	int r;
	double w[3]  = { 0 };
	if (0 == (r = mc_tredsy3x3(a, v, e, w))) {
		r = mc_tredql3x3(v, e, w);
	}
	return r;
}

MC_TARGET_FUNC int mc_eigsyq3x3l(const long double a[9], long double e[3], long double * v)
{
	int r;
	long double w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3l(a, v, e, w))) {
		r = mc_tredql3x3l(v, e, w);
	}
	return r;
}

#endif /* !MC_EIGSYQ3X3_H */

/* EOF */
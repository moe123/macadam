//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tredql3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_TREDQL3X3_H
#define MC_TREDQL3X3_H

#pragma mark - mc_tredql3x3 -

MC_TARGET_PROC int mc_tredql3x3f(float * a, float d[3], float e[3])
{
	int wanta = mc_nonnull(a);
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

				if (wanta) {
					t            = a[i + 1];
					a[i + 1    ] = s * a[i] + c * t;
					a[i        ] = c * a[i] - s * t;

					t            = a[3 + i + 1];
					a[3 + i + 1] = s * a[3 + i] + c * t;
					a[3 + i    ] = c * a[3 + i] - s * t;

					t            = a[6 + i + 1];
					a[6 + i + 1] = s * a[6 + i] + c * t;
					a[6 + i    ] = c * a[6 + i] - s * t;
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
	return 0;
}

MC_TARGET_PROC int mc_tredql3x3(double * a, double d[3], double e[3])
{
	int wanta = mc_nonnull(a);
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

				if (wanta) {
					t            = a[i + 1];
					a[i + 1    ] = s * a[i] + c * t;
					a[i        ] = c * a[i] - s * t;

					t            = a[3 + i + 1];
					a[3 + i + 1] = s * a[3 + i] + c * t;
					a[3 + i    ] = c * a[3 + i] - s * t;

					t            = a[6 + i + 1];
					a[6 + i + 1] = s * a[6 + i] + c * t;
					a[6 + i    ] = c * a[6 + i] - s * t;
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
	return 0;
}

MC_TARGET_PROC int mc_tredql3x3l(long double * a, long double d[3], long double e[3])
{
	int wanta = mc_nonnull(a);
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

				if (wanta) {
					t            = a[i + 1];
					a[i + 1    ] = s * a[i] + c * t;
					a[i        ] = c * a[i] - s * t;

					t            = a[3 + i + 1];
					a[3 + i + 1] = s * a[3 + i] + c * t;
					a[3 + i    ] = c * a[3 + i] - s * t;

					t            = a[6 + i + 1];
					a[6 + i + 1] = s * a[6 + i] + c * t;
					a[6 + i    ] = c * a[6 + i] - s * t;
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
	return 0;
}

#endif /* !MC_TREDQL3X3_H */

/* EOF */
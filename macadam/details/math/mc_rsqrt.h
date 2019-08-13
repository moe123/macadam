//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rsqrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RSQRT_H
#define MC_RSQRT_H

#pragma mark - mc_rsqrt -

MC_TARGET_FUNC float mc_rsqrtf(float x)
{
#	if MC_TARGET_HAVE_SSE
	__m128 y  = _mm_set_ss(x);
	__m128 e  = _mm_rsqrt_ss(y);
	__m128 e3 = _mm_mul_ss(_mm_mul_ss(e, e), e);
	__m128 h  = _mm_set_ss(0.5f);
	return _mm_cvtss_f32(_mm_add_ss(e, _mm_mul_ss(h, _mm_sub_ss(e, _mm_mul_ss(y, e3)))));
#	elif MC_TARGET_HAVE_NEON
	float32x2_t y = vdup_n_f32(x);
	float32x2_t e = vrsqrte_f32(y);
	e             = vmul_f32(e, vrsqrts_f32(y, vmul_f32(e, e)));
	e             = vmul_f32(e, vrsqrts_f32(y, vmul_f32(e, e)));
	return vget_lane_f32(e, 0);
#	elif MC_TARGET_C99 || MC_TARGET_CPP11
	float y   = x;
	float x_2 = y * 0.5f;
	int32_t i = *(int32_t *)&y;
	i         = 0x5F375A86 - (i >> 1);
	y         = *(float *)&i;
	y         = y * (1.5f - (x_2 * y * y));
	y         = y * (1.5f - (x_2 * y * y));
	return y;
#	else
	float g = 2.0f / x;
	float h = g;
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	g = g * (1.5f - (h) * g * g);
	return g;
#	endif
} 

MC_TARGET_FUNC double mc_rsqrt(double x)
{
#	if MC_TARGET_HAVE_SSE
		double r;
		__m128d v = _mm_set_pd(x, 0);
		v         = _mm_sqrt_pd(v);
		v         = _mm_div_pd(_mm_set_pd(1.0, 0), v);
		_mm_storel_pd(&r, v);
		return r;
#	elif MC_TARGET_C99 || MC_TARGET_CPP11
	double y   = x;
	double x_2 = y * 0.5;
	int64_t i  = *(int64_t *)&y;
	i          = 0x5FE6EB50C7B537A9 - (i >> 1);
	y          = *(double *)&i;
	y          = y * (1.5 - (x_2 * y * y));
	y          = y * (1.5 - (x_2 * y * y));
	return y;
#	else
	double g = 2.0 / x;
	double h = g;
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	g = g * (1.5 - (h) * g * g);
	return g;
#	endif
}

MC_TARGET_FUNC long double mc_rsqrtl(long double x)
{
#	if MC_TARGET_HAVE_SSE
	return mc_cast(long double, mc_rsqrt(mc_cast(double, x)));
#	else
	long double g = 2.0L / x;
	long double h = g;
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	g = g * (1.5L - (h) * g * g);
	return g;
#	endif
}

#endif /* !MC_RSQRT_H */

/* EOF */
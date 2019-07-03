//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_inverf.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>

#ifndef MC_INVERF_H
#define MC_INVERF_H

#pragma mark - mc_inverf -

static MC_TARGET_INLINE float mc_inverff(float x)
{
	float w = 0.0f, z, n, d;
	if(x < -1.0f || x > 1.0f) {
		return NAN;
	} else if (x == -1.0f) {
		return INFINITY;
	} else if (x == 1.0f) {
		return -INFINITY;
	}
#	if MC_TARGET_CPP98
	if (::fabsf(x) <= 0.7f) {
		z = mc_raise2f(x);
		n = ((((-0.140543331f * z + 0.914624893f) * z - 1.645349621f) * z + 0.886226899f));
		d = (((( 0.012229801f * z - 0.329097515f) * z + 1.442710462f) * z - 2.118377725f) * z + 1.0f);
		w = (x * n) / d;
	} else if ((::fabsf(x) > 0.7f) && (::fabsf(x) < 1.0f) ) {
		z = ::sqrtf(-::logf((1.0f - ::fabsf(x)) / 2.0f));
		n = ((1.641345311f * z + 3.429567803f) * z - 1.624906493f) * z - 1.970840454f;
		d = ((1.637067800f * z + 3.543889200f) * z + 1.0f);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (::erff(w) - x) / (MCK_KF(MCK_2_SQRTPI) * ::expf(-w * w));
	w -= (::erff(w) - x) / (MCK_KF(MCK_2_SQRTPI) * ::expf(-w * w));
#	else
	if (fabsf(x) <= 0.7f) {
		z = mc_raise2f(x);
		n = ((((-0.140543331f * z + 0.914624893f) * z - 1.645349621f) * z + 0.886226899f));
		d = (((( 0.012229801f * z - 0.329097515f) * z + 1.442710462f) * z - 2.118377725f) * z + 1.0f);
		w = (x * n) / d;
	} else if ((fabsf(x) > 0.7f) && (fabsf(x) < 1.0f) ) {
		z = sqrtf(-logf((1.0f - fabsf(x)) / 2.0));
		n = ((1.641345311f * z + 3.429567803f) * z - 1.624906493f) * z - 1.970840454f;
		d = ((1.637067800f * z + 3.543889200f) * z + 1.0f);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (erff(w) - x) / (MCK_KF(MCK_2_SQRTPI) * expf(-w * w));
	w -= (erff(w) - x) / (MCK_KF(MCK_2_SQRTPI) * expf(-w * w));
#	endif
	return w;
}

static MC_TARGET_INLINE double mc_inverf(double x)
{
	double w = 0.0, z, n, d;
	if(x < -1.0 || x > 1.0) {
		return NAN;
	} else if (x == -1.0) {
		return INFINITY;
	} else if (x == 1.0) {
		return -INFINITY;
	}
#	if MC_TARGET_CPP98
	if (::fabs(x) <= 0.7) {
		z = mc_raise2(x);
		n = ((((-0.140543331 * z + 0.914624893) * z - 1.645349621) * z + 0.886226899));
		d = (((( 0.012229801 * z - 0.329097515) * z + 1.442710462) * z - 2.118377725) * z + 1.0);
		w = (x * n) / d;
	} else if ((::fabs(x) > 0.7) && (::fabs(x) < 1.0) ) {
		z = ::sqrt(-::log((1.0 - ::fabs(x)) / 2.0));
		n = ((1.641345311 * z + 3.429567803) * z - 1.624906493) * z - 1.970840454;
		d = ((1.637067800 * z + 3.543889200) * z + 1.0);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (::erf(w) - x) / (MCK_K(MCK_2_SQRTPI) * ::exp(-w * w));
	w -= (::erf(w) - x) / (MCK_K(MCK_2_SQRTPI) * ::exp(-w * w));
#	else
	if (fabs(x) <= 0.7) {
		z = mc_raise2(x);
		n = ((((-0.140543331 * z + 0.914624893) * z - 1.645349621) * z + 0.886226899));
		d = (((( 0.012229801 * z - 0.329097515) * z + 1.442710462) * z - 2.118377725) * z + 1.0);
		w = (x * n) / d;
	} else if ((fabs(x) > 0.7) && (fabs(x) < 1.0) ) {
		z = sqrt(-log((1.0 - fabs(x)) / 2.0));
		n = ((1.641345311 * z + 3.429567803) * z - 1.624906493) * z - 1.970840454;
		d = ((1.637067800 * z + 3.543889200) * z + 1.0);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (erf(w) - x) / (MCK_K(MCK_2_SQRTPI) * exp(-w * w));
	w -= (erf(w) - x) / (MCK_K(MCK_2_SQRTPI) * exp(-w * w));
#	endif
	return w;
}

static MC_TARGET_INLINE long double mc_inverfl(long double x)
{
	long double w = 0.0L, z, n, d;
	if(x < -1.0L || x > 1.0L) {
		return NAN;
	} else if (x == -1.0L) {
		return INFINITY;
	} else if (x == 1.0L) {
		return -INFINITY;
	}
#	if MC_TARGET_CPP98
	if (::fabsl(x) <= 0.7L) {
		z = mc_raise2l(x);
		n = ((((-0.140543331L * z + 0.914624893L) * z - 1.645349621L) * z + 0.886226899L));
		d = (((( 0.012229801L * z - 0.329097515L) * z + 1.442710462L) * z - 2.118377725L) * z + 1.0L);
		w = (x * n) / d;
	} else if ((::fabsl(x) > 0.7L) && (::fabsl(x) < 1.0L) ) {
		z = ::sqrtl(-::logl((1.0L - ::fabsl(x)) / 2.0L));
		n = ((1.641345311L * z + 3.429567803L) * z - 1.624906493L) * z - 1.970840454L;
		d = ((1.637067800L * z + 3.543889200L) * z + 1.0L);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (::erfl(w) - x) / (MCK_KL(MCK_2_SQRTPI) * ::expl(-w * w));
	w -= (::erfl(w) - x) / (MCK_KL(MCK_2_SQRTPI) * ::expl(-w * w));
#	else
	if (fabsl(x) <= 0.7L) {
		z = mc_raise2l(x);
		n = ((((-0.140543331L * z + 0.914624893L) * z - 1.645349621L) * z + 0.886226899L));
		d = (((( 0.012229801L * z - 0.329097515L) * z + 1.442710462L) * z - 2.118377725L) * z + 1.0L);
		w = (x * n) / d;
	} else if ((fabsl(x) > 0.7L) && (fabsl(x) < 1.0L) ) {
		z = sqrtl(-logl((1.0L - fabsl(x)) / 2.0L));
		n = ((1.641345311L * z + 3.429567803L) * z - 1.624906493L) * z - 1.970840454L;
		d = ((1.637067800L * z + 3.543889200L) * z + 1.0L);
		w = (x < 0 ? -n : n) / d;
	}
	w -= (erfl(w) - x) / (MCK_KL(MCK_2_SQRTPI) * expl(-w * w));
	w -= (erfl(w) - x) / (MCK_KL(MCK_2_SQRTPI) * expl(-w * w));
#	endif
	return w;
}

#endif /* !MC_INVERF_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_gammaquo.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_ffrac.h>
#include <macadam/details/math/mc_fisval.h>
#include <macadam/details/math/mc_gammasign.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_rgamma.h>
#include <macadam/details/math/mc_sinpi.h>

#ifndef MC_GAMMAQUO_H
#define MC_GAMMAQUO_H

#pragma mark - mc_gammaquo -

MC_TARGET_FUNC float mc_gammaquof(float x, float d)
{
//!# Returns gamma(x) / gamma(x + d).
	float r = MCK_NAN;
	if (x == (x + d)) {
		r = 1.0f;
	} else if (x > 0.0f  && (x + d) > 0.0f) {
		if (x <= MCLIMITS_EPSILONF) {
			r = mc_rgammaf(x + d);
			if (mc_fisvalf(r)) {
				r = r * (1.0f / x);
			}
			if (!mc_fisvalf(r)) {
				r = mc_lgammaf_approx1(x + d, MC_NULLPTR);
				if (mc_fisvalf(r)) {
					r = r + mc_logf(x);
					r = mc_expf(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasignf(x) * mc_gammasignf(x + d));
			r = r * mc_expf(mc_lgammaf_approx1(x, MC_NULLPTR) - mc_lgammaf_approx1(x + d, MC_NULLPTR));
		}
	} else if ((x + d) <= 0.0f && mc_fisintf(x + d)) {
		if (x > 0.0f || !mc_fisintf(x)) {
			r = 0.0f;
		} else {
			if ((1.0f - x) <= MCLIMITS_EPSILONF) {
				r = mc_rgammaf((1.0f - x) + (-d));
				if (mc_fisvalf(r)) {
					r = r * (1.0f / (1.0f - x));
				}
				if (!mc_fisvalf(r)) {
					r = mc_lgammaf_approx1((1.0f - x) + (-d), MC_NULLPTR);
					if (mc_fisvalf(r)) {
						r = r + mc_logf((1.0f - x));
						r = mc_expf(-r);
					} else {
						r = MCK_NAN;
					}
				}
			} else {
				r = (mc_gammasignf((1.0f - x)) * mc_gammasignf((1.0f - x) + (-d)));
				r = r * mc_expf(mc_lgammaf_approx1((1.0f - x), MC_NULLPTR) - mc_lgammaf_approx1((1.0f - x) + (-d), MC_NULLPTR));
			}
			if (r != 0.0f && mc_fisvalf(r)) {
				if (mc_ffracf(0.5f * x) != mc_ffracf(0.5f * (x + d))) {
					r = -r;
				}
				r = 1.0f / r;
			}
		}
	} else if (x < 0.0f && (x + d) < 0.0f) {
		if ((1.0f - x) <= MCLIMITS_EPSILONF) {
			r = mc_rgammaf((1.0f - x) + (-d));
			if (mc_fisvalf(r)) {
				r = r * (1.0f / (1.0f - x));
			}
			if (!mc_fisvalf(r)) {
				r = mc_lgammaf_approx1((1.0f - x) + (-d), MC_NULLPTR);
				if (mc_fisvalf(r)) {
					r = r + mc_logf((1.0f - x));
					r = mc_expf(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasignf((1.0f - x)) * mc_gammasignf((1.0f - x) + (-d)));
			r = r * mc_expf(mc_lgammaf_approx1((1.0f - x), MC_NULLPTR) - mc_lgammaf_approx1((1.0f - x) + (-d), MC_NULLPTR));
		}
		if (mc_fisvalf(r)) {
			r = mc_sinpif(x) * r;
			r = mc_sinpif(x + d) * (1.0f / r);
		}
	} else {
		r = (mc_gammasignf(x) * mc_gammasignf(x + d));
		r = r * mc_expf(mc_lgammaf_approx1(x, MC_NULLPTR) - mc_lgammaf_approx1(x + d, MC_NULLPTR));
	}
	if (!mc_fisvalf(r)) {
		r = MCK_NAN;
	}
	return r;
}

MC_TARGET_FUNC double mc_gammaquo(double x, double d)
{
//!# Returns gamma(x) / gamma(x + d).
	double r = MCK_NAN;
	if (x == (x + d)) {
		r = 1.0;
	} else if (x > 0.0  && (x + d) > 0.0) {
		if (x <= MCLIMITS_EPSILON) {
			r = mc_rgamma(x + d);
			if (mc_fisval(r)) {
				r = r * (1.0 / x);
			}
			if (!mc_fisval(r)) {
				r = mc_lgamma_approx1(x + d, MC_NULLPTR);
				if (mc_fisval(r)) {
					r = r + mc_log(x);
					r = mc_exp(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasign(x) * mc_gammasign(x + d));
			r = r * mc_exp(mc_lgamma_approx1(x, MC_NULLPTR) - mc_lgamma_approx1(x + d, MC_NULLPTR));
		}
	} else if ((x + d) <= 0.0 && mc_fisint(x + d)) {
		if (x > 0.0 || !mc_fisint(x)) {
			r = 0.0;
		} else {
			if ((1.0 - x) <= MCLIMITS_EPSILON) {
				r = mc_rgamma((1.0 - x) + (-d));
				if (mc_fisval(r)) {
					r = r * (1.0 / (1.0 - x));
				}
				if (!mc_fisval(r)) {
					r = mc_lgamma_approx1((1.0 - x) + (-d), MC_NULLPTR);
					if (mc_fisval(r)) {
						r = r + mc_log((1.0 - x));
						r = mc_exp(-r);
					} else {
						r = MCK_NAN;
					}
				}
			} else {
				r = (mc_gammasign((1.0 - x)) * mc_gammasign((1.0 - x) + (-d)));
				r = r * mc_exp(mc_lgamma_approx1((1.0 - x), MC_NULLPTR) - mc_lgamma_approx1((1.0 - x) + (-d), MC_NULLPTR));
			}
			if (r != 0.0 && mc_fisval(r)) {
				if (mc_ffrac(0.5 * x) != mc_ffrac(0.5 * (x + d))) {
					r = -r;
				}
				r = 1.0 / r;
			}
		}
	} else if (x < 0.0 && (x + d) < 0.0) {
		if ((1.0 - x) <= MCLIMITS_EPSILON) {
			r = mc_rgamma((1.0 - x) + (-d));
			if (mc_fisval(r)) {
				r = r * (1.0 / (1.0 - x));
			}
			if (!mc_fisval(r)) {
				r = mc_lgamma_approx1((1.0 - x) + (-d), MC_NULLPTR);
				if (mc_fisval(r)) {
					r = r + mc_log((1.0 - x));
					r = mc_exp(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasign((1.0 - x)) * mc_gammasign((1.0 - x) + (-d)));
			r = r * mc_exp(mc_lgamma_approx1((1.0 - x), MC_NULLPTR) - mc_lgamma_approx1((1.0 - x) + (-d), MC_NULLPTR));
		}
		if (mc_fisval(r)) {
			r = mc_sinpi(x) * r;
			r = mc_sinpi(x + d) * (1.0 / r);
		}
	} else {
		r = (mc_gammasign(x) * mc_gammasign(x + d));
		r = r * mc_exp(mc_lgamma_approx1(x, MC_NULLPTR) - mc_lgamma_approx1(x + d, MC_NULLPTR));
	}
	if (!mc_fisval(r)) {
		r = MCK_NAN;
	}
	return r;
}

MC_TARGET_FUNC long double mc_gammaquol(long double x, long double d)
{
//!# Returns gamma(x) / gamma(x + d).
	long double r = MCK_NAN;
	if (x == (x + d)) {
		r = 1.0L;
	} else if (x > 0.0L  && (x + d) > 0.0L) {
		if (x <= MCLIMITS_EPSILONL) {
			r = mc_rgammal(x + d);
			if (mc_fisvall(r)) {
				r = r * (1.0L / x);
			}
			if (!mc_fisvall(r)) {
				r = mc_lgammal_approx1(x + d, MC_NULLPTR);
				if (mc_fisvall(r)) {
					r = r + mc_logl(x);
					r = mc_expl(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasignl(x) * mc_gammasignl(x + d));
			r = r * mc_expl(mc_lgammal_approx1(x, MC_NULLPTR) - mc_lgammal_approx1(x + d, MC_NULLPTR));
		}
	} else if ((x + d) <= 0.0L && mc_fisintl(x + d)) {
		if (x > 0.0L || !mc_fisintl(x)) {
			r = 0.0L;
		} else {
			if ((1.0L - x) <= MCLIMITS_EPSILONL) {
				r = mc_rgammal((1.0L - x) + (-d));
				if (mc_fisvall(r)) {
					r = r * (1.0L / (1.0L - x));
				}
				if (!mc_fisvall(r)) {
					r = mc_lgammal_approx1((1.0L - x) + (-d), MC_NULLPTR);
					if (mc_fisvall(r)) {
						r = r + mc_logl((1.0L - x));
						r = mc_expl(-r);
					} else {
						r = MCK_NAN;
					}
				}
			} else {
				r = (mc_gammasignl((1.0L - x)) * mc_gammasignl((1.0L - x) + (-d)));
				r = r * mc_expl(mc_lgammal_approx1((1.0L - x), MC_NULLPTR) - mc_lgammal_approx1((1.0L - x) + (-d), MC_NULLPTR));
			}
			if (r != 0.0L && mc_fisvall(r)) {
				if (mc_ffracl(0.5L * x) != mc_ffracl(0.5L * (x + d))) {
					r = -r;
				}
				r = 1.0L / r;
			}
		}
	} else if (x < 0.0L && (x + d) < 0.0L) {
		if ((1.0L - x) <= MCLIMITS_EPSILONL) {
			r = mc_rgammal((1.0L - x) + (-d));
			if (mc_fisvall(r)) {
				r = r * (1.0L / (1.0L - x));
			}
			if (!mc_fisvall(r)) {
				r = mc_lgammal_approx1((1.0L - x) + (-d), MC_NULLPTR);
				if (mc_fisvall(r)) {
					r = r + mc_logl((1.0L - x));
					r = mc_expl(-r);
				} else {
					r = MCK_NAN;
				}
			}
		} else {
			r = (mc_gammasignl((1.0L - x)) * mc_gammasignl((1.0L - x) + (-d)));
			r = r * mc_expl(mc_lgammal_approx1((1.0L - x), MC_NULLPTR) - mc_lgammal_approx1((1.0L - x) + (-d), MC_NULLPTR));
		}
		if (mc_fisvall(r)) {
			r = mc_sinpil(x) * r;
			r = mc_sinpil(x + d) * (1.0L / r);
		}
	} else {
		r = (mc_gammasignl(x) * mc_gammasignl(x + d));
		r = r * mc_expl(mc_lgammal_approx1(x, MC_NULLPTR) - mc_lgammal_approx1(x + d, MC_NULLPTR));
	}
	if (!mc_fisvall(r)) {
		r = MCK_NAN;
	}
	return r;
}

#endif /* !MC_GAMMAQUO_H */

/* EOF */
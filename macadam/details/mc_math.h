//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_math.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_MATH_H
#define MC_MATH_H

#	include <macadam/details/math/mc_absmag.h>
#	include <macadam/details/math/mc_absrsqrt.h>
#	include <macadam/details/math/mc_abssqrt.h>
#	include <macadam/details/math/mc_acosh.h>
#	include <macadam/details/math/mc_acospi.h>
#	include <macadam/details/math/mc_acot.h>
#	include <macadam/details/math/mc_acoth.h>
#	include <macadam/details/math/mc_acsch.h>
#	include <macadam/details/math/mc_asech.h>
#	include <macadam/details/math/mc_asinh.h>
#	include <macadam/details/math/mc_asinpi.h>
#	include <macadam/details/math/mc_atan2pi.h>
#	include <macadam/details/math/mc_atan.h>
#	include <macadam/details/math/mc_atanh.h>
#	include <macadam/details/math/mc_atanh.h>
#	include <macadam/details/math/mc_atanpi.h>
#	include <macadam/details/math/mc_bessel.h>
#	include <macadam/details/math/mc_besseli.h>
#	include <macadam/details/math/mc_besselj.h>
#	include <macadam/details/math/mc_bessely.h>
#	include <macadam/details/math/mc_beta.h>
#	include <macadam/details/math/mc_binomial.h>
#	include <macadam/details/math/mc_bisquare.h>
#	include <macadam/details/math/mc_biweight.h>
#	include <macadam/details/math/mc_choose.h>
#	include <macadam/details/math/mc_cospi.h>
#	include <macadam/details/math/mc_digamma.h>
#	include <macadam/details/math/mc_erf.h>
#	include <macadam/details/math/mc_eta.h>
#	include <macadam/details/math/mc_exp.h>
#	include <macadam/details/math/mc_exp10.h>
#	include <macadam/details/math/mc_exp10m1.h>
#	include <macadam/details/math/mc_exp2.h>
#	include <macadam/details/math/mc_exp2m1.h>
#	include <macadam/details/math/mc_expit.h>
#	include <macadam/details/math/mc_expm1.h>
#	include <macadam/details/math/mc_fabs.h>
#	include <macadam/details/math/mc_factorial.h>
#	include <macadam/details/math/mc_fhrt.h>
#	include <macadam/details/math/mc_floor.h>
#	include <macadam/details/math/mc_fmod.h>
#	include <macadam/details/math/mc_gamma.h>
#	include <macadam/details/math/mc_gammap.h>
#	include <macadam/details/math/mc_gammaq.h>
#	include <macadam/details/math/mc_gcd.h>
#	include <macadam/details/math/mc_hermite_hen.h>
#	include <macadam/details/math/mc_hermite_hn.h>
#	include <macadam/details/math/mc_hypotc.h>
#	include <macadam/details/math/mc_hypotq.h>
#	include <macadam/details/math/mc_hzeta.h>
#	include <macadam/details/math/mc_igammac.h>
#	include <macadam/details/math/mc_igammad.h>
#	include <macadam/details/math/mc_inverf.h>
#	include <macadam/details/math/mc_invlogit.h>
#	include <macadam/details/math/mc_invprobit.h>
#	include <macadam/details/math/mc_ipow2.h>
#	include <macadam/details/math/mc_isfinite.h>
#	include <macadam/details/math/mc_isinf.h>
#	include <macadam/details/math/mc_isnan.h>
#	include <macadam/details/math/mc_lbeta.h>
#	include <macadam/details/math/mc_lchoose.h>
#	include <macadam/details/math/mc_lcm.h>
#	include <macadam/details/math/mc_ldexp.h>
#	include <macadam/details/math/mc_legendre_pn.h>
#	include <macadam/details/math/mc_legendre_qn.h>
#	include <macadam/details/math/mc_lerp.h>
#	include <macadam/details/math/mc_lgamma.h>
#	include <macadam/details/math/mc_log.h>
#	include <macadam/details/math/mc_log10.h>
#	include <macadam/details/math/mc_log10p1.h>
#	include <macadam/details/math/mc_log1m.h>
#	include <macadam/details/math/mc_log1me.h>
#	include <macadam/details/math/mc_log1p.h>
#	include <macadam/details/math/mc_log1pe.h>
#	include <macadam/details/math/mc_log2.h>
#	include <macadam/details/math/mc_log2p1.h>
#	include <macadam/details/math/mc_logaddexp.h>
#	include <macadam/details/math/mc_logdiffexp.h>
#	include <macadam/details/math/mc_logistic.h>
#	include <macadam/details/math/mc_logit.h>
#	include <macadam/details/math/mc_logodds.h>
#	include <macadam/details/math/mc_logp1.h>
#	include <macadam/details/math/mc_logradix.h>
#	include <macadam/details/math/mc_logsubexp.h>
#	include <macadam/details/math/mc_maxmag.h>
#	include <macadam/details/math/mc_minmag.h>
#	include <macadam/details/math/mc_nchoosek.h>
#	include <macadam/details/math/mc_nthroot.h>
#	include <macadam/details/math/mc_pow.h>
#	include <macadam/details/math/mc_pow2.h>
#	include <macadam/details/math/mc_powm1.h>
#	include <macadam/details/math/mc_probit.h>
#	include <macadam/details/math/mc_raise2.h>
#	include <macadam/details/math/mc_raise3.h>
#	include <macadam/details/math/mc_raise4.h>
#	include <macadam/details/math/mc_raise5.h>
#	include <macadam/details/math/mc_raise6.h>
#	include <macadam/details/math/mc_rbeta.h>
#	include <macadam/details/math/mc_rootn.h>
#	include <macadam/details/math/mc_rsqr.h>
#	include <macadam/details/math/mc_rsqrt.h>
#	include <macadam/details/math/mc_scalb.h>
#	include <macadam/details/math/mc_sigmoid.h>
#	include <macadam/details/math/mc_sin.h>
#	include <macadam/details/math/mc_sinc.h>
#	include <macadam/details/math/mc_sincos.h>
#	include <macadam/details/math/mc_sinhcosh.h>
#	include <macadam/details/math/mc_sinpi.h>
#	include <macadam/details/math/mc_sqr.h>
#	include <macadam/details/math/mc_sqrt.h>
#	include <macadam/details/math/mc_sqrt1pm1.h>
#	include <macadam/details/math/mc_tanpi.h>
#	include <macadam/details/math/mc_trigamma.h>
#	include <macadam/details/math/mc_trigonometry.h>
#	include <macadam/details/math/mc_trunc.h>
#	include <macadam/details/math/mc_xlog1px.h>
#	include <macadam/details/math/mc_xlog1py.h>
#	include <macadam/details/math/mc_xlogp1x.h>
#	include <macadam/details/math/mc_xlogp1y.h>
#	include <macadam/details/math/mc_xlogx.h>
#	include <macadam/details/math/mc_xlogy.h>
#	include <macadam/details/math/mc_xpolyevaln.h>
#	include <macadam/details/math/mc_zeta.h>
#	include <macadam/details/math/mc_zetap.h>

#endif /* !MC_MATH_H */

/* EOF */
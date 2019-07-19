from libc.stdint cimport *

cdef extern from "<macadam/details/math/mc_absrsqrt.h>":
	float mc_absrsqrtf(float x)
	double mc_absrsqrt(double x)
	long double mc_absrsqrtl(long double x)

cdef extern from "<macadam/details/math/mc_abssqrt.h>":
	float mc_abssqrtf(float x)
	double mc_abssqrt(double x)
	long double mc_abssqrtl(long double x)

cdef extern from "<macadam/details/math/mc_acos.h>":
	float mc_acosf(float x)
	double mc_acos(double x)
	long double mc_acosl(long double x)

cdef extern from "<macadam/details/math/mc_acosh.h>":
	float mc_acoshf(float x)
	double mc_acosh(double x)
	long double mc_acoshl(long double x)

cdef extern from "<macadam/details/math/mc_acospi.h>":
	float mc_acospif (float x)
	double mc_acospi(double x)
	long double mc_acospil(long double x)

cdef extern from "<macadam/details/math/mc_acot.h>":
	float mc_acotf(float x)
	double mc_acot(double x)
	long double mc_acotl(long double x)

cdef extern from "<macadam/details/math/mc_acoth.h>":
	float mc_acothf(float x)
	double mc_acoth(double x)
	long double mc_acothl(long double x)

cdef extern from "<macadam/details/math/mc_acsc.h>":
	float mc_acscf(float x)
	double mc_acsc(double x)
	long double mc_acscl(long double x)

cdef extern from "<macadam/details/math/mc_acsch.h>":
	float mc_acschf(float x)
	double mc_acsch(double x)
	long double mc_acschl(long double x)

cdef extern from "<macadam/details/math/mc_asec.h>":
	float mc_asecf(float x)
	double mc_asec(double x)
	long double mc_asecl(long double x)

cdef extern from "<macadam/details/math/mc_asech.h>":
	float mc_asechf(float x)
	double mc_asech(double x)
	long double mc_asechl(long double x)

cdef extern from "<macadam/details/math/mc_asin.h>":
	float mc_asinf(float x)
	double mc_asin(double x)
	long double mc_asinl(long double x)

cdef extern from "<macadam/details/math/mc_asinh.h>":
	float mc_asinhf(float x)
	double mc_asinh(double x)
	long double mc_asinhl(long double x)

cdef extern from "<macadam/details/math/mc_asinpi.h>":
	float mc_asinpif (float x)
	double mc_asinpi(double x)
	long double mc_asinpil(long double x)

cdef extern from "<macadam/details/math/mc_atan.h>":
	float mc_atanf(float x)
	double mc_atan(double x)
	long double mc_atanl(long double x)

cdef extern from "<macadam/details/math/mc_atan2.h>":
	float mc_atan2f(float y, float x)
	double mc_atan2(double y, double x)
	long double mc_atan2l(long double y, long double x)

cdef extern from "<macadam/details/math/mc_atan2pi.h>":
	float mc_atan2pif (float y, float x)
	double mc_atan2pi(double y, double x)
	long double mc_atan2pil(long double y, long double x)

cdef extern from "<macadam/details/math/mc_atanh.h>":
	float mc_atanhf(float x)
	double mc_atanh(double x)
	long double mc_atanhl(long double x)

cdef extern from "<macadam/details/math/mc_atanpi.h>":
	float mc_atanpif (float x)
	double mc_atanpi(double x)
	long double mc_atanpil(long double x)

cdef extern from "<macadam/details/math/mc_besseli.h>":
	float mc_besseli0f(float x)
	double mc_besseli0(double x)
	long double mc_besseli0l(long double x)
	float mc_besseli1f(float x)
	double mc_besseli1(double x)
	long double mc_besseli1l(long double x)
	float mc_besselinf(int n, float x)
	double mc_besselin(int n, double x)
	long double mc_besselinl(int n, long double x)

cdef extern from "<macadam/details/math/mc_besselj.h>":
	float mc_besselj0f(float x)
	double mc_besselj0(double x)
	long double mc_besselj0l(long double x)
	float mc_besselj1f(float x)
	double mc_besselj1(double x)
	long double mc_besselj1l(long double x)
	float mc_besseljnf(int n, float x)
	double mc_besseljn(int n, double x)
	long double mc_besseljnl(int n, long double x)

cdef extern from "<macadam/details/math/mc_bessely.h>":
	float mc_bessely0f(float x)
	double mc_bessely0(double x)
	long double mc_bessely0l(long double x)
	float mc_bessely1f(float x)
	double mc_bessely1(double x)
	long double mc_bessely1l(long double x)
	float mc_besselynf(int n, float x)
	double mc_besselyn(int n, double x)
	long double mc_besselynl(int n, long double x)

cdef extern from "<macadam/details/math/mc_binomial.h>":
	float mc_binomialf(unsigned int n, unsigned int k)
	double mc_binomial(unsigned int n, unsigned int k)
	long double mc_binomiall(unsigned int n, unsigned int k)

cdef extern from "<macadam/details/math/mc_bisquare.h>":
	float mc_bisquaref(float x, float k)
	double mc_bisquare(double x, double k)
	long double mc_bisquarel(long double x, long double k)

cdef extern from "<macadam/details/math/mc_biweight.h>":
	float mc_biweightf(float x)
	double mc_biweight(double x)
	long double mc_biweightl(long double x)

cdef extern from "<macadam/details/math/mc_cbrt.h>":
	float mc_cbrtf(float x)
	double mc_cbrt(double x)
	long double mc_cbrtl(long double x)

cdef extern from "<macadam/details/math/mc_ceil.h>":
	float mc_ceilf(float x)
	double mc_ceil(double x)
	long double mc_ceill(long double x)

cdef extern from "<macadam/details/math/mc_choose.h>":
	float mc_choosef(unsigned int n, unsigned int k)
	double mc_choose(unsigned int n, unsigned int k)
	long double mc_choosel(unsigned int n, unsigned int k)

cdef extern from "<macadam/details/math/mc_cos.h>":
	float mc_cosf(float x)
	double mc_cos(double x)
	long double mc_cosl(long double x)

cdef extern from "<macadam/details/math/mc_cosh.h>":
	float mc_coshf(float x)
	double mc_cosh(double x)
	long double mc_coshl(long double x)

cdef extern from "<macadam/details/math/mc_cospi.h>":
	float mc_cospif (float x)
	double mc_cospi(double x)
	long double mc_cospil(long double x)

cdef extern from "<macadam/details/math/mc_cot.h>":
	float mc_cotf(float x)
	double mc_cot(double x)
	long double mc_cotl(long double x)

cdef extern from "<macadam/details/math/mc_coth.h>":
	float mc_cothf(float x)
	double mc_coth(double x)
	long double mc_cothl(long double x)

cdef extern from "<macadam/details/math/mc_csc.h>":
	float mc_cscf(float x)
	double mc_csc(double x)
	long double mc_cscl(long double x)

cdef extern from "<macadam/details/math/mc_csch.h>":
	float mc_cschf(float x)
	double mc_csch(double x)
	long double mc_cschl(long double x)

cdef extern from "<macadam/details/math/mc_digamma.h>":
	float mc_digammaf(float x)
	double mc_digamma(double x)
	long double mc_digammal(long double x)

cdef extern from "<macadam/details/math/mc_erf.h>":
	float mc_erff(float x)
	double mc_erf(double x)
	long double mc_erfl(long double x)

cdef extern from "<macadam/details/math/mc_erfc.h>":
	float mc_erfcf(float x)
	double mc_erfc(double x)
	long double mc_erfcl(long double x)

cdef extern from "<macadam/details/math/mc_eta.h>":
	float mc_etaf(float x)
	double mc_eta(double x)
	long double mc_etal(long double x)

cdef extern from "<macadam/details/math/mc_exp.h>":
	float mc_expf(float x)
	double mc_exp(double x)
	long double mc_expl(long double x)

cdef extern from "<macadam/details/math/mc_exp10.h>":
	float mc_exp10f(float x)
	double mc_exp10(double x)
	long double mc_exp10l(long double x)

cdef extern from "<macadam/details/math/mc_exp10m1.h>":
	float mc_exp10m1f(float x)
	double mc_exp10m1(double x)
	long double mc_exp10m1l(long double x)

cdef extern from "<macadam/details/math/mc_exp2.h>":
	float mc_exp2f(float x)
	double mc_exp2(double x)
	long double mc_exp2l(long double x)

cdef extern from "<macadam/details/math/mc_exp2m1.h>":
	float mc_exp2m1f(float x)
	double mc_exp2m1(double x)
	long double mc_exp2m1l(long double x)

cdef extern from "<macadam/details/math/mc_expit.h>":
	float mc_expitf(float x)
	double mc_expit(double x)
	long double mc_expitl(long double x)

cdef extern from "<macadam/details/math/mc_expm1.h>":
	float mc_expm1f(float x)
	double mc_expm1(double x)
	long double mc_expm1l(long double x)

cdef extern from "<macadam/details/math/mc_fabs.h>":
	float mc_fabsf(float x)
	double mc_fabs(double x)
	long double mc_fabsl(long double x)

cdef extern from "<macadam/details/math/mc_factorial.h>":
	float mc_factorialf(unsigned int x)
	double mc_factorial(unsigned int x)
	long double mc_factoriall(unsigned int x)

cdef extern from "<macadam/details/math/mc_ffrac.h>":
	float mc_ffracf(float x)
	double mc_ffrac(double x)
	long double mc_ffracl(long double x)

cdef extern from "<macadam/details/math/mc_fhrt.h>":
	float mc_fhrtf(float x)
	double mc_fhrt(double x)
	long double mc_fhrtl(long double x)

cdef extern from "<macadam/details/math/mc_fisint.h>":
	int mc_fisintf(float x)
	int mc_fisint(double x)
	int mc_fisintl(long double x)

cdef extern from "<macadam/details/math/mc_floor.h>":
	float mc_floorf(float x)
	double mc_floor(double x)
	long double mc_floorl(long double x)

cdef extern from "<macadam/details/math/mc_fmod.h>":
	float mc_fmodf(float x, float y)
	double mc_fmod(double x, double y)
	long double mc_fmodl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_gammap.h>":
	float mc_gammapf(float a, float z)
	double mc_gammap(double a, double z)
	long double mc_gammapl(long double a, long double z)

cdef extern from "<macadam/details/math/mc_gammaq.h>":
	float mc_gammaqf(float a, float z)
	double mc_gammaq(double a, double z)
	long double mc_gammaql(long double a, long double z)

cdef extern from "<macadam/details/math/mc_gammasign.h>":
	float mc_gammasignf(float x)
	double mc_gammasign(double x)
	long double mc_gammasignl(long double x)

cdef extern from "<macadam/details/math/mc_gcd.h>":
	int mc_igcd(int m, int n)
	long mc_lgcd(long m, long n)
	long long mc_llgcd(long long m, long long n)

cdef extern from "<macadam/details/math/mc_hermite_hen.h>":
	float mc_hermite_henf(unsigned int n, float x)
	double mc_hermite_hen(unsigned int n, double x)
	long double mc_hermite_henl(unsigned int n, long double x)

cdef extern from "<macadam/details/math/mc_hermite_hn.h>":
	float mc_hermite_h0f(float x)
	double mc_hermite_h0(double x)
	long  double mc_hermite_h0l(long double x)
	float mc_hermite_h1f(float x)
	double mc_hermite_h1(double x)
	long  double mc_hermite_h1l(long double x)
	float mc_hermite_hnf(unsigned int n, float x)
	double mc_hermite_hn(unsigned int n, double x)
	long double mc_hermite_hnl(unsigned int n, long double x)

cdef extern from "<macadam/details/math/mc_hypot.h>":
	float mc_hypotf(float x, float y)
	double mc_hypot(double x, double y)
	long double mc_hypotl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_hypotc.h>":
	float mc_hypotcf(float x, float y, float z)
	double mc_hypotc(double x, double y, double z)
	long double mc_hypotcl(long double x, long double y, long double z)

cdef extern from "<macadam/details/math/mc_hypotq.h>":
	float mc_hypotqf(float x, float y)
	double mc_hypotq(double x, double y)
	long double mc_hypotql(long double x, long double y)

cdef extern from "<macadam/details/math/mc_hzeta.h>":
	float mc_hzetaf(float s, float q)
	double mc_hzeta(double s, double q)
	long double mc_hzetal(long double s, long double q)

cdef extern from "<macadam/details/math/mc_ilog2.h>":
	int mc_ilog2(int x)
	long mc_llog2(long x)
	long long mc_lllog2(long long x)

cdef extern from "<macadam/details/math/mc_inverf.h>":
	float mc_inverff(float x)
	double mc_inverf(double x)
	long double mc_inverfl(long double x)

cdef extern from "<macadam/details/math/mc_invlogit.h>":
	float mc_invlogitf(float x)
	double mc_invlogit(double x)
	long double mc_invlogitl(long double x)

cdef extern from "<macadam/details/math/mc_invprobit.h>":
	float mc_invprobitf(float x)
	double mc_invprobit(double x)
	long double mc_invprobitl(long double x)

cdef extern from "<macadam/details/math/mc_ipow2.h>":
	float mc_ipow2f(int x)
	double mc_ipow2(int x)
	long double mc_ipow2l(int x)

cdef extern from "<macadam/details/math/mc_lbeta.h>":
	float mc_lbetaf(float x, float y)
	double mc_lbeta(double x, double y)
	long double mc_lbetal(long double x, long double y)

cdef extern from "<macadam/details/math/mc_lchoose.h>":
	float mc_lchoosef(float x, float y)
	double mc_lchoose(double x, double y)
	long double mc_lchoosel(long double x, long double y)

cdef extern from "<macadam/details/math/mc_lcm.h>":
	int mc_ilcm(int m, int n)
	long mc_llcm(long m, long n)
	long mc_lllcm(long long m, long long n)

cdef extern from "<macadam/details/math/mc_ldexp.h>":
	float mc_ldexpf(float x, int n)
	double mc_ldexp(double x, int n)
	long double mc_ldexpl(long double x, int n)

cdef extern from "<macadam/details/math/mc_legendre_pn.h>":
	float mc_legendre_pnf(unsigned int n, float x)
	double mc_legendre_pn(unsigned int n, double x)
	long double mc_legendre_pnl(unsigned int n, long double x)

cdef extern from "<macadam/details/math/mc_legendre_pnm.h>":
	float mc_legendre_pnmf(int n, int m, float x)
	double mc_legendre_pnm(int n, int m, double x)
	long double mc_legendre_pnml(int n, int m, long double x)

cdef extern from "<macadam/details/math/mc_lerp.h>":
	float mc_lerpf(float x, float y, float z)
	double mc_lerp(double x, double y, double z)
	long double mc_lerpl(long double x, long double y, long double z)

cdef extern from "<macadam/details/math/mc_lgamma.h>":
	float mc_lgammaf(float x)
	double mc_lgamma(double x)
	long double mc_lgammal(long double x)

cdef extern from "<macadam/details/math/mc_log.h>":
	float mc_logf(float x)
	double mc_log(double x)
	long double mc_logl(long double x)

cdef extern from "<macadam/details/math/mc_log10.h>":
	float mc_log10f(float x)
	double mc_log10(double x)
	long double mc_log10l(long double x)

cdef extern from "<macadam/details/math/mc_log10p1.h>":
	float  mc_log10p1f(float x)
	double  mc_log10p1(double x)
	long double  mc_log10p1l(long double x)

cdef extern from "<macadam/details/math/mc_log1m.h>":
	float mc_log1mf(float x)
	double mc_log1m(double x)
	long double mc_log1ml(long double x)

cdef extern from "<macadam/details/math/mc_log1me.h>":
	float mc_log1mef(float x)
	double mc_log1me(double x)
	long double mc_log1mel(long double x)

cdef extern from "<macadam/details/math/mc_log1p.h>":
	float mc_log1pf(float x)
	double mc_log1p(double x)
	long double mc_log1pl(long double x)

cdef extern from "<macadam/details/math/mc_log1pe.h>":
	float mc_log1pef(float x)
	double mc_log1pe(double x)
	long double mc_log1pel(long double x)

cdef extern from "<macadam/details/math/mc_log2.h>":
	float mc_log2f(float x)
	double mc_log2(double x)
	long double mc_log2l(long double x)

cdef extern from "<macadam/details/math/mc_log2p1.h>":
	float mc_log2p1f(float x)
	double mc_log2p1(double x)
	long double mc_log2p1l(long double x)

cdef extern from "<macadam/details/math/mc_logaddexp.h>":
	float mc_logaddexpf(float x, float y)
	double mc_logaddexp(double x, double y)
	long double mc_logaddexpl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_logdiffexp.h>":
	float mc_logdiffexpf(float x, float y)
	double mc_logdiffexp(double x, double y)
	long double mc_logdiffexpl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_logistic.h>":
	float mc_logisticf(float x, float l)
	double mc_logistic(double x, double l)
	long double mc_logisticl(long double x, long double l)

cdef extern from "<macadam/details/math/mc_logit.h>":
	float mc_logitf(float x)
	double mc_logit(double x)
	long double mc_logitl(long double x)

cdef extern from "<macadam/details/math/mc_logodds.h>":
	float mc_logoddsf(float x, float l)
	double mc_logodds(double x, double l)
	long double mc_logoddsl(long double x, long double l)

cdef extern from "<macadam/details/math/mc_logp1.h>":
	float mc_logp1f(float x)
	double mc_logp1(double x)
	long double mc_logp1l(long double x)

cdef extern from "<macadam/details/math/mc_logradix.h>":
	float mc_logradixf(float x, int n)
	double mc_logradix(double x, int n)
	long double mc_logradixl(long double x, int n)

cdef extern from "<macadam/details/math/mc_logsubexp.h>":
	float mc_logsubexpf(float x, float y)
	double mc_logsubexp(double x, double y)
	long double mc_logsubexpl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_modf.h>":
	float mc_modff(float x, float * y)
	double mc_modf(double x, double * y)
	long double mc_modfl(long double x, long double * y)

cdef extern from "<macadam/details/math/mc_nchoosek.h>":
	unsigned int mc_nchoosek(unsigned int n, unsigned int k)

cdef extern from "<macadam/details/math/mc_pow.h>":
	float mc_powf(float x, float y)
	double mc_pow(double x, double y)
	long double mc_powl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_pow2.h>":
	float mc_pow2f(float x)
	double mc_pow2(double x)
	long double mc_pow2l(long double x)

cdef extern from "<macadam/details/math/mc_powm1.h>":
	float mc_powm1f(float x, float y)
	double mc_powm1(double x, double y)
	long double mc_powm1l(long double x, long double y)

cdef extern from "<macadam/details/math/mc_probit.h>":
	float mc_probitf(float x)
	double mc_probit(double x)
	long double mc_probitl(long double x)

cdef extern from "<macadam/details/math/mc_raise2.h>":
	float mc_raise2f(float x)
	double mc_raise2(double x)
	long double mc_raise2l(long double x)

cdef extern from "<macadam/details/math/mc_raise3.h>":
	float mc_raise3f(float x)
	double mc_raise3(double x)
	long double mc_raise3l(long double x)

cdef extern from "<macadam/details/math/mc_raise4.h>":
	float mc_raise4f(float x)
	double mc_raise4(double x)
	long double mc_raise4l(long double x)

cdef extern from "<macadam/details/math/mc_raise5.h>":
	float mc_raise5f(float x)
	double mc_raise5(double x)
	long double mc_raise5l(long double x)

cdef extern from "<macadam/details/math/mc_raise6.h>":
	float mc_raise6f(float x)
	double mc_raise6(double x)
	long double mc_raise6l(long double x)

cdef extern from "<macadam/details/math/mc_rbeta.h>":
	float mc_rbetaf(float a, float b, float x)
	double mc_rbeta(double a, double b, double x)
	long double mc_rbetal(long double a, long double b, long double x)

cdef extern from "<macadam/details/math/mc_rootn.h>":
	float mc_rootnf(float x, unsigned int n)
	double mc_rootn(double x, unsigned int n)
	long double mc_rootnl(long double x, unsigned int n)

cdef extern from "<macadam/details/math/mc_rsqr.h>":
	float mc_rsqrf(float x)
	double mc_rsqr(double x)
	long double mc_rsqrl(long double x)

cdef extern from "<macadam/details/math/mc_rsqrt.h>":
	float mc_rsqrtf(float x)
	double mc_rsqrt(double x)
	long double mc_rsqrtl(long double x)

cdef extern from "<macadam/details/math/mc_scalb.h>":
	float mc_scalbf(float x, float y)
	double mc_scalb(double x, double y)
	long double mc_scalbl(long double x, long double y)
	float mc_scalbf(float x, float y)
	long double mc_scalbl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_sec.h>":
	float mc_secf(float x)
	double mc_sec(double x)
	long double mc_secl(long double x)

cdef extern from "<macadam/details/math/mc_sech.h>":
	float mc_sechf(float x)
	double mc_sech(double x)
	long double mc_sechl(long double x)

cdef extern from "<macadam/details/math/mc_sigmoid.h>":
	float mc_sigmoidf(float x)
	double mc_sigmoid(double x)
	long double mc_sigmoidl(long double x)

cdef extern from "<macadam/details/math/mc_sin.h>":
	float mc_sinf(float x)
	double mc_sin(double x)
	long double mc_sinl(long double x)

cdef extern from "<macadam/details/math/mc_sinc.h>":
	float mc_sincf(float x)
	double mc_sinc(double x)
	long double mc_sincl(long double x)

cdef extern from "<macadam/details/math/mc_sincos.h>":
	void mc_sincosf(float x, float * sinp, float * cosp)
	void mc_sincos(double x, double * sinp, double * cosp)
	void mc_sincosl(long double x, long double * sinp, long double * cosp)

cdef extern from "<macadam/details/math/mc_sinh.h>":
	float mc_sinhf(float x)
	double mc_sinh(double x)
	long double mc_sinhl(long double x)

cdef extern from "<macadam/details/math/mc_sinhcosh.h>":
	void mc_sinhcoshf(float x, float * mc_sinhp, float * mc_coshp)
	void mc_sinhcosh(double x, double * mc_sinhp, double * mc_coshp)
	void mc_sinhcoshl(long double x, long double * mc_sinhp, long double * mc_coshp)

cdef extern from "<macadam/details/math/mc_sinpi.h>":
	float mc_sinpif (float x)
	double mc_sinpi(double x)
	long double mc_sinpil(long double x)

cdef extern from "<macadam/details/math/mc_sqr.h>":
	float mc_sqrf(float x)
	double mc_sqr(double x)
	long double mc_sqrl(long double x)

cdef extern from "<macadam/details/math/mc_sqrt.h>":
	float mc_sqrtf(float x)
	double mc_sqrt(double x)
	long double mc_sqrtl(long double x)

cdef extern from "<macadam/details/math/mc_sqrt1pm1.h>":
	float mc_sqrt1pm1f(float x)
	double mc_sqrt1pm1(double x)
	long double mc_sqrt1pm1l(long double x)

cdef extern from "<macadam/details/math/mc_tan.h>":
	float mc_tanf(float x)
	double mc_tan(double x)
	long double mc_tanl(long double x)

cdef extern from "<macadam/details/math/mc_tanh.h>":
	float mc_tanhf(float x)
	double mc_tanh(double x)
	long double mc_tanhl(long double x)

cdef extern from "<macadam/details/math/mc_tanpi.h>":
	float mc_tanpif (float x)
	double mc_tanpi(double x)
	long double mc_tanpil(long double x)

cdef extern from "<macadam/details/math/mc_trigamma.h>":
	float mc_trigammaf(float x)
	double mc_trigamma(double x)
	long double mc_trigammal(long double x)

cdef extern from "<macadam/details/math/mc_trunc.h>":
	float mc_truncf(float x)
	double mc_trunc(double x)
	long double mc_truncl(long double x)

cdef extern from "<macadam/details/math/mc_xlog1px.h>":
	float mc_xlog1pxf(float x)
	double mc_xlog1px(double x)
	long double mc_xlog1pxl(long double x)

cdef extern from "<macadam/details/math/mc_xlog1py.h>":
	float mc_xlog1pyf(float x, float y)
	double mc_xlog1py(double x, double y)
	long double mc_xlog1pyl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_xlogp1x.h>":
	float mc_xlogp1xf(float x)
	double mc_xlogp1x(double x)
	long double mc_xlogp1xl(long double x)

cdef extern from "<macadam/details/math/mc_xlogp1y.h>":
	float mc_xlogp1yf(float x, float y)
	double mc_xlogp1y(double x, double y)
	long double mc_xlogp1yl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_xlogx.h>":
	float mc_xlogxf(float x)
	double mc_xlogx(double x)
	long double mc_xlogxl(long double x)

cdef extern from "<macadam/details/math/mc_xlogy.h>":
	float mc_xlogyf(float x, float y)
	double mc_xlogy(double x, double y)
	long double mc_xlogyl(long double x, long double y)

cdef extern from "<macadam/details/math/mc_zeta.h>":
	float mc_zetaf(float x)
	double mc_zeta(double x)
	long double mc_zetal(long double x)

# EOF
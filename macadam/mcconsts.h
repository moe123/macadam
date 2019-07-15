//
// # -*- coding: utf-8, tab-width: 3 -*-

// mcconsts.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MCCONSTS_H
#define MCCONSTS_H

#	if MCTRAGET_CPP98
#	if MCTRAGET_CPP11
#		define MCK_NAN ::std::NAN
#		define MCK_INF ::std::INFINITY
#	else
#		define MCK_NAN ::NAN
#		define MCK_INF ::INFINITY
#	endif
#	else
#		define MCK_NAN NAN
#		define MCK_INF INFINITY
#	endif

#	define MCK_INFP +MCK_INF
#	define MCK_INFN -MCK_INF

//!# Value of Euler's number e=exp(1).
#	ifndef M_E
#	define M_E           +2.718281828459045235360287471352662497757247093699959574966E+00
#	endif

//!# Value of log2(e).
#	ifndef M_LOG2E
#	define M_LOG2E       +1.442695040888963407359924681001892137426645954152985934135E+00
#	endif

//!# Value of log10(e).
#	ifndef M_LOG10E
#	define M_LOG10E      +0.434294481903251827651128918916605082294397005803666566114E+00
#	endif

//!# Value of loge(2).
#	ifndef M_LN2
#	define M_LN2         +0.693147180559945309417232121458176568075500134360255254120E+00
#	endif

//!# Value of loge(10).
#	ifndef M_LN10
#	define M_LN10        +2.302585092994045684017991454684364207601101488628772976033E+00
#	endif

//!# Value of pi.
#	ifndef M_PI
#	define M_PI          +3.141592653589793238462643383279502884197169399375105820974E+00
#	endif

//!# Value of pi/2.
#	ifndef M_PI_2
#	define M_PI_2        +1.570796326794896619231321691639751442098584699687552910487E+00
#	endif

//!# Value of pi/4.
#	ifndef M_PI_4
#	define M_PI_4        +0.785398163397448309615660845819875721049292349843776455243E+00
#	endif

//!# Value of 1/pi.
#	ifndef M_1_PI
#	define M_1_PI        +0.318309886183790671537767526745028724068919291480912897495E+00
#	endif

//!# Value of 2/pi.
#	ifndef M_2_PI
#	define M_2_PI        +0.636619772367581343075535053490057448137838582961825794990E+00
#	endif

//!# Value of 2/sqrt(pi).
#	ifndef M_2_SQRTPI
#	define M_2_SQRTPI    +1.128379167095512573896158903121545171688101258657997713688E+00
#	endif

//!# Value of sqrt(2).
#	ifndef M_SQRT2
#	define M_SQRT2       +1.414213562373095048801688724209698078569671875376948073176E+00
#	endif

//!# Value of 1/sqrt(2).
#	ifndef M_SQRT1_2
#	define M_SQRT1_2     +0.707106781186547524400844362104849039284835937688474036588E+00
#	endif

#pragma mark -

//!# Value of Euler's number e=exp(1).
#	define MCK_E          M_E

//!# Value of 1/e.
#	define MCK_1_E       +0.367879441171442321595523770161460867445811131031767834507E+00

//!# Value of Euler–Mascheroni's gamma.
#	define MCK_G         +0.577215664901532860606512090082402431042159335939923598805E+00

//!# Value of Glaisher-Kinkelin constant.
#	define MCK_A         +1.282427129100622636875342568869791727767688927325001192063E+00

//!# Value of log2(e).
#	define MCK_LOG2E      M_LOG2E

//!# Value of log10(e).
#	define MCK_LOG10E     M_LOG10E

//!# Value of loge(2).
#	define MCK_LOG2       M_LN2

//!# Value of log10(2).
#	define MCK_LOG102    +0.301029995663981195213738894724493026768189881462108541310E+00

//!# Value of 1/loge(2).
#	define MCK_1_LOG2     M_LOG2E

//!# Value of log2(10).
#	define MCK_LOG210    +3.321928094887362347870319429489390175864831393024580612054E+00

//!# Integer part of log2(10).
#	define MCK_LOG210Q    3.0

//!# Fractional part of log2(10).
#	define MCK_LOG210R    0.321928094887362347870319429489390175864831393024580612054E+00

//!# Value of loge(10).
#	define MCK_LOG10      M_LN10

//!# Value of pi.
#	define MCK_PI         M_PI

//!# Value of 2*pi.
#	define MCK_2PI       +6.283185307179586476925286766559005768394338798750211641949E+00

//!# Value of pi^2.
#	define MCK_PI2       +9.869604401089358618834490999876151135313699407240790626413E+00

//!# Value of pi^2/6.
#	define MCK_PI2_6     +1.644934066848226436472415166646025189218949901206798437735E+00

//!# Value of pi^4
#	define MCK_PI4       +97.40909103400243723644033268870511124972758567268542169146E+00

//!# Value of pi^4/90.
#	define MCK_PI4_90    +1.082323233711138191516003696541167902774750951918726907682E+00

//!# Value of pi/2.
#	define MCK_PI_2       M_PI_2

//!# Value of pi/4.
#	define MCK_PI_4       M_PI_4

//!# Value of 1/pi.
#	define MCK_1_PI       M_1_PI

//!# Value of 2/pi.
#	define MCK_2_PI       M_2_PI

//!# Value of 2/sqrt(pi).
#	define MCK_2_SQRTPI   M_2_SQRTPI

//!# Value of sqrt(pi).
#	define MCK_SQRTPI    +1.772453850905516027298167483341145182797549456122387128213E+00

//!# Value of sqrt(2/pi).
#	define MCK_SQRT2_PI  +0.797884560802865355879892119868763736951717262329869315331E+00

//!# Value of log(sqrt(pi)).
#	define MCK_LSQRTPI   +0.572364942924700087071713675676529355823647406457655785756E+00

//!# Value of log(sqrt(2*pi)).
#	define MCK_LSQRT2PI  +0.918938533204672741780329736405617639861397473637783412817E+00

//!# Value of log(sqrt(pi/2)).
#	define MCK_LSQRTPI_2 +0.225791352644727432363097614947441071785897339277528158696E+00

//!# Value of sqrt(1).
#	define MCK_SQRT1     +1.0

//!# Value of sqrt(2).
#	define MCK_SQRT2      M_SQRT2

//!# Value of sqrt(3).
#	define MCK_SQRT3     +1.732050807568877293527446341505872366942805253810380628055E+00

//!# Value of sqrt(4).
#	define MCK_SQRT4     +2.0

//!# Value of sqrt(5).
#	define MCK_SQRT5     +2.236067977499789696409173668731276235440618359611525724270E+00

//!# Value of sqrt(6).
#	define MCK_SQRT6     +2.449489742783178098197284074705891391965947480656670128432E+00

//!# Value of sqrt(7).
#	define MCK_SQRT7     +2.645751311064590590501615753639260425710259183082450180368E+00

//!# Value of sqrt(8).
#	define MCK_SQRT8     +2.828427124746190097603377448419396157139343750753896146353E+00

//!# Value of sqrt(9).
#	define MCK_SQRT9     +3.0

#	define MCK_SQRT10    +3.162277660168379331998893544432718533719555139325216826857E+00
#	define MCK_SQRT11    +3.316624790355399849114932736670686683927088545589353597058E+00
#	define MCK_SQRT12    +3.464101615137754587054892683011744733885610507620761256111E+00
#	define MCK_SQRT13    +3.605551275463989293119221267470495946251296573845246212710E+00
#	define MCK_SQRT14    +3.741657386773941385583748732316549301756019807778726946303E+00
#	define MCK_SQRT15    +3.872983346207416885179265399782399610832921705291590826587E+00

#	define MCK_SQRT16    +4.0
#	define MCK_SQRT17    +4.123105625617660549821409855974077025147199225373620434398E+00
#	define MCK_SQRT18    +4.242640687119285146405066172629094235709015626130844219530E+00
#	define MCK_SQRT19    +4.358898943540673552236981983859615659137003925232444936890E+00
#	define MCK_SQRT20    +4.472135954999579392818347337462552470881236719223051448541E+00
#	define MCK_SQRT21    +4.582575694955840006588047193728008488984456576767971902607E+00
#	define MCK_SQRT22    +4.690415759823429554565630113544466280588228353411737153605E+00
#	define MCK_SQRT23    +4.795831523312719541597438064162693919996707041904129346485E+00
#	define MCK_SQRT24    +4.898979485566356196394568149411782783931894961313340256865E+00

#	define MCK_SQRT25    +5.0
#	define MCK_SQRT26    +5.099019513592784830028224109022781989563770946099596407584E+00
#	define MCK_SQRT27    +5.196152422706631880582339024517617100828415761431141884167E+00
#	define MCK_SQRT28    +5.291502622129181181003231507278520851420518366164900360736E+00
#	define MCK_SQRT29    +5.385164807134504031250710491540329556295120161644788837680E+00
#	define MCK_SQRT30    +5.477225575051661134569697828008021339527446949979832542268E+00
#	define MCK_SQRT31    +5.567764362830021922119471298918549520476393377570414303968E+00
#	define MCK_SQRT32    +5.656854249492380195206754896838792314278687501507792292706E+00
#	define MCK_SQRT33    +5.744562646538028659850611468218929318220264457982792367699E+00
#	define MCK_SQRT34    +5.830951894845300470874152877545583076521398334885971954450E+00

//!# Value of sqrt(2pi).
#	define MCK_SQRT2PI   +2.506628274631000502415765284811045253006986740609938316629E+00

//!# Value of 1/sqrt(1).
#	define MCK_1_SQRT1   +1.0

//!# Value of 1/sqrt(2).
#	define MCK_1_SQRT2   M_SQRT1_2

//!# Value of 1/sqrt(3).
#	define MCK_1_SQRT3   +0.577350269189625764509148780501957455647601751270126876018E+00

//!# Value of 1/sqrt(4).
#	define MCK_1_SQRT4   +0.5

//!# Value of 1/sqrt(5).
#	define MCK_1_SQRT5   +0.447213595499957939281834733746255247088123671922305144854E+00

//!# Value of 1/sqrt(6).
#	define MCK_1_SQRT6   +0.408248290463863016366214012450981898660991246776111688072E+00

//!# Value of 1/sqrt(7).
#	define MCK_1_SQRT7   +0.377964473009227227214516536234180060815751311868921454338E+00

//!# Value of 1/sqrt(8).
#	define MCK_1_SQRT8   +0.353553390593273762200422181052424519642417968844237018294E+00

//!# Value of 1/sqrt(9).
#	define MCK_1_SQRT9   +0.333333333333333333333333333333333333333333333333333333333E+00

//!# Value of 1/sqrt(2pi).
#	define MCK_1_SQRT2PI +0.398942280401432677939946059934381868475858631164934657665E+00

//!# Bernoulli numbers.
#	define MCK_BN0       +1.000000000000000000000000000000000000000000000000000000000E+00
#	define MCK_BN1       +0.500000000000000000000000000000000000000000000000000000000E+00

#	define MCK_BN2       +0.166666666666666666666666666666666666666666666666666666666E+00
#	define MCK_BN4       -0.033333333333333333333333333333333333333333333333333333333E+00
#	define MCK_BN6       +0.023809523809523809523809523809523809523809523809523809523E+00
#	define MCK_BN8       -0.033333333333333333333333333333333333333333333333333333333E+00
#	define MCK_BN10      +0.075757575757575757575757575757575757575757575757575757575E+00
#	define MCK_BN12      -0.253113553113553113553113553113553113553113553113553113553E+00
#	define MCK_BN14      +1.166666666666666666666666666666666666666666666666666666666E+00
#	define MCK_BN16      -7.092156862745098039215686274509803921568627450980392156862E+00
#	define MCK_BN18      +54.97117794486215538847117794486215538847117794486215538847E+00
#	define MCK_BN20      -529.1242424242424242424242424242424242424242424242424242424E+00
#	define MCK_BN22      +6.192123188405797101600000000000000000000000000000000000000E+3
#	define MCK_BN24      -8.658025311355311355000000000000000000000000000000000000000E+4
#	define MCK_BN26      +1.425517166666666666600000000000000000000000000000000000000E+6
#	define MCK_BN28      -2.729823106781609195400000000000000000000000000000000000000E+7
#	define MCK_BN30      +6.015808739006423683600000000000000000000000000000000000000E+8
#	define MCK_BN32      -1.511631576709215686300000000000000000000000000000000000000E+10
#	define MCK_BN34      +4.296146430611666666600000000000000000000000000000000000000E+11
#	define MCK_BN36      -1.371165520508833277200000000000000000000000000000000000000E+13
#	define MCK_BN38      +4.883323189735931666600000000000000000000000000000000000000E+14
#	define MCK_BN40      -1.929657934194006814800000000000000000000000000000000000000E+16
#	define MCK_BN42      +8.416930475736826150000000000000000000000000000000000000000E+17
#	define MCK_BN44      -4.033807185405945541200000000000000000000000000000000000000E+19
#	define MCK_BN46      +2.115074863808199160600000000000000000000000000000000000000E+21
#	define MCK_BN48      -1.208662652229652593400000000000000000000000000000000000000E+23
#	define MCK_BN50      +7.500866746076964366800000000000000000000000000000000000000E+24
#	define MCK_BN52      -5.038778101481068914300000000000000000000000000000000000000E+26
#	define MCK_BN54      +3.652877648481812333400000000000000000000000000000000000000E+28
#	define MCK_BN56      -2.849876930245088222600000000000000000000000000000000000000E+30
#	define MCK_BN58      +2.386542749968362764500000000000000000000000000000000000000E+32
#	define MCK_BN60      -2.139994925722533366600000000000000000000000000000000000000E+34
#	define MCK_BN62      +2.050097572347809757000000000000000000000000000000000000000E+36
#	define MCK_BN64      -2.093800591134637840800000000000000000000000000000000000000E+38
#	define MCK_BN66      +2.275269648846351555900000000000000000000000000000000000000E+40
#	define MCK_BN68      -2.625771028623957604700000000000000000000000000000000000000E+42
#	define MCK_BN70      +3.212508210271803251800000000000000000000000000000000000000E+44
#	define MCK_BN72      -4.159827816679471091400000000000000000000000000000000000000E+46
#	define MCK_BN74      +5.692069548203528002300000000000000000000000000000000000000E+48
#	define MCK_BN76      -8.218362941978457569400000000000000000000000000000000000000E+50
#	define MCK_BN78      +1.250290432716699301700000000000000000000000000000000000000E+53
#	define MCK_BN80      -2.001558323324837027500000000000000000000000000000000000000E+55
#	define MCK_BN82      +3.367498291536437423200000000000000000000000000000000000000E+57
#	define MCK_BN84      -5.947097050313544771800000000000000000000000000000000000000E+59
#	define MCK_BN86      +1.101191032362797756000000000000000000000000000000000000000E+62
#	define MCK_BN88      -2.135525954525350118800000000000000000000000000000000000000E+64
#	define MCK_BN90      +4.332889698664119241800000000000000000000000000000000000000E+66
#	define MCK_BN92      -9.188552824166932822800000000000000000000000000000000000000E+68
#	define MCK_BN94      +2.034689677632907449300000000000000000000000000000000000000E+71
#	define MCK_BN96      -4.700383395803573107700000000000000000000000000000000000000E+73
#	define MCK_BN98      +1.131804344548424927100000000000000000000000000000000000000E+76
#	define MCK_BN100     -2.838224957069370695800000000000000000000000000000000000000E+78
#	define MCK_BN102     +7.406424897967885063200000000000000000000000000000000000000E+80
#	define MCK_BN104     -2.009645480275660448400000000000000000000000000000000000000E+83
#	define MCK_BN106     +5.665717005080594144500000000000000000000000000000000000000E+85
#	define MCK_BN108     -1.658451115413621691600000000000000000000000000000000000000E+88
#	define MCK_BN110     +5.036885995049237741800000000000000000000000000000000000000E+90
#	define MCK_BN112     -1.586146823765818636900000000000000000000000000000000000000E+93
#	define MCK_BN114     +5.175674361754562698400000000000000000000000000000000000000E+95
#	define MCK_BN116     -1.748892184021711734000000000000000000000000000000000000000E+98
#	define MCK_BN118     +6.116051999495218525400000000000000000000000000000000000000E+100
#	define MCK_BN120     -2.212277691270783494200000000000000000000000000000000000000E+103

//!# Value of 1/2.
#	define MCK_1_2       +0.500000000000000000000000000000000000000000000000000000000E+00

//!# Value of 1/3.
#	define MCK_1_3       +0.333333333333333333333333333333333333333333333333333333333E+00

//!# Value of 1/4.
#	define MCK_1_4       +0.250000000000000000000000000000000000000000000000000000000E+00

//!# Value of 1/8.
#	define MCK_1_8       +0.125000000000000000000000000000000000000000000000000000000E+00

//!# Value of 1/12.
#	define MCK_1_12      +0.083333333333333333333333333333333333333333333333333333333E+00

//!# Value of 1/24.
#	define MCK_1_24      +0.041666666666666666666666666666666666666666666666666666666E+00

//!# Value of 1/120.
#	define MCK_1_120     +0.008333333333333333333333333333333333333333333333333333333E+00

//!# Value of 1/132.
#	define MCK_1_132     +0.007575757575757575757575757575757575757575757575757575757E+00

//!# Value of 1/240.
#	define MCK_1_240     +0.004166666666666666666666666666666666666666666666666666666E+00

//!# Value of 1/252.
#	define MCK_1_252     +0.003968253968253968253968253968253968253968253968253968253E+00

//!# Value of 1/360.
#	define MCK_1_360     +0.002777777777777777777777777777777777777777777777777777777E+00

//!# Value of 1/1260.
#	define MCK_1_1260    +0.000793650793650793650793650793650793650793650793650793650E+00

//!# Value of 2/3.
#	define MCK_2_3       +0.666666666666666666666666666666666666666666666666666666666E+00

//!# Value of 3/2.
#	define MCK_3_2       +1.500000000000000000000000000000000000000000000000000000000E+00

//!# Value of 5/2.
#	define MCK_5_2       +2.500000000000000000000000000000000000000000000000000000000E+00

//!# Value of 8/15.
#	define MCK_8_15      +0.533333333333333333333333333333333333333333333333333333333E+00

//!# Value of 35/8.
#	define MCK_35_8      +4.375000000000000000000000000000000000000000000000000000000E+00

//!# Value of 49/8.
#	define MCK_49_8      +6.125000000000000000000000000000000000000000000000000000000E+00

//!# Value of 55/24.
#	define MCK_55_24     +2.291666666666666666666666666666666666666666666666666666666E+00

//!# Value of 63/8.
#	define MCK_63_8      +7.875000000000000000000000000000000000000000000000000000000E+00

//!# Value of 691/32760.
#	define MCK_691_32760 +0.003968253968253968253968253968253968253968253968253968253E+00

//!# Value ~zeta(0).
#	define MCK_ZETA0     -0.500000000000000000000000000000000000000000000000000000000E+00

//!# Value ~zeta(-1).
#	define MCK_ZETA_N1    -MCK_1_12

//!# Value ~zeta(-3).
#	define MCK_ZETA_N3    +MCK_1_120

//!# Value ~zeta(-5).
#	define MCK_ZETA_N5    -MCK_1_252

//!# Value ~zeta(-7).
#	define MCK_ZETA_N7    +MCK_1_240

//!# Value ~zeta(-9).
#	define MCK_ZETA_N9    -MCK_1_132

//!# Value ~zeta(-11).
#	define MCK_ZETA_N11   +MCK_691_32760

//!# Value ~zeta(-12).
#	define MCK_ZETA_N12   +0.0

#define MCK_KF(K) (mc_cast_exp(const float, K))
#define MCK_K(K)  (mc_cast_exp(const double, K))
#define MCK_KL(K) (mc_cast_exp(const long double, K))

#endif /* !MCCONSTS_H */

/* EOF */
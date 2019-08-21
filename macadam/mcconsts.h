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
#	define MCK_LOG210Q   +3.0

//!# Fractional part of log2(10).
#	define MCK_LOG210R   +0.321928094887362347870319429489390175864831393024580612054E+00

//!# Value of loge(10).
#	define MCK_LOG10      M_LN10

//!# Value of 1/loge(10).
#	define MCK_1_LOG10   +0.434294481903251827651128918916605082294397005803666566114E+00

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

#	define MCK_LOGPI     +1.144729885849400174143427351353058711647294812915311571513E+00

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

//!# Bernoulli numbers B2n.
#	define MCK_BN2       +1.666666666666666574148081281236954964697360992431640625000E-01
#	define MCK_BN4       -3.333333333333333287074040640618477482348680496215820312500E-02
#	define MCK_BN6       +2.380952380952380820211544687481364235281944274902343750000E-02
#	define MCK_BN8       -3.333333333333333287074040640618477482348680496215820312500E-02
#	define MCK_BN10      +7.575757575757575967845269815370556898415088653564453125000E-02
#	define MCK_BN12      -2.531135531135531024915508169215172529220581054687500000000E-01
#	define MCK_BN14      +1.166666666666666740681534975010436028242111206054687500000E+00
#	define MCK_BN16      -7.092156862745097711808739404659718275070190429687500000000E+00
#	define MCK_BN18      +5.497117794486215558436015271581709384918212890625000000000E+01
#	define MCK_BN20      -5.291242424242424249314353801310062408447265625000000000000E+02
#	define MCK_BN22      +6.192123188405797009181696921586990356445312500000000000000E+03
#	define MCK_BN24      -8.658025311355311714578419923782348632812500000000000000000E+04
#	define MCK_BN26      +1.425517166666666744276881217956542968750000000000000000000E+06
#	define MCK_BN28      -2.729823106781609356403350830078125000000000000000000000000E+07
#	define MCK_BN30      +6.015808739006423950195312500000000000000000000000000000000E+08
#	define MCK_BN32      -1.511631576709215736389160156250000000000000000000000000000E+10
#	define MCK_BN34      +4.296146430611666870117187500000000000000000000000000000000E+11
#	define MCK_BN36      -1.371165520508833203125000000000000000000000000000000000000E+13
#	define MCK_BN38      +4.883323189735931875000000000000000000000000000000000000000E+14
#	define MCK_BN40      -1.929657934194006800000000000000000000000000000000000000000E+16
#	define MCK_BN42      +8.416930475736825600000000000000000000000000000000000000000E+17
#	define MCK_BN44      -4.033807185405945446400000000000000000000000000000000000000E+19
#	define MCK_BN46      +2.115074863808199262208000000000000000000000000000000000000E+21
#	define MCK_BN48      -1.208662652229652620247040000000000000000000000000000000000E+23
#	define MCK_BN50      +7.500866746076964166041600000000000000000000000000000000000E+24
#	define MCK_BN52      -5.038778101481068849874862080000000000000000000000000000000E+26
#	define MCK_BN54      +3.652877648481812227556586291200000000000000000000000000000E+28
#	define MCK_BN56      -2.849876930245088236122601947136000000000000000000000000000E+30
#	define MCK_BN58      +2.386542749968362744796290723348480000000000000000000000000E+32
#	define MCK_BN60      -2.139994925722533485948652372570931200000000000000000000000E+34
#	define MCK_BN62      +2.050097572347809739009841803334516736000000000000000000000E+36
#	define MCK_BN64      -2.093800591134637930126474156401083023360000000000000000000E+38

#	define MCK_BN66      +2.275269648846351486285821826473401725747200000000000000000E+40
#	define MCK_BN68      -2.625771028623957720729781252781663963840512000000000000000E+42
#	define MCK_BN70      +3.212508210271803174284353517902252463966126080000000000000E+44
#	define MCK_BN72      -4.159827816679471197820027632551292248630545612800000000000E+46
#	define MCK_BN74      +5.692069548203528317355790461742945664460956631040000000000E+48
#	define MCK_BN76      -8.218362941978457766498766971898335402620356153835520000000E+50
#	define MCK_BN78      +1.250290432716699400421815713913615904890249748613693440000E+53
#	define MCK_BN80      -2.001558323324837005179256836618343758910173679329266892800E+55
#	define MCK_BN82      +3.367498291536437555623746663418789430021835942007050076160E+57
#	define MCK_BN84      -5.947097050313545020497504980536459190538792521117989066506E+59
#	define MCK_BN86      +1.101191032362797676156189769705662027064040121152751280157E+62
#	define MCK_BN88      -2.135525954525350207883674669233657105945686752790530583576E+64
#	define MCK_BN90      +4.332889698664119384671158414652150889163849167738765903394E+66
#	define MCK_BN92      -9.188552824166933181065339055374482943053837053782453392898E+68
#	define MCK_BN94      +2.034689677632907370763344991579971719763300925992969415675E+71
#	define MCK_BN96      -4.700383395803573015767497401594855577727251959409356514894E+73
#	define MCK_BN98      +1.131804344548424941072581731366008343544947033010486049543E+76
#	define MCK_BN100     -2.838224957069370735406342499107608127141603375805558726521E+78
#	define MCK_BN102     +7.406424897967885293547485988650422079291886480025830894412E+80
#	define MCK_BN104     -2.009645480275660526207039422210972577968776257944677329962E+83
#	define MCK_BN106     +5.665717005080594208872332689771487718797066738021851615864E+85
#	define MCK_BN108     -1.658451115413621590354050889781835074824223866919761959889E+88
#	define MCK_BN110     +5.036885995049237838964782987478715724484686628148728064628E+90
#	define MCK_BN112     -1.586146823765818562977513052715619305681091385218903038429E+93
#	define MCK_BN114     +5.175674361754562518932024777965703468577691752687065889666E+95
#	define MCK_BN116     -1.748892184021711584618203495033421163880301611203183428639E+98
#	define MCK_BN118     +6.116051999495218235895423169103328043685229284479428153989E+100
#	define MCK_BN120     -2.212277691270783319357167165537428849902026026318921856715E+103

#	define MCK_BN122     +8.272277679877096876606137764315274903709154043454250545745E+105
#	define MCK_BN124     -3.195892511141570847764095105239941129360246816251823963037E+108
#	define MCK_BN126     +1.275008222338779313959203179797323487197811005286674781139E+111
#	define MCK_BN128     -5.250092308677413134679856863184493530232079989575802835371E+113
#	define MCK_BN130     +2.230181789424162663446503544082111060093678780321838856969E+116
#	define MCK_BN132     -9.768452193095520742204084456550644735887900646950494836848E+118
#	define MCK_BN134     +4.409836197845294982056981254956629675779234416180793016787E+121
#	define MCK_BN136     -2.050857088646408895743576321686700756484464155367609538558E+124
#	define MCK_BN138     +9.821443327979127658076074360779821752388798972149388002105E+126
#	define MCK_BN140     -4.841260079820888056914518865954567458927841242447389145517E+129
#	define MCK_BN142     +2.455308880148098232041334894791407719159311326603727413797E+132
#	define MCK_BN144     -1.280692680408474755356001634781515460455298318789259024910E+135
#	define MCK_BN146     +6.867616710466857943527184427029943407277047159367642466256E+137
#	define MCK_BN148     -3.784646858196910585185406602559931141716286507587674365055E+140
#	define MCK_BN150     +2.142610125066529065104501205105224322606567565674847374273E+143
#	define MCK_BN152     -1.245672713718369539869194399415433579090054998957682530593E+146
#	define MCK_BN154     +7.434578755100015575254064271436272252218175586517482007874E+148
#	define MCK_BN156     -4.553579530464170372930663286169212276153675866637815431547E+151
#	define MCK_BN158     +2.861211281685887046034878814148289741433428178625574051234E+154
#	define MCK_BN160     -1.843772355203386995195894348919275612123241665926819933887E+157
#	define MCK_BN162     +1.218115453622104654392393789105308615286791465823352916479E+160
#	define MCK_BN164     -8.248218718531412167854846052904664989792170434731083151990E+162
#	define MCK_BN166     +5.722587793783294216781156260956163332811489986209224882965E+165
#	define MCK_BN168     -4.066853052505910459042404199511451321304141206556563031034E+168
#	define MCK_BN170     +2.959609206464205219127289466361209519623164294776785081504E+171
#	define MCK_BN172     -2.204952256518945714336026455244048152786363540211455880239E+174
#	define MCK_BN174     +1.681259707288959937493710584667367161708472146459041758017E+177
#	define MCK_BN176     -1.311673621355695809097718918433203325523024145733388575481E+180
#	define MCK_BN178     +1.046789400947803852214522892099181537614077884410734859408E+183
#	define MCK_BN180     -8.543289357883371024812400535960721126368303527617130285786E+185
#	define MCK_BN182     +7.128782132248654685468790899213271677589453675980794928498E+188
#	define MCK_BN184     -6.080293145553590496659092856160420699268151316739668203802E+191
#	define MCK_BN186     +5.299677642484992116716110600915701645427575368167903484741E+194
#	define MCK_BN188     -4.719425916874586046992698615340336957167074921894016163164E+197
#	define MCK_BN190     +4.292841379140298260708418117345535858646460911673020652012E+200
#	define MCK_BN192     -3.987674496823220536796170036978168490916948755349534091791E+203
#	define MCK_BN194     +3.781978041935887976573185195547319810381624177440000418494E+206
#	define MCK_BN196     -3.661423368368119189861236054247179580639232372992488801403E+209
#	define MCK_BN198     +3.617609027237285991672455287270892221027447677167796761576E+212
#	define MCK_BN200     -3.647077264519135631061085718925481436107296746425246018733E+215
#	define MCK_BN202     +3.750875543645440632326922241241085570309293403999133414435E+218
#	define MCK_BN204     -3.934586729643903006019925940226613576231218116987892164002E+221
#	define MCK_BN206     +4.208821114819008395697396506966059041488080887940130413709E+224
#	define MCK_BN208     -4.590229622061791754252926939754212459714038828219053270481E+227
#	define MCK_BN210     +5.103172577262957190736444703349495990388234263748373240150E+230
#	define MCK_BN212     -5.782276230365695420618505434577653455858480522601260159302E+233
#	define MCK_BN214     +6.676248216783588380179427924215168218824392336752002691784E+236
#	define MCK_BN216     -7.853530764445041702209963867887352605266367566261062872018E+239
#	define MCK_BN218     +9.410689406705872429213813582719433268037087713069354614918E+242
#	define MCK_BN220     -1.148493387346518466066017697233769705089973903855611282651E+246
#	define MCK_BN222     +1.427295874284878491799584470557543049137106829281593652811E+249
#	define MCK_BN224     -1.805955958690930935390502720874417058734910550558401966443E+252
#	define MCK_BN226     +2.326153530766080678593494027442846150246554880180128877447E+255
#	define MCK_BN228     -3.049575171549959409906759613082844065051475311959406560019E+258
#	define MCK_BN230     +4.068580607643397566454514991940591743075665809425192830325E+261
#	define MCK_BN232     -5.523103132197436200658677764865366816367841182877965764642E+264
#	define MCK_BN234     +7.627727939643439515008768512827237441345207461357109443550E+267
#	define MCK_BN236     -1.071557111969788579160346119933658247661730895387631156514E+271
#	define MCK_BN238     +1.531020089596918805070260042215900911037165906041971786170E+274
#	define MCK_BN240     -2.224489168217983573398387941262333344757134026607391395262E+277
#	define MCK_BN242     +3.286267919069013990613421754801507783998619782475614599881E+280
#	define MCK_BN244     -4.935592895596034798815126102465976774654346462540527857503E+283
#	define MCK_BN246     +7.534957120083251090080010255611760003063263208725421169839E+286
#	define MCK_BN248     -1.169148515458417828281837740910494063774922853265893946825E+290
#	define MCK_BN250     +1.843526146783893841905132718714405924697423079162855681263E+293
#	define MCK_BN252     -2.953682617296808179473777116545505396122992758259469819851E+296
#	define MCK_BN254     +4.807932127750156807935259973624580127057215333544069204694E+299
#	define MCK_BN256     -7.950212504588525167289997533515423876188510259936572793027E+302
#	define MCK_BN258     +1.335278418735463405971388791493569979558060937843209935281E+306

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
#	define MCK_ZETA_N1    (-(MCK_1_12))

//!# Value ~zeta(-3).
#	define MCK_ZETA_N3    (+(MCK_1_120))

//!# Value ~zeta(-5).
#	define MCK_ZETA_N5    (-(MCK_1_252))

//!# Value ~zeta(-7).
#	define MCK_ZETA_N7    (+(MCK_1_240))

//!# Value ~zeta(-9).
#	define MCK_ZETA_N9    (-(MCK_1_132))

//!# Value ~zeta(-11).
#	define MCK_ZETA_N11   (+(MCK_691_32760))

#define MCK_KF(K) (mc_cast_exp(const float, K))
#define MCK_K(K)  (mc_cast_exp(const double, K))
#define MCK_KL(K) (mc_cast_exp(const long double, K))

#endif /* !MCCONSTS_H */

/* EOF */
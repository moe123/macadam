//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_target.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_TARGET_H
#define MC_TARGET_H

#	if    (defined(__INTEL_COMPILER) && defined(_WIN32))         \
		|| (defined(__ICC)   && defined(_WIN32))                 \
		|| (defined(__ICL)   && defined(_WIN32))                 \
		|| (defined(_MSC_VER) && (defined(__STDC__) && __STDC__)) \
		|| (defined(_MSC_VER) && _MSC_VER < 1916)
#		error "C99 compiler and Posix 1-2001 CRT required."
#	endif

#	if defined(__linux__) && defined(__GLIBC__)
#		ifndef _GNU_SOURCE
#			define _GNU_SOURCE
#		endif
#	endif

#	if    defined(__unix__)  \
		|| defined(__linux__) \
		|| defined(__bsdi__) \
		|| (defined(__APPLE__) && defined(__MACH__))
#		include <unistd.h>
#	endif

#	if defined(__APPLE__) && defined(__MACH__)
#		ifndef __MATH_LONG_DOUBLE_CONSTANTS
#			define __MATH_LONG_DOUBLE_CONSTANTS
#		endif
#	endif

#	if MC_DISABLE_REENTRANT
#	undef  _REENTRANT
#	define _REENTRANT 0
#	else
#	undef  _REENTRANT
#	define _REENTRANT 1
#	endif

#	if MC_DISABLE_TGMATH
#	undef  MC_TARGET_HAVE_TGMATH
#	define MC_TARGET_HAVE_TGMATH 0
#	else
#	undef  MC_TARGET_HAVE_TGMATH
#	define MC_TARGET_HAVE_TGMATH 1
#	endif

#	if MC_DISABLE_LOG2
#	undef  MC_TARGET_HAVE_LOG2
#	define MC_TARGET_HAVE_LOG2 0
#	else
#	undef  MC_TARGET_HAVE_LOG2
#	define MC_TARGET_HAVE_LOG2 1
#	endif

#	if MC_DISABLE_INLINE
#	undef  MC_TARGET_INLINE
#	define MC_TARGET_INLINE inline
#	endif

#	if defined(__STDC__)
#		define MC_TARGET_C89 1
#		if defined(__STDC_VERSION__)
#			define MC_TARGET_C90 1
#			if (__STDC_VERSION__ >= 199409L)
#				define MC_TARGET_C94 1
#			endif
#			if (__STDC_VERSION__ >= 199901L)
#				define MC_TARGET_C99 1
#			endif
#			if (__STDC_VERSION__ >= 201112L)
#				define MC_TARGET_C11 1
#			endif
#		endif
#	endif

#	if defined(__cplusplus)
#		define MC_TARGET_CPP98 1
#		if (__cplusplus >= 201103L)
#			define MC_TARGET_CPP11 1
#		endif
#		if (__cplusplus >= 201402L)
#			define MC_TARGET_CPP14 1
#		endif
#		if (__cplusplus >= 201703L)
#			define MC_TARGET_CPP17 1
#		endif
#		if (__cplusplus > 201703L)
#			define MC_TARGET_CPP20 1
#		endif
#	endif

#	define MC_TARGET_MSVC_CPP 0
#	if defined(_MSC_VER)
#		undef  MC_TARGET_MSVC_CPP
#		define MC_TARGET_MSVC_CPP 1
#		ifndef MC_TARGET_CPP98
#			define MC_TARGET_CPP98 1
#		endif
#		ifndef MC_TARGET_CPP11
#			define MC_TARGET_CPP11 1
#		endif
#		ifndef MC_TARGET_CPP14
#			define MC_TARGET_CPP14 1
#		endif
#	endif

#	if MC_TARGET_MSVC_CPP
#		undef  _USE_MATH_DEFINES
#		define _USE_MATH_DEFINES 1
#	endif

#	if MC_TARGET_CPP98 && !MC_TARGET_CPP11
#		ifndef __STDC_CONSTANT_MACROS
#			define __STDC_CONSTANT_MACROS
#		endif
#		ifndef __STDC_LIMIT_MACROS
#			define __STDC_LIMIT_MACROS
#		endif
#		ifndef __STDC_FORMAT_MACROS
#			define __STDC_FORMAT_MACROS
#		endif
#	endif

#	if !defined(MC_TARGET_INLINE)
#	if MC_TARGET_C99 || MC_TARGET_CPP98
#		if (((defined(__GNUC__) && __GNUC__ >= 4)) || defined(__clang__))
#			define MC_TARGET_INLINE __inline__ __attribute__((__always_inline__, __unused__))
#		elif defined(__GNUC__)
#			define MC_TARGET_INLINE __inline__
#		else
#			define MC_TARGET_INLINE inline
#		endif
#	else
#		define MC_TARGET_INLINE
#	endif
#	endif

#	if !defined(MC_TARGET_PROC)
#		define MC_TARGET_PROC static MC_TARGET_INLINE
#	endif

#	if !defined(MC_TARGET_FUNC)
#		define MC_TARGET_FUNC static MC_TARGET_INLINE
#	endif

#	if MC_TARGET_C99
#		define MC_TARGET_NONNULL static
#	else
#		define MC_TARGET_NONNULL
#	endif

#	if MC_DISABLE_OVERLOADABLE
#		undef  MC_TARGET_HAVE_OVERLOADABLE
#		undef  MC_TARGET_OVERLOADABLE
#		undef  MC_TARGET_ALIAS
#		define MC_TARGET_HAVE_OVERLOADABLE   0
#		define MC_TARGET_OVERLOADABLE        MC_TARGET_INLINE
#		define MC_TARGET_ALIAS               static MC_TARGET_OVERLOADABLE
#	else
#	if defined(__clang__) && __has_attribute(__overloadable__)
#		undef  MC_TARGET_HAVE_OVERLOADABLE
#		undef  MC_TARGET_OVERLOADABLE
#		undef  MC_TARGET_ALIAS
#		define MC_TARGET_HAVE_OVERLOADABLE   1
#		define MC_TARGET_OVERLOADABLE        __attribute__((__overloadable__, __always_inline__, __unused__))
#		define MC_TARGET_ALIAS               static MC_TARGET_OVERLOADABLE
#	else
#		undef  MC_TARGET_HAVE_OVERLOADABLE
#		undef  MC_TARGET_OVERLOADABLE
#		undef  MC_TARGET_ALIAS
#		define MC_TARGET_HAVE_OVERLOADABLE   0
#		define MC_TARGET_OVERLOADABLE
#		define MC_TARGET_ALIAS
#	endif
#	endif

#	if defined(WIN32) && (defined(_MSC_VER) || defined(__ICL))
#		define __declspec(thread)
#	elif defined(__clang__)
#		if __has_feature(c_thread_local) || __has_extension(c_thread_local)
#			define MC_TARGET_THREAD_LOCAL _Thread_local
#		else
#			define MC_TARGET_THREAD_LOCAL
#		endif
#	elif defined(__GNUG__) && (__GNUC__ <= 4 && __GNUC_MINOR__ < 80)
#		define MC_TARGET_THREAD_LOCAL __thread
#	elif defined(__GNUG__) && (__GNUC__ == 4 && __GNUC_MINOR__ >= 80)
#		define MC_TARGET_THREAD_LOCAL _Thread_local
#	elif defined(__GNUG__) && (__GNUC__ > 4)
#		define MC_TARGET_THREAD_LOCAL _Thread_local
#	elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_THREADS__)
#		define MC_TARGET_THREAD_LOCAL _Thread_local
#	else
#		define MC_TARGET_THREAD_LOCAL
#	endif

#	if MC_DISABLE_TYPEOF
#		undef  MC_TARGET_HAVE_TYPEOF
#		undef  MC_TARGET_HAVE_AUTOTYPE
#		undef  MC_TARGET_AUTOTYPE
#		undef  MC_TARGET_TYPEOF
#		undef  MC_TARGET_TYPEISOF
#		define MC_TARGET_HAVE_TYPEOF      0
#		define MC_TARGET_HAVE_AUTOTYPE    0
#		define MC_TARGET_AUTOTYPE         void *
#		define MC_TARGET_TYPEOF(X)        void *
#		define MC_TARGET_TYPEISOF(T1, T2) 0
#	else
#	if MC_TARGET_C89 || MC_TARGET_CPP98
#		undef  MC_TARGET_HAVE_AUTOTYPE
#		undef  MC_TARGET_HAVE_TYPEOF
#		undef  MC_TARGET_AUTOTYPE
#		undef  MC_TARGET_TYPEOF
#		undef  MC_TARGET_TYPEISOF
#		define MC_TARGET_HAVE_TYPEOF 1
#		if MC_TARGET_CPP11
#			define MC_TARGET_HAVE_AUTOTYPE 1
#			define MC_TARGET_AUTOTYPE      auto
#		elif ((defined(__GNUC__) && (__GNUC__ >= 5)) || defined(__clang__))
#			define MC_TARGET_HAVE_AUTOTYPE 1
#			define MC_TARGET_AUTOTYPE      __auto_type
#		endif
#		if ((defined(__GNUC__) && (__GNUC__ >= 3)) || defined(__clang__))
#			define MC_TARGET_TYPEISOF(type1, type2) ((__builtin_types_compatible_p(type1, type2)) ? 1 : 0)
#		elif MC_TARGET_CPP11
#			define MC_TARGET_TYPEISOF(type1, type2) \
			( \
				::std::is_same< \
					  typename ::std::decay<type1>::type \
					, typename ::std::decay<type2>::type \
				>::value == true ? 1 : 0 \
			)
#		elif MC_TARGET_CPP98
			template<class T>        struct mc_remove_const                { typedef T type; };
			template<class T>        struct mc_remove_const<const T>       { typedef T type; };
			template<class T>        struct mc_remove_volatile             { typedef T type; };
			template<class T>        struct mc_remove_volatile<volatile T> { typedef T type; };
			template<class T>        struct mc_remove_cv
			{
				typedef typename mc_remove_volatile<typename mc_remove_const<T>::type>::type type;
			};
			template<class T>        struct mc_remove_reference            { typedef T type; };
			template<class T>        struct mc_remove_reference<T&>        { typedef T type; };
			template<class T>        struct mc_decay
			{
				typedef typename mc_remove_reference<typename mc_remove_cv<T>::type>::type type;
			};
			template<class T, class U> struct mc_is_same                   { static const bool value = false; };
			template<class T>          struct mc_is_same<T, T>             { static const bool value = true;  };
#			define MC_TARGET_TYPEISOF(type1, type2) \
			( \
				mc_is_same< \
					  typename mc_decay<type1>::type \
					, typename mc_decay<type2>::type \
				>::value == true ? 1 : 0 \
			)
#		endif
#		if MC_TARGET_MSVC_CPP
#			define MC_TARGET_TYPEOF(x) ::std::decay<decltype((x))>::type
#		else
#			define MC_TARGET_TYPEOF(x) __typeof__((x) + 0)
#		endif
#	else
#		undef  MC_TARGET_HAVE_TYPEOF
#		undef  MC_TARGET_HAVE_AUTOTYPE
#		undef  MC_TARGET_AUTOTYPE
#		undef  MC_TARGET_TYPEOF
#		undef  MC_TARGET_TYPEISOF
#		define MC_TARGET_HAVE_TYPEOF      0
#		define MC_TARGET_HAVE_AUTOTYPE    0
#		define MC_TARGET_AUTOTYPE         void *
#		define MC_TARGET_TYPEOF(X)        void *
#		define MC_TARGET_TYPEISOF(T1, T2) 0
#	endif
#	endif

#	if MC_TARGET_CPP98
#		include <cassert>
#	else
#		include <assert.h>
#	endif

#	if MC_TARGET_CPP11
#	define mc_static_assert(COND, IDF) ::static_assert(COND, #IDF)
#	elif MC_TARGET_C11
#	define mc_static_assert(COND, IDF) _Static_assert(COND, #IDF)
#	else
#	define mc_static_assert(COND, IDF) typedef char static_assertion_##IDF[(COND) ? 1 : -1]
#	endif

#	define mc_cast(t, x) (t)x
#	define mc_cast_exp(t, x) mc_cast(t, (x))
#	define mc_nonnull(p) ((p) != NULL)

#	define mc_scope_begin do {
#	define mc_scope_end   break; } while (0)

#	if MC_TARGET_CPP98
#		include <cstdio>
#		include <climits>
#		include <ctime>
#		include <cstdlib>
#		include <cstring>
#		include <cctype>
#		include <cstdint>
#		include <cinttypes>
#		include <cfenv>
#		include <cfloat>
#		include <complex>
#		include <cmath>
#	elif MC_TARGET_HAVE_TGMATH
#		include <stdio.h>
#		include <limits.h>
#		include <time.h>
#		include <stdlib.h>
#		include <string.h>
#		include <ctype.h>
#		include <stdint.h>
#		include <inttypes.h>
#		include <fenv.h>
#		include <float.h>
#		include <tgmath.h>
#	else
#		include <stdio.h>
#		include <limits.h>
#		include <time.h>
#		include <stdlib.h>
#		include <string.h>
#		include <ctype.h>
#		include <stdint.h>
#		include <inttypes.h>
#		include <fenv.h>
#		include <complex.h>
#		include <float.h>
#		include <math.h>
#	endif

#	if defined(__SSE__) && __SSE__
#		undef  MC_TARGET_HAVE_SSE
#		define MC_TARGET_HAVE_SSE 1
#		include <immintrin.h>
#	endif

#	if (defined(__ARM_NEON__) && __ARM_NEON__) || (defined(__ARM_NEON) && __ARM_NEON)
#		undef  MC_TARGET_HAVE_NEON
#		define MC_TARGET_HAVE_NEON 1
#		include <arm_neon.h>
#	endif

#	if 0
#	if !defined(_MSC_VER)
#	if !__STDC_IEC_559__ || !__STDC_IEC_559_COMPLEX__
#		error "IEC_559 required."
#	endif
#	endif
#	endif

#	if defined(__APPLE__) && (!defined(__DARWIN_C_LEVEL) || __DARWIN_C_LEVEL < 199506L)
#		error "C99 compiler and Posix 1-2001 CRT required."
#	endif

#	undef MC_TARGET_APPLEXM
#	if    defined(__APPLE__)                              \
		&& defined(__IPHONE_OS_VERSION_MIN_ALLOWED)        \
		&& defined(__IPHONE_7_0)                           \
		&& __IPHONE_OS_VERSION_MIN_ALLOWED >= __IPHONE_7_0
#	define MC_TARGET_APPLEXM 1
#	endif

#	if    defined(__APPLE__)                                       \
		&& defined(MAC_OS_X_VERSION_MIN_REQUIRED)                   \
		&& defined(MAC_OS_X_VERSION_10_9)                           \
		&& MAC_OS_X_VERSION_MIN_REQUIRED   >= MAC_OS_X_VERSION_10_9
#	undef MC_TARGET_APPLEXM
#	define MC_TARGET_APPLEXM 1
#	endif

#	if defined(_MSC_VER)
#	include <intrin.h>
	MC_TARGET_FUNC int __builtin_ctz(unsigned int x)
	{
		unsigned long ret;
		_BitScanForward(&ret, x);
		return mc_cast(int, ret);
	}

	MC_TARGET_FUNC int __builtin_ctzll(unsigned long long x)
	{
		unsigned long ret;
		_BitScanForward64(&ret, x);
		return mc_cast(int, ret);
	}

	MC_TARGET_FUNC int __builtin_ctzl(unsigned long x)
	{
		return (sizeof(x) == 8 ?
			  __builtin_ctzll(mc_cast(unsigned long long, x))
			: __builtin_ctz(mc_cast(unsigned int, x))
		);
	}
	
	MC_TARGET_FUNC int __builtin_clz(unsigned int x)
	{
		unsigned long ret;
		_BitScanReverse(&ret, x);
		return mc_cast(int, (31 ^ ret));
	}

	MC_TARGET_FUNC int __builtin_clzll(unsigned long long x)
	{
		unsigned long ret;
		_BitScanReverse64(&ret, x);
		return mc_cast(int, (63 ^ ret));
	}

	MC_TARGET_FUNC int __builtin_clzl(unsigned long x)
	{
		return (sizeof(x) == 8 ?
			  __builtin_clzll(x)
			: __builtin_clz(mc_cast(unsigned int, x))
		);
	}
#	endif

#	define MC_TARGET_CTZ(x)   __builtin_ctz(x)
#	define MC_TARGET_CTZL(x)  __builtin_ctzl(x)
#	define MC_TARGET_CTZLL(x) __builtin_ctzll(x)
#	define MC_TARGET_CLZ(x)   __builtin_clz(x)
#	define MC_TARGET_CLZL(x)  __builtin_clzl(x)
#	define MC_TARGET_CLZLL(x) __builtin_clzll(x)

MC_TARGET_FUNC char               MC_TARGET_CHAR      (char x)               { return x; }
MC_TARGET_FUNC short              MC_TARGET_SHORT     (short x)              { return x; }
MC_TARGET_FUNC int                MC_TARGET_INT       (int x)                { return x; }
MC_TARGET_FUNC long               MC_TARGET_LONG      (long x)               { return x; }
MC_TARGET_FUNC unsigned char      MC_TARGET_UCHAR     (unsigned char x)      { return x; }
MC_TARGET_FUNC unsigned short     MC_TARGET_USHORT    (unsigned short x)     { return x; }
MC_TARGET_FUNC unsigned int       MC_TARGET_UINT      (unsigned int x)       { return x; }
MC_TARGET_FUNC unsigned long      MC_TARGET_ULONG     (unsigned long x)      { return x; }

#	if MC_TARGET_C99 || MC_TARGET_CPP11
MC_TARGET_FUNC long long          MC_TARGET_LONGLONG  (long long x)          { return x; }
MC_TARGET_FUNC unsigned long long MC_TARGET_ULONGLONG (unsigned long long x) { return x; }
#	else
#	define MC_TARGET_LONGLONG  MC_TARGET_LONG
#	define MC_TARGET_ULONGLONG MC_TARGET_ULONG
#	endif

#endif /* !MC_TARGET_H */

/* EOF */
//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_alloc.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ALLOC_H
#define MC_ALLOC_H

#pragma mark - mc_os_memset -

static MC_TARGET_INLINE
void * mc_os_memset(void * b, int c, size_t len)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	size_t max = sizeof(size_t) < sizeof(uint64_t) ?
		  mc_cast(size_t, UINT32_MAX)
		: mc_cast(size_t, UINT64_MAX)
	;
#	else
	size_t max = mc_cast(size_t, UINT32_MAX);
#	endif
	if (b != NULL && len > 0 && len < max) {
#	if MC_TARGET_CPP98
		return ::memset(b, c, len);
#	else
		return memset(b, c, len);
#	endif
	}
	return NULL;
}

#pragma mark - mc_os_memzero -

static MC_TARGET_INLINE
void * mc_os_memzero(void * b, size_t len)
{
	return mc_os_memset(b, 0, len);
}

#pragma mark - mc_os_memcpy -

static MC_TARGET_INLINE
void * mc_os_memcpy(void * restrict dest, const void * restrict src, size_t len)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	size_t max = sizeof(size_t) < sizeof(uint64_t) ?
		  mc_cast(size_t, UINT32_MAX)
		: mc_cast(size_t, UINT64_MAX)
	;
#	else
	size_t max = mc_cast(size_t, UINT32_MAX);
#	endif
	if (dest != NULL && src != NULL && (len > 0 && len < max)) {
#	if MC_TARGET_CPP98
		return ::memcpy(dest, src, len);
#	else
		return memcpy(dest, src, len);
#	endif
	}
	return NULL;
}

#pragma mark - mc_os_memmove -

static MC_TARGET_INLINE
void * mc_os_memmove(void * restrict dest, const void * restrict src, size_t len)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	size_t max = sizeof(size_t) < sizeof(uint64_t) ?
		  mc_cast(size_t, UINT32_MAX)
		: mc_cast(size_t, UINT64_MAX)
	;
#	else
	size_t max = mc_cast(size_t, UINT32_MAX);
#	endif
	if (dest != NULL && src != NULL && (len > 0 && len < max)) {
#	if MC_TARGET_CPP98
		return ::memmove(dest, src, len);
#	else
		return memmove(dest, src, len);
#	endif
	}
	return NULL;
}

#pragma mark - mc_os_memcmp -

static MC_TARGET_INLINE
int mc_os_memcmp(const void * restrict left, const void * restrict right, size_t len)
{
#	if MC_TARGET_C99 || MC_TARGET_CPP11
	size_t max = sizeof(size_t) < sizeof(uint64_t) ?
		  mc_cast(size_t, UINT32_MAX)
		: mc_cast(size_t, UINT64_MAX)
	;
#	else
	size_t max = mc_cast(size_t, UINT32_MAX);
#	endif
	if (left != NULL && right != NULL && (len > 0 && len < max)) {
#	if MC_TARGET_CPP98
		return ::memcmp(left, right, len);
#	else
		return memcmp(left, right, len);
#	endif
	}
	return -1;
}

#pragma mark - mc_os_malloc -

static MC_TARGET_INLINE
void * mc_os_malloc(size_t size)
{
#	if MC_TARGET_CPP98
	return ::malloc(size);
#	else
	return malloc(size);
#	endif
}

#pragma mark - mc_os_cmalloc -

static MC_TARGET_INLINE
void * mc_os_cmalloc(size_t size)
{
	return mc_os_memzero(mc_os_malloc(size), size);
}

#pragma mark - mc_os_calloc -

static MC_TARGET_INLINE
void * mc_os_calloc(size_t count, size_t size)
{
#	if MC_TARGET_CPP98
	return ::calloc(count, size);
#	else
	return calloc(count, size);
#	endif
}

#pragma mark - mc_os_realloc -

static MC_TARGET_INLINE
void * mc_os_realloc(void * ptr, size_t size)
{
#	if MC_TARGET_CPP98
	return ::realloc(ptr, size);
#	else
	return realloc(ptr, size);
#	endif
}

#pragma mark - mc_os_free -

static MC_TARGET_INLINE
void mc_os_free(void * ptr)
{
#	if MC_TARGET_CPP98
	::free(ptr);
#	else
	free(ptr);
#	endif
}

#pragma mark - mc_base_memset -

#	define mc_base_memset(src_addr, c, size) \
		mc_os_memset(src_addr, c, mc_cast_expr(size_t, size))

#pragma mark - mc_base_memzero -

#	define mc_base_memzero(src_addr, size) \
		mc_os_memzero(src_addr, mc_cast_expr(size_t, size))

#pragma mark - mc_base_memcpy -

#	define mc_base_memcpy(dest_addr, src_addr, size) \
		mc_os_memcpy(dest_addr, src_addr, mc_cast_expr(size_t, size))

#pragma mark - mc_base_memmove -

#	define mc_base_memmove(dest_addr, src_addr, size) \
		mc_os_memmove(dest_addr, src_addr, mc_cast_expr(size_t, size))

#pragma mark - mc_base_memcmp -

#	define mc_base_memcmp(left_addr, right_addr, size) \
		mc_os_memcmp(left_addr, right_addr, mc_cast_expr(size_t, size))

#pragma mark - mc_base_alloc -

#	define mc_base_alloc(item_type, size) \
		mc_cast(item_type *, mc_os_malloc(mc_cast_expr(size_t, size)))

#	define mc_base_alloc_count(item_type, count) \
		 mc_cast(item_type *, mc_os_malloc(mc_cast_expr(size_t, count) * sizeof((item_type))))

#pragma mark - mc_base_calloc -

#	define mc_base_calloc(item_type, size) \
		mc_cast(item_type *, mc_os_cmalloc(mc_cast_expr(size_t, size)))

#	define mc_base_calloc_count(item_type, count) \
		mc_cast(item_type *, mc_os_calloc(mc_cast_expr(size_t, count), sizeof((item_type))))

#pragma mark - mc_base_realloc -

#	define mc_base_realloc(item_type, src_addr, newsize) \
		mc_cast(item_type *, mc_os_realloc(src_addr, mc_cast(size_t, newsize)))

#	define mc_base_realloc_count(item_type, src_addr, newcount) \
		mc_cast(item_type *, mc_os_realloc(src_addr, mc_cast_expr(size_t, newcount) * sizeof((item_type))))

#pragma mark - mc_alloc_sizeck -

#	define mc_alloc_sizeck(size) \
		((size) > 0 && mc_cast_expr(size_t, size) < mc_cast(size_t, MC_TARGET_ALLOCATOR_MAXSIZE) ? 0 : -1)

#pragma mark - mc_alloc_countck -

#	define mc_alloc_countck(item_type, count) \
		((count) > 0 && mc_cast_expr(size_t, count) * sizeof((item_type)) < mc_cast(size_t, MC_TARGET_ALLOCATOR_MAXSIZE) ? 0 : -1)

#pragma mark - mc_alloc -

#	define mc_alloc(item_type, dest_addr, size)    \
	mc_scope_begin                                 \
		dest_addr = mc_base_alloc(item_type, size); \
	mc_scope_end

#	define mc_alloc_safe(item_type, dest_addr, size)                                   \
	mc_scope_begin                                                                     \
		dest_addr = mc_alloc_sizeck(size) == 0 ? mc_base_alloc(item_type, size) : NULL; \
	mc_scope_end

#	define mc_alloc_count(item_type, dest_addr, count)    \
	mc_scope_begin                                        \
		dest_addr = mc_base_alloc_count(item_type, count); \
	mc_scope_end

#	define mc_alloc_count_safe(item_type, dest_addr, count)                                                \
	mc_scope_begin                                                                                         \
		dest_addr = mc_alloc_countck(item_type, count) == 0 ? mc_base_alloc_count(item_type, count) : NULL; \
	mc_scope_end

#pragma mark - mc_calloc -

#	define mc_calloc(item_type, dest_addr, size)    \
	mc_scope_begin                                  \
		dest_addr = mc_base_calloc(item_type, size); \
	mc_scope_end

#	define mc_calloc_safe(item_type, dest_addr, size)                                   \
	mc_scope_begin                                                                      \
		dest_addr = mc_alloc_sizeck(size) == 0 ? mc_base_calloc(item_type, size) : NULL; \
	mc_scope_end

#	define mc_calloc_count(item_type, dest_addr, count)    \
	mc_scope_begin                                         \
		dest_addr = mc_base_calloc_count(item_type, count); \
	mc_scope_end

#	define mc_calloc_count_safe(item_type, dest_addr, count)                                                \
	mc_scope_begin                                                                                          \
		dest_addr = mc_alloc_countck(item_type, count) == 0 ? mc_base_calloc_count(item_type, count) : NULL; \
	mc_scope_end

#pragma mark - mc_realloc -

#	define mc_realloc(item_type, dest_addr, src_addr, newsize)    \
	mc_scope_begin                                                \
		dest_addr = mc_base_realloc(item_type, src_addr, newsize); \
	mc_scope_end

#	define mc_realloc_safe(item_type, dest_addr, src_addr, newsize)                  \
	mc_scope_begin                                                                   \
		if (0 == mc_alloc_sizeck(newsize)) {                                          \
			if (NULL == (dest_addr = mc_base_realloc(item_type, src_addr, newsize))) { \
				if (src_addr != NULL) {                                                 \
					mc_os_free(src_addr);                                                \
					src_addr = NULL;                                                     \
				}                                                                       \
			}                                                                          \
		} else {                                                                      \
			dest_addr = NULL;                                                          \
		}                                                                             \
	mc_scope_end

#	define mc_realloc_count(item_type, dest_addr, src_addr, newcount)    \
	mc_scope_begin                                                       \
		dest_addr = mc_base_realloc_count(item_type, src_addr, newcount); \
	mc_scope_end

#	define mc_realloc_count_safe(item_type, dest_addr, src_addr, newcount)                  \
	mc_scope_begin                                                                          \
		if (0 == mc_alloc_countck(item_type, newcount)) {                                    \
			if (NULL == (dest_addr = mc_base_realloc_count(item_type, src_addr, newcount))) { \
				if (src_addr != NULL) {                                                        \
					mc_os_free(src_addr);                                                       \
					src_addr = NULL;                                                            \
				}                                                                              \
			}                                                                                 \
		} else {                                                                             \
			dest_addr = NULL;                                                                 \
		}                                                                                    \
	mc_scope_end

#pragma mark - mc_dealloc -

#	define mc_dealloc(src_addr) \
		mc_os_free(src_addr)

#	define mc_dealloc_safe(src_addr) \
	mc_scope_begin                   \
		if (src_addr != NULL) {       \
			mc_os_free(src_addr);      \
			src_addr = NULL;           \
		}                             \
	mc_scope_end

#endif /* !MC_ALLOC_H */

/* EOF */
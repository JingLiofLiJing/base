#pragma once

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_COMPILER_GCC
#  define BASE_LIKELY(x) __builtin_expect(!!(x), 1)
#  define BASE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#  define BASE_LIKELY(x) x
#  define BASE_UNLIKELY(x) x
#endif  // CPU_FEATURES_COMPILER_GCC

#ifdef CPU_FEATURES_COMPILER_GCC
#  define BASE_ALWAYS_INLINE inline __attribute__((always_inline))
#  define BASE_NOINLINE __attribute__((noinline))
#else
#  define BASE_ALWAYS_INLINE inline
#  define BASE_NOINLINE
#endif  // CPU_FEATURES_COMPILER_GCC

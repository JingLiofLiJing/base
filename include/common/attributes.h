#pragma once

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_COMPILER_GCC
#  define BASE_LIKELY(x) __builtin_expect(!!(x), 1)
#  define BASE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#  define BASE_LIKELY(x) x
#  define BASE_UNLIKELY(x) x
#endif  // CPU_FEATURES_COMPILER_GCC

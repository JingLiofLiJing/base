#pragma once

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_ARCH_X86
#  include <cpu_features/cpuinfo_x86.h>
#endif  // CPU_FEATURES_ARCH_X86

#include "common/namespace.h"

BASE_NS_BEGIN

#ifdef CPU_FEATURES_ARCH_X86

inline const cpu_features::X86Info*
get_cpu_info() {
    static auto info = cpu_features::GetX86Info();
    return &info;
}

inline cpu_features::X86Features
get_cpu_features() { return get_cpu_info()->features; }

inline const bool enable_popcnt = static_cast<bool>(get_cpu_features().popcnt);

#if CPU_FEATURES_COMPILED_X86_SSE
inline constexpr bool enable_sse = true;
#else
inline const bool enable_sse = static_cast<bool>(get_cpu_features().sse);
#endif

#if CPU_FEATURES_COMPILED_X86_SSE2
inline constexpr bool enable_sse2 = true;
#else
inline const bool enable_sse2 = static_cast<bool>(get_cpu_features().sse2);
#endif

#if CPU_FEATURES_COMPILED_X86_SSE4_1
inline constexpr bool enable_sse4_1 = true;
#else
inline const bool enable_sse4_1 = static_cast<bool>(get_cpu_features().sse4_1);
#endif

#if CPU_FEATURES_COMPILED_X86_SSE4_2
inline constexpr bool enable_sse4_2 = true;
#else
inline const bool enable_sse4_2 = static_cast<bool>(get_cpu_features().sse4_2);
#endif

#if CPU_FEATURES_COMPILED_X86_AVX
inline constexpr bool enable_avx = true;
#else
inline const bool enable_avx = static_cast<bool>(get_cpu_features().avx);
#endif

#if CPU_FEATURES_COMPILED_X86_AVX2
inline constexpr bool enable_avx2 = true;
#else
inline const bool enable_avx2 = static_cast<bool>(get_cpu_features().avx2);
#endif

#endif  // CPU_FEATURES_ARCH_X86

BASE_NS_END

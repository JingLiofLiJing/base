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

inline bool enable_popcnt() { return static_cast<bool>(get_cpu_features().popcnt); }

#if CPU_FEATURES_COMPILED_X86_SSE
constexpr bool enable_sse() { return true; }
#else
inline bool enable_sse() { return static_cast<bool>(get_cpu_features().sse); }
#endif

#if CPU_FEATURES_COMPILED_X86_SSE2
constexpr bool enable_sse2() { return true; }
#else
inline bool enable_sse2() { return static_cast<bool>(get_cpu_features().sse2); }
#endif

#if CPU_FEATURES_COMPILED_X86_SSE4_1
constexpr bool enable_sse4_1() { return true; }
#else
inline bool enable_sse4_1() { return static_cast<bool>(get_cpu_features().sse4_1); }
#endif

#if CPU_FEATURES_COMPILED_X86_SSE4_2
constexpr bool enable_sse4_2() { return true; }
#else
inline bool enable_sse4_2() { return static_cast<bool>(get_cpu_features().sse4_2); }
#endif

#if CPU_FEATURES_COMPILED_X86_AVX
constexpr bool enable_avx() { return true; }
#else
inline bool enable_avx() { return static_cast<bool>(get_cpu_features().avx); }
#endif

#if CPU_FEATURES_COMPILED_X86_AVX2
constexpr bool enable_avx2() { return true; }
#else
inline bool enable_avx2() { return static_cast<bool>(get_cpu_features().avx2); }
#endif

#endif  // CPU_FEATURES_ARCH_X86

BASE_NS_END

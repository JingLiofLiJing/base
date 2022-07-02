#pragma once

#include <cstdint>

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_ARCH_X86
#  include <cpu_features/cpuinfo_x86.h>
#endif  // CPU_FEATURES_ARCH_X86

#include "common/namespace.h"

BASE_NS_BEGIN

#ifdef CPU_FEATURES_ARCH_X86

#ifdef CPU_FEATURES_ARCH_X86_32
inline constexpr uint32_t word_bits = 32u;
inline constexpr uint32_t word_bytes = 4u;
#elif defined(CPU_FEATURES_ARCH_X86_64)
inline constexpr uint32_t word_bits = 64u;
inline constexpr uint32_t word_bytes = 8u;
#endif  // CPU_FEATURES_ARCH_X86_32

#endif  // CPU_FEATURES_ARCH_X86

BASE_NS_END

#pragma once

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_ARCH_X86

#ifdef CPU_FEATURES_ARCH_X86_32
#  define B_WORD_BITS 32
#  define B_WORD_BYTES 4
#elif defined(CPU_FEATURES_ARCH_X86_64)
#  define B_WORD_BITS 64
#  define B_WORD_BYTES 8
#endif  // CPU_FEATURES_ARCH_X86_32

#endif  // CPU_FEATURES_ARCH_X86

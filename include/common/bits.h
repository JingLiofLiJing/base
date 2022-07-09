#pragma once

#include <cstdint>

#include <stdexcept>

#include <cpu_features/cpu_features_macros.h>

#ifdef CPU_FEATURES_ARCH_X86
#  include <cpu_features/cpuinfo_x86.h>
#endif  // CPU_FEATURES_ARCH_X86

#include "common/attributes.h"
#include "common/namespace.h"

BASE_NS_BEGIN

inline constexpr uint32_t byte_bits = 8u;
inline constexpr std::size_t bytes_to_bits(std::size_t bytes) { return bytes * byte_bits; }
inline constexpr std::size_t bits_to_bytes(std::size_t bits) { return bits / byte_bits; }

#ifdef CPU_FEATURES_ARCH_X86

#ifdef CPU_FEATURES_ARCH_X86_32
inline constexpr uint32_t word_bits = 32u;
inline constexpr uint32_t word_bytes = 4u;
#elif defined(CPU_FEATURES_ARCH_X86_64)
inline constexpr uint32_t word_bits = 64u;
inline constexpr uint32_t word_bytes = 8u;
#endif  // CPU_FEATURES_ARCH_X86_32

inline const cpu_features::CacheInfo*
get_cache_info() {
    static auto info = cpu_features::GetX86CacheInfo();
    return &info;
}

inline uint32_t get_cacheline_size() {
    auto info = get_cache_info();
    const auto* entry = info->levels;
    bool found = false;
    uint32_t sz = 0u;
    for (int i = 0; i < info->size; ++i, ++entry) {
        if ((entry->level == 1) && (entry->cache_type == cpu_features::CPU_FEATURE_CACHE_DATA)) {
            sz = static_cast<uint32_t>(entry->line_size);
            found = true;
            break;
        }
    }

    if (BASE_UNLIKELY(!found)) {
        throw std::runtime_error("could not solve the cpu cacheline size.");
    }
    return sz;
}

#endif  // CPU_FEATURES_ARCH_X86

BASE_NS_END

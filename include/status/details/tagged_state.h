#pragma once

#include "status/rcode.h"

BASE_NS_BEGIN
BASE_BEGIN_NAMESPACE(details)

struct tagged_state {
    enum state_mask : uintptr_t {
        rcode_only = 0u,
        tags_width = 1u,
    };

    static_assert(bytes_to_bits(sizeof(uintptr_t)) >= bytes_to_bits(sizeof(rcode)) + tags_width);

    static constexpr uintptr_t rcode_only_mask = (1u << rcode_only);
    static constexpr uintptr_t tagged_mask     = (1u << tags_width) - 1u;

    constexpr tagged_state() : tagged_state(rcode::ok) {}
    explicit constexpr tagged_state(rcode code) : state_(rcode_only_state(code)) {}

    static constexpr uintptr_t rcode_only_state(rcode code) {
        return (static_cast<uintptr_t>(code) << tags_width) | rcode_only_mask;
    }
    constexpr bool is_rcode_only() const { return (state_ & tagged_mask) == rcode_only_mask; }
    constexpr rcode only_rcode() const { return static_cast<rcode>(state_ >> tags_width); }

    constexpr bool is_payload() const { return (state_ & tagged_mask) == 0u; }

    uintptr_t state_;
};

BASE_END_NAMESPACE(details)
BASE_NS_END

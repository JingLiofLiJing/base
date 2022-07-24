#pragma once

#include <atomic>

#include "common.h"

BASE_NS_BEGIN

template <typename T>
class ref_counter_base {
public:
    void increase() { ref_count_.fetch_add(1u, std::memory_order_relaxed); }

    void decrease() {
        if (ref_count_.fetch_sub(1u, std::memory_order_release) == 1u) {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<T*>(this);
        }
    }

    uint32_t ref_count() const {
        return static_cast<uint32_t>(ref_count_.load(std::memory_order_relaxed));
    }

protected:
    ref_counter_base() { increase(); }

private:
    mutable std::atomic_uint_fast32_t ref_count_{0u};
};

BASE_NS_END

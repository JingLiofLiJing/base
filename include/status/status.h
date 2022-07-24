#pragma once

#include <string>
#include <utility>

#include "status/details/tagged_state.h"

BASE_NS_BEGIN

class status final : private details::tagged_state {
public:
    BASE_DECLARE_COPY(status)
    BASE_DECLARE_MOVE(status)

    status() : details::tagged_state() {}
    explicit status(rcode code) : details::tagged_state(code) {}
    ~status() { clear_maybe_payload(); }

    status(rcode code, std::string_view reason) : status(code, static_cast<std::string>(reason)) {}
    status(rcode code, std::string reason);

    rcode code() const;

    std::string what() const;

#define BASE_ADD_METHODS(rc)                         \
    static status rc() { return status(rcode::rc); } \
    static status rc(std::string_view reason) {      \
        return status(rcode::rc, reason);            \
    }                                                \
    static status rc(std::string reason) {           \
        return status(rcode::rc, std::move(reason)); \
    }                                                \
    bool is_##rc() const {                           \
        return code() == rcode::rc;                  \
    }

    BASE_ADD_METHODS(ok)
    BASE_ADD_METHODS(internal_error)
    BASE_ADD_METHODS(unknown_error)

#undef BASE_ADD_METHODS

    bool equal(const status& other) const { return state_ == other.state_; }

private:
    void clear_maybe_payload();
};

status::status(status&& other) noexcept
      : details::tagged_state(std::move(other)) {
    if (other.is_payload()) { other.state_ = rcode_only_state(rcode::ok); }
}

inline bool operator==(const status& lhs,
                       const status& rhs) {
    return lhs.equal(rhs);
}

inline bool operator!=(const status& lhs,
                       const status& rhs) {
    return !(lhs == rhs);
}

BASE_NS_END

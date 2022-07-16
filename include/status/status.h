#pragma once

#include "status/details/tagged_state.h"

BASE_NS_BEGIN

class status final : private details::tagged_state {
public:
    BASE_DECLARE_COPY(status)
    BASE_DECLARE_MOVE(status)

    status() : details::tagged_state() {}
    explicit status(rcode code) : details::tagged_state(code) {}
    ~status();

#define BASE_ADD_METHODS(rc)                                   \
    static status rc() { return status(rcode::rc); }           \
    bool is_##rc() const {                                     \
        return is_rcode_only() && (only_rcode() == rcode::rc); \
    }

    BASE_ADD_METHODS(ok)
    BASE_ADD_METHODS(internal_error)
    BASE_ADD_METHODS(unknown_error)

#undef BASE_ADD_METHODS
};

BASE_NS_END

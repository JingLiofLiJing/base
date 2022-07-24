#pragma once

#include <cassert>

#include <memory>
#include <string>
#include <utility>

#include "status/rcode.h"
#include "sync/ref_counter.h"

#include "fmt/format.h"

BASE_NS_BEGIN

class status_payload;
using status_payload_ptr = std::unique_ptr<status_payload, void(*)(status_payload*)>;

class status_payload final : public ref_counter_base<status_payload> {
    template <typename ...T>
    friend status_payload_ptr make_status_payload(T&&...);
public:
    status_payload() = delete;

    rcode code() const { return code_; }

    std::string what() const;

private:
    status_payload(rcode code, std::string reason)
          : code_(code)
          , reason_(std::move(reason)) {
        assert((code_ != rcode::ok) && (!reason_.empty()));
    }

private:
    rcode       code_;
    std::string reason_;
};

inline void status_payload_ptr_deleter(status_payload* sp) { sp->decrease(); }

template <typename ...T>
status_payload_ptr make_status_payload(T&&... args) {
    return status_payload_ptr(
        new status_payload(std::forward<T>(args)...),
        status_payload_ptr_deleter);
}

std::string status_payload::what() const {
    return fmt::format("{}: {}",
                       rcode_text(code_),
                       std::string_view(reason_));
}

BASE_NS_END

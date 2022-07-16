#pragma once

#include <memory>
#include <string>
#include <utility>

#include "status/rcode.h"
#include "sync/ref_counter.h"

BASE_NS_BEGIN

class status_payload final : public ref_counter_base<status_payload> {
    template <typename ...T>
    friend std::unique_ptr<status_payload> make_status_payload(T&&...);
public:
    status_payload() = delete;

private:
    rcode       rc_;
    std::string reason_;
};

inline void status_payload_ptr_deleter(status_payload* sp) { sp->decrease(); }

template <typename ...T>
std::unique_ptr<status_payload>
make_status_payload(T&&... args) {
    return std::unique_ptr<status_payload>(
        new status_payload(std::forward<T>(args)...),
        status_payload_ptr_deleter);
}

BASE_NS_END

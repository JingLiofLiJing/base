#include "status/status.h"

#include "status_payload.h"

BASE_NS_BEGIN

status::status(const status& other)
      : details::tagged_state(other) {
    if (other.is_payload()) { to_payload()->increase(); }
}

status& status::operator=(const status& other) {
    if (BASE_LIKELY(!equal(other))) {
        clear_maybe_payload();
        details::tagged_state::operator=(other);
        if (other.is_payload()) { to_payload()->increase(); }
    }
    return *this;
}

status& status::operator=(status&& other) noexcept {
    if (BASE_LIKELY(!equal(other))) {
        clear_maybe_payload();
        details::tagged_state::operator=(std::move(other));
        if (other.is_payload()) { other.state_ = rcode_only_state(rcode::ok); }
    }
    return *this;
}

status::status(rcode code, std::string reason) {
    auto payload = make_status_payload(code, std::move(reason));
    state_ = payload_state(payload.release());
}

void status::clear_maybe_payload() {
    if (is_payload()) { status_payload_ptr_deleter(to_payload()); }
}

rcode status::code() const {
    if (is_rcode_only()) { return only_rcode(); }
    return to_payload()->code();
}

std::string status::what() const {
    if (is_rcode_only()) { return static_cast<std::string>(rcode_text(only_rcode())); }
    return to_payload()->what();
}

BASE_NS_END

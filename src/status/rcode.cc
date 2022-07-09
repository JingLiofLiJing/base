#include "status/rcode.h"

BASE_NS_BEGIN

std::string_view rcode_text(rcode code) {
    using std::string_view_literals::operator""sv;
    switch (code) {
        case rcode::ok:             { return "ok"sv; }
        case rcode::internal_error: { return "internal_error"sv; }
        default:                    { return "unknown_error"sv; }
    }
}

BASE_NS_END

#include "status/rcode.h"

BASE_NS_BEGIN

std::string_view rcode_text(RCode code) {
    using namespace std::string_view_literals;
    switch (code) {
        case RCode::kOK:            { return "OK"sv; }
        case RCode::kInternalError: { return "InternalError"sv; }
        default:                    { return "UnknownError"sv; }
    }
}

BASE_NS_END

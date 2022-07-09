#pragma once

#include <string_view>

#include "common.h"

BASE_NS_BEGIN

enum class rcode : uint16_t {
    ok             = 0u,
    internal_error = 1u,
    // Unknown error category.
    unknown_error  = 2u,
};

std::string_view rcode_text(rcode code);

BASE_NS_END

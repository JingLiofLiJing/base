#pragma once

#include <string_view>

#include "common.h"

BASE_NS_BEGIN

enum class RCode : uint32_t {
    kOK            = 0u,
    kInternalError = 1u,
    // Unknown error category.
    kUnknownError  = static_cast<uint32_t>(-1),
};

std::string_view rcode_text(RCode code);

BASE_NS_END

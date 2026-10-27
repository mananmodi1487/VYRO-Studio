#pragma once

#include <string_view>

namespace vyro {

[[nodiscard]] constexpr std::string_view version() noexcept {
    return "0.0.1-dev";
}

} // namespace vyro
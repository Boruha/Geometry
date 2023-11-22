#pragma once

#include <cmath>

namespace BPW {

constexpr bool
Epsilon(const auto& lhs, const auto& rhs) {
    constexpr auto kThreshold { 0.001 };
    return std::abs(lhs - rhs) < kThreshold;
}

}
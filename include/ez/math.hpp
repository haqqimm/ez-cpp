#pragma once

/**
 * @file math.hpp
 * @brief High-level, human-friendly Math utilities for ez-cpp.
 * @author haqqimm
 * @note Zero-bloat, Type-agnostic, and Panic-free.
 */

#include <random>
#include <type_traits>
#include <algorithm>

namespace ez {
namespace math {

    /**
     * @brief Returns a value clamped within the range [min, max].
     * @note Smart Error Handling: Automatically swaps min and max if min > max.
     */
    template <typename T1, typename T2, typename T3>
    inline auto clamp(T1 value, T2 min_val, T3 max_val) {
        using CommonT = std::common_type_t<T1, T2, T3>;
        CommonT v = static_cast<CommonT>(value);
        CommonT mn = static_cast<CommonT>(min_val);
        CommonT mx = static_cast<CommonT>(max_val);

        if (mn > mx) std::swap(mn, mx);
        if (v < mn) return mn;
        if (v > mx) return mx;
        return v;
    }

    /**
     * @brief Generates a random number between min and max (inclusive).
     * @note Smart: Auto-detects int or float. Auto-swaps min/max if backward.
     */
    template <typename T>
    inline T random(T min_val, T max_val) {
        if (min_val > max_val) std::swap(min_val, max_val);

        thread_local std::random_device rd;
        thread_local std::mt19937 gen(rd());

        if constexpr (std::is_floating_point_v<T>) {
            std::uniform_real_distribution<T> dis(min_val, max_val);
            return dis(gen);
        } else {
            std::uniform_int_distribution<T> dis(min_val, max_val);
            return dis(gen);
        }
    }

    /**
     * @brief Re-maps a number from one range to another.
     * @note Safe: Prevents division-by-zero panic. Calculates in floating-point.
     */
    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    inline auto map(T1 value, T2 in_min, T3 in_max, T4 out_min, T5 out_max) {
        using CommonT = std::common_type_t<T1, T2, T3, T4, T5, double>;
        CommonT v = static_cast<CommonT>(value);
        CommonT imin = static_cast<CommonT>(in_min);
        CommonT imax = static_cast<CommonT>(in_max);
        CommonT omin = static_cast<CommonT>(out_min);
        CommonT omax = static_cast<CommonT>(out_max);

        if (imin == imax) return omin;
        
        return (v - imin) * (omax - omin) / (imax - imin) + omin;
    }

    /**
     * @brief Calculates the percentage of a total value.
     * @example ez::math::percent(25, 1000) -> 250
     */
    template <typename T1, typename T2>
    inline auto percent(T1 percentage, T2 total) {
        using CommonT = std::common_type_t<T1, T2, double>;
        return (static_cast<CommonT>(percentage) / 100.0) * static_cast<CommonT>(total);
    }

} // namespace math
} // namespace ez
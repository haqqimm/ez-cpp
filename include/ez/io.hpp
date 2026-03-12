#pragma once

/**
 * @file io.hpp
 * @brief High-level Input/Output utilities for ez-cpp.
 * @author haqqimm
 */

#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <type_traits>
#include <sstream>

namespace ez {

    /**
     * @brief Namespace containing ANSI escape codes for terminal styling.
     */
    namespace color {
        inline constexpr std::string_view reset   = "\033[0m";
        inline constexpr std::string_view red     = "\033[31m";
        inline constexpr std::string_view green   = "\033[32m";
        inline constexpr std::string_view yellow  = "\033[33m";
        inline constexpr std::string_view blue    = "\033[34m";
        inline constexpr std::string_view magenta = "\033[35m";
        inline constexpr std::string_view cyan    = "\033[36m";
    }

    /**
     * @brief Type trait to check if a type is iterable (supports std::begin/std::end).
     * @tparam T The type to check.
     */
    template <typename T, typename = void>
    struct is_iterable : std::false_type {};

    template <typename T>
    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), 
                                      decltype(std::end(std::declval<T>()))>> : std::true_type {};

    /**
     * @brief Internal helper to print values, including automatic container formatting.
     * @tparam T The type of value to print.
     * @param val The actual value.
     */
    template <typename T>
    inline void _print_single(const T& val) {
        if constexpr (is_iterable<T>::value && 
                      !std::is_same_v<T, std::string> && 
                      !std::is_same_v<T, std::string_view>) {
            
            std::cout << "[";
            bool first = true;
            for (const auto& item : val) {
                if (!first) std::cout << ", ";
                _print_single(item);
                first = false;
            }
            std::cout << "]";
        } else {
            std::cout << val;
        }
    }

    /**
     * @brief Prints multiple arguments to the standard output.
     * @tparam Args Variadic template arguments.
     * @param args The data to be printed.
     */
    template <typename... Args>
    inline void print(Args&&... args) {
        (_print_single(std::forward<Args>(args)), ...);
    }

    /**
     * @brief Prints multiple arguments followed by a newline.
     * @tparam Args Variadic template arguments.
     * @param args The data to be printed.
     */
    template <typename... Args>
    inline void println(Args&&... args) {
        if constexpr (sizeof...(args) > 0) {
            print(std::forward<Args>(args)...);
        }
        std::cout << '\n';
    }

    /**
     * @brief Captures a line of string input from the user.
     * @param prompt An optional message to display before input.
     * @return std::string The user's input.
     */
    inline std::string input(std::string_view prompt = "") {
        if (!prompt.empty()) {
            std::cout << prompt << std::flush;
        }
        std::string buffer;
        if (!std::getline(std::cin, buffer)) {
            return "";
        }
        return buffer;
    }

    /**
     * @brief Captures and automatically converts user input to a specific type.
     * @tparam T The target type for conversion (e.g., int, double).
     * @param prompt An optional message to display.
     * @return T The converted input value.
     * @note This function will loop until a valid conversion is possible.
     */
    template <typename T>
    inline T input(std::string_view prompt = "") {
        T result;
        while (true) {
            std::string buffer = input(prompt);
            std::istringstream iss(buffer);
            
            if (iss >> result) {
                return result;
            }
            
            println(color::red, "[Error] Invalid input type. Please try again.", color::reset);
        }
    }

} // namespace ez
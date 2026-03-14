#pragma once

/**
 * @file str.hpp
 * @brief High-level, human-friendly String manipulation utilities for ez-cpp.
 * @author haqqimm
 * @note Clean, zero-bloat, and panic-free string operations.
 */

#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iterator>

namespace ez {
namespace str {

    /**
     * @brief Converts all characters in a string to lowercase.
     * @param input The original string.
     * @return std::string A new lowercase string.
     * @note Safe: Casts to unsigned char to prevent undefined behavior with non-ASCII characters.
     */
    inline std::string to_lower(std::string_view input) {
        std::string result(input);
        std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    /**
     * @brief Converts all characters in a string to uppercase.
     * @param input The original string.
     * @return std::string A new uppercase string.
     * @note Safe: Casts to unsigned char to prevent undefined behavior with non-ASCII characters.
     */
    inline std::string to_upper(std::string_view input) {
        std::string result(input);
        std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return std::toupper(c); });
        return result;
    }

    /**
     * @brief Removes leading and trailing whitespaces from a string.
     * @param input The string to be trimmed.
     * @return std::string The trimmed string.
     * @note Returns an empty string safely if the input is entirely whitespace.
     */
    inline std::string trim(std::string_view input) {
        auto start = std::find_if_not(input.begin(), input.end(), [](unsigned char c) { return std::isspace(c); });
        auto end = std::find_if_not(input.rbegin(), input.rend(), [](unsigned char c) { return std::isspace(c); }).base();
        
        if (start >= end) {
            return std::string();
        }
        return std::string(start, end);
    }

    /**
     * @brief Splits a string into a vector of substrings based on a delimiter.
     * @param input The string to split.
     * @param delimiter The string sequence to split by.
     * @return std::vector<std::string> A vector of string tokens.
     * @note Anti-bug: Automatically handles empty delimiters and empty input safely.
     */
    inline std::vector<std::string> split(std::string_view input, std::string_view delimiter) {
        std::vector<std::string> tokens;
        if (input.empty()) {
            return tokens;
        }
        if (delimiter.empty()) {
            tokens.emplace_back(input);
            return tokens;
        }

        size_t start = 0;
        size_t end = input.find(delimiter);

        while (end != std::string_view::npos) {
            tokens.emplace_back(input.substr(start, end - start));
            start = end + delimiter.length();
            end = input.find(delimiter, start);
        }
        tokens.emplace_back(input.substr(start));

        return tokens;
    }

    /**
     * @brief Joins an iterable container of items into a single string using a delimiter.
     * @tparam Iterable The type of the container (e.g., std::vector, std::list).
     * @param container The container containing elements to join.
     * @param delimiter The string to insert between elements.
     * @return std::string The combined string.
     * @note Agnostic: Works with any container type and any data type that supports the << operator.
     */
    template <typename Iterable>
    inline std::string join(const Iterable& container, std::string_view delimiter) {
        std::ostringstream oss;
        auto it = std::begin(container);
        auto end = std::end(container);

        if (it != end) {
            oss << *it;
            ++it;
        }
        for (; it != end; ++it) {
            oss << delimiter << *it;
        }
        return oss.str();
    }

    /**
     * @brief Replaces all occurrences of a search string with a replacement string.
     * @param input The original string.
     * @param search The substring to find.
     * @param replacement The string to substitute in place of the search string.
     * @return std::string The modified string.
     * @note Anti-bug: Ignores empty search strings to prevent infinite replacement loops.
     */
    inline std::string replace_all(std::string_view input, std::string_view search, std::string_view replacement) {
        std::string result(input);
        if (search.empty()) {
            return result;
        }

        size_t pos = 0;
        while ((pos = result.find(search, pos)) != std::string::npos) {
            result.replace(pos, search.length(), replacement);
            pos += replacement.length();
        }
        return result;
    }

    /**
     * @brief Checks if a string contains a specific substring.
     * @param input The string to search inside.
     * @param search The substring to look for.
     * @return bool True if the substring is found, false otherwise.
     */
    inline bool contains(std::string_view input, std::string_view search) {
        return input.find(search) != std::string_view::npos;
    }

}
}
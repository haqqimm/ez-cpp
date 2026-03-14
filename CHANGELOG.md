# Changelog 📜

All notable changes to this project will be documented in this file.

## [0.3.0] - 2026-03-14
### Added
- High-level, zero-bloat `str.hpp` module for safe string manipulation.
- `ez::str::to_lower(str)` and `ez::str::to_upper(str)`: Safe case conversion.
- `ez::str::trim(str)`: Removes leading and trailing whitespaces.
- `ez::str::split(str, delimiter)`: Safely splits strings into vectors, protected against infinite loops.
- `ez::str::join(container, delimiter)`: Agnostic template to join any iterable container into a string.
- `ez::str::replace_all(str, search, replacement)`: Replaces all substring occurrences safely.
- `ez::str::contains(str, search)`: Checks for substrings.
- Added `examples/demo_str.cpp` to showcase string features.
- Integrated `str.hpp` into the main `ez.hpp` gateway.

## [0.2.0] - 2026-03-13
### Added
- Human-friendly `math.hpp` module for safe, boilerplate-free math operations.
- `ez::math::random<T>(min, max)`: Auto-detects `int` or `float` with thread-local, zero-bloat RNG.
- `ez::math::clamp(val, min, max)`: Restricts values with smart auto-swap for inverted min/max.
- `ez::math::map(val, in_min, in_max, out_min, out_max)`: Safely re-scales numbers with division-by-zero protection.
- `ez::math::percent(percentage, total)`: Calculates percentages seamlessly across different types.

## [0.1.0] - 2026-03-12
### Added
- Initial release of `ez-cpp`.
- Core `io.hpp` module with variadic `print` and `println`.
- Automatic container printing (vectors, arrays, nested matrices).
- Memory-safe `input()` and templated `input<T>()` with auto-retry on error.
- Zero-overhead ANSI color support via `ez::color`.
- Professional Doxygen-style documentation for all functions.
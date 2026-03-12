# Contributing to ez-cpp 🚀

First off, thanks for taking the time to contribute! 

`ez-cpp` is built on a specific philosophy: **"Zero-bloat, maximum vibe."** Before you submit a Pull Request, please read these quick ground rules:

## 🛠️ The Ground Rules
1. **No External Dependencies:** This is a header-only, dependency-free library. Please do not add external libraries (`Boost`, `fmt`, etc.). We rely entirely on standard C++17 (or newer).
2. **Zero-Cost Abstractions:** If you add a feature, make sure it doesn't slow down the runtime performance. Use `constexpr`, `string_view`, and compile-time evaluations wherever possible.
3. **Developer Experience (DX) First:** The goal is to make C++ easier to write. If your feature requires the user to write boilerplate code, it doesn't belong here.

## 🐛 Found a Bug?
If you find a bug (e.g., memory leak, compilation error on specific compilers), please open an Issue with:
- The code snippet that caused the error.
- Your compiler version (Clang, GCC, MSVC).

## 💡 Proposing a Feature
We're currently expanding `ez-cpp`. If you want to add a new module (like `ez/math.hpp` or `ez/strings.hpp`), open an Issue first to discuss the idea before you start coding. We want to keep the library lean!
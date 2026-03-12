# ez-cpp

![C++17](https://img.shields.io/badge/Standard-C%2B%2B17-blue.svg?logo=c%2B%2B)
![Header Only](https://img.shields.io/badge/Type-Header--Only-success.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Zero Dependencies](https://img.shields.io/badge/Dependencies-0-orange.svg)

The missing C++ standard library for humans. 

C++ is incredibly fast and powerful, but writing basic I/O can be miserable. You shouldn't have to write `std::cout << x << '\n'` a hundred times a day, chain nested `for-loops` just to print a vector, or write 10 lines of boilerplate to safely read an integer.

`ez-cpp` is a zero-overhead, header-only library that makes writing C++ feel as fluid as Python or Rust, without sacrificing a single drop of runtime performance.

## Standard C++ vs ez-cpp

**The Old Way (Suffering):**
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::cout << "My numbers: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    std::cout << "]\n";
}
```

**The `ez-cpp` Way:**
```cpp
#include "ez/ez.hpp"
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3};
    ez::println("My numbers: ", nums);
}
```

--- 

## Features

- **Variadic Printing:** Pass as many arguments of different types as you want. No more chaining `<<`.
- **Auto-Container Printing:** Automatically formats and prints `std::vector`, `std::array`, or even nested matrices. No loops required.
- **Memory-Safe Input:** `ez::input()` handles `std::getline` safely behind the scenes.
- **Safe Type Conversion:** `ez::input<int>()` forces the user to input an integer. If they type text, it gracefully asks again without crashing or leaking memory.
- **Zero-Bloat Colors:** Built-in ANSI colors (`ez::color::cyan`, etc.) using `std::string_view` for zero allocation cost.
- **Header-Only:** Drop the folder into your project and you're done. No CMake hell, no linker errors.

---

## Quick Start

**1. installation**

Since **ez-cpp** is a header-only library, there is no build step.
Simply copy the **include/ez** folder into your project's include path or **third_party** directory.

**2. Usage**

```cpp
#include "ez/ez.hpp"
#include <string>
#include <vector>

int main() {
    using namespace ez::color;

    // Print text with zero-overhead colors
    ez::println(cyan, "=== ez-cpp Showcase ===", reset);

    // Safe string input
    std::string name = ez::input("Enter your name: ");

    // Safe type conversion (Will reject non-numeric input automatically)
    int age = ez::input<int>("Enter your age: ");

    // Print multiple types seamlessly
    ez::println("Awesome! ", name, " is ", age, " years old.");

    // Print nested containers instantly
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
    ez::println("Your matrix: ", matrix);

    return 0;
}
```

---

## ez-cpp API

**Output**

- `ez::print(args...)`: Prints multiple arguments.
- `ez::println(args...)`: Prints multiple arguments followed by a fast `\n`.

**Input**

- `ez::input(prompt)`: Returns a `std::string` safely.
- `ez::input<T>(prompt)`: Prompts the user until a valid type `T` (e.g., `int`, `double`) is provided.

**Styling**

- `ez::color::[red|green|yellow|blue|magenta|cyan|reset]`: ANSI escape codes optimized as `constexpr std::string_view`.

## License

MIT © Haqqi Muazzam
#include "../include/ez/ez.hpp"
#include <vector>
#include <string>

int main() {
    // Import colors for cleaner code
    using namespace ez::color;

    // 1. Simple Print & Color Support
    ez::println(cyan, "=== Welcome to ez-cpp Demo ===", reset);
    ez::println("This library makes C++ I/O as easy as Python!\n");

    // 2. Auto Container Printing (No more for-loops!)
    std::vector<int> numbers = {10, 20, 30, 40};
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}}; // Nested vector!

    ez::println(green, "1. Printing Containers:", reset);
    ez::println("Numbers : ", numbers);
    ez::println("Fruits  : ", fruits);
    ez::println("Matrix  : ", matrix, "\n");

    // 3. Fast & Safe Input (String)
    ez::println(green, "2. Fast Input (String):", reset);
    std::string name = ez::input("What is your name? ");
    
    // 4. Templated Safe Input (Integer)
    // Try typing text here instead of numbers to see the anti-crash protection!
    ez::println("\n", green, "3. Safe Type Conversion (int):", reset);
    int age = ez::input<int>("How old are you? ");

    // 5. Variadic Printing (Mixing types seamlessly)
    ez::println("\n", cyan, "=== Result ===", reset);
    ez::println("Awesome! Your name is ", yellow, name, reset, 
                " and you are ", yellow, age, reset, " years old.");

    return 0;
}
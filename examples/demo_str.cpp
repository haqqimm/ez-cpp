#include "../include/ez/ez.hpp" // Adjust path if necessary based on your folder structure
#include <vector>
#include <string>

int main() {
    // Import colors for cleaner code
    using namespace ez::color;

    // 1. Module Introduction
    ez::println(cyan, "=== Welcome to ez-cpp String Demo ===", reset);
    ez::println("Making C++ String manipulation safe, smart, and human-friendly!\n");

    // 2. Case Conversion Demo
    // Note: Safe from undefined behavior with non-ASCII characters!
    ez::println(green, "1. Case Conversion:", reset);
    std::string text = "HaLlo C++17!";
    
    ez::println("Original : ", text);
    ez::println("Lower    : ", ez::str::to_lower(text));
    ez::println("Upper    : ", ez::str::to_upper(text));
    ez::println();

    // 3. Trim Demo (Removing spaces)
    ez::println(green, "2. Trim (Whitespace Removal):", reset);
    std::string dirty_text = "   \t  text with spaces   \n ";
    
    // Automatically cleans up leading and trailing garbage spaces
    ez::println("Original : '", dirty_text, "'");
    ez::println("Trimmed  : '", ez::str::trim(dirty_text), "'");
    ez::println();

    // 4. Split Demo (Breaking string into vector safely)
    ez::println(green, "3. Split (String to Vector):", reset);
    std::string csv_data = "apple,orange,mango,banana";
    
    // Anti-bug: Handles empty delimiters and strings safely
    auto fruits = ez::str::split(csv_data, ",");
    
    ez::println("CSV Data : ", csv_data);
    // Showcasing ez::io's hidden ability to print vectors directly!
    ez::println("Tokens   : ", fruits); 
    ez::println();

    // 5. Join Demo (Vector back to string)
    ez::println(green, "4. Join (Vector to String):", reset);
    
    // Agnostic: Works with any iterable container
    std::string joined = ez::str::join(fruits, " | ");
    
    ez::println("Joined Result : ", joined);
    ez::println();

    // 6. Replace & Contains Demo
    ez::println(green, "5. Replace & Contains:", reset);
    std::string sentence = "I like bugs, bugs are my friends.";
    
    // Anti-bug replacement (safe from infinite loops)
    std::string fixed = ez::str::replace_all(sentence, "bugs", "code");
    
    ez::println("Original : ", sentence);
    ez::println("Fixed    : ", fixed);
    ez::println("Has 'code'? : ", ez::str::contains(fixed, "code") ? "Yes" : "No");
    ez::println("Has 'bugs'? : ", ez::str::contains(fixed, "bugs") ? "Yes" : "No");
    ez::println();

    // Conclusion
    ez::println(cyan, "=== Demo Finished ===", reset);
    ez::println("All string functions executed smoothly without boilerplate!");

    return 0;
}
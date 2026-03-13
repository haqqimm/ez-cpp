#include "../include/ez/ez.hpp" // Adjust path if necessary based on your folder structure
#include <vector>
#include <string>

int main() {
    // Import colors for cleaner code
    using namespace ez::color;

    // 1. Module Introduction
    ez::println(cyan, "=== Welcome to ez-cpp Math Demo ===", reset);
    ez::println("Making C++ Math utilities safe, smart, and human-friendly!\n");

    // 2. Random Numbers Demo (Auto-detects int or float)
    // Note: No need to setup std::mt19937 or std::random_device manually!
    ez::println(green, "1. Random Numbers:", reset);
    int gacha = ez::math::random(1, 100);
    float drop_rate = ez::math::random(0.0f, 100.0f);
    
    ez::println("Gacha Roll (1-100) : ", gacha);
    ez::println("Drop Rate (0-100)  : ", drop_rate, "%");
    ez::println();

    // 3. Clamp Demo (Restricting values)
    ez::println(green, "2. Clamp (Value Restriction):", reset);
    int hp = 150; // HP exceeds the maximum limit
    ez::println("Character HP before clamp : ", hp);
    
    // Automatically limits the value to be between 0 and 100
    hp = ez::math::clamp(hp, 0, 100); 
    ez::println("Character HP after clamp  : ", hp, " (Max 100)");
    ez::println();

    // 4. Map Demo (Re-scaling numbers safely)
    ez::println(green, "3. Map (Re-scaling Ranges):", reset);
    int sensor_value = 512; // Example: Analog sensor reading (0-1023)
    
    // Convert the sensor value to a UI percentage (0-100)
    float ui_percentage = ez::math::map(sensor_value, 0, 1023, 0.0, 100.0);
    
    ez::println("Analog Sensor (0-1023) : ", sensor_value);
    ez::println("UI Percentage (0-100)  : ", ui_percentage, "%");
    ez::println();

    // 5. Percent Demo
    ez::println(green, "4. Percentage Calculation:", reset);
    int item_price = 250000;
    
    // Calculate 20% of the item price seamlessly
    auto discount = ez::math::percent(20, item_price); 
    
    ez::println("Normal Price : Rp ", item_price);
    ez::println("20% Discount : Rp ", discount);
    ez::println("Total to Pay : Rp ", item_price - discount);
    ez::println();

    // Conclusion
    ez::println(cyan, "=== Demo Finished ===", reset);
    ez::println("All math functions executed smoothly without boilerplate!");

    return 0;
}
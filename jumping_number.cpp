#include <algorithm>
#include <iostream>
#include <string>

std::string jumpingNumber(int number) {
    std::string num = std::to_string(number);

    auto result = std::adjacent_find(num.begin(), num.end(), [](auto first, auto second) {
        if (std::abs(first - second) != 1) {
            return true;
        }
        return false;
    });

    if (result != num.end()) {
        return "Not!!";
    }
    return "Jumping!!";
}

int main() {
    std::cout << jumpingNumber(3456543213);

    return 0;
}


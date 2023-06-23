#include <algorithm>
#include <iostream>
#include <string>

std::string arbitrate(const std::string& input, int n) {
    std::string solve = std::move(input);
    auto it = solve.find_first_of("1");
    if (it != std::string::npos) {
        it++;
        std::transform(solve.begin() + it, solve.end(), solve.begin() + it,
                       [](auto el) {
                           el = '0';
                           return el;
                       });
    }

    return solve;
}

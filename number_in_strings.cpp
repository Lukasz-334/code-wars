#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

void transformStr(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](auto el) {
        if (std::isalpha(el)) {
            return ' ';
        }
        return el;
    });
}

int solve(std::string s) {
    transformStr(s);
    std::stringstream sstream(s);
    int number = 0;
    int max_number = 0;

    while (sstream >> number) {
        max_number = std::max(number, max_number);
    }
    return max_number;
}


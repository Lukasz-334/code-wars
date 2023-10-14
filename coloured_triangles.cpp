#include <algorithm>
#include <iostream>
#include <string>

std::string triangle(std::string str) {
    while (str.size() > 1) {
        std::transform(str.cbegin(), --str.cend(), ++str.cbegin(), str.begin(), [](auto first, auto second) {
            if (first == second) {
                return first;
            }
            if ((first != 'R') && (second != 'R')) {
                return 'R';
            }
            if ((first != 'G') && (second != 'G')) {
                return 'G';
            }
            return 'B';
        });
        str.pop_back();
    }

    return str;
}

int main() {
    triangle("RRGBRGBB");

    return 0;
}


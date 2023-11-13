#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

std::string alphabetized(const std::string& str) {
    std::string copy_str;

    std::copy_if(str.begin(), str.end(), std::back_inserter(copy_str), [](auto c) {
        return std::isalpha(c);
    });

    std::stable_sort(copy_str.begin(), copy_str.end(), [](auto lhs, auto rhs) {
        return std::tolower(lhs) < std::tolower(rhs);
    });

    return copy_str;
}




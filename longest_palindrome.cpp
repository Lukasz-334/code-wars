#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(const std::string& test_str) {
    std::string str2(test_str.crbegin(), test_str.crend());

    return str2 == test_str;
}

int longest_palindrome(const std::string& s) {
    if (s.size() < 2) {
        return s.size();
    }

    size_t size_palindrome = 1;
    for (size_t i = 0; i < s.size(); i++) {
        std::string str = s.substr(i, 1);
        for (size_t j = i + 1; j < s.size(); j++) {
            str += s[j];
            if (is_palindrome(str)) {
                size_palindrome = std::max(size_palindrome, str.size());
            }
        }
    }
    return size_palindrome;
}

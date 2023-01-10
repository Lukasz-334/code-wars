#include <algorithm>
#include <iostream>

size_t duplicate_Count(const std::string& in) {
    std::string s1 = in;
    std::string s2;
    size_t solv = 0;

    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::sort(s1.begin(), s1.end());

    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2));
    for (const auto& el : s2) {
        if (std::count(s1.begin(), s1.end(), el) > 1) {
            solv++;
        }
    }

    return solv;
}

int main() {
    std::cout << duplicate_Count("asdfghjkl;'\\'");

    return 0;
}

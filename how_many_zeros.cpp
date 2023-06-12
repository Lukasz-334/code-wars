#include <algorithm>
#include <iostream>
#include <string>

bool oneCharacter(const char c) {
    std::string set("abdegopq069DOPQR");
    return std::find(set.begin(), set.end(), c) != set.end();
}

bool twoCharacters(const char c) {
    std::string set("%&B8");
    return std::find(set.begin(), set.end(), c) != set.end();
}

int search(const std::string& str) {
    std::string pattern("()");

    auto count = 0;
    auto it = str.begin();

    while (it != str.end()) {
        it = std::search(it, str.end(), pattern.begin(), pattern.end());
        if (it != str.end()) {
            count++;
            it++;
        }
    }
    return count;
}

int countZero(std::string s) {
    return std::count_if(s.begin(), s.end(), oneCharacter) +
           (2 * (std::count_if(s.begin(), s.end(), twoCharacters))) + search(s);
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void transformVec(const std::vector<char>& chars, std::vector<char>& vecChar) {
    vecChar = chars;
    std::transform(vecChar.begin(), vecChar.end(), vecChar.begin(), ::toupper);
}

char findMissingLetter(const std::vector<char>& chars) {
    std::string pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<char> incomplete_set;
    transformVec(chars, incomplete_set);

    std::vector<char> result;
    auto it_b = std::find(pattern.begin(), pattern.end(), incomplete_set.at(0));
    auto it_e = std::find(pattern.begin(), pattern.end(), incomplete_set.back());
    auto lon = std::distance(it_b, it_e);
    auto substring_pattern = pattern.substr(pattern.find(incomplete_set.at(0)), ++lon);
    std::vector<char> complete_set(substring_pattern.begin(), substring_pattern.end());

    std::set_difference(complete_set.begin(), complete_set.end(), incomplete_set.begin(), incomplete_set.end(),
                        back_inserter(result));

    if (isupper(chars.at(0))) {
        return *result.begin();
    }
    return std::tolower(*result.begin());
}

int main() {
    std::cout << findMissingLetter({'a', 'b', 'c', 'd', 'e', 'g'});

    return 0;
}

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

std::optional<std::pair<char, unsigned int>> counter(const std::vector<std::vector<char>>& vec) {
    int first = 0;
    char sign;

    for (auto element : vec) {
        if (element.size() > first) {
            sign = element.front();
            first = element.size();
        }
    }

    return std::make_optional<std::pair<char, unsigned int>>({sign, first});
}

std::optional<std::pair<char, unsigned int>> longestRepetition(const std::string& str) {
    if (str.empty()) {
        return std::nullopt;
    }

    std::vector<std::vector<char>> vec;
    vec.resize(str.size());
    int j = 0;
    char temp = str[0];
    vec[j].push_back(temp);

    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] == temp) {
            vec[j].push_back(temp);
        } else {
            temp = str[i];
            j++;
            vec[j].push_back(temp);
        }
    }

    return counter(vec);
}

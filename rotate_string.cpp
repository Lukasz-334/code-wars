#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> rotate(const std::string& s) {
    std::vector<std::string> result;
    int size = s.size();
    std::string temp = std::move(s);

    while (size--) {
        std::rotate(temp.begin(), temp.begin() + 1, temp.end());
        result.push_back(temp);
    }
    return result;
}

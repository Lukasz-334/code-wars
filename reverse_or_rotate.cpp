#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

bool calculateTheSumOfTheCubesAndCheckTheEvenness(const std::string& str) {
    auto sum = std::accumulate(str.begin(), str.end(), 0, [](int s, char c) {
        return s + pow(c - '0', 3);
    });

    return sum % 2 == 0;
}

class RevRot {
public:
    static std::string revRot(const std::string& str, unsigned int sz) {
        if (sz <= 0 || str.empty() || sz > str.size()) {
            return "";
        }

        std::string result;
        for (unsigned int i = 0; i < str.size(); i += sz) {
            std::string chunk = str.substr(i, sz);
            if (chunk.size() < sz) {
                break;
            }
            if (calculateTheSumOfTheCubesAndCheckTheEvenness(chunk)) {
                std::reverse(chunk.begin(), chunk.end());
            } else {
                std::rotate(chunk.begin(), chunk.begin() + 1, chunk.end());
            }
            result += chunk;
        }
        return result;
    }
};

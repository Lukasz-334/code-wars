#include <algorithm>
#include <iostream>
#include <vector>

class MaxRotate {
public:
    static long long maxRot(long long n) {
        std::string number;
        std::vector<std::string> numbers;
        number = std::to_string(n);
        numbers.push_back(number);
        number = number.substr(1) + number.at(0);
        numbers.push_back(number);

        for (size_t i = 1; i < number.size() - 1; i++) {
            char n = number.at(i);
            number.erase(i, 1);
            number += n;
            numbers.push_back(number);
        }

        return std::stoll(*std::max_element(numbers.begin(), numbers.end()));
    }
};


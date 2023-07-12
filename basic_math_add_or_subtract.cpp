#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

std::string transformDigit(const std::string& str) {
    std::string num;
    for (size_t i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            num += str[i];

        } else {
            num += ' ';
        }
    }
    return num;
}

std::string transformOperator(const std::string& str) {
    std::string op;
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            op += str[i];
        } else {
            op += ' ';
        }
    }
    return op;
}

std::vector<std::string> split(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> tokens{std::istream_iterator<std::string>(iss), {}};

    return tokens;
}

std::string calculate(std::string str) {
    if (str.empty())
        return "";

    auto nums = split(transformDigit(str));
    auto op = split(transformOperator(str));

    int sum = std::stoi(nums[0]);

    for (size_t i = 1; i < nums.size(); i++) {
        if (op[i - 1] == "plus") {
            sum += std::stoi(nums[i]);

        } else {
            sum -= std::stoi(nums[i]);
        }
    }

    return std::to_string(sum);
}

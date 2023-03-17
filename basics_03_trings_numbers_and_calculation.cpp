#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

std::string calculateString(std::string calcIt) {
    double num1;
    double num2;
    char oper;
    using type = double;
    std::string cleaned;
    std::unordered_map<char, std::function<type(type, type)>> calcMap;

    calcMap['+'] = std::plus<type>();
    calcMap['-'] = std::minus<type>();
    calcMap['*'] = std::multiplies<type>();
    calcMap['/'] = std::divides<type>();

    std::copy_if(calcIt.begin(), calcIt.end(), std::back_inserter(cleaned), [](auto el) {
        return ((isdigit(el)) || (el == '.') || (el == '*') || (el == '/') || (el == '+') || (el == '-'));
    });

    std::istringstream stream(cleaned);

    stream >> num1 >> oper >> num2;

    auto temp = calcMap[oper](num1, num2);

    int result = static_cast<int>(std::round(temp));
    return std::to_string(result);
}

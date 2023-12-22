#include <algorithm>
#include <iostream>
#include <iterator>

unsigned add(unsigned x, unsigned y) {
    std::string str_x = std::to_string(x);
    std::string str_y = std::to_string(y);
    std::string sstr;
    std::string solve;

    if (str_x.size() > str_y.size()) {
        sstr = str_x.substr(0, str_x.size() - str_y.size());
        str_x.erase(0, sstr.size());
    } else {
        sstr = str_y.substr(0, str_y.size() - str_x.size());
        str_y.erase(0, sstr.size());
    }

    for (size_t i = 0; i < str_x.size(); i++) {
        size_t ptr = (str_x[i] + str_y[i] - 96);
        solve += std::to_string(ptr);
    }

    return std::stoi(solve.insert(0, sstr));
}

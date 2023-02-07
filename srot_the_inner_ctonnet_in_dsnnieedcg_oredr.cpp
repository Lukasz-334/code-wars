#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

std::string sortTheInnerContent(std::string words, int length) {
    std::string tmp;
    std::string solv;
    std::string r;
    std::istringstream str(words);
    while (str >> tmp) {
        if (tmp.size() > 3) {
            std::sort(tmp.begin() + 1, tmp.end() - 1, std::greater<char>());
            solv += tmp;
        } else {
            solv += tmp;
        }
    }

    for (auto i = 0, j = 0; i < length; i++) {
        if (words[i] == ' ') {
            r += ' ';

        } else {
            r += solv[j];
            j++;
        }
    }

    return r;
}

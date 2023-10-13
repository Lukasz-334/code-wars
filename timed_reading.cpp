#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int timed_reading(int maxLength, const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> vectorOfWords{std::istream_iterator<std::string>(iss), {}};
    return std::count_if(vectorOfWords.begin(), vectorOfWords.end(), [maxLength](auto word) {
        auto wordLength = std::count_if(word.begin(), word.end(), [](auto sign) {
            return std::isalpha(sign);
        });

        return ((wordLength <= maxLength) && (wordLength > 0));
    });
}

int main() {
    std::cout << timed_reading(3, "Suddenly he stopped, and glanced up at the houses");
}

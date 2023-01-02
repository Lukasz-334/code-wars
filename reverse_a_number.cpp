#include <algorithm>
#include <string>

long long reverseNumber(long long n) {
    std::string str = std::to_string(n);
    if (str.front() == '-') {
        std::reverse(str.begin() + 1, str.end());
    } else {
        std::reverse(str.begin(), str.end());
    }
    n = std::stoi(str);

    return n;
}

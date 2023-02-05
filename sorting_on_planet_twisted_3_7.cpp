#include <algorithm>
#include <string>
#include <vector>

using namespace std;

std::vector<int> sortTwisted37(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end(), [](int lhs, int rhs) {
        std::vector<std::string> num{std::to_string(lhs), std::to_string(rhs)};

        for (int i = 0; i < 2; ++i) {
            std::transform(num[i].begin(), num[i].end(), num[i].begin(), [](auto c) {
                if (c == '3') {
                    return '7';
                } else if (c == '7') {
                    return '3';
                }
                return c;
            });
        }

        return std::stoi(num.front()) < std::stoi(num.back());
    });

    return numbers;
}

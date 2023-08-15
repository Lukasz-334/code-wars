#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

bool even_numbers(const int num) {
    return num % 2 == 0;
}

void eraseDuplicate(std::vector<int>& vec) {
    std::unordered_set unique(vec.begin(), vec.end());
    vec.assign(unique.begin(), unique.end());
}

std::vector<int> menFromBoys(std::vector<int> values) {
    eraseDuplicate(values);
    std::sort(

        std::begin(values), std::end(values), [](auto lhs, auto rhs) {
            if ((even_numbers(lhs)) && (even_numbers(rhs))) {
                return lhs < rhs;
            }
            if (!(even_numbers(lhs)) && (!even_numbers(rhs))) {
                return lhs > rhs;
            }
            return ((even_numbers(lhs)) && (!even_numbers(rhs)));
        });

    return values;
}

int main() {
    auto v = menFromBoys({20, 33, 50, 20, 46, 34, 43, 46});

    for (auto el : v) {
        std::cout << el << ' ';
    }
    return 0;
}

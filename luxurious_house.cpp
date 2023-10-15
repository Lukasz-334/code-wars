#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> luxhouse(const std::vector<int>& houses) {
    std::vector<int> result(houses.size(), 0);
    for (size_t i = 1; i < houses.size(); i++) {
        result[i - 1] = (std::clamp(*std::max_element(houses.begin() + i, houses.end()) - houses[i - 1] + 1, 0, 2147483647));
    }
    return result;
}

int main() {
    for (auto el : luxhouse({1, 2, 3, 1, 2})) {
        std::cout << el << ' ';
    }

    return 0;
}

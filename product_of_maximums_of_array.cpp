#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

int maxProduct(std::vector<int> numbers, int sub_size) {
    std::partial_sort(numbers.begin(), numbers.begin() + sub_size, numbers.end(), std::greater());
    auto it_end = numbers.begin();
    std::advance(it_end, sub_size);
    return std::accumulate(numbers.begin(), it_end, 1, std::multiplies());
}

int main() {
    std::cout << maxProduct({4, 3, 5}, 2);
    return 0;
}

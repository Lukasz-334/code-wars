#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> arrayLeaders(const std::vector<int>& numbers) {
    std::vector<int> partial_sum;
    std::vector<int> result;
    partial_sum.resize(numbers.size());
    inclusive_scan(crbegin(numbers), crend(numbers), begin(partial_sum));

    auto it = partial_sum.end();
    it = std::prev(it, 2);
    for (size_t i = 0; i < numbers.size() - 1; i++) {
              if (numbers[i] > *it) {
            result.push_back(numbers[i]);
        }
        it--;
    }
    if (numbers.back() > 0) {
        result.push_back(numbers.back());
    }

    return result;
}

int main() {
    auto vec = arrayLeaders({1,5,15,2,1});

    for (auto el : vec) {
        std::cout << el << ' ';
    }

    return 0;
}


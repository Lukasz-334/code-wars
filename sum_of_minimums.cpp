#include <algorithm>
#include <vector>

int sum_of_minimums(const std::vector<std::vector<int>>& numbers) {
    int sum = 0;

    for (const auto& v : numbers) {
        sum += *std::min_element(v.begin(), v.end());
    }

    return sum;
}

int main() {
    sum_of_minimums({{7, 9, 8, 6, 2}, {6, 3, 5, 4, 3}, {5, 8, 7, 4, 5}});

    return 0;
}


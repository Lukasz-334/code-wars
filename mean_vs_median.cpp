#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int Median(std::vector<int>& numbers) {
    auto m = numbers.begin() + numbers.size() / 2;
    std::nth_element(numbers.begin(), m, numbers.end());
    return numbers[numbers.size() / 2];
}

double Mean(std::vector<int>& numbers) {
    return static_cast<double>(
               std::accumulate(numbers.begin(), numbers.end(), 0)) /
           static_cast<double>(numbers.size());
}

std::string meanVsMedian(std::vector<int> numbers) {
    auto median = Median(numbers);
    auto mean = Mean(numbers);

    if (median > mean) {
        return "median";
    } else if (median < mean) {
        return "mean";
    }

    return "same";
}

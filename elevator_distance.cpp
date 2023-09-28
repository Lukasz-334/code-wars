#include <iostream>
#include <numeric>
#include <vector>

int elevator_distance(std::vector<int> array) {
    auto sum = 0;
    std::adjacent_difference(array.begin(), array.end(), array.begin(), [&sum](auto first, auto second) {
        sum += abs(first - second);
        return sum;
    });

    return sum;
}

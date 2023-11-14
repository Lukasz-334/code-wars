#include <cmath>
#include <iostream>
#include <vector>

bool isSmooth(const std::vector<int>& arr) {
    if (arr.size() % 2) {
        return ((arr.front() == arr.back()) && (arr.front() == arr[std::floor(arr.size() / 2)]));
    }

    return ((arr.front() == (arr[arr.size() / 2] + arr[(arr.size() / 2) - 1])) && (arr.front() == arr.back()));
}

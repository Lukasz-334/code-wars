#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

std::vector<int> firstNSmallest(const std::vector<int> arr, int n) {
    if (arr.size() == n) {
        return arr;
    }
    if (n == 0) {
        return {};
    }
    std::list<int> solv(arr.rbegin(), arr.rend());

    while (solv.size() > n) {
        auto it = std::max_element(solv.begin(), solv.end());
        solv.erase(it);
    }
    std::vector<int> r(solv.rbegin(), solv.rend());
    return r;
}

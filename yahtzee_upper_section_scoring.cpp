#include <algorithm>
#include <unordered_map>
#include <vector>

long yahtzee_upper(std::vector<int> arr) {
    std::unordered_map<int, int> m;

    long solv = 0;
    long tmp = 0;
    for (const auto& el : arr) {
        m[el]++;
    }
    for (const auto& [k, v] : m) {
        tmp = k * v;
        solv = std::max(solv, tmp);
    }
    return solv;
}

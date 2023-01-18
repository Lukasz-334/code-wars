#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solve(std::vector<int> vec) {
    std::vector<int> solv;
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        if (std::find(solv.begin(), solv.end(), *it) == solv.end()) {
            solv.insert(solv.begin(), *it);
        }

    return solv;
}

#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<int>*> bucketize(const std::vector<int>& a) {
    std::vector<std::vector<int>*> solve;

    std::map<size_t, size_t> m;

    for (const auto& el : a) {
        m[el]++;
    }

    for (size_t j = 0; j < a.size() + 1; j++) {
        std::vector<int>* temp = new std::vector<int>();
        for (auto [k, v] : m) {
            if (v == j) {
                temp->push_back(k);
            }
        }
        if (temp->size() == 0) {
            solve.push_back(nullptr);

        } else {
            solve.push_back(temp);
        }
    }

    return solve;
}

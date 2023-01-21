#include <forward_list>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>

std::pair<int, int> findMostFrequent(std::forward_list<int> l) {
    std::pair<int, int> solv({0, 0});

    int old = 0;
    std::unordered_map<int,int>m;
    for (const auto& el : l) {
        m[el]++;
    }

    for (const auto& el : l) {
        if (m[el] > old) {
            old = m[el];
            solv.first = el;
            solv.second = m[el];
        }
    }

    return solv;
}

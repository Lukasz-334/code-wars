#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

std::deque<int> get_sorted(const std::vector<int>& arr) {
    std::deque<int> q;

    for (const auto& el : arr) {
        if (el == 1) {
            q.push_front(el);
        } else if (el == 2) {
            q.push_back(el);
        }
    }
    for (const auto& el : arr) {
        if (el != 1 && el != 2) {
            q.push_back(el);
        }
    }

    return q;
}

bool test(std::deque<int>& d) {
    if (d.front() == 1) {
        d.pop_front();
        return true;
    }
    return false;
}

int get_in_line(std::vector<int>& arr) {
    std::deque<int> q = get_sorted(arr);
    int solve = 0;
    while (test(q)) {
        for (size_t i = 0; i < q.size() / 2; ++i) {
            if (((q[i] != 1) && (q[i] != 3)) && ((q[q.size() - 1 - i] != 1) && (q[q.size() - 1 - i] != 3))) {
                std::swap(q[i], q[q.size() - 1 - i]);
            }
        }
        ++solve;
    }

    auto it = std::find(q.begin(), q.end(), 0);
    auto distanse = std::distance(q.begin(), it) + 1;

    return distanse + solve;
}

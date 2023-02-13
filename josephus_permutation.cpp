#include <numeric>
#include <queue>
#include <vector>

std::vector<int> josephus(std::vector<int> items, int k) {
    if (k == 1) {
        return items;
    }
    std::vector<int> solv;
    solv.reserve(items.size());
    std::queue<int> q;
    for (auto const& el : items) {
        q.push(el);
    }
    k--;

    while (q.size() > 0) {
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }

        solv.emplace_back(q.front());
        q.pop();
    }

    return solv;
}


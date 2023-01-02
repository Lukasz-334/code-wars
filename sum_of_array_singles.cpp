#include <iostream>
#include <unordered_map>
#include <vector>

int repeats(std::vector<int> v) {
    std::unordered_map<int, int> m;
    int sum = 0;

    for (const int& el : v) {
        m[el]++;
    }

    for (auto [k, v] : m) {
        if (v < 2) {
            sum += k;
        }
    }
    return sum;
}

int main() {
    std::cout << repeats({4, 5, 7, 5, 4, 8});

    return 0;
}

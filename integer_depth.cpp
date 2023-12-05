#include <forward_list>
#include <iostream>
#include <numeric>

unsigned integer_depth(unsigned n) {
    std::forward_list<int> collect(10);
    std::iota(collect.begin(), collect.end(), 0);
    int temp1 = 0;
    int multiplier = 1;
    int solve = 0;

    while (!collect.empty()) {
        solve++;
        temp1 = n * multiplier++;
        while (temp1) {
            collect.remove(temp1 % 10);
            temp1 /= 10;
        }
    }

    return solve;
}

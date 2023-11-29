#include <cmath>
#include <iostream>
#include <vector>

bool fun(int num) {
    int sum = 0;
    int copy_num = num;
    auto size = std::to_string(copy_num).size();

    while (copy_num) {
        sum += std::pow(copy_num % 10, size--);
        copy_num /= 10;
    }

    return sum == num;
}

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
    std::vector<unsigned int> solve;

    for (int i = a; i <= b; i++) {
        if (fun(i)) {
            solve.push_back(i);
        }
    }
    return solve;
}

#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
int constantAndEven(const T& el) {
    int num = static_cast<int>(el);
    if ((el == num) && (num % 2 == 0)) {
        return num;
    }

    return 0;
}

int sum_even_numbers(const std::vector<double>& seq) {
    return std::accumulate(std::begin(seq), std::end(seq), 0, [](auto sum, auto num) {
        return sum + (constantAndEven(num));
    });
}

int main() {
    std::cout << sum_even_numbers({1, 2.1, 3, 4.6, 5, 6.0, 7, 7.9, 9, 10});
}

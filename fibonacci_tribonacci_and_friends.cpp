#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int sumOfTheSequences(const std::vector<int>& numbers, const int numbers_size) {
    return std::accumulate(numbers.rbegin(), numbers.rbegin() + numbers_size, 0);
}

std::vector<int> xbonacci(std::vector<int> signature, int n) {
    int number_of_numbers_to_add = signature.size();

    if (n < number_of_numbers_to_add) {
        std::vector<int> incomplete_value(n);
        std::copy_n(std::begin(signature), n, std::begin(incomplete_value));
        return incomplete_value;
    }

    while (signature.size() < n) {
        signature.push_back(sumOfTheSequences(signature, number_of_numbers_to_add));
    }

    return signature;
}


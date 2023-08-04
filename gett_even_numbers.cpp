#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> get_even_numbers(const std::vector<int>& arr) {
    std::vector<int> solutions;
    std::copy_if(std::begin(arr), std::end(arr), back_inserter(solutions),
                 [](auto el) {
                     return el % 2 == 0;
                 });

    return solutions;
}


#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>

std::string disariumNumber(int number) {
    std::list<int> numbers;
    int pattern = number;

    while (number > 0) {
        numbers.push_front(number % 10);
        number /= 10;
    }

    int exp = 1;
    auto sum = std::accumulate(std::begin(numbers), std::end(numbers), 0, [&exp](auto acc, auto dig) {
        return acc + pow(dig, exp++);
    });

    if (sum == pattern) {
        return "Disarium !!";
    }
    return "Not !!";
}

int main() {
    std::cout << disariumNumber(89);
    return 0;
}

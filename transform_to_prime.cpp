#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

bool primeTest(size_t number) {
    if (number == 1) {
        return true;
    }
    for (int i = 2; i <= std::sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int minimumNumber(const std::vector<int>& numbers) {
    size_t sumNumbers = std::accumulate(numbers.begin(), numbers.end(), 0);
    int missingNumber = 0;
    while (!primeTest(sumNumbers)) {
        sumNumbers++;
        missingNumber++;
    }

    return missingNumber;
}

int main() {
    std::cout << minimumNumber({1, 4});
    return 1;
}

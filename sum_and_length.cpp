#include <cmath>
#include <sstream>
#include <vector>

std::string sumLength(const std::vector<int>& input) {
    int sumOfPositiveNumbers = 0;
    int theNumberOfNegativeNumbers = 0;
    double numberOfZeros = 0;
    std::stringstream solve;

    for (const auto& el : input) {
        if (el > 0) {
            sumOfPositiveNumbers += el;
        } else if (el < 0) {
            theNumberOfNegativeNumbers++;
        } else {
            numberOfZeros++;
        }
    }
    theNumberOfNegativeNumbers += std::ceil(numberOfZeros /= 2.0);
    solve << sumOfPositiveNumbers << ' ' << theNumberOfNegativeNumbers;

    return solve.str();
}

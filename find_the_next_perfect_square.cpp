#include <cmath>
#include <iostream>

long long findNextSquare(long long sqrt) {
    long long value = std::sqrt(sqrt);
    if (value * value == sqrt) {
        ++value;
        return value * value;
    }
    return -1;
}

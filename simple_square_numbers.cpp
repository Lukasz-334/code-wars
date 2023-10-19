#include <cmath>
#include <cstdint>
#include <string>

bool integer(long number) {
    auto result_sqrt = sqrt(number);
    return std::round(result_sqrt) == result_sqrt;
}

long long solve(long n) {
    long long max_sqrt_long = 20537256558025;
    long long multiplier = 2;
    long long perfect_square = 0;

    if (integer(n + 1)) {
        return 1;
    }

    while (perfect_square <= max_sqrt_long) {
        perfect_square = multiplier * multiplier;
        if (integer(n + perfect_square)) {
            return perfect_square;
        }
        multiplier++;
    }

    return -1;
}

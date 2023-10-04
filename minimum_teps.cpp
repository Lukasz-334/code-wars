#include <algorithm>
#include <vector>

int minimumSteps(std::vector<int> numbers, int input) {
    int result = -1;
    int sum = 0;
    int index = 0;
    std::sort(numbers.begin(), numbers.end());

    while (sum <= input) {
        sum += numbers[index++];
        result++;
    }

    return result;
}

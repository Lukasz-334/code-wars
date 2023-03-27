#include <algorithm>
#include <vector>

int maxSequence(const std::vector<int>& arr) {
    int temp_sum = 0;
    int max_sum = 0;
    const int comp = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        temp_sum += arr[i];
        max_sum = std::max(max_sum, temp_sum);
        temp_sum = std::max(comp, temp_sum);
    }
    return max_sum;
}

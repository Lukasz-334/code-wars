#include <vector>

long elementsSum(const std::vector<std::vector<int>>& arr, int d = 0) {
    int number_of_arrays = arr.size();
    int sum_array = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].size() < number_of_arrays) {
            sum_array += d;
        } else {
            sum_array += arr[i][number_of_arrays - 1];
        }

        number_of_arrays--;
    }

    return sum_array;
}

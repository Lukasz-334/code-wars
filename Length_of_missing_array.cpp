#include <algorithm>
#include <iostream>
#include <vector>

template <class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays) {
    if (arrayOfArrays.empty()) {
        return 0;
    }

    float incomplete_sum = 0.0;
    float max_size = 0.0;
    float m_element = arrayOfArrays.size();
    float arr2d_size = arrayOfArrays.size();

    for (auto array : arrayOfArrays) {
        if (array.empty()) {
            return 0;
        }
        incomplete_sum += array.size();
        max_size = std::max(max_size, static_cast<float>(array.size()));
        m_element = std::min(m_element,static_cast<float>(array.size()));
    }

    float full_sum = ((m_element + max_size) / 2.0) * (arr2d_size + 1);
    return full_sum - incomplete_sum;
}

int main() {
    int expected = 5;

    std::vector<std::vector<char>> testInput = {{2, 2}, {1}, {1, 1, 1, 1}};
    int actual = getLengthOfMissingArray(testInput);
    std::cout << actual;
    return 0;
}


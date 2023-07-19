#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> sortString(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        std::string s1 = std::to_string(a);
        std::string s2 = std::to_string(b);
        return s1 + s2 > s2 + s1;
    });

    return nums;
}

void eraseFrontZero(std::string& str) {
    if (std::count(str.begin(), str.end(), '0') == str.size()) {
        str = "0";
    }
}

std::string biggest(const std::vector<int>& nums) {
    std::vector<int> sortVec = sortString(nums);

    std::string result;
    for (auto num : sortVec) {
        result += std::to_string(num);
    }
    eraseFrontZero(result);
    return result;
}

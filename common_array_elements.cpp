#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

void srtVec(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

std::vector<int> setIntersection(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> temp;

    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
                          std::back_inserter(temp));

    return temp;
}

int common(std::vector<int> a, std::vector<int> b, std::vector<int> c) {
    std::vector<int> CommonArray;
    srtVec(a);
    srtVec(b);
    srtVec(c);
    CommonArray = setIntersection(setIntersection(a, b), c);

    return std::accumulate(CommonArray.begin(), CommonArray.end(), 0);
}

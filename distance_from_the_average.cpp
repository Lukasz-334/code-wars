#include <algorithm>  
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

std::vector<double> distancesFromAverage(std::vector<int> input) {
    std::vector<double> solve;
    double vs =
        static_cast<double>(std::accumulate(input.begin(), input.end(), 0)) /
        static_cast<double>(input.size());
    vs = round(vs * 1000) / 1000;
    std::transform(input.begin(), input.end(), std::back_inserter(solve),
                   [&vs](auto el) { return vs - static_cast<double>(el); });

    return solve;
}

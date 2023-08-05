#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>

unsigned int sum_cubes(unsigned int n) {
    std::vector<unsigned int> v(n);
    std::vector<unsigned int>result;
    std::iota(std::begin(v), std::end(v), 1);
    std::transform_inclusive_scan(v.begin(), v.end(),
				std::back_inserter(result), std::plus<int>{}, [](auto el){
                    return el*el*el;
                });
   return result.back();
}

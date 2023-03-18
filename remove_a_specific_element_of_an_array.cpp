#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> select_subarray(const std::vector<int>& arr) {
    std::multimap<double, int> results;
    std::vector<std::pair<int, int>> r;

    double multi = std::accumulate(arr.begin(), arr.end(), 1.0, std::multiplies<>{});
    double plus = std::accumulate(arr.begin(), arr.end(), 0.0);
    double cpplus = 0;
    double cpmulti = 0;

    for (auto it = arr.begin(); it != arr.end(); it++) {
        cpmulti = multi;
        cpplus = plus;
        cpplus -= *it;
        cpmulti /= *it;
        if (cpplus != 0) {
            results.insert({std::abs(cpmulti / cpplus), *it});
        }
    }

    auto temp = results.begin();

    for (auto it = results.begin(); it != results.end(); it++) {
        if (temp->first == it->first) {
            auto position = std::find(arr.begin(), arr.end(), it->second);
            auto dist = std::distance(arr.begin(), position);
            r.push_back({dist, it->second});
            temp = it;
        } else {
            break;
        }
    }

    return r;
}

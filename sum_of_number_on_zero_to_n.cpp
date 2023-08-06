#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class SequenceSum {
    int count;

public:
    SequenceSum(int);
    string showSequence();
    string testNumber(int);
};

std::string SequenceSum::testNumber(int n) {
    if (count < 0) {
        return std::to_string(count) + "<0";
    } else if (count == 0) {
        return "0=0";
    }
    return "";
}

string SequenceSum::showSequence() {
    std::string result = testNumber(count);
    if (result.size()) {
        return result;
    }
    std::vector<int> v(++count);
    std::iota(std::begin(v), std::end(v), 0);
    int sum = 0;
    result = std::accumulate(std::next(v.begin()), v.end(),
                             std::to_string(v.front()),
                             [&sum](auto str, auto num) {
                                 sum += num;
                                 return std::move(str) + '+' + std::to_string(num);
                             });
    result += " = " + std::to_string(sum);
    return result;
}

SequenceSum::SequenceSum(int c) {
    count = c;
}

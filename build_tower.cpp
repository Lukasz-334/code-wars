#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
    std::vector<std::string> solve;
    std::string second("*" + std::string(nFloors - 1, ' '));

    for (int i = 1; i <= nFloors; i++) {
        std::string first(second.rbegin(), second.rend() - 1);
        solve.push_back(first + second);
        second[i] = '*';
    }

    return solve;
}

int main() {
    for (auto c : towerBuilder(5)) {
        std::cout << '"' << c << '"' << std::endl;
    }

    return 0;
}

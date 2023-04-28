#include <iostream>
#include <set>

bool isConsecutive(std::string s) {
    std::set<char> unique;
    std::vector<int> index;

    for (const auto& el : s) {
        unique.insert(el);
    }

    for (auto it = unique.begin(); it != unique.end(); it++) {
        for (int i = 0; i < s.size(); i++) {
            if (*it == s[i]) {
                index.push_back(i);
            }
        }
        for (int i = 0; i < index.size() - 1; i++) {
            std::cout << index[i] << ' ' << index[i + 1] << std::endl;
            if (index[i] - index[i + 1] != -1) {
                return 0;
            }
        }
        index.clear();
    }
    return 1;
}


#include <iostream>
#include <map>
#include <vector>

bool isValidWalk(std::vector<char> walk) {
    std::map<char, int> step_map;

    if (walk.size() != 10) {
        return false;
    }

    for (const auto& el : walk) {
        switch (el) {
        case 'n':
            step_map['n']++;
            break;
        case 's':
            step_map['n']--;
            break;
        case 'e':
            step_map['e']++;
            break;
        case 'w':
            step_map['e']--;
            break;
        }
    }
    return step_map['n'] == 0 && step_map['e'] == 0;
}

int main() {
    std::cout << isValidWalk({'w', 'e', 'n', 's'}) << std::endl;

    return 0;
}

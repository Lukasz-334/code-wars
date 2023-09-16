#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

static const std::vector<std::string> RQUIRED_ELEMENTS{"H", "C", "N", "O", "P", "Ca"};

bool comparison(const char el, const char next_el, const char pattern) {
    return ((el == pattern) && (std::isupper(next_el) || (next_el == '_')));
}

bool findCa(const std::string str) {
    if (str.find("Ca") != std::string::npos) {
        return true;
    }
    return false;
}

bool findElement(const std::string str) {
    size_t number_of_elements = 0;
    for (const auto el : RQUIRED_ELEMENTS) {
        if (el == "Ca") {
            if (findCa(str)) {
                number_of_elements++;
            }
            break;
        }
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] == '_') {
                break;
            }
            if (comparison(str[i], str[i + 1], el[0])) {
                number_of_elements++;
                break;
            }
        }
    }
    if (number_of_elements == RQUIRED_ELEMENTS.size()) {
        return true;
    }
    return false;
}

int findSizePlanet(std::string str) {
    auto it = str.find('_');
    ++it;
    return std::stoi(str.substr(it));
}

std::string bestPlanet(const std::vector<std::string>& solarSystem, int maxSize) {
    std::string bestPl;
    int size_best_planet = 0;

    for (const auto el : solarSystem) {
        if (findElement(el)) {
            auto s = findSizePlanet(el);
            if ((s > size_best_planet) && (s <= maxSize)) {
                size_best_planet = s;
                bestPl = el;
            }
        }
    }

    return bestPl;
}

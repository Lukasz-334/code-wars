#include <iostream>
#include <string>

bool Presence(const std::string& str) {
    std::string cat = "C";
    std::string mouse = "m";
    std::string dog = "D";
    if (str.find(cat) == std::string::npos) {
        return false;
    }
    if (str.find(mouse) == std::string::npos) {
        return false;
    }
    if (str.find(dog) == std::string::npos) {
        return false;
    }
    return true;
}

std::string distance(const std::string& str, const std::string& objA, const std::string& objB) {
    auto itA = str.find(objA);
    auto itB = str.find(objB);
    if (itA > itB) {
        std::swap(itA, itB);
    }
    return str.substr(itA, std::distance(str.begin() + itA, str.begin() + itB) + 1);
}

std::string catMouse(std::string field, unsigned int jump) {
    if (!Presence(field)) {
        return "boring without all three";
    }
    if (distance(field, "C", "m").find("D") == std::string::npos) {
        if (distance(field, "C", "m").size() - 2 <= jump) {
            return "Caught!";
        }

        return "Escaped!";
    }
    if ((distance(field, "C", "m").find("D") != std::string::npos) && (distance(field, "C", "m").size() - 2 <= jump)) {
        return "Protected!";
    }

    return "Escaped!";
}

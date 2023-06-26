#include <iostream>

bool visa(const std::string &n) {
    return (((n.size() == 13) || (n.size() == 16)) && (n.at(0) == '4'));
}

bool mastercard(const std::string &n) {
    return ((n.size() == 16) && (n.at(0) == '5') &&
            ((n.at(1) >= '1') && (n.at(1) <= '5')));
}

bool discover(const std::string &n) {
    return ((n.size() == 16) && (n.at(0) == '6') && (n.at(1) == '0') &&
            (n.at(2) == '1') && (n.at(3) == '1'));
}

bool amex(const std::string &n) {
    return ((n.size() == 15) && (n.at(0) == '3') &&
            ((n.at(1) == '4') || (n.at(1) == '7')));
}

std::string getIssuer(const std::string &number) {
    if (visa(number)) {
        return "VISA";
    }
    if (mastercard(number)) {
        return "Mastercard";
    }
    if (discover(number)) {
        return "Discover";
    }
    if (amex(number)) {
        return "AMEX";
    }

    return "Unknown";
}

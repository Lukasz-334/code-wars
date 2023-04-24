#include <bitset>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string bitLetter(const std::vector<unsigned char> n) {
    std::string bitLetter;
    std::string sign;
    bool capital;
    unsigned char punctuation;
    constexpr uint8_t shift = 97;
    uint32_t letter = 0;

    for (const auto& el : n) {
        std::bitset<8> set(el);
        letter = (set[0] * 1) + (set[1] * 2) + (set[2] * 4) + (set[3] * 8) + (set[4] * 16);
        capital = set[5];
        punctuation = (set[6] * 1) + (set[7] * 2);
        sign = letter + shift;
        if (capital) {
            sign = std::toupper(letter + shift);
        }

        switch (punctuation) {
        case 1:
            sign = " " + sign;
            break;
        case 2:
            sign += ",";
            break;
        case 3:
            sign += ".";
            break;
        }

        bitLetter += sign;
    }

    return bitLetter;
}

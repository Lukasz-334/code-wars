#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

auto countVowels(const std::string& str) -> double {
    return std::count_if(str.begin(), str.end(), [](char c) { return std::toupper(c) == 'A' || std::toupper(c) == 'E' || std::toupper(c) == 'I' || std::toupper(c) == 'O' || std::toupper(c) == 'U'; });
}

bool validateVowelAndSpace(const char sign) {
    return (std::toupper(sign) == 'A' || std::toupper(sign) == 'E' || std::toupper(sign) == 'I' || std::toupper(sign) == 'O' || std::toupper(sign) == 'U' || sign == ' ');
}

std::string reduce_vowels(const std::string& str) {
    std::string result;
    for (size_t i = 1; i < str.size(); i++) {
        if (((std::toupper(str[i]) == std::toupper(str[i - 1])) && (validateVowelAndSpace(str[i - 1])) && validateVowelAndSpace(str[i]))) {
        } else {
            result += str[i - 1];
        }
    }

    if (std::toupper(str[str.size() - 1]) != std::toupper(result[result.size() - 1])) {
        result += str[str.size() - 1];
    }

    return result;
}

float roundUpToTwoDecimalPlaces(float var) {
    float value = static_cast<int>(var * 100 + .5);
    return static_cast<float>(value) / 100.0;
}

float trump_detector(const std::string& trump_speech) {
    auto result = 0.0;
    auto allVowels = countVowels(trump_speech);
    auto resetDuplicateVowels = countVowels(reduce_vowels(trump_speech));
    allVowels = allVowels - resetDuplicateVowels;
    result = allVowels / resetDuplicateVowels;

    return roundUpToTwoDecimalPlaces(result);
}

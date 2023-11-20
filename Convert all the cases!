#include <algorithm>
#include <iostream>

std::string snakeCase(const std::string& str) {
    std::string solve;
    for (auto el : str) {
        if (std::isupper(el)) {
            solve += '_';
            solve += std::tolower(el);
        } else if (el == '-') {
            solve += '_';
        }

        else {
            solve += el;
        }
    }
    return solve;
}

std::string camelCase(const std::string& str) {
    std::string solve;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '-' || str[i] == '_') {
            solve += std::toupper(str[++i]);

        } else {
            solve += str[i];
        }
    }
    return solve;
}

std::string kebabCase(const std::string& str) {
    std::string str_copy = snakeCase(str);
    std::string solve;
    for (auto el : str_copy) {
        if (el == '_') {
            solve += "-";

        } else {
            solve += el;
        }
    }
    return solve;
}

std::string changeCase(const std::string& identifier, const std::string& targetCase) {
    auto test_upper = std::find_if(identifier.begin(), identifier.end(), [](auto el) {
                          return std::isupper(el);
                      }) != identifier.end();
    auto test_snake = identifier.find('_') != std::string::npos;
    auto test_kebab = identifier.find('-') != std::string::npos;
    if (test_upper + test_snake + test_kebab > 1) {
        return "";
    }
    if (targetCase != "snake" && targetCase != "camel" && targetCase != "kebab") {
        return "";
    }

    if (targetCase == "snake") {
        return snakeCase(identifier);
    }
    if (targetCase == "camel") {
        return camelCase(identifier);
    }
    if (targetCase == "kebab") {
        return kebabCase(identifier);
    }

    return "";
}

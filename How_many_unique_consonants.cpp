#include <cctype>
#include <string>
#include <unordered_set>

unsigned int countConsonants(const std::string& str) {
    std::unordered_set<char> solv;
    std::string str2 = str;

    for (char el : str2) {
        el = std::toupper(el);
        if ((el != 'A') && (el != 'E') && (el != 'I') && (el != 'O') && (el != 'U') && (std::isalpha(el))) {
            solv.insert(el);
        }
    }
    return solv.size();
}

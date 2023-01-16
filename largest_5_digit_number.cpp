#include <string>

int largest_five_digits(const std::string& digits) {
    int solv =0;
    for (size_t i = 0; i < digits.size() - 4; i++) {
        std::string str;
        for (size_t j = i; j < i + 5; j++) {
            str += digits[j];
            solv = std::max(solv,std::stoi(str));
            
        }
    }

    return solv;
}

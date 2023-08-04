#include <algorithm>
#include <iostream>
#include <string>

class Kata {
public:
    std::string replaceNth(std::string text, int n, char oldValue, char newValue) {
        if (n < 1) {
            return text;
        }
        std::transform(std::begin(text), std::end(text),
                       std::begin(text), [&, rep = 0](auto sign) mutable {
                           if (sign == oldValue) {
                               rep++;

                               if ((rep % n == 0)) {
                                   return newValue;
                               }
                           }

                           return sign;
                       });

        return text;
    }
};

int main() {
    Kata kata;
    std::string actual = kata.replaceNth("Vader said: No, I am your father!", 1, 'i', 'y');
    std::cout << actual;

    return 0;
}

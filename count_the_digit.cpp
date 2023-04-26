#include <iostream>

class CountDig {
private:
public:
    static int nbDig(int n, int d) {
        size_t pow;
        size_t solve = 0;

        for (size_t i = 0; i <= n; i++) {
            pow = i * i;
            while (pow > 0) {
                if (pow % 10 == d) {
                    solve++;
                }
                pow /= 10;
            }
        }
        if (!d) {
            solve++;
        }
        return solve;
    }
};

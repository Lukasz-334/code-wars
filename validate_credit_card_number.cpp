#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Kata {
public:
    static std::vector<int> divisionOfANumberIntoDigits(long long int num) {
        std::vector<int> c;
        int temp;
        while (num > 0) {
            temp = num % 10;
            c.push_back(temp);
            num /= 10;
        }

        return c;
    }
    static void transformCollect(std::vector<int>& collect) {
        std::reverse(collect.begin(), collect.end());

        bool validate = true;
        int temp;

        if (collect.size() % 2) {
            validate = false;
        }
        for (size_t j = 0; j < collect.size(); j++) {
            if (validate) {
                temp = collect[j] * 2;

                if (temp > 9) {
                    auto pair = divisionOfANumberIntoDigits(temp);
                    temp = pair[0] + pair[1];
                    collect[j] = temp;
                } else {
                    collect[j] = temp;
                }
            }
            validate = !validate;
        }
    }

    static bool validate(long long int n) {
        auto collect = divisionOfANumberIntoDigits(n);
        transformCollect(collect);

        if (std::accumulate(collect.begin(), collect.end(), 0) % 10) {
            return false;
        }
        return true;
    }
};

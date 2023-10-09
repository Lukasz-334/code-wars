#include <algorithm>
#include <iostream>
#include <vector>

std::vector<long long int> wheatFromChaff(std::vector<long long int> values) {
    auto itb = values.begin();
    auto ite = values.rbegin();

    while (true) {
        itb = std::find_if(itb, values.end(), [](auto el) {
            return el > 0;
        });

        ite = std::find_if(ite, values.rend(), [](auto el) {
            return el < 0;
        });

        if (&(*itb) > &(*ite)) {
            break;
        }

        std::swap(*itb, *ite);

        itb++;
        ite++;
    }

    return values;
}

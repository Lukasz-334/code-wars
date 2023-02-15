#include <algorithm>
#include <vector>

class Kata {
public:
    std::vector<int> foldArray(std::vector<int> array, int runs) {
        std::vector<int> solv = std::move(array);

        while (runs--) {
            array = std::move(solv);
            auto itb = array.begin();
            auto ite = array.end();
            ite--;
            while (itb < ite) {
                solv.push_back(*itb + *ite);
                itb++;
                ite--;
            }
            if (array.size() % 2 != 0) {
                solv.push_back(array[array.size() / 2]);
            }
        }

        return solv;
    }
};

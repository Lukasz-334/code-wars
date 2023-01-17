#include <utility>
#include <vector>

using namespace std;

pair<int, int> rowWeights(const vector<int>& weights) {
    pair<int, int> solv;
    bool vave = 1;
    for (const auto& el : weights) {
        if (vave) {
            solv.first += el;
        } else {
            solv.second += el;
        }
        vave = !vave;
    }
    return solv;
}

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

int josephusSurvivor(int n, int k) {
    
    if (k == 1) {
        return n;
    }

    std::list<int> circle(n);
    
    std::iota(circle.begin(), circle.end(), 1);

    int count = k;

    while (circle.size() > 1) {
        for (auto it = circle.begin(); it != circle.end(); it++) {
            count--;
            if (count == 0) {
                it = circle.erase(it);
                it--;
                count = k;
            }
        }
    }

    return circle.front();
}

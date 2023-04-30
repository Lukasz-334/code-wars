#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Operarray {
public:
    using ll = long long;
    static ll gcdi(ll x, ll y) {
        return std::gcd(x, y);
    }
    static ll lcmu(ll a, ll b) {
        return std::lcm(a, b);
    }
    static ll som(ll a, ll b) {
        return a + b;
    }
    static ll maxi(ll a, ll b) {
        return std::max(a, b);
    }
    static ll mini(ll a, ll b) {
        return std::min(a, b);
    }

    static std::vector<ll> operArray(std::function<ll(ll, ll)> fun, std::vector<ll>& arr, ll init) {
        std::vector<ll> vec(arr.size());

        std::inclusive_scan(arr.begin(), arr.end(), vec.begin(), fun, init);

        return vec;
    }
};

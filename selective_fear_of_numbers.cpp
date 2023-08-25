#include <cmath>
#include <functional>
#include <map>
#include <string>

bool monday(int n) {
    return n == 12;
}
bool tuesday(int n) {
    return n > 95;
}
bool wednesday(int n) {
    return n == 34;
}
bool thursday(int n) {
    return n == 0;
}
bool friday(int n) {
    return !(n % 2);
}
bool saturday(int n) {
    return n == 56;
}
bool sunday(int n) {
    return std::abs(n) == 666;
}

bool am_i_afraid(const std::string& day, int num) {
    std::map<std::string, std::function<bool(int)>> fearOfNum;

    fearOfNum["Monday"] = monday;
    fearOfNum["Tuesday"] = tuesday;
    fearOfNum["Wednesday"] = wednesday;
    fearOfNum["Thursday"] = thursday;
    fearOfNum["Friday"] = friday;
    fearOfNum["Saturday"] = saturday;
    fearOfNum["Sunday"] = sunday;

    return fearOfNum[day](num);
}


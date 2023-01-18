#include <string>
#include <vector>

std::string get_order(const std::string& order) {
    std::vector<std::string> pattern{{"burger"}, {"fries"}, {"chicken"}, {"pizza"}, {"sandwich"}, {"onionrings"}, {"milkshake"}, {"coke"}};
    std::string solv;
    std::string temp;
    std::string::size_type pos = -1;
    for (size_t i = 0; i < pattern.size(); i++) {
        while (true) {
            pos = order.find(pattern[i], pos + 1);

            if (pos == std::string::npos) {
                break;
            }
            temp = pattern[i];
            temp.front() = std::toupper(temp.front());
            solv += temp + ' ';
        }
    }
    solv.pop_back();
    return solv;
}

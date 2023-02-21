#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

struct VersionException : public std::logic_error {
    VersionException(const std::string& msg)
        : std::logic_error(msg){};
};

class VersionManager {
public:
    explicit VersionManager(){};
    explicit VersionManager(VersionManager&);
    VersionManager& operator=(const VersionManager&);
    explicit VersionManager(VersionManager&&);
    VersionManager& operator=(VersionManager&&);
    explicit VersionManager(const std::string&);

    VersionManager& major();
    VersionManager& minor();
    VersionManager& patch();
    VersionManager& rollback();
    std::string release();
    void transform(const std::string&);
    void assignment(std::vector<int>&&);

private:
    struct mmp {
        int major_ = 0;
        int minor_ = 0;
        int patch_ = 1;
    };
    mmp newData_{0, 0, 1};
    std::vector<mmp> data{newData_};
};
void VersionManager::assignment(std::vector<int>&& vec) {
    
    if (vec.size() == 1) {
        newData_.major_ = vec.at(0);
        newData_.patch_ = 0;

    } else if (vec.size() == 2) {
        newData_.major_ = vec.at(0);
        newData_.minor_ = vec.at(1);
        newData_.patch_ = 0;
    } else {
        newData_.major_ = vec.at(0);
        newData_.minor_ = vec.at(1);
        newData_.patch_ = vec.at(2);
    }

    data.push_back({newData_.major_, newData_.minor_, newData_.patch_});
}
void VersionManager::transform(const std::string& st) {
    auto it = st.begin();
    std::vector<int> v;
    std::string tmp;
    while (it != st.end()) {
        if (std::isdigit(*it)) {
            tmp += *it;
            auto it2 = st.end();
            std::advance(it2, -1);
            if (it == it2) {
                v.push_back(std::stoi(tmp));
            }
        } else if (*it == '.') {
            v.push_back(std::stoi(tmp));
            tmp.clear();
        }
        if ((v.size() < 3) && (std::isdigit(*it) == 0) && (*it != '.')) {
            throw VersionException("Error occured while parsing version!");
        } else if (v.size() == 3) {
            break;
        }
        it++;
    }

    assignment(std::move(v));
}

std::string VersionManager::release() {
    std::string str;
    str = std::to_string(data.back().major_) + "." + std::to_string(data.back().minor_) + "." + std::to_string(data.back().patch_);
    std::cout << str << std::endl;
    return str;
}

VersionManager::VersionManager(VersionManager& obj) {
    std::cout << "copy constructor" << std::endl;
    data = obj.data;
}

VersionManager& VersionManager::operator=(const VersionManager& obj) {
    std::cout << "copy assigment operator " << std::endl;
    data = obj.data;
    return *this;
}

VersionManager::VersionManager(VersionManager&& obj) {
    std::cout << "move constructor" << std::endl;
    data = std::move(obj.data);
}

VersionManager& VersionManager::operator=(VersionManager&& obj) {
    std::cout << "move assigment operator" << std::endl;
    data = std::move(obj.data);
    return *this;
}

VersionManager::VersionManager(const std::string& str) {
    if ((str.size() > 0)) {
        transform(str);
    }
};

VersionManager& VersionManager::major() {
    newData_ = data.back();
    newData_.major_++;
    newData_.minor_ = 0;
    newData_.patch_ = 0;
    data.push_back(newData_);

    return *this;
}

VersionManager& VersionManager::minor() {
    newData_ = data.back();
    newData_.minor_++;
    newData_.patch_ = 0;
    data.push_back(newData_);
    return *this;
}

VersionManager& VersionManager::patch() {
    newData_ = data.back();
    newData_.patch_++;
    data.push_back(newData_);
    return *this;
}

VersionManager& VersionManager::rollback() {
    data.pop_back();
    if (data.empty()) {
        throw VersionException("Cannot rollback!");
    }
    return *this;
}

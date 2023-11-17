#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> dup(std::vector<std::string> arr)
{

    std::vector<std::string> solve;

    for (auto el : arr)
    {
        std::string pattern;
        std::unique_copy(el.begin(), el.end(), std::back_inserter(pattern),
                         [](char c1, char c2)
                         { return c1 == c2; });
        solve.push_back(pattern);
    }
    return solve;
}


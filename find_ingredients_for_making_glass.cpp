#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

std::string creStr(double num) {
    std::stringstream str;

    str << std::fixed << std::setprecision(2) << num;
    return str.str();
}

std::string createIngredients(double sand = 0, double seaweed = 0,
                              double chalk = 0) {
    if ((sand < 0) || (seaweed < 0) || (chalk < 0)) {
        return "";
    }

    std::string solve;

    double Sand = 60.0;
    double SeaWeed = 180.0;
    double Chalk = 5.0;
    double newProcent = 1;

    if (sand != 0) {
        newProcent = sand / Sand;
    } else if (seaweed != 0) {
        newProcent = seaweed / SeaWeed;
    } else if (chalk != 0) {
        newProcent = chalk / Chalk;
    }

    if (sand == 0) {
        sand = 60.0 * newProcent;
    }
    if (seaweed == 0) {
        seaweed = 180.0 * newProcent;
    }
    if (chalk == 0) {
        chalk = 5.0 * newProcent;
    }

    solve =
        '[' + creStr(sand) + ';' + creStr(seaweed) + ';' + creStr(chalk) + ']';

    return solve;
}

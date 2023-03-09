#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

class Team {
protected:
    std::string teamName;
    int goalsScored = 0;
    int goalsConceded = 0;
    int numberOfMatches = 0;
    int matchesWon = 0;
    int matchDrawn = 0;
    int matchesLost = 0;
    int point = 0;
    int differenceOfGoals = 0;

public:
    Team() = default;
    Team(std::string t, int gs = 0, int gc = 0)
        : teamName{t} {
        if (gs >= 0) {
            if (gs > gc) {
                point += 3;
                matchesWon++;
            } else if (gs == gc) {
                point++;
                matchDrawn++;
            } else {
                matchesLost++;
            }

            goalsScored += gs;
            goalsConceded += gc;
            differenceOfGoals = goalsScored - goalsConceded;
            numberOfMatches++;
        }
    }

    std::string tName(std::string str1) const {
        std::transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        return str1;
    }

    bool operator<(const Team& rhs) const {
        if (std::tie(point, differenceOfGoals, goalsScored) > std::tie(rhs.point, rhs.differenceOfGoals, rhs.goalsScored)) {
            return true;
        }
        if (std::tie(point, differenceOfGoals, goalsScored) < std::tie(rhs.point, rhs.differenceOfGoals, rhs.goalsScored)) {
            return false;
        }

        return tName(teamName) < tName(rhs.teamName);
    }

    std::string getTeamName() const {
        return teamName;
    }
    int getGoalsScored() const {
        return goalsScored;
    };
    int getGoalsConceded() const {
        return goalsConceded;
    };
    int getNumberOfMatches() const {
        return numberOfMatches;
    };
    int getMatchesWon() const {
        return matchesWon;
    };
    int getMatchDrawn() const {
        return matchDrawn;
    };
    int getMatchesLost() const {
        return matchesLost;
    };
    int getPoint() const {
        return point;
    };
    int getDifferenceOfGoals() const {
        return differenceOfGoals;
    }
};

class Data {
protected:
    std::string firstTeam;
    std::string secondTeam;
    int firstTeamPoint;
    int secondTeamPoint;
    const std::string str;

public:
    Data() = default;
    Data(std::string&& data)
        : str{std::move(data)} {
        dataAssignment();
    }

    void validate(int& num, std::string& s) {
        if (std::isdigit(s.at(0))) {
            num = std::stoi(s);
        } else {
            num = -1;
        }
    }

    void dataAssignment() {
        std::string temp;
        int colonPosition = str.find(':');
        int dashPosition = str.rfind('-');
        temp = str.substr(0, colonPosition);
        validate(firstTeamPoint, temp);
        temp = str.substr(colonPosition + 1, str.find(' ') - colonPosition - 1);
        validate(secondTeamPoint, temp);
        firstTeam = str.substr(str.find(' ') + 1, dashPosition - str.find(' ') - 2);
        secondTeam = str.substr(dashPosition + 2);
    }
    std::string getFirstTeam() const {
        return firstTeam;
    }
    std::string getSecondTeam() const {
        return secondTeam;
    }
    int getFirstTeamPoint() const {
        return firstTeamPoint;
    }
    int getSecondTeamPoint() const {
        return secondTeamPoint;
    }
};

class Bundesliga : public Team,
                   public Data {
private:
    std::vector<Team> collect;
    std::vector<int> position;

public:
    std::string table(std::vector<std::string> results) {
        position.resize(18, 1);
        for (std::string el : results) {
            Data data(std::move(el));
            Team team1(data.getFirstTeam(), data.getFirstTeamPoint(), data.getSecondTeamPoint());
            collect.push_back(team1);
            Team team2(data.getSecondTeam(), data.getSecondTeamPoint(), data.getFirstTeamPoint());
            collect.push_back(team2);
        }

        std::sort(collect.begin(), collect.end());
        teamPosition();
        return print();
    }

    std::string print() {
        std::string str;
        std::stringstream ss;
        int current = 0;

        for (const Team& team : collect) {
            ss << std::right << std::setw(2) << position[current] << '.' << " " << std::left << std::setw(30) << team.getTeamName()

               << team.getNumberOfMatches()
               << "  " << team.getMatchesWon()
               << "  " << team.getMatchDrawn()
               << "  " << team.getMatchesLost()
               << "  " << team.getGoalsScored()
               << ":" << team.getGoalsConceded()
               << "  " << team.getPoint()
               << std::endl;
            current++;
        }
        std::string solv = ss.str();
        solv.pop_back();
        return solv;
    }

    void teamPosition() {
        std::iota(position.begin(), position.end(), 1);
        for (size_t i = 0; i < collect.size() - 1; i++) {
            if ((collect[i].getPoint() == collect[i + 1].getPoint()) && (collect[i].getDifferenceOfGoals() == collect[i + 1].getDifferenceOfGoals()) && (collect[i].getGoalsScored() == collect[i + 1].getGoalsScored())) {
                position[i + 1] = position[i];
            }
        }
    }
};


#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <vector>


class Scenario
{
public:
    Scenario();



    bool isMain() const;
    void setIsMain(bool newIsMain);
    std::string name() const;
    void setName(const std::string &newName);
    std::vector<std::string> steps() const;
    void setSteps(const std::vector<std::string> &newSteps);
    void addStep(const std::string& step);

private:
    bool isMain_;
    std::string name_;
    std::vector<std::string> steps_;
};

#endif // SCENARIO_H

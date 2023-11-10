
#include "scenario.h"

Scenario::Scenario()
{

}

bool Scenario::isMain() const
{
    return isMain_;
}

void Scenario::setIsMain(bool newIsMain)
{
    isMain_ = newIsMain;
}

std::string Scenario::name() const
{
    return isMain_ ? "Main scenario- " + name_ : "Alternative scenario- " + name_;
}

void Scenario::setName(const std::string &newName)
{
    name_ = newName;
}

std::vector<std::string> Scenario::steps() const
{
    return steps_;
}

void Scenario::setSteps(const std::vector<std::string> &newSteps)
{
    steps_ = newSteps;
}

void Scenario::addStep(const std::string &step)
{
    steps_.push_back(step);
}

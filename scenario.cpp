
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

QString Scenario::name() const
{
    return name_;
}

void Scenario::setName(const QString &newName)
{
    name_ = newName;
}

QStringList Scenario::steps() const
{
    return steps_;
}

void Scenario::setSteps(const QStringList &newSteps)
{
    steps_ = newSteps;
}

void Scenario::addStep(const QString &step)
{
    steps_.push_back(step);
}

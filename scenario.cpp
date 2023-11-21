
#include "scenario.h"

Scenario::Scenario() { }

Scenario::Scenario(const QString &name) :
    name_{name} { }

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

void Scenario::swapSteps(qsizetype i, qsizetype j)
{
    steps_.swapItemsAt(i, j);
}

void Scenario::removeStep(int index)
{
    steps_.remove(index);
}


#include "technique.hpp"

Technique::Technique() :
    name_{} { }

Technique::Technique(const QString& name) :
    name_{name} { }

void Technique::setName(const QString &name)
{
    name_ = name;
}

const QString Technique::getName()
{
    return name_;
}



#include "technique.hpp"

Technique::Technique() :
    name_{} { }

Technique::Technique(const std::string& name) :
    name_{name} { }

const std::string Technique::getName()
{
    return name_;
}


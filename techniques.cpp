
#include "techniques.hpp"

QVector<std::shared_ptr<Technique>> Techniques::techniques_;

Techniques::Techniques()
{

}

void Techniques::addTechnique(std::shared_ptr<Technique> technique)
{
    techniques_.push_back(technique);
}

void Techniques::removeTechnique(qsizetype index)
{
    techniques_.remove(index);
}


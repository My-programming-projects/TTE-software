
#ifndef TECHNIQUES_HPP
#define TECHNIQUES_HPP

#include <memory>
#include <QVector>

#include "technique.hpp"


class Techniques
{
public:
    Techniques();

    static void addTechnique(std::shared_ptr<Technique> technique);
    static void removeTechnique(qsizetype index);

private:
    static QVector<std::shared_ptr<Technique>> techniques_;
};

#endif // TECHNIQUES_HPP


#include "usecase.hpp"

UseCase::UseCase() { }

QString UseCase::id() const
{
    return id_;
}

void UseCase::setId(const QString &newId)
{
    id_ = newId;
}

QString UseCase::title() const
{
    return title_;
}

void UseCase::setTitle(const QString &newTitle)
{
    title_ = newTitle;
}

QString UseCase::purpose() const
{
    return purpose_;
}

void UseCase::setPurpose(const QString &newPurpose)
{
    purpose_ = newPurpose;
}

QString UseCase::actors() const
{
    return actors_;
}

void UseCase::setActors(const QString &newActors)
{
    actors_ = newActors;
}

QStringList UseCase::preconditions() const
{
    return preconditions_;
}

void UseCase::setPreconditions(const QStringList &newPreconditions)
{
    preconditions_ = newPreconditions;
}

void UseCase::addPrecondition(const QString &precondition)
{
    preconditions_.push_back(precondition);
}

void UseCase::swapPreconditions(qsizetype i, qsizetype j)
{
    preconditions_.swapItemsAt(i, j);
}

void UseCase::removePrecondition(int index)
{
    preconditions_.remove(index);
}

QVector<Scenario> UseCase::scenarios() const
{
    return scenarios_;
}

void UseCase::setScenarios(const QVector<Scenario> &newScenarios)
{
    scenarios_ = newScenarios;
}

void UseCase::addScenario(Scenario scenario)
{
    scenarios_.push_back(scenario);
}

void UseCase::swapScenarios(qsizetype i, qsizetype j)
{
    scenarios_.swapItemsAt(i, j);
}

void UseCase::removeScenario(int index)
{
    scenarios_.remove(index);
}


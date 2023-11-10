
#include "usecase.hpp"

UseCase::UseCase()
{

}

std::string UseCase::id() const
{
    return id_;
}

void UseCase::setId(const std::string &newId)
{
    id_ = newId;
}

std::string UseCase::title() const
{
    return title_;
}

void UseCase::setTitle(const std::string &newTitle)
{
    title_ = newTitle;
}

std::string UseCase::purpose() const
{
    return purpose_;
}

void UseCase::setPurpose(const std::string &newPurpose)
{
    purpose_ = newPurpose;
}

std::string UseCase::actors() const
{
    return actors_;
}

void UseCase::setActors(const std::string &newActors)
{
    actors_ = newActors;
}

std::vector<std::string> UseCase::preconditions() const
{
    return preconditions_;
}

void UseCase::setPreconditions(const std::vector<std::string> &newPreconditions)
{
    preconditions_ = newPreconditions;
}

void UseCase::addPrecondition(const std::string &precondition)
{
    preconditions_.push_back(precondition);
}

std::vector<Scenario> UseCase::scenarios() const
{
    return scenarios_;
}

void UseCase::setScenarios(const std::vector<Scenario> &newScenarios)
{
    scenarios_ = newScenarios;
}

void UseCase::addScenario(Scenario scenario)
{
    bool isMain = scenarios_.empty() ? true : false;

    scenario.setIsMain(isMain);

    scenarios_.push_back(scenario);
}


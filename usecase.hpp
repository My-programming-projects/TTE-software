
#ifndef USECASE_HPP
#define USECASE_HPP

#include <vector>

#include "technique.hpp"
#include "scenario.h"

class UseCase : public Technique
{
public:
    UseCase();



    std::string id() const;
    void setId(const std::string &newId);
    std::string title() const;
    void setTitle(const std::string &newTitle);
    std::string purpose() const;
    void setPurpose(const std::string &newPurpose);
    std::string actors() const;
    void setActors(const std::string &newActors);
    std::vector<std::string> preconditions() const;
    void setPreconditions(const std::vector<std::string> &newPreconditions);
    void addPrecondition(const std::string& precondition);
    std::vector<Scenario> scenarios() const;
    void setScenarios(const std::vector<Scenario> &newScenarios);
    void addScenario(Scenario scenario);

private:
    std::string id_;
    std::string title_;
    std::string purpose_;
    std::string actors_;
    std::vector<std::string> preconditions_;
    std::vector<Scenario> scenarios_;
};

#endif // USECASE_HPP

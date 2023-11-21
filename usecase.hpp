
#ifndef USECASE_HPP
#define USECASE_HPP

#include <QVector>

#include "technique.hpp"
#include "scenario.h"

class UseCase : public Technique
{
public:
    UseCase();

    QString id() const;
    void setId(const QString &newId);
    QString title() const;
    void setTitle(const QString &newTitle);
    QString purpose() const;
    void setPurpose(const QString &newPurpose);
    QString actors() const;
    void setActors(const QString &newActors);
    QStringList preconditions() const;
    void setPreconditions(const QStringList &newPreconditions);
    void addPrecondition(const QString& precondition);
    void removePrecondition(int index);
    QVector<Scenario> scenarios() const;
    void setScenarios(const QVector<Scenario> &newScenarios);
    void addScenario(Scenario scenario);

private:
    QString id_;
    QString title_;
    QString purpose_;
    QString actors_;
    QStringList preconditions_;
    QVector<Scenario> scenarios_;
};

#endif // USECASE_HPP

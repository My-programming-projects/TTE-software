
#ifndef SCENARIO_H
#define SCENARIO_H

#include <QVector>


class Scenario
{
public:
    Scenario();
    Scenario(const QString &name);

    bool isMain() const;
    void setIsMain(bool newIsMain);
    QString name() const;
    void setName(const QString &newName);
    QStringList steps() const;
    void setSteps(const QStringList &newSteps);
    void addStep(const QString& step);
    void removeStep(int index);

private:
    bool isMain_;
    QString name_;
    QStringList steps_;
};

#endif // SCENARIO_H

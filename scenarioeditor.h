#ifndef SCENARIOEDITOR_H
#define SCENARIOEDITOR_H

#include <QDialog>

#include "step.hpp"

namespace Ui {
class ScenarioEditor;
}

class ScenarioEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ScenarioEditor(QWidget *parent = nullptr);
    ~ScenarioEditor();

    QString getScenarioTitle() const;

private slots:
    void addStep();
    void removeStep();

private:
    void setConnections();

    Ui::ScenarioEditor *ui;
};

#endif // SCENARIOEDITOR_H

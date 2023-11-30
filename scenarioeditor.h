#ifndef SCENARIOEDITOR_H
#define SCENARIOEDITOR_H

#include <QDialog>
#include <QTimer>

#include "scenario.h"
#include "step.hpp"
#include "utils.hpp"
#include "stepsrelation.hpp"

namespace Ui {
class ScenarioEditor;
}

class ScenarioEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ScenarioEditor(QWidget *parent = nullptr);
    ~ScenarioEditor();

    void setFirstScenarioSteps(const QStringList& items);
    QString getScenarioTitle() const;
    Scenario scenario() const noexcept;

private slots:
    void addStep();
    void removeStep();
    void moveStepUp();
    void moveStepDown();
    void updateOkButtonState();
    void updateButtonsState();
    void updateStepUpDownButtonsState();
    void openStepsRelation();
    void save();


private:
    void setButtonStates();
    void setConnections();

    Ui::ScenarioEditor *ui;

    QTimer timer_;

    Scenario scenario_;
    QStringList firstScenarioSteps_;
};

#endif // SCENARIOEDITOR_H

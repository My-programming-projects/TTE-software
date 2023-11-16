#ifndef SCENARIOEDITOR_H
#define SCENARIOEDITOR_H

#include <QDialog>
#include <QTimer>

#include "step.hpp"
#include "utils.hpp"

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
    void moveStepUp();
    void moveStepDown();
    void updateOkButtonState();
    void updateButtonsState();
    void updateStepUpDownButtonsState();

private:
    void setButtonStates();
    void setConnections();

    Ui::ScenarioEditor *ui;

    QTimer timer_;
};

#endif // SCENARIOEDITOR_H

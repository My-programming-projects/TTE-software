#ifndef USECASEEDITOR_H
#define USECASEEDITOR_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QVector>
#include <QPair>
#include <QTimer>

#include "scenarioeditor.h"
#include "usecase.hpp"
#include "precondition.hpp"
#include "utils.hpp"

namespace Ui {
class UseCaseEditor;
}

class UseCaseEditor : public QDialog
{
    Q_OBJECT

public:
    explicit UseCaseEditor(QWidget *parent = nullptr);
    ~UseCaseEditor();

    UseCase useCase() const noexcept;

private slots:
    void addScenario();
    void removeScenario();
    void addPrecondition();
    void removePrecondition();
    void updateOKButtonState();
    void updateButtonsState();
    void updatePrecUpDownButtonsState();
    void updateScenarioUpDownButtonsState();
    void movePrecUp();
    void movePrecDown();
    void moveScenarioUp();
    void moveScenarioDown();

    void save();

private:
    void setButtonsState();
    void setConnections();

    QVector<QPair<QLabel, QPushButton>> scenariosDesc_;

    Ui::UseCaseEditor *ui;

    QTimer timer_;

    UseCase useCase_;
    QVector<Scenario> scenarios_;
};

#endif // USECASEEDITOR_H

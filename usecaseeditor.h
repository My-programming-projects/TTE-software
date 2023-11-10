#ifndef USECASEEDITOR_H
#define USECASEEDITOR_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QPair>
#include <QTimer>

#include "scenarioeditor.h"
#include "precondition.hpp"

namespace Ui {
class UseCaseEditor;
}

class UseCaseEditor : public QDialog
{
    Q_OBJECT

public:
    explicit UseCaseEditor(QWidget *parent = nullptr);
    ~UseCaseEditor();

private slots:
    void addScenario();
    void removeScenario();
    void addPrecondition();
    void removePrecondition();
    void updateButtonsState();

private:
    void setConnections();

    QVector<QPair<QLabel, QPushButton>> scenariosDesc_;

    Ui::UseCaseEditor *ui;

    QTimer timer_;
};

#endif // USECASEEDITOR_H

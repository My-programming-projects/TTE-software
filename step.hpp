#ifndef STEP_HPP
#define STEP_HPP

#include <QDialog>
#include <QPushButton>

#include "utils.hpp"

namespace Ui {
class Step;
}

class Step : public QDialog
{
    Q_OBJECT

public:
    explicit Step(QWidget *parent = nullptr);
    ~Step();

    QString getStepName() const;

private slots:
    void updateOKButtonState();

private:
    void setButtonState();
    void setConnections();

    Ui::Step *ui;
};

#endif // STEP_HPP

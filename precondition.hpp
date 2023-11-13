#ifndef PRECONDITION_HPP
#define PRECONDITION_HPP

#include <QDialog>
#include <QPushButton>
#include <QTimer>

#include "utils.hpp"


namespace Ui {
class Precondition;
}

class Precondition : public QDialog
{
    Q_OBJECT

public:
    explicit Precondition(QWidget *parent = nullptr);
    ~Precondition();

    QString getPreconditionName();

private slots:
    void updateOKButtonState();

private:
    void setButtonState();
    void setConnections();

    Ui::Precondition *ui;
};

#endif // PRECONDITION_HPP

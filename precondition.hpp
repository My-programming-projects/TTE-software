#ifndef PRECONDITION_HPP
#define PRECONDITION_HPP

#include <QDialog>

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

private:
    Ui::Precondition *ui;
};

#endif // PRECONDITION_HPP

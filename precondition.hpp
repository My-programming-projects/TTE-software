#ifndef PRECONDITION_HPP
#define PRECONDITION_HPP

#include <QDialog>
#include <QPushButton>
#include <QTimer>

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
    void updateButtonState();

private:
    void setConnections();

    Ui::Precondition *ui;

    QTimer timer_;
};

#endif // PRECONDITION_HPP

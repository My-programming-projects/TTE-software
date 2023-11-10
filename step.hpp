#ifndef STEP_HPP
#define STEP_HPP

#include <QDialog>

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

private:
    Ui::Step *ui;
};

#endif // STEP_HPP

#ifndef STEPSRELATION_HPP
#define STEPSRELATION_HPP

#include <QDialog>
#include <QListWidget>

namespace Ui {
class StepsRelation;
}

class StepsRelation : public QDialog
{
    Q_OBJECT

public:
    explicit StepsRelation(QWidget *parent = nullptr);
    ~StepsRelation();

    void addSteps(QStringList items);

private:
    Ui::StepsRelation *ui;
};

#endif // STEPSRELATION_HPP

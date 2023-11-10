#include "step.hpp"
#include "ui_step.h"

Step::Step(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Step)
{
    ui->setupUi(this);
}

Step::~Step()
{
    delete ui;
}

QString Step::getStepName() const
{
    return ui->stepLineEdit->text();
}

#include "stepsrelation.hpp"
#include "ui_stepsrelation.h"

StepsRelation::StepsRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StepsRelation)
{
    ui->setupUi(this);
}

StepsRelation::~StepsRelation()
{
    delete ui;
}

void StepsRelation::addSteps(QStringList items)
{
    ui->stepsListWidget->addItems(items);
}

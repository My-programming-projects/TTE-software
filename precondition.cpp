#include "precondition.hpp"
#include "ui_precondition.h"

Precondition::Precondition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Precondition)
{
    ui->setupUi(this);
}

Precondition::~Precondition()
{
    delete ui;
}

QString Precondition::getPreconditionName()
{
    return ui->precNameLineEdit->text();
}

#include "precondition.hpp"
#include "ui_precondition.h"

Precondition::Precondition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Precondition)
{
    ui->setupUi(this);

    timer_.setInterval(1000);
    timer_.start();

    setConnections();
}

Precondition::~Precondition()
{
    delete ui;
}

QString Precondition::getPreconditionName()
{
    return ui->precNameLineEdit->text();
}

void Precondition::setConnections()
{
    connect(&timer_, &QTimer::timeout, this, &Precondition::updateButtonState);
}

void Precondition::updateButtonState()
{
    bool enabled = ui->precNameLineEdit->text().isEmpty() ? false : true;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

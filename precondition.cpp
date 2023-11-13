#include "precondition.hpp"
#include "ui_precondition.h"

Precondition::Precondition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Precondition)
{
    ui->setupUi(this);

    setButtonState();
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

void Precondition::setButtonState()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void Precondition::setConnections()
{
    connect(ui->precNameLineEdit, &QLineEdit::textChanged, this, &Precondition::updateOKButtonState);
}

void Precondition::updateOKButtonState()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isLineEditNotEmpty(ui->precNameLineEdit));
}

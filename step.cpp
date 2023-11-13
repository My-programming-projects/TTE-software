#include "step.hpp"
#include "ui_step.h"

Step::Step(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Step)
{
    ui->setupUi(this);

    setButtonState();
    setConnections();
}

void Step::setButtonState()
{
     ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void Step::setConnections()
{
     connect(ui->stepLineEdit, &QLineEdit::textChanged, this, &Step::updateOKButtonState);
}

Step::~Step()
{
    delete ui;
}

QString Step::getStepName() const
{
    return ui->stepLineEdit->text();
}

void Step::updateOKButtonState()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isLineEditNotEmpty(ui->stepLineEdit));
}

#include "preconditionseditor.hpp"
#include "ui_preconditionseditor.h"

PreconditionsEditor::PreconditionsEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreconditionsEditor)
{
    ui->setupUi(this);
}

PreconditionsEditor::~PreconditionsEditor()
{
    delete ui;
}

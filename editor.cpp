#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

    setConnections();
}

Editor::~Editor()
{
    delete ui;
}

void Editor::setConnections()
{
    connect(ui->useCaseButton, &QPushButton::clicked, this, &Editor::addUseCase);
}

void Editor::addUseCase()
{
    UseCaseEditor* useCaseEditor = new UseCaseEditor(this);

    useCaseEditor->setModal(true);

    if(useCaseEditor->exec() == QDialog::Accepted)
    {

    }
}

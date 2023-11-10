
#include "tte_app.h"
#include "ui_tte_app.h"


TTE_App::TTE_App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TTE_App)
{
    ui->setupUi(this);

    setConnections();
}

TTE_App::~TTE_App()
{
    delete ui;
}

void TTE_App::setConnections()
{
    connect(ui->actionNew, &QAction::triggered, this, &TTE_App::openEditor);
}

void TTE_App::openEditor()
{
    Editor* editor = new Editor(this);

    editor->setModal(true);

    if(editor->exec() == QDialog::Accepted)
    {

    }
}

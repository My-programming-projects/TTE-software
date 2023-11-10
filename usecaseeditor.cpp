#include "usecaseeditor.h"
#include "ui_usecaseeditor.h"

UseCaseEditor::UseCaseEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseEditor)
{
    ui->setupUi(this);

    setConnections();
}

UseCaseEditor::~UseCaseEditor()
{
    delete ui;
}

void UseCaseEditor::setConnections()
{
    connect(ui->addScenarioButton, &QPushButton::clicked, this, &UseCaseEditor::addScenario);
    connect(ui->removeScenarioButton, &QPushButton::clicked, this, &UseCaseEditor::removeScenario);
    connect(ui->addPrecButton, &QPushButton::clicked, this, &UseCaseEditor::addPrecondition);
    connect(ui->removePrecButton, &QPushButton::clicked, this, &UseCaseEditor::removePrecondition);
}

void UseCaseEditor::addScenario()
{
    ScenarioEditor* scenarioEditor = new ScenarioEditor(this);

    scenarioEditor->setModal(true);

    if(scenarioEditor->exec() == QDialog::Accepted)
    {
        ui->scenarioListWidget->addItem(scenarioEditor->getScenarioTitle());
    }
}

void UseCaseEditor::removeScenario()
{
    qDeleteAll(ui->scenarioListWidget->selectedItems());
}

void UseCaseEditor::addPrecondition()
{
    Precondition* precondition = new Precondition(this);

    precondition->setModal(true);

    if(precondition->exec() == QDialog::Accepted)
    {
        ui->precListWidget->addItem(precondition->getPreconditionName());
    }
}

void UseCaseEditor::removePrecondition()
{
    qDeleteAll(ui->precListWidget->selectedItems());
}

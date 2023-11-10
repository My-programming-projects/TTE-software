#include "usecaseeditor.h"
#include "ui_usecaseeditor.h"

UseCaseEditor::UseCaseEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseEditor)
{
    ui->setupUi(this);

    timer_.setInterval(1000);
    timer_.start();

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
    connect(&timer_, &QTimer::timeout, this, &UseCaseEditor::updateButtonsState);
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

void UseCaseEditor::updateButtonsState()
{
    bool removePrecButtonEnabled = ui->precListWidget->count() == 0 || ui->precListWidget->selectedItems().empty() ? false : true;
    bool scenarioListButtonsEnabled = ui->scenarioListWidget->count() == 0 || ui->scenarioListWidget->selectedItems().empty() ? false : true;

    ui->removePrecButton->setEnabled(removePrecButtonEnabled);
    ui->removeScenarioButton->setEnabled(scenarioListButtonsEnabled);
    ui->openScenarioButton->setEnabled(scenarioListButtonsEnabled);
}

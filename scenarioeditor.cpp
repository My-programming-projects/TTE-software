#include "scenarioeditor.h"
#include "ui_scenarioeditor.h"

ScenarioEditor::ScenarioEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScenarioEditor)
{
    ui->setupUi(this);

    timer_.setInterval(1000);
    timer_.start();

    setConnections();
}

ScenarioEditor::~ScenarioEditor()
{
    delete ui;
}

void ScenarioEditor::setConnections()
{
    connect(ui->addButton, &QPushButton::clicked, this, &ScenarioEditor::addStep);
    connect(ui->removeButton, &QPushButton::clicked, this, &ScenarioEditor::removeStep);
    connect(&timer_, &QTimer::timeout, this, &ScenarioEditor::updateButtonsState);
}

void ScenarioEditor::addStep()
{
    Step* step = new Step(this);

    step->setModal(true);

    if(step->exec() == QDialog::Accepted)
    {
        ui->stepsListWidget->addItem(step->getStepName());
    }
}

void ScenarioEditor::removeStep()
{
    qDeleteAll(ui->stepsListWidget->selectedItems());
}

QString ScenarioEditor::getScenarioTitle() const
{
    return ui->titleLineEdit->text();
}

void ScenarioEditor::updateButtonsState()
{
    bool removeStepButtonEnabled = ui->stepsListWidget->count() == 0 || ui->stepsListWidget->selectedItems().empty() ? false : true;

    ui->removeButton->setEnabled(removeStepButtonEnabled);
}

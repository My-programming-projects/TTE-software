#include "scenarioeditor.h"
#include "ui_scenarioeditor.h"

ScenarioEditor::ScenarioEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScenarioEditor)
{
    ui->setupUi(this);

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

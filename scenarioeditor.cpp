#include "scenarioeditor.h"
#include "ui_scenarioeditor.h"

ScenarioEditor::ScenarioEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScenarioEditor)
{
    ui->setupUi(this);

    timer_.setInterval(500);
    timer_.start();

    setButtonStates();
    setConnections();
}

ScenarioEditor::~ScenarioEditor()
{
    delete ui;
}

void ScenarioEditor::setButtonStates()
{
    ui->removeButton->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void ScenarioEditor::setConnections()
{
    connect(ui->titleLineEdit, &QLineEdit::textChanged, this, &ScenarioEditor::updateOkButtonState);
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

void ScenarioEditor::updateOkButtonState()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isLineEditNotEmpty(ui->titleLineEdit));
}

void ScenarioEditor::updateButtonsState()
{
    bool enabled = !(isListWidgetNotEmpty(ui->stepsListWidget)) || !(isListWidgetItemSelected(ui->stepsListWidget)) ? false : true;

    ui->removeButton->setEnabled(enabled);
}

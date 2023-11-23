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

    connect(ui->stepsListWidget, &QListWidget::itemClicked, this, &ScenarioEditor::updateStepUpDownButtonsState);
    connect(ui->stepUpButton, &QPushButton::clicked, this, &ScenarioEditor::moveStepUp);
    connect(ui->stepDownButton, &QPushButton::clicked, this, &ScenarioEditor::moveStepDown);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &ScenarioEditor::save);
}

void ScenarioEditor::addStep()
{
    Step* step = new Step(this);

    step->setModal(true);

    if(step->exec() == QDialog::Accepted)
    {
        ui->stepsListWidget->addItem(step->getStepName());        
        updateStepUpDownButtonsState();
    }
}

void ScenarioEditor::removeStep()
{
    qDeleteAll(ui->stepsListWidget->selectedItems());
    updateStepUpDownButtonsState();
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

void ScenarioEditor::updateStepUpDownButtonsState()
{
    updateUpDownButtonsState(ui->stepUpButton, ui->stepDownButton, ui->stepsListWidget);
}

void ScenarioEditor::moveStepUp()
{
    moveItemUp(ui->stepsListWidget);
    updateStepUpDownButtonsState();
}

void ScenarioEditor::moveStepDown()
{
    moveItemDown(ui->stepsListWidget);
    updateStepUpDownButtonsState();
}

void ScenarioEditor::save()
{
    QStringList steps = itemsToList(ui->stepsListWidget);

    scenario_.setName(ui->titleLineEdit->text());
    scenario_.setSteps(steps);
}

Scenario ScenarioEditor::scenario() const noexcept
{
    return scenario_;
}

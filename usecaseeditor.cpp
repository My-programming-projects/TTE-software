#include "usecaseeditor.h"
#include "ui_usecaseeditor.h"

UseCaseEditor::UseCaseEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseEditor)
{
    ui->setupUi(this);

    timer_.setInterval(500);
    timer_.start();

    setButtonsState();
    setConnections();
}

UseCaseEditor::~UseCaseEditor()
{
    delete ui;
}

void UseCaseEditor::setButtonsState()
{
    ui->removePrecButton->setEnabled(false);
    ui->removeScenarioButton->setEnabled(false);
    ui->openScenarioButton->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void UseCaseEditor::setConnections()
{
    connect(ui->idLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
    connect(ui->actorsLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
    connect(ui->titleLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
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

void UseCaseEditor::updateOKButtonState()
{
    bool enabled = (isLineEditNotEmpty(ui->idLineEdit)) && (isLineEditNotEmpty(ui->titleLineEdit)) && (isLineEditNotEmpty(ui->actorsLineEdit)) ? true : false;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

void UseCaseEditor::updateButtonsState()
{
    bool removePrecButtonEnabled = !(isListWidgetNotEmpty(ui->precListWidget)) || !(isListWidgetItemSelected(ui->precListWidget)) ? false : true;
    bool scenarioListButtonsEnabled = !(isListWidgetNotEmpty(ui->scenarioListWidget)) || !(isListWidgetItemSelected(ui->scenarioListWidget)) ? false : true;

    ui->removePrecButton->setEnabled(removePrecButtonEnabled);
    ui->removeScenarioButton->setEnabled(scenarioListButtonsEnabled);
    ui->openScenarioButton->setEnabled(scenarioListButtonsEnabled);
}

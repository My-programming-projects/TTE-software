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
    connect(ui->purposeLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
    connect(ui->actorsLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
    connect(ui->titleLineEdit, &QLineEdit::textChanged, this, &UseCaseEditor::updateOKButtonState);
    connect(ui->addScenarioButton, &QPushButton::clicked, this, &UseCaseEditor::addScenario);
    connect(ui->removeScenarioButton, &QPushButton::clicked, this, &UseCaseEditor::removeScenario);
    connect(ui->addPrecButton, &QPushButton::clicked, this, &UseCaseEditor::addPrecondition);
    connect(ui->removePrecButton, &QPushButton::clicked, this, &UseCaseEditor::removePrecondition);

    connect(ui->precListWidget, &QListWidget::itemClicked, this, &UseCaseEditor::updatePrecUpDownButtonsState);
    connect(ui->scenarioListWidget, &QListWidget::itemClicked, this, &UseCaseEditor::updateScenarioUpDownButtonsState);

    connect(ui->precUpButton, &QPushButton::clicked, this, &UseCaseEditor::movePrecUp);
    connect(ui->precDownButton, &QPushButton::clicked, this, &UseCaseEditor::movePrecDown);
    connect(ui->scenarioUpButton, &QPushButton::clicked, this, &UseCaseEditor::moveScenarioUp);
    connect(ui->scenarioDownButton, &QPushButton::clicked, this, &UseCaseEditor::moveScenarioDown);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &UseCaseEditor::save);

    connect(&timer_, &QTimer::timeout, this, &UseCaseEditor::updateButtonsState);
}

void UseCaseEditor::addScenario()
{
    ScenarioEditor* scenarioEditor = new ScenarioEditor(this);

    if(!scenarios_.isEmpty())
    {
        scenarioEditor->setFirstScenarioSteps(scenarios_.at(0).steps());
    }

    scenarioEditor->setModal(true);

    if(scenarioEditor->exec() == QDialog::Accepted)
    {
        ui->scenarioListWidget->addItem(scenarioEditor->getScenarioTitle());
        scenarios_.push_back(scenarioEditor->scenario());

        updateScenarioUpDownButtonsState();
    }
}

void UseCaseEditor::removeScenario()
{
    int index = getSelectedItemIndex(ui->scenarioListWidget);
    scenarios_.remove(index);

    qDeleteAll(ui->scenarioListWidget->selectedItems());
    updateScenarioUpDownButtonsState();
}

void UseCaseEditor::addPrecondition()
{
    Precondition* precondition = new Precondition(this);

    precondition->setModal(true);

    if(precondition->exec() == QDialog::Accepted)
    {
        ui->precListWidget->addItem(precondition->getPreconditionName());

        updatePrecUpDownButtonsState();
    }
}

void UseCaseEditor::removePrecondition()
{
    qDeleteAll(ui->precListWidget->selectedItems());
    updatePrecUpDownButtonsState();
}

void UseCaseEditor::updateOKButtonState()
{
    bool enabled = (isLineEditNotEmpty(ui->idLineEdit)) &&
                   (isLineEditNotEmpty(ui->titleLineEdit)) &&
                   (isLineEditNotEmpty(ui->actorsLineEdit)) &&
                   (isLineEditNotEmpty(ui->purposeLineEdit)) ? true : false;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

void UseCaseEditor::updateButtonsState()
{
    bool precButtonsEnabled = !(isListWidgetNotEmpty(ui->precListWidget)) || !(isListWidgetItemSelected(ui->precListWidget)) ? false : true;
    bool scenarioButtonsEnabled = !(isListWidgetNotEmpty(ui->scenarioListWidget)) || !(isListWidgetItemSelected(ui->scenarioListWidget)) ? false : true;

    ui->removePrecButton->setEnabled(precButtonsEnabled);
    ui->removeScenarioButton->setEnabled(scenarioButtonsEnabled);
    ui->openScenarioButton->setEnabled(scenarioButtonsEnabled);
}

void UseCaseEditor::updatePrecUpDownButtonsState()
{
    updateUpDownButtonsState(ui->precUpButton, ui->precDownButton, ui->precListWidget);
}

void UseCaseEditor::updateScenarioUpDownButtonsState()
{
    updateUpDownButtonsState(ui->scenarioUpButton, ui->scenarioDownButton, ui->scenarioListWidget);
}

void UseCaseEditor::movePrecUp()
{
    moveItemUp(ui->precListWidget);
    updatePrecUpDownButtonsState();
}

void UseCaseEditor::movePrecDown()
{
    moveItemDown(ui->precListWidget);
    updatePrecUpDownButtonsState();
}

void UseCaseEditor::moveScenarioUp()
{
    moveItemUp(ui->scenarioListWidget);

    int index = getSelectedItemIndex(ui->scenarioListWidget);
    scenarios_.swapItemsAt(index, index + 1);

    updateScenarioUpDownButtonsState();
}

void UseCaseEditor::moveScenarioDown()
{
    moveItemDown(ui->scenarioListWidget);

    int index = getSelectedItemIndex(ui->scenarioListWidget);
    scenarios_.swapItemsAt(index, index - 1);

    updateScenarioUpDownButtonsState();
}

void UseCaseEditor::save()
{    
    QStringList preconditions = itemsToList(ui->precListWidget);

    useCase_.setId(ui->idLineEdit->text());
    useCase_.setName(ui->titleLineEdit->text());
    useCase_.setPurpose(ui->purposeLineEdit->text());
    useCase_.setActors(ui->actorsLineEdit->text());
    useCase_.setPreconditions(preconditions);
    useCase_.setScenarios(scenarios_);
}

UseCase UseCaseEditor::useCase() const noexcept
{
    return useCase_;
}

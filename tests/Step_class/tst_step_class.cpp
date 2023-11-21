
#include <QtTest>

#include "../../scenario.h"


class Step_class : public QObject
{
    Q_OBJECT

public:
    Step_class();
    ~Step_class();

private slots:
    void adding_steps();
    void setting_steps_list();
    void removing_steps();

private:
    void add_step(Scenario &scenario);
    void verify_list_size(const Scenario &scenario, const QStringList &expSteps);
    void verify_data(const Scenario &scenario, const QStringList &expSteps);

    const QStringList expected_steps_;
};

Step_class::Step_class() :
    expected_steps_{"An user enters email", "An user enters password", "An user clicks the submit button"} { }

Step_class::~Step_class() { }

void Step_class::add_step(Scenario &scenario)
{
    for(auto &step : expected_steps_)
    {
        scenario.addStep(step);
    }
}

void Step_class::verify_list_size(const Scenario &scenario, const QStringList &expSteps)
{
    QCOMPARE(scenario.steps().size(), expSteps.size());
}

void Step_class::verify_data(const Scenario &scenario, const QStringList &expSteps)
{
    for(int i = 0; i < expSteps.size(); ++i)
    {
        QCOMPARE(scenario.steps().at(i), expSteps.at(i));
    }
}

void Step_class::adding_steps()
{
    Scenario scenario;

    add_step(scenario);

    verify_list_size(scenario, expected_steps_);
    verify_data(scenario, expected_steps_);
}

void Step_class::setting_steps_list()
{
    Scenario scenario;
    scenario.setSteps(expected_steps_);

    verify_list_size(scenario, expected_steps_);
    verify_data(scenario, expected_steps_);
}

void Step_class::removing_steps()
{
    int index = 2;
    QStringList temp = expected_steps_;

    Scenario scenario;

    scenario.setSteps(expected_steps_);
    scenario.removeStep(index);

    temp.remove(index);

    verify_list_size(scenario, temp);
    verify_data(scenario, temp);
}

QTEST_APPLESS_MAIN(Step_class)

#include "tst_step_class.moc"

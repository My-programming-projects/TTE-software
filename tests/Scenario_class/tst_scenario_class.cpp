
#include <QtTest>

#include "../../usecase.hpp"
#include "../../scenario.h"

class Scenario_class : public QObject
{
    Q_OBJECT

public:
    Scenario_class();
    ~Scenario_class();

private slots:
    void setting_scenario_with_constructor();
    void setting_scenario_name();
    void adding_scenario();
    void removing_scenario();

private:
    void set_scenarios();
    void verify_list_size(const UseCase &useCase, const QVector<Scenario> &exp_scenarios);
    void verify_scenario_data(const Scenario &scenario, const QString &expected_name);
    void verify_scenarios_data(const UseCase &useCase, const QVector<Scenario> &exp_scenarios);

private:
    void add_scenarios(UseCase &useCase);

    const QVector<Scenario> expected_scenarios_;
};

Scenario_class::Scenario_class() :
    expected_scenarios_{
                        Scenario{"Correct login"},
                        Scenario{"Incorrect email"},
                        Scenario{"Incorrect password"},
                        Scenario{"Blank email field"}
                        } { }

Scenario_class::~Scenario_class() { }

void Scenario_class::add_scenarios(UseCase &useCase)
{
    for(auto &scenario : expected_scenarios_)
    {
        useCase.addScenario(scenario);
    }
}

void Scenario_class::verify_list_size(const UseCase &useCase, const QVector<Scenario> &exp_scenarios)
{
    QCOMPARE(useCase.scenarios().size(), exp_scenarios.size());
}

void Scenario_class::verify_scenario_data(const Scenario &scenario, const QString &expected_name)
{
    QCOMPARE(scenario.name(), expected_name);
}

void Scenario_class::verify_scenarios_data(const UseCase &useCase, const QVector<Scenario> &exp_scenarios)
{
    for(int i = 0; i < exp_scenarios.size(); ++i) {

        verify_scenario_data(useCase.scenarios().at(i), exp_scenarios.at(i).name());
    }
}

void Scenario_class::setting_scenario_with_constructor()
{
    const QString name = "Filling the address form";

    Scenario scenario{name};

    verify_scenario_data(scenario, name);
}

void Scenario_class::setting_scenario_name()
{
    const QString name = "Correct login";

    Scenario scenario;
    scenario.setName(name);

    verify_scenario_data(scenario, name);
}

void Scenario_class::adding_scenario()
{
    UseCase useCase;

    add_scenarios(useCase);
    verify_list_size(useCase, expected_scenarios_);
}

void Scenario_class::removing_scenario()
{
    const int index = 1;
    QVector<Scenario> temp = expected_scenarios_;

    UseCase useCase;
    useCase.setScenarios(expected_scenarios_);

    useCase.removeScenario(index);
    temp.remove(index);

    verify_list_size(useCase, temp);
    verify_scenarios_data(useCase, temp);
}

QTEST_APPLESS_MAIN(Scenario_class)

#include "tst_scenario_class.moc"


#include <QtTest>

// add necessary includes here

class Scenario_class : public QObject
{
    Q_OBJECT

public:
    Scenario_class();
    ~Scenario_class();

private slots:
    void test_case1();

};

Scenario_class::Scenario_class()
{

}

Scenario_class::~Scenario_class()
{

}

void Scenario_class::test_case1()
{

}

QTEST_APPLESS_MAIN(Scenario_class)

#include "tst_scenario_class.moc"

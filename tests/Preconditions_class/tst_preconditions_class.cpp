
#include <QtTest>

#include "../../usecase.hpp"


class Preconditions_class : public QObject
{
    Q_OBJECT

public:
    Preconditions_class();
    ~Preconditions_class();

private slots:
    void adding_preconditions();
    void setting_preconditions_list();
    void removing_precondition();

private:
    void add_precondition(UseCase& useCase);
    void verify_list_size(UseCase useCase, const QStringList &expPreconditions);
    void verify_data(UseCase useCase, const QStringList &expPreconditions);

    const QStringList expected_preconditions_;
    const int expectedListSize_;
};

Preconditions_class::Preconditions_class() :
    expected_preconditions_{"The software is running",
                            "The main menu is open",
                            "The \"Use case\" button is visible"},
    expectedListSize_{3} { }

Preconditions_class::~Preconditions_class() { }

void Preconditions_class::add_precondition(UseCase &useCase)
{
    useCase.addPrecondition(expected_preconditions_.at(0));
    useCase.addPrecondition(expected_preconditions_.at(1));
    useCase.addPrecondition(expected_preconditions_.at(2));
}

void Preconditions_class::verify_data(UseCase useCase, const QStringList &expPreconditions)
{
    for(int i = 0; i < expPreconditions.size(); ++i)
    {
        QCOMPARE(useCase.preconditions().at(i), expPreconditions.at(i));
    }
}

void Preconditions_class::verify_list_size(UseCase useCase, const QStringList &expPreconditions)
{
    QCOMPARE(useCase.preconditions().size(), expPreconditions.size());
}

void Preconditions_class::adding_preconditions()
{
    UseCase useCase;

    add_precondition(useCase);

    verify_list_size(useCase, expected_preconditions_);
    verify_data(useCase, expected_preconditions_);
}

void Preconditions_class::setting_preconditions_list()
{
    UseCase useCase;

    useCase.setPreconditions(expected_preconditions_);

    verify_list_size(useCase, expected_preconditions_);
    verify_data(useCase, expected_preconditions_);
}

void Preconditions_class::removing_precondition()
{
    const int index = 2;
    QStringList temp = expected_preconditions_;

    UseCase useCase;

    useCase.setPreconditions(expected_preconditions_);

    useCase.removePrecondition(index);
    temp.removeAt(index);

    verify_list_size(useCase, temp);
    verify_data(useCase, temp);
}

QTEST_APPLESS_MAIN(Preconditions_class)

#include "tst_preconditions_class.moc"


#ifndef TECHNIQUE_HPP
#define TECHNIQUE_HPP

#include <QString>


class Technique
{
public:
    Technique();
    Technique(const QString &name);

    void setName(const QString& name);
    const QString getName();

private:
    QString name_;
};

#endif // TECHNIQUE_HPP

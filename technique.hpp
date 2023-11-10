
#ifndef TECHNIQUE_HPP
#define TECHNIQUE_HPP

#include <string>


class Technique
{
public:
    Technique();
    Technique(const std::string& name);

    const std::string getName();

private:
    std::string name_;
};

#endif // TECHNIQUE_HPP

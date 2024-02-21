#include <iostream>
#include <iomanip>
#include <vector>
#include "Object.hpp"

Object ::Object(std ::string name, std ::vector<double> featureVector)
{
    this->_name = name;
    this->_featureVector = featureVector;
}

void Object ::print_info()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std ::cout << "Object: " << this->_name << "\tFeatureVector: [";
    for (auto d = this->_featureVector.begin(); d != this->_featureVector.end(); ++d)
    {
        if (d != this->_featureVector.begin())
            std ::cout << ", ";

        std ::cout << *d;
    }

    std ::cout << "]" << std ::endl;
}

std ::string Object ::get_name()
{
    return this->_name;
}

std ::vector<double> Object ::get_featureVector()
{
    return this->_featureVector;
}

bool Object ::operator>(const Object &outro)
{
    if (this->_name.compare(outro._name) > 0)
        return true;
    else
        return false;
}

bool Object ::operator<(const Object &outro)
{
    return !operator>(outro);
}

bool Object ::operator==(const Object &outro)
{
    if (this->_name == outro._name && this->_featureVector == outro._featureVector)
        return true;
    else
        return false;
}

bool Object ::operator!=(const Object &outro)
{
    return !operator==(outro);
}
#include <iostream>
#include <list>
#include "Object.hpp"
#include "Dataset.hpp"

Dataset ::Dataset(std ::string category)
{
    this->_category = category;
}

void Dataset ::add_object(std ::string name, std ::vector<double> featureVector)
{
    Object obj(name, featureVector);
    this->_objects.push_back(obj);

    this->_objects.sort();
}

void Dataset ::remove_object(std ::string name)
{
    for (auto it = this->_objects.begin(); it != this->_objects.end(); it++)
    {
        if (it->get_name() == name)
        {
            this->_objects.erase(it);
            return;
        }
    }

    std ::cout << "Invalid object: " << name << "!" << std ::endl;
}

void Dataset ::print_summary()
{
    if (this->_objects.size() == 0)
    {
        std ::cout << "Empty dataset: " << this->_category << "!" << std ::endl;
        return;
    }
    std :: cout << "Dataset: " << this->_category << std ::endl;
    for (auto obj : this->_objects)
    {
        obj.print_info();
    }
}

std ::string Dataset ::get_category()
{
    return this->_category;
}
std ::list<Object> Dataset ::get_objects()
{
    return this->_objects;
}


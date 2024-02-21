#ifndef Dataset_H
#define Dataset_H

#include <iostream>
#include <list>
#include "Object.hpp"

class Dataset
{
private:
    std ::string _category;
    std ::list<Object> _objects;

public:
    Dataset(std ::string category);
    void add_object(std ::string name, std ::vector<double> featureVector);
    void remove_object(std ::string name);
    void print_summary();
    std ::string get_category();
    std ::list<Object> get_objects();
};

#endif

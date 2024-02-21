#ifndef Recognizer_H
#define Recognizer_H

#include <iostream>
#include <list>
#include <vector>
#include "Object.hpp"
#include "Dataset.hpp"

class Recognizer
{
private:
    std ::list<Dataset> _datasets;

public:
    void add_dataset(std ::string category);
    void add_object(std ::string category, std ::string name, std ::vector<double> featureVector);
    void remove_object(std ::string category, std ::string name);
    void print_dataset_summary(std ::string category);
    double calc_vector_distance(std ::vector<double> v1, std ::vector<double> v2);
    void recognize_object(std ::string category, std ::vector<double> inputFeature);
};

#endif
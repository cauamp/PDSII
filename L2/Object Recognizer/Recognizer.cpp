#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include "Object.hpp"
#include "Dataset.hpp"
#include "Recognizer.hpp"

void Recognizer ::add_dataset(std ::string category)
{
    Dataset novoDataset = Dataset(category);
    _datasets.push_back(novoDataset);
}
void Recognizer ::add_object(std ::string category, std ::string name, std ::vector<double> featureVector)
{
    for (auto &dataset : _datasets)
    {
        if (dataset.get_category() == category)
        {
            dataset.add_object(name, featureVector);
            return;
        }
    }
    Dataset novoDataset = Dataset(category);
    novoDataset.add_object(name, featureVector);
    _datasets.push_back(novoDataset);
}
void Recognizer ::remove_object(std ::string category, std ::string name)
{
    for (auto &dataset : _datasets)
    {
        if (dataset.get_category() == category)
        {
            dataset.remove_object(name);
            return;
        }
    }

    std ::cout << "Invalid dataset: " << category << "!" << std ::endl;
}
void Recognizer ::print_dataset_summary(std ::string category)
{
    if (_datasets.empty())
    {
        std::cout << "There are no datasets!" << std::endl;
        return;
    }
    for (auto &dataset : _datasets)
    {
        if (dataset.get_category() == category)
        {
            dataset.print_summary();
            return;
        }
    }
    std ::cout << "Invalid dataset: " << category << "!" << std ::endl;
}
double Recognizer ::calc_vector_distance(std ::vector<double> v1, std ::vector<double> v2)
{
    double distance = 0;
    for (unsigned int i = 0; i < v1.size(); i++)
    {
        distance += pow(v1[i] - v2[i], 2);
    }

    return sqrt(distance);
}
void Recognizer ::recognize_object(std ::string category, std ::vector<double> inputFeature)
{

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std ::cout << "Matching object [";
    for (auto d = inputFeature.begin(); d != inputFeature.end(); ++d)
    {
        if (d != inputFeature.begin())
            std ::cout << ", ";

        std ::cout << *d;
    }
    std ::cout << "] in dataset " << category << std ::endl;

    std ::string likelyName = "Unknown";
    double minDistance = -1;

    for (auto &dataset : _datasets)
    {
        if (dataset.get_category() == category)
        {
            for (auto &object : dataset.get_objects())
            {
                double distance = calc_vector_distance(inputFeature, object.get_featureVector());
                std ::cout << "Object: " << object.get_name() << "\tDistance: " << distance << " " << std ::endl;

                if (distance < minDistance || minDistance < 0)
                {
                    minDistance = distance;
                    likelyName = object.get_name();
                }
            }
            break;
        }
    }

    std ::cout << "The input object is probably a " << likelyName << "." << std ::endl;
}


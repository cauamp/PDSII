#ifndef Object_H
#define Object_H
#include <iostream>
#include <vector>

class Object
{
private:
    std ::string _name;
    std ::vector<double> _featureVector;

public:
    Object(std ::string name, std ::vector<double> featureVector);

    void print_info();
    std ::string get_name();
    std ::vector<double> get_featureVector();

    bool operator==(const Object &outro);
    bool operator!=(const Object &outro);

    bool operator>(const Object &outro);
    bool operator<(const Object &outro);
};

#endif
#ifndef Circulo_H
#define Circulo_H
#include "Ponto.hpp"
#include "Figura.hpp"
class Circulo : public Figura
{
private:
    double _x;
    double _y;
    double _r;
  
public:
    Circulo(double x, double y, double r);
    ~Circulo();
    bool contem(const Ponto &p) const override;
};

#endif
#ifndef Retangulo_H
#define Retangulo_H
#include "Ponto.hpp"
#include "Figura.hpp"
class Retangulo : public Figura
{
private:
    double _x;
    double _y;
    double _largura;
    double _altura;
public:
    Retangulo(double x, double y, double largura, double altura);
    ~Retangulo();
    bool contem(const Ponto &p) const override;
};

#endif
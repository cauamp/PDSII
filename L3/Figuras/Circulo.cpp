#include "Circulo.hpp"
#include <iostream>
#include <cmath>

Circulo ::Circulo(double x, double y, double r) : _x(x), _y(y), _r(r) {}

Circulo ::~Circulo()
{
    std::cout << "Destrutor Circulo" << std::endl;
}

bool Circulo ::contem(const Ponto &p) const
{
    double distancia = sqrt(pow(p.getX() - this->_x, 2) + pow(p.getY() - this->_y, 2));

    return distancia <= this->_r;
}
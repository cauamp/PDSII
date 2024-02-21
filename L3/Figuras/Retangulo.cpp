#include "Retangulo.hpp"
#include <iostream>

Retangulo ::Retangulo(double x, double y, double largura, double altura) : _x(x), _y(y), _largura(largura), _altura(altura) {}

Retangulo ::~Retangulo()
{
    std::cout << "Destrutor Retangulo" << std::endl;
}

bool Retangulo ::contem(const Ponto &p) const{
    if(p.getX() >= _x && p.getX() <= _x + _largura && p.getY() >= _y && p.getY() <= _y + _altura){
        return true;
    }
    return false;
}